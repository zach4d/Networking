/*******************************************************************************
* File Name: Recieve_Input.c  
* Version 2.5
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "Recieve_Input.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 Recieve_Input__PORT == 15 && ((Recieve_Input__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: Recieve_Input_Write
********************************************************************************
*
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  None
*  
*******************************************************************************/
void Recieve_Input_Write(uint8 value) 
{
    uint8 staticBits = (Recieve_Input_DR & (uint8)(~Recieve_Input_MASK));
    Recieve_Input_DR = staticBits | ((uint8)(value << Recieve_Input_SHIFT) & Recieve_Input_MASK);
}


/*******************************************************************************
* Function Name: Recieve_Input_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  Recieve_Input_DM_STRONG     Strong Drive 
*  Recieve_Input_DM_OD_HI      Open Drain, Drives High 
*  Recieve_Input_DM_OD_LO      Open Drain, Drives Low 
*  Recieve_Input_DM_RES_UP     Resistive Pull Up 
*  Recieve_Input_DM_RES_DWN    Resistive Pull Down 
*  Recieve_Input_DM_RES_UPDWN  Resistive Pull Up/Down 
*  Recieve_Input_DM_DIG_HIZ    High Impedance Digital 
*  Recieve_Input_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void Recieve_Input_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(Recieve_Input_0, mode);
}


/*******************************************************************************
* Function Name: Recieve_Input_Read
********************************************************************************
*
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  None
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro Recieve_Input_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Recieve_Input_Read(void) 
{
    return (Recieve_Input_PS & Recieve_Input_MASK) >> Recieve_Input_SHIFT;
}


/*******************************************************************************
* Function Name: Recieve_Input_ReadDataReg
********************************************************************************
*
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 Recieve_Input_ReadDataReg(void) 
{
    return (Recieve_Input_DR & Recieve_Input_MASK) >> Recieve_Input_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Recieve_Input_INTSTAT) 

    /*******************************************************************************
    * Function Name: Recieve_Input_ClearInterrupt
    ********************************************************************************
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  None 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 Recieve_Input_ClearInterrupt(void) 
    {
        return (Recieve_Input_INTSTAT & Recieve_Input_MASK) >> Recieve_Input_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
