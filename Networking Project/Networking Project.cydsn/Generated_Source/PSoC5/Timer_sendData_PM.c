/*******************************************************************************
* File Name: Timer_sendData_PM.c
* Version 2.60
*
*  Description:
*     This file provides the power management source code to API for the
*     Timer.
*
*   Note:
*     None
*
*******************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#include "Timer_sendData.h"

static Timer_sendData_backupStruct Timer_sendData_backup;


/*******************************************************************************
* Function Name: Timer_sendData_SaveConfig
********************************************************************************
*
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
*  Timer_sendData_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void Timer_sendData_SaveConfig(void) 
{
    #if (!Timer_sendData_UsingFixedFunction)
        Timer_sendData_backup.TimerUdb = Timer_sendData_ReadCounter();
        Timer_sendData_backup.InterruptMaskValue = Timer_sendData_STATUS_MASK;
        #if (Timer_sendData_UsingHWCaptureCounter)
            Timer_sendData_backup.TimerCaptureCounter = Timer_sendData_ReadCaptureCount();
        #endif /* Back Up capture counter register  */

        #if(!Timer_sendData_UDB_CONTROL_REG_REMOVED)
            Timer_sendData_backup.TimerControlRegister = Timer_sendData_ReadControlRegister();
        #endif /* Backup the enable state of the Timer component */
    #endif /* Backup non retention registers in UDB implementation. All fixed function registers are retention */
}


/*******************************************************************************
* Function Name: Timer_sendData_RestoreConfig
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
*  Timer_sendData_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void Timer_sendData_RestoreConfig(void) 
{   
    #if (!Timer_sendData_UsingFixedFunction)

        Timer_sendData_WriteCounter(Timer_sendData_backup.TimerUdb);
        Timer_sendData_STATUS_MASK =Timer_sendData_backup.InterruptMaskValue;
        #if (Timer_sendData_UsingHWCaptureCounter)
            Timer_sendData_SetCaptureCount(Timer_sendData_backup.TimerCaptureCounter);
        #endif /* Restore Capture counter register*/

        #if(!Timer_sendData_UDB_CONTROL_REG_REMOVED)
            Timer_sendData_WriteControlRegister(Timer_sendData_backup.TimerControlRegister);
        #endif /* Restore the enable state of the Timer component */
    #endif /* Restore non retention registers in the UDB implementation only */
}


/*******************************************************************************
* Function Name: Timer_sendData_Sleep
********************************************************************************
*
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
*  Timer_sendData_backup.TimerEnableState:  Is modified depending on the
*  enable state of the block before entering sleep mode.
*
*******************************************************************************/
void Timer_sendData_Sleep(void) 
{
    #if(!Timer_sendData_UDB_CONTROL_REG_REMOVED)
        /* Save Counter's enable state */
        if(Timer_sendData_CTRL_ENABLE == (Timer_sendData_CONTROL & Timer_sendData_CTRL_ENABLE))
        {
            /* Timer is enabled */
            Timer_sendData_backup.TimerEnableState = 1u;
        }
        else
        {
            /* Timer is disabled */
            Timer_sendData_backup.TimerEnableState = 0u;
        }
    #endif /* Back up enable state from the Timer control register */
    Timer_sendData_Stop();
    Timer_sendData_SaveConfig();
}


/*******************************************************************************
* Function Name: Timer_sendData_Wakeup
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
*  Timer_sendData_backup.enableState:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Timer_sendData_Wakeup(void) 
{
    Timer_sendData_RestoreConfig();
    #if(!Timer_sendData_UDB_CONTROL_REG_REMOVED)
        if(Timer_sendData_backup.TimerEnableState == 1u)
        {     /* Enable Timer's operation */
                Timer_sendData_Enable();
        } /* Do nothing if Timer was disabled before */
    #endif /* Remove this code section if Control register is removed */
}


/* [] END OF FILE */
