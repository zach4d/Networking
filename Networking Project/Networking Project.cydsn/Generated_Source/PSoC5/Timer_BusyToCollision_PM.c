/*******************************************************************************
* File Name: Timer_BusyToCollision_PM.c
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
        /* Backup the UDB non-rentention registers for CY_UDB_V0 */
        #if (CY_UDB_V0)
            Timer_BusyToCollision_backup.TimerUdb = Timer_BusyToCollision_ReadCounter();
            Timer_BusyToCollision_backup.TimerPeriod = Timer_BusyToCollision_ReadPeriod();
            Timer_BusyToCollision_backup.InterruptMaskValue = Timer_BusyToCollision_STATUS_MASK;
            #if (Timer_BusyToCollision_UsingHWCaptureCounter)
                Timer_BusyToCollision_backup.TimerCaptureCounter = Timer_BusyToCollision_ReadCaptureCount();
            #endif /* Backup the UDB non-rentention register capture counter for CY_UDB_V0 */
        #endif /* Backup the UDB non-rentention registers for CY_UDB_V0 */

        #if (CY_UDB_V1)
            Timer_BusyToCollision_backup.TimerUdb = Timer_BusyToCollision_ReadCounter();
            Timer_BusyToCollision_backup.InterruptMaskValue = Timer_BusyToCollision_STATUS_MASK;
            #if (Timer_BusyToCollision_UsingHWCaptureCounter)
                Timer_BusyToCollision_backup.TimerCaptureCounter = Timer_BusyToCollision_ReadCaptureCount();
            #endif /* Back Up capture counter register  */
        #endif /* Backup non retention registers, interrupt mask and capture counter for CY_UDB_V1 */

        #if(!Timer_BusyToCollision_ControlRegRemoved)
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
        /* Restore the UDB non-rentention registers for CY_UDB_V0 */
        #if (CY_UDB_V0)
            /* Interrupt State Backup for Critical Region*/
            uint8 Timer_BusyToCollision_interruptState;

            Timer_BusyToCollision_WriteCounter(Timer_BusyToCollision_backup.TimerUdb);
            Timer_BusyToCollision_WritePeriod(Timer_BusyToCollision_backup.TimerPeriod);
            /* CyEnterCriticalRegion and CyExitCriticalRegion are used to mark following region critical*/
            /* Enter Critical Region*/
            Timer_BusyToCollision_interruptState = CyEnterCriticalSection();
            /* Use the interrupt output of the status register for IRQ output */
            Timer_BusyToCollision_STATUS_AUX_CTRL |= Timer_BusyToCollision_STATUS_ACTL_INT_EN_MASK;
            /* Exit Critical Region*/
            CyExitCriticalSection(Timer_BusyToCollision_interruptState);
            Timer_BusyToCollision_STATUS_MASK =Timer_BusyToCollision_backup.InterruptMaskValue;
            #if (Timer_BusyToCollision_UsingHWCaptureCounter)
                Timer_BusyToCollision_SetCaptureCount(Timer_BusyToCollision_backup.TimerCaptureCounter);
            #endif /* Restore the UDB non-rentention register capture counter for CY_UDB_V0 */
        #endif /* Restore the UDB non-rentention registers for CY_UDB_V0 */

        #if (CY_UDB_V1)
            Timer_BusyToCollision_WriteCounter(Timer_BusyToCollision_backup.TimerUdb);
            Timer_BusyToCollision_STATUS_MASK =Timer_BusyToCollision_backup.InterruptMaskValue;
            #if (Timer_BusyToCollision_UsingHWCaptureCounter)
                Timer_BusyToCollision_SetCaptureCount(Timer_BusyToCollision_backup.TimerCaptureCounter);
            #endif /* Restore Capture counter register*/
        #endif /* Restore up non retention registers, interrupt mask and capture counter for CY_UDB_V1 */

        #if(!Timer_BusyToCollision_ControlRegRemoved)
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
    #if(!Timer_BusyToCollision_ControlRegRemoved)
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
    #if(!Timer_BusyToCollision_ControlRegRemoved)
        if(Timer_BusyToCollision_backup.TimerEnableState == 1u)
        {     /* Enable Timer's operation */
                Timer_BusyToCollision_Enable();
        } /* Do nothing if Timer was disabled before */
    #endif /* Remove this code section if Control register is removed */
}


/* [] END OF FILE */
