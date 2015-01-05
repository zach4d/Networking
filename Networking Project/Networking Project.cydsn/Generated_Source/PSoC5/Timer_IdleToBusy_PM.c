/*******************************************************************************
* File Name: Timer_IdleToBusy_PM.c
* Version 2.50
*
*  Description:
*     This file provides the power management source code to API for the
*     Timer.
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

#include "Timer_IdleToBusy.h"
static Timer_IdleToBusy_backupStruct Timer_IdleToBusy_backup;


/*******************************************************************************
* Function Name: Timer_IdleToBusy_SaveConfig
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
*  Timer_IdleToBusy_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void Timer_IdleToBusy_SaveConfig(void) 
{
    #if (!Timer_IdleToBusy_UsingFixedFunction)
        /* Backup the UDB non-rentention registers for CY_UDB_V0 */
        #if (CY_UDB_V0)
            Timer_IdleToBusy_backup.TimerUdb = Timer_IdleToBusy_ReadCounter();
            Timer_IdleToBusy_backup.TimerPeriod = Timer_IdleToBusy_ReadPeriod();
            Timer_IdleToBusy_backup.InterruptMaskValue = Timer_IdleToBusy_STATUS_MASK;
            #if (Timer_IdleToBusy_UsingHWCaptureCounter)
                Timer_IdleToBusy_backup.TimerCaptureCounter = Timer_IdleToBusy_ReadCaptureCount();
            #endif /* Backup the UDB non-rentention register capture counter for CY_UDB_V0 */
        #endif /* Backup the UDB non-rentention registers for CY_UDB_V0 */

        #if (CY_UDB_V1)
            Timer_IdleToBusy_backup.TimerUdb = Timer_IdleToBusy_ReadCounter();
            Timer_IdleToBusy_backup.InterruptMaskValue = Timer_IdleToBusy_STATUS_MASK;
            #if (Timer_IdleToBusy_UsingHWCaptureCounter)
                Timer_IdleToBusy_backup.TimerCaptureCounter = Timer_IdleToBusy_ReadCaptureCount();
            #endif /* Back Up capture counter register  */
        #endif /* Backup non retention registers, interrupt mask and capture counter for CY_UDB_V1 */

        #if(!Timer_IdleToBusy_ControlRegRemoved)
            Timer_IdleToBusy_backup.TimerControlRegister = Timer_IdleToBusy_ReadControlRegister();
        #endif /* Backup the enable state of the Timer component */
    #endif /* Backup non retention registers in UDB implementation. All fixed function registers are retention */
}


/*******************************************************************************
* Function Name: Timer_IdleToBusy_RestoreConfig
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
*  Timer_IdleToBusy_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void Timer_IdleToBusy_RestoreConfig(void) 
{   
    #if (!Timer_IdleToBusy_UsingFixedFunction)
        /* Restore the UDB non-rentention registers for CY_UDB_V0 */
        #if (CY_UDB_V0)
            /* Interrupt State Backup for Critical Region*/
            uint8 Timer_IdleToBusy_interruptState;

            Timer_IdleToBusy_WriteCounter(Timer_IdleToBusy_backup.TimerUdb);
            Timer_IdleToBusy_WritePeriod(Timer_IdleToBusy_backup.TimerPeriod);
            /* CyEnterCriticalRegion and CyExitCriticalRegion are used to mark following region critical*/
            /* Enter Critical Region*/
            Timer_IdleToBusy_interruptState = CyEnterCriticalSection();
            /* Use the interrupt output of the status register for IRQ output */
            Timer_IdleToBusy_STATUS_AUX_CTRL |= Timer_IdleToBusy_STATUS_ACTL_INT_EN_MASK;
            /* Exit Critical Region*/
            CyExitCriticalSection(Timer_IdleToBusy_interruptState);
            Timer_IdleToBusy_STATUS_MASK =Timer_IdleToBusy_backup.InterruptMaskValue;
            #if (Timer_IdleToBusy_UsingHWCaptureCounter)
                Timer_IdleToBusy_SetCaptureCount(Timer_IdleToBusy_backup.TimerCaptureCounter);
            #endif /* Restore the UDB non-rentention register capture counter for CY_UDB_V0 */
        #endif /* Restore the UDB non-rentention registers for CY_UDB_V0 */

        #if (CY_UDB_V1)
            Timer_IdleToBusy_WriteCounter(Timer_IdleToBusy_backup.TimerUdb);
            Timer_IdleToBusy_STATUS_MASK =Timer_IdleToBusy_backup.InterruptMaskValue;
            #if (Timer_IdleToBusy_UsingHWCaptureCounter)
                Timer_IdleToBusy_SetCaptureCount(Timer_IdleToBusy_backup.TimerCaptureCounter);
            #endif /* Restore Capture counter register*/
        #endif /* Restore up non retention registers, interrupt mask and capture counter for CY_UDB_V1 */

        #if(!Timer_IdleToBusy_ControlRegRemoved)
            Timer_IdleToBusy_WriteControlRegister(Timer_IdleToBusy_backup.TimerControlRegister);
        #endif /* Restore the enable state of the Timer component */
    #endif /* Restore non retention registers in the UDB implementation only */
}


/*******************************************************************************
* Function Name: Timer_IdleToBusy_Sleep
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
*  Timer_IdleToBusy_backup.TimerEnableState:  Is modified depending on the
*  enable state of the block before entering sleep mode.
*
*******************************************************************************/
void Timer_IdleToBusy_Sleep(void) 
{
    #if(!Timer_IdleToBusy_ControlRegRemoved)
        /* Save Counter's enable state */
        if(Timer_IdleToBusy_CTRL_ENABLE == (Timer_IdleToBusy_CONTROL & Timer_IdleToBusy_CTRL_ENABLE))
        {
            /* Timer is enabled */
            Timer_IdleToBusy_backup.TimerEnableState = 1u;
        }
        else
        {
            /* Timer is disabled */
            Timer_IdleToBusy_backup.TimerEnableState = 0u;
        }
    #endif /* Back up enable state from the Timer control register */
    Timer_IdleToBusy_Stop();
    Timer_IdleToBusy_SaveConfig();
}


/*******************************************************************************
* Function Name: Timer_IdleToBusy_Wakeup
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
*  Timer_IdleToBusy_backup.enableState:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Timer_IdleToBusy_Wakeup(void) 
{
    Timer_IdleToBusy_RestoreConfig();
    #if(!Timer_IdleToBusy_ControlRegRemoved)
        if(Timer_IdleToBusy_backup.TimerEnableState == 1u)
        {     /* Enable Timer's operation */
                Timer_IdleToBusy_Enable();
        } /* Do nothing if Timer was disabled before */
    #endif /* Remove this code section if Control register is removed */
}


/* [] END OF FILE */
