/*******************************************************************************
* File Name: ShiftReg_output.c
* Version 2.30
*
* Description:
*  This file provides the API source code for the Shift Register component.
*
* Note: none
*
********************************************************************************
* Copyright 2008-2013, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#include "ShiftReg_output.h"

uint8 ShiftReg_output_initVar = 0u;


/*******************************************************************************
* Function Name: ShiftReg_output_Start
********************************************************************************
*
* Summary:
*  Starts the Shift Register.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  ShiftReg_output_initVar - used to check initial configuration, modified on
*  first function call.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void ShiftReg_output_Start(void) 
{
    if(0u == ShiftReg_output_initVar)
    {
        ShiftReg_output_Init();
        ShiftReg_output_initVar = 1u; /* Component initialized */
    }

    ShiftReg_output_Enable();
}


/*******************************************************************************
* Function Name: ShiftReg_output_Enable
********************************************************************************
*
* Summary:
*  Enables the Shift Register.
*
* Parameters:
*  void.
*
* Return:
*  void.
*
*******************************************************************************/
void ShiftReg_output_Enable(void) 
{
    /* Changing address in Datapath Control Store
       from NOP to component state machine commands space */
    ShiftReg_output_SR_CONTROL |= ShiftReg_output_CLK_EN;

    ShiftReg_output_EnableInt();
}


/*******************************************************************************
* Function Name: ShiftReg_output_Init
********************************************************************************
*
* Summary:
*  Initializes Tx and/or Rx interrupt sources with initial values.
*
* Parameters:
*  void.
*
* Return:
*  void.
*
*******************************************************************************/
void ShiftReg_output_Init(void) 
{
    ShiftReg_output_SetIntMode(ShiftReg_output_INT_SRC);
}


/*******************************************************************************
* Function Name: ShiftReg_output_Stop
********************************************************************************
*
* Summary:
*  Disables the Shift Register
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void ShiftReg_output_Stop(void) 
{
    /*changing Datapath Control Store address to NOP space*/
    ShiftReg_output_SR_CONTROL &= ((uint8) ~ShiftReg_output_CLK_EN);
    ShiftReg_output_DisableInt();
}


/*******************************************************************************
* Function Name: ShiftReg_output_EnableInt
********************************************************************************
*
* Summary:
*  Enables the Shift Register interrupt.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void ShiftReg_output_EnableInt(void) 
{
    uint8 interruptState;

    interruptState = CyEnterCriticalSection();
    ShiftReg_output_SR_AUX_CONTROL |= ShiftReg_output_INTERRUPTS_ENABLE;
    CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: ShiftReg_output_DisableInt
********************************************************************************
*
* Summary:
*  Disables the Shift Register interrupt.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void ShiftReg_output_DisableInt(void) 
{
    uint8 interruptState;

    interruptState = CyEnterCriticalSection();
    ShiftReg_output_SR_AUX_CONTROL &= ((uint8) ~ShiftReg_output_INTERRUPTS_ENABLE);
    CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: ShiftReg_output_GetFIFOStatus
********************************************************************************
*
* Summary:
*  Returns current status of input or output FIFO.
*
* Parameters:
*  fifoId.
*
* Return:
*  FIFO status.
*
*******************************************************************************/
uint8 ShiftReg_output_GetFIFOStatus(uint8 fifoId) 
{
    uint8 result;

    result = ShiftReg_output_RET_FIFO_NOT_DEFINED;

    #if(0u != ShiftReg_output_USE_INPUT_FIFO)
        if(ShiftReg_output_IN_FIFO == fifoId)
        {
            switch(ShiftReg_output_GET_IN_FIFO_STS)
            {
                case ShiftReg_output_IN_FIFO_FULL :
                    result = ShiftReg_output_RET_FIFO_FULL;
                    break;

                case ShiftReg_output_IN_FIFO_EMPTY :
                    result = ShiftReg_output_RET_FIFO_EMPTY;
                    break;

                case ShiftReg_output_IN_FIFO_PARTIAL:
                    result = ShiftReg_output_RET_FIFO_PARTIAL;
                    break;
                    
                default:
                    /* Initial result value, while 
                       IN_FIFO_EMPTY case is false 
                     */
                    result = ShiftReg_output_RET_FIFO_EMPTY;
                    break;
            }   
        }
    #endif /* (0u != ShiftReg_output_USE_INPUT_FIFO) */

    if(ShiftReg_output_OUT_FIFO == fifoId)
    {
        switch(ShiftReg_output_GET_OUT_FIFO_STS)
        {
            case ShiftReg_output_OUT_FIFO_FULL :
                result = ShiftReg_output_RET_FIFO_FULL;
                break;

            case ShiftReg_output_OUT_FIFO_EMPTY :
                result = ShiftReg_output_RET_FIFO_EMPTY;
                break;

            case ShiftReg_output_OUT_FIFO_PARTIAL :
                result = ShiftReg_output_RET_FIFO_PARTIAL;
                break;

            default:
                /* Initial result value, while 
                   OUT_FIFO_FULL case is false 
                 */
                result = ShiftReg_output_RET_FIFO_FULL;
                break;
        }
    }

    return(result);
}


/*******************************************************************************
* Function Name: ShiftReg_output_SetIntMode
********************************************************************************
*
* Summary:
*  Sets the Interrupt Source for the Shift Register interrupt. Multiple
*  sources may be ORed together
*
* Parameters:
*  interruptSource: Byte containing the constant for the selected interrupt
*  source/s.
*
* Return:
*  None.
*
*******************************************************************************/
void ShiftReg_output_SetIntMode(uint8 interruptSource) 
{
    ShiftReg_output_SR_STATUS_MASK &= ((uint8) ~ShiftReg_output_INTS_EN_MASK);          /* Clear existing int */
    ShiftReg_output_SR_STATUS_MASK |= (interruptSource & ShiftReg_output_INTS_EN_MASK); /* Set int */
}


/*******************************************************************************
* Function Name: ShiftReg_output_GetIntStatus
********************************************************************************
*
* Summary:
*  Gets the Shift Register Interrupt status.
*
* Parameters:
*  None.
*
* Return:
*  Byte containing the constant for the selected interrupt source/s.
*
*******************************************************************************/
uint8 ShiftReg_output_GetIntStatus(void) 
{
    return(ShiftReg_output_SR_STATUS & ShiftReg_output_INTS_EN_MASK);
}


/*******************************************************************************
* Function Name: ShiftReg_output_WriteRegValue
********************************************************************************
*
* Summary:
*  Send state directly to shift register
*
* Parameters:
*  shiftData: containing shift register state.
*
* Return:
*  None.
*
*******************************************************************************/
void ShiftReg_output_WriteRegValue(uint32 shiftData)
                                                                     
{
    CY_SET_REG32(ShiftReg_output_SHIFT_REG_LSB_PTR, shiftData);
}


#if(0u != ShiftReg_output_USE_INPUT_FIFO)
    /*******************************************************************************
    * Function Name: ShiftReg_output_WriteData
    ********************************************************************************
    *
    * Summary:
    *  Send state to FIFO for later transfer to shift register based on the Load
    *  input
    *
    * Parameters:
    *  shiftData: containing shift register state.
    *
    * Return:
    *  Indicates: successful execution of function
    *  when FIFO is empty; and error when FIFO is full.
    *
    * Reentrant:
    *  No.
    *
    *******************************************************************************/
    cystatus ShiftReg_output_WriteData(uint32 shiftData)
                                                                         
    {
        cystatus result;

        result = CYRET_INVALID_STATE;

        /* Writes data into the input FIFO if it is not FULL */
        if(ShiftReg_output_RET_FIFO_FULL != (ShiftReg_output_GetFIFOStatus(ShiftReg_output_IN_FIFO)))
        {
            CY_SET_REG32(ShiftReg_output_IN_FIFO_VAL_LSB_PTR, shiftData);
            result = CYRET_SUCCESS;
        }

        return(result);
    }
#endif /* (0u != ShiftReg_output_USE_INPUT_FIFO) */


#if(0u != ShiftReg_output_USE_OUTPUT_FIFO)
    /*******************************************************************************
    * Function Name: ShiftReg_output_ReadData
    ********************************************************************************
    *
    * Summary:
    *  Returns state in FIFO due to Store input.
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  Shift Register state
    *
    * Reentrant:
    *  No.
    *
    *******************************************************************************/
    uint32 ShiftReg_output_ReadData(void) 
    {
        return(CY_GET_REG32(ShiftReg_output_OUT_FIFO_VAL_LSB_PTR));
    }
#endif /* (0u != ShiftReg_output_USE_OUTPUT_FIFO) */


/*******************************************************************************
* Function Name: ShiftReg_output_ReadRegValue
********************************************************************************
*
* Summary:
*  Directly returns current state in shift register, not data in FIFO due
*  to Store input.
*
* Parameters:
*  None.
*
* Return:
*  Shift Register state. Clears output FIFO.
*
* Reentrant:
*  No.
*
*******************************************************************************/
uint32 ShiftReg_output_ReadRegValue(void) 
{
    uint32 result;

    /* Clear FIFO before software capture */
    while(ShiftReg_output_RET_FIFO_EMPTY != ShiftReg_output_GetFIFOStatus(ShiftReg_output_OUT_FIFO))
    {
        (void) CY_GET_REG32(ShiftReg_output_OUT_FIFO_VAL_LSB_PTR);
    }

    /* Read of 8 bits from A1 causes capture to output FIFO */
    (void) CY_GET_REG8(ShiftReg_output_SHIFT_REG_CAPTURE_PTR);

    /* Read output FIFO */
    result  = CY_GET_REG32(ShiftReg_output_OUT_FIFO_VAL_LSB_PTR);
    
    #if(0u != (ShiftReg_output_SR_SIZE % 8u))
        result &= ((uint32) ShiftReg_output_SR_MASK);
    #endif /* (0u != (ShiftReg_output_SR_SIZE % 8u)) */
    
    return(result);
}


/* [] END OF FILE */
