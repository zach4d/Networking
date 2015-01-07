/*******************************************************************************
* File Name: Counter_output_PM.c  
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

#include "Counter_output.h"

static Counter_output_backupStruct Counter_output_backup;


/*******************************************************************************
* Function Name: Counter_output_SaveConfig
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
*  Counter_output_backup:  Variables of this global structure are modified to 
*  store the values of non retention configuration registers when Sleep() API is 
*  called.
*
*******************************************************************************/
void Counter_output_SaveConfig(void) 
{
    #if (!Counter_output_UsingFixedFunction)

        Counter_output_backup.CounterUdb = Counter_output_ReadCounter();

        #if (CY_UDB_V0)
            Counter_output_backup.CounterPeriod = Counter_output_ReadPeriod();
            Counter_output_backup.CompareValue = Counter_output_ReadCompare();
            Counter_output_backup.InterruptMaskValue = Counter_output_STATUS_MASK;
        #endif /* CY_UDB_V0 */

        #if(!Counter_output_ControlRegRemoved)
            Counter_output_backup.CounterControlRegister = Counter_output_ReadControlRegister();
        #endif /* (!Counter_output_ControlRegRemoved) */

    #endif /* (!Counter_output_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Counter_output_RestoreConfig
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
*  Counter_output_backup:  Variables of this global structure are used to 
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void Counter_output_RestoreConfig(void) 
{      
    #if (!Counter_output_UsingFixedFunction)

        #if (CY_UDB_V0)
            uint8 Counter_output_interruptState;
        #endif  /* (CY_UDB_V0) */

       Counter_output_WriteCounter(Counter_output_backup.CounterUdb);

        #if (CY_UDB_V0)
            Counter_output_WritePeriod(Counter_output_backup.CounterPeriod);
            Counter_output_WriteCompare(Counter_output_backup.CompareValue);

            Counter_output_interruptState = CyEnterCriticalSection();
            Counter_output_STATUS_AUX_CTRL |= Counter_output_STATUS_ACTL_INT_EN_MASK;
            CyExitCriticalSection(Counter_output_interruptState);

            Counter_output_STATUS_MASK = Counter_output_backup.InterruptMaskValue;
        #endif  /* (CY_UDB_V0) */

        #if(!Counter_output_ControlRegRemoved)
            Counter_output_WriteControlRegister(Counter_output_backup.CounterControlRegister);
        #endif /* (!Counter_output_ControlRegRemoved) */

    #endif /* (!Counter_output_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Counter_output_Sleep
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
*  Counter_output_backup.enableState:  Is modified depending on the enable 
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void Counter_output_Sleep(void) 
{
    #if(!Counter_output_ControlRegRemoved)
        /* Save Counter's enable state */
        if(Counter_output_CTRL_ENABLE == (Counter_output_CONTROL & Counter_output_CTRL_ENABLE))
        {
            /* Counter is enabled */
            Counter_output_backup.CounterEnableState = 1u;
        }
        else
        {
            /* Counter is disabled */
            Counter_output_backup.CounterEnableState = 0u;
        }
    #else
        Counter_output_backup.CounterEnableState = 1u;
        if(Counter_output_backup.CounterEnableState != 0u)
        {
            Counter_output_backup.CounterEnableState = 0u;
        }
    #endif /* (!Counter_output_ControlRegRemoved) */
    
    Counter_output_Stop();
    Counter_output_SaveConfig();
}


/*******************************************************************************
* Function Name: Counter_output_Wakeup
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
*  Counter_output_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Counter_output_Wakeup(void) 
{
    Counter_output_RestoreConfig();
    #if(!Counter_output_ControlRegRemoved)
        if(Counter_output_backup.CounterEnableState == 1u)
        {
            /* Enable Counter's operation */
            Counter_output_Enable();
        } /* Do nothing if Counter was disabled before */    
    #endif /* (!Counter_output_ControlRegRemoved) */
    
}


/* [] END OF FILE */
