/*******************************************************************************
* File Name: isr_BusyToCollision.h
* Version 1.70
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(CY_ISR_isr_BusyToCollision_H)
#define CY_ISR_isr_BusyToCollision_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void isr_BusyToCollision_Start(void);
void isr_BusyToCollision_StartEx(cyisraddress address);
void isr_BusyToCollision_Stop(void);

CY_ISR_PROTO(isr_BusyToCollision_Interrupt);

void isr_BusyToCollision_SetVector(cyisraddress address);
cyisraddress isr_BusyToCollision_GetVector(void);

void isr_BusyToCollision_SetPriority(uint8 priority);
uint8 isr_BusyToCollision_GetPriority(void);

void isr_BusyToCollision_Enable(void);
uint8 isr_BusyToCollision_GetState(void);
void isr_BusyToCollision_Disable(void);

void isr_BusyToCollision_SetPending(void);
void isr_BusyToCollision_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the isr_BusyToCollision ISR. */
#define isr_BusyToCollision_INTC_VECTOR            ((reg32 *) isr_BusyToCollision__INTC_VECT)

/* Address of the isr_BusyToCollision ISR priority. */
#define isr_BusyToCollision_INTC_PRIOR             ((reg8 *) isr_BusyToCollision__INTC_PRIOR_REG)

/* Priority of the isr_BusyToCollision interrupt. */
#define isr_BusyToCollision_INTC_PRIOR_NUMBER      isr_BusyToCollision__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable isr_BusyToCollision interrupt. */
#define isr_BusyToCollision_INTC_SET_EN            ((reg32 *) isr_BusyToCollision__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the isr_BusyToCollision interrupt. */
#define isr_BusyToCollision_INTC_CLR_EN            ((reg32 *) isr_BusyToCollision__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the isr_BusyToCollision interrupt state to pending. */
#define isr_BusyToCollision_INTC_SET_PD            ((reg32 *) isr_BusyToCollision__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the isr_BusyToCollision interrupt. */
#define isr_BusyToCollision_INTC_CLR_PD            ((reg32 *) isr_BusyToCollision__INTC_CLR_PD_REG)


#endif /* CY_ISR_isr_BusyToCollision_H */


/* [] END OF FILE */
