/*******************************************************************************
* File Name: Counter_input_PM.c  
* Version 2.40
*
*  Description:
*    This file provides the power management source code to API for the
*    Counter.  
*
*   Note:
*     None
*
*******************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#include "Counter_input.h"

static Counter_input_backupStruct Counter_input_backup;


/*******************************************************************************
* Function Name: Counter_input_SaveConfig
********************************************************************************
* Summary:
*     Save the current user configuration
*
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  Counter_input_backup:  Variables of this global structure are modified to 
*  store the values of non retention configuration registers when Sleep() API is 
*  called.
*
*******************************************************************************/
void Counter_input_SaveConfig(void) 
{
    #if (!Counter_input_UsingFixedFunction)

        Counter_input_backup.CounterUdb = Counter_input_ReadCounter();

        #if (CY_UDB_V0)
            Counter_input_backup.CounterPeriod = Counter_input_ReadPeriod();
            Counter_input_backup.CompareValue = Counter_input_ReadCompare();
            Counter_input_backup.InterruptMaskValue = Counter_input_STATUS_MASK;
        #endif /* CY_UDB_V0 */

        #if(!Counter_input_ControlRegRemoved)
            Counter_input_backup.CounterControlRegister = Counter_input_ReadControlRegister();
        #endif /* (!Counter_input_ControlRegRemoved) */

    #endif /* (!Counter_input_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Counter_input_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  Counter_input_backup:  Variables of this global structure are used to 
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void Counter_input_RestoreConfig(void) 
{      
    #if (!Counter_input_UsingFixedFunction)

        #if (CY_UDB_V0)
            uint8 Counter_input_interruptState;
        #endif  /* (CY_UDB_V0) */

       Counter_input_WriteCounter(Counter_input_backup.CounterUdb);

        #if (CY_UDB_V0)
            Counter_input_WritePeriod(Counter_input_backup.CounterPeriod);
            Counter_input_WriteCompare(Counter_input_backup.CompareValue);

            Counter_input_interruptState = CyEnterCriticalSection();
            Counter_input_STATUS_AUX_CTRL |= Counter_input_STATUS_ACTL_INT_EN_MASK;
            CyExitCriticalSection(Counter_input_interruptState);

            Counter_input_STATUS_MASK = Counter_input_backup.InterruptMaskValue;
        #endif  /* (CY_UDB_V0) */

        #if(!Counter_input_ControlRegRemoved)
            Counter_input_WriteControlRegister(Counter_input_backup.CounterControlRegister);
        #endif /* (!Counter_input_ControlRegRemoved) */

    #endif /* (!Counter_input_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Counter_input_Sleep
********************************************************************************
* Summary:
*     Stop and Save the user configuration
*
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  Counter_input_backup.enableState:  Is modified depending on the enable 
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void Counter_input_Sleep(void) 
{
    #if(!Counter_input_ControlRegRemoved)
        /* Save Counter's enable state */
        if(Counter_input_CTRL_ENABLE == (Counter_input_CONTROL & Counter_input_CTRL_ENABLE))
        {
            /* Counter is enabled */
            Counter_input_backup.CounterEnableState = 1u;
        }
        else
        {
            /* Counter is disabled */
            Counter_input_backup.CounterEnableState = 0u;
        }
    #else
        Counter_input_backup.CounterEnableState = 1u;
        if(Counter_input_backup.CounterEnableState != 0u)
        {
            Counter_input_backup.CounterEnableState = 0u;
        }
    #endif /* (!Counter_input_ControlRegRemoved) */
    
    Counter_input_Stop();
    Counter_input_SaveConfig();
}


/*******************************************************************************
* Function Name: Counter_input_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration
*  
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  Counter_input_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Counter_input_Wakeup(void) 
{
    Counter_input_RestoreConfig();
    #if(!Counter_input_ControlRegRemoved)
        if(Counter_input_backup.CounterEnableState == 1u)
        {
            /* Enable Counter's operation */
            Counter_input_Enable();
        } /* Do nothing if Counter was disabled before */    
    #endif /* (!Counter_input_ControlRegRemoved) */
    
}


/* [] END OF FILE */
