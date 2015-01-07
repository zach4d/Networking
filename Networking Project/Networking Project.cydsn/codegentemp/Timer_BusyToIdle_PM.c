/*******************************************************************************
* File Name: Timer_BusyToIdle_PM.c
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

#include "Timer_BusyToIdle.h"

static Timer_BusyToIdle_backupStruct Timer_BusyToIdle_backup;


/*******************************************************************************
* Function Name: Timer_BusyToIdle_SaveConfig
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
*  Timer_BusyToIdle_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void Timer_BusyToIdle_SaveConfig(void) 
{
    #if (!Timer_BusyToIdle_UsingFixedFunction)
        Timer_BusyToIdle_backup.TimerUdb = Timer_BusyToIdle_ReadCounter();
        Timer_BusyToIdle_backup.InterruptMaskValue = Timer_BusyToIdle_STATUS_MASK;
        #if (Timer_BusyToIdle_UsingHWCaptureCounter)
            Timer_BusyToIdle_backup.TimerCaptureCounter = Timer_BusyToIdle_ReadCaptureCount();
        #endif /* Back Up capture counter register  */

        #if(!Timer_BusyToIdle_UDB_CONTROL_REG_REMOVED)
            Timer_BusyToIdle_backup.TimerControlRegister = Timer_BusyToIdle_ReadControlRegister();
        #endif /* Backup the enable state of the Timer component */
    #endif /* Backup non retention registers in UDB implementation. All fixed function registers are retention */
}


/*******************************************************************************
* Function Name: Timer_BusyToIdle_RestoreConfig
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
*  Timer_BusyToIdle_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void Timer_BusyToIdle_RestoreConfig(void) 
{   
    #if (!Timer_BusyToIdle_UsingFixedFunction)

        Timer_BusyToIdle_WriteCounter(Timer_BusyToIdle_backup.TimerUdb);
        Timer_BusyToIdle_STATUS_MASK =Timer_BusyToIdle_backup.InterruptMaskValue;
        #if (Timer_BusyToIdle_UsingHWCaptureCounter)
            Timer_BusyToIdle_SetCaptureCount(Timer_BusyToIdle_backup.TimerCaptureCounter);
        #endif /* Restore Capture counter register*/

        #if(!Timer_BusyToIdle_UDB_CONTROL_REG_REMOVED)
            Timer_BusyToIdle_WriteControlRegister(Timer_BusyToIdle_backup.TimerControlRegister);
        #endif /* Restore the enable state of the Timer component */
    #endif /* Restore non retention registers in the UDB implementation only */
}


/*******************************************************************************
* Function Name: Timer_BusyToIdle_Sleep
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
*  Timer_BusyToIdle_backup.TimerEnableState:  Is modified depending on the
*  enable state of the block before entering sleep mode.
*
*******************************************************************************/
void Timer_BusyToIdle_Sleep(void) 
{
    #if(!Timer_BusyToIdle_UDB_CONTROL_REG_REMOVED)
        /* Save Counter's enable state */
        if(Timer_BusyToIdle_CTRL_ENABLE == (Timer_BusyToIdle_CONTROL & Timer_BusyToIdle_CTRL_ENABLE))
        {
            /* Timer is enabled */
            Timer_BusyToIdle_backup.TimerEnableState = 1u;
        }
        else
        {
            /* Timer is disabled */
            Timer_BusyToIdle_backup.TimerEnableState = 0u;
        }
    #endif /* Back up enable state from the Timer control register */
    Timer_BusyToIdle_Stop();
    Timer_BusyToIdle_SaveConfig();
}


/*******************************************************************************
* Function Name: Timer_BusyToIdle_Wakeup
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
*  Timer_BusyToIdle_backup.enableState:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Timer_BusyToIdle_Wakeup(void) 
{
    Timer_BusyToIdle_RestoreConfig();
    #if(!Timer_BusyToIdle_UDB_CONTROL_REG_REMOVED)
        if(Timer_BusyToIdle_backup.TimerEnableState == 1u)
        {     /* Enable Timer's operation */
                Timer_BusyToIdle_Enable();
        } /* Do nothing if Timer was disabled before */
    #endif /* Remove this code section if Control register is removed */
}


/* [] END OF FILE */
