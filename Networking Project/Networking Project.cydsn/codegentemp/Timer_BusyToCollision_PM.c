/*******************************************************************************
* File Name: Timer_BusyToCollision_PM.c
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

#include "Timer_BusyToCollision.h"

static Timer_BusyToCollision_backupStruct Timer_BusyToCollision_backup;


/*******************************************************************************
* Function Name: Timer_BusyToCollision_SaveConfig
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
*  Timer_BusyToCollision_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void Timer_BusyToCollision_SaveConfig(void) 
{
    #if (!Timer_BusyToCollision_UsingFixedFunction)
        Timer_BusyToCollision_backup.TimerUdb = Timer_BusyToCollision_ReadCounter();
        Timer_BusyToCollision_backup.InterruptMaskValue = Timer_BusyToCollision_STATUS_MASK;
        #if (Timer_BusyToCollision_UsingHWCaptureCounter)
            Timer_BusyToCollision_backup.TimerCaptureCounter = Timer_BusyToCollision_ReadCaptureCount();
        #endif /* Back Up capture counter register  */

        #if(!Timer_BusyToCollision_UDB_CONTROL_REG_REMOVED)
            Timer_BusyToCollision_backup.TimerControlRegister = Timer_BusyToCollision_ReadControlRegister();
        #endif /* Backup the enable state of the Timer component */
    #endif /* Backup non retention registers in UDB implementation. All fixed function registers are retention */
}


/*******************************************************************************
* Function Name: Timer_BusyToCollision_RestoreConfig
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
*  Timer_BusyToCollision_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void Timer_BusyToCollision_RestoreConfig(void) 
{   
    #if (!Timer_BusyToCollision_UsingFixedFunction)

        Timer_BusyToCollision_WriteCounter(Timer_BusyToCollision_backup.TimerUdb);
        Timer_BusyToCollision_STATUS_MASK =Timer_BusyToCollision_backup.InterruptMaskValue;
        #if (Timer_BusyToCollision_UsingHWCaptureCounter)
            Timer_BusyToCollision_SetCaptureCount(Timer_BusyToCollision_backup.TimerCaptureCounter);
        #endif /* Restore Capture counter register*/

        #if(!Timer_BusyToCollision_UDB_CONTROL_REG_REMOVED)
            Timer_BusyToCollision_WriteControlRegister(Timer_BusyToCollision_backup.TimerControlRegister);
        #endif /* Restore the enable state of the Timer component */
    #endif /* Restore non retention registers in the UDB implementation only */
}


/*******************************************************************************
* Function Name: Timer_BusyToCollision_Sleep
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
*  Timer_BusyToCollision_backup.TimerEnableState:  Is modified depending on the
*  enable state of the block before entering sleep mode.
*
*******************************************************************************/
void Timer_BusyToCollision_Sleep(void) 
{
    #if(!Timer_BusyToCollision_UDB_CONTROL_REG_REMOVED)
        /* Save Counter's enable state */
        if(Timer_BusyToCollision_CTRL_ENABLE == (Timer_BusyToCollision_CONTROL & Timer_BusyToCollision_CTRL_ENABLE))
        {
            /* Timer is enabled */
            Timer_BusyToCollision_backup.TimerEnableState = 1u;
        }
        else
        {
            /* Timer is disabled */
            Timer_BusyToCollision_backup.TimerEnableState = 0u;
        }
    #endif /* Back up enable state from the Timer control register */
    Timer_BusyToCollision_Stop();
    Timer_BusyToCollision_SaveConfig();
}


/*******************************************************************************
* Function Name: Timer_BusyToCollision_Wakeup
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
*  Timer_BusyToCollision_backup.enableState:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Timer_BusyToCollision_Wakeup(void) 
{
    Timer_BusyToCollision_RestoreConfig();
    #if(!Timer_BusyToCollision_UDB_CONTROL_REG_REMOVED)
        if(Timer_BusyToCollision_backup.TimerEnableState == 1u)
        {     /* Enable Timer's operation */
                Timer_BusyToCollision_Enable();
        } /* Do nothing if Timer was disabled before */
    #endif /* Remove this code section if Control register is removed */
}


/* [] END OF FILE */
