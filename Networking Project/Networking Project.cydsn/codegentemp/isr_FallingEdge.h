/*******************************************************************************
* File Name: isr_FallingEdge.h
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
#if !defined(CY_ISR_isr_FallingEdge_H)
#define CY_ISR_isr_FallingEdge_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void isr_FallingEdge_Start(void);
void isr_FallingEdge_StartEx(cyisraddress address);
void isr_FallingEdge_Stop(void);

CY_ISR_PROTO(isr_FallingEdge_Interrupt);

void isr_FallingEdge_SetVector(cyisraddress address);
cyisraddress isr_FallingEdge_GetVector(void);

void isr_FallingEdge_SetPriority(uint8 priority);
uint8 isr_FallingEdge_GetPriority(void);

void isr_FallingEdge_Enable(void);
uint8 isr_FallingEdge_GetState(void);
void isr_FallingEdge_Disable(void);

void isr_FallingEdge_SetPending(void);
void isr_FallingEdge_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the isr_FallingEdge ISR. */
#define isr_FallingEdge_INTC_VECTOR            ((reg32 *) isr_FallingEdge__INTC_VECT)

/* Address of the isr_FallingEdge ISR priority. */
#define isr_FallingEdge_INTC_PRIOR             ((reg8 *) isr_FallingEdge__INTC_PRIOR_REG)

/* Priority of the isr_FallingEdge interrupt. */
#define isr_FallingEdge_INTC_PRIOR_NUMBER      isr_FallingEdge__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable isr_FallingEdge interrupt. */
#define isr_FallingEdge_INTC_SET_EN            ((reg32 *) isr_FallingEdge__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the isr_FallingEdge interrupt. */
#define isr_FallingEdge_INTC_CLR_EN            ((reg32 *) isr_FallingEdge__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the isr_FallingEdge interrupt state to pending. */
#define isr_FallingEdge_INTC_SET_PD            ((reg32 *) isr_FallingEdge__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the isr_FallingEdge interrupt. */
#define isr_FallingEdge_INTC_CLR_PD            ((reg32 *) isr_FallingEdge__INTC_CLR_PD_REG)


#endif /* CY_ISR_isr_FallingEdge_H */


/* [] END OF FILE */
