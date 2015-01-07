/*******************************************************************************
* File Name: Transmit_Output.h  
* Version 2.0
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Transmit_Output_H) /* Pins Transmit_Output_H */
#define CY_PINS_Transmit_Output_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Transmit_Output_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_0 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Transmit_Output__PORT == 15 && ((Transmit_Output__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    Transmit_Output_Write(uint8 value) ;
void    Transmit_Output_SetDriveMode(uint8 mode) ;
uint8   Transmit_Output_ReadDataReg(void) ;
uint8   Transmit_Output_Read(void) ;
uint8   Transmit_Output_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Transmit_Output_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Transmit_Output_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Transmit_Output_DM_RES_UP          PIN_DM_RES_UP
#define Transmit_Output_DM_RES_DWN         PIN_DM_RES_DWN
#define Transmit_Output_DM_OD_LO           PIN_DM_OD_LO
#define Transmit_Output_DM_OD_HI           PIN_DM_OD_HI
#define Transmit_Output_DM_STRONG          PIN_DM_STRONG
#define Transmit_Output_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Transmit_Output_MASK               Transmit_Output__MASK
#define Transmit_Output_SHIFT              Transmit_Output__SHIFT
#define Transmit_Output_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Transmit_Output_PS                     (* (reg8 *) Transmit_Output__PS)
/* Data Register */
#define Transmit_Output_DR                     (* (reg8 *) Transmit_Output__DR)
/* Port Number */
#define Transmit_Output_PRT_NUM                (* (reg8 *) Transmit_Output__PRT) 
/* Connect to Analog Globals */                                                  
#define Transmit_Output_AG                     (* (reg8 *) Transmit_Output__AG)                       
/* Analog MUX bux enable */
#define Transmit_Output_AMUX                   (* (reg8 *) Transmit_Output__AMUX) 
/* Bidirectional Enable */                                                        
#define Transmit_Output_BIE                    (* (reg8 *) Transmit_Output__BIE)
/* Bit-mask for Aliased Register Access */
#define Transmit_Output_BIT_MASK               (* (reg8 *) Transmit_Output__BIT_MASK)
/* Bypass Enable */
#define Transmit_Output_BYP                    (* (reg8 *) Transmit_Output__BYP)
/* Port wide control signals */                                                   
#define Transmit_Output_CTL                    (* (reg8 *) Transmit_Output__CTL)
/* Drive Modes */
#define Transmit_Output_DM0                    (* (reg8 *) Transmit_Output__DM0) 
#define Transmit_Output_DM1                    (* (reg8 *) Transmit_Output__DM1)
#define Transmit_Output_DM2                    (* (reg8 *) Transmit_Output__DM2) 
/* Input Buffer Disable Override */
#define Transmit_Output_INP_DIS                (* (reg8 *) Transmit_Output__INP_DIS)
/* LCD Common or Segment Drive */
#define Transmit_Output_LCD_COM_SEG            (* (reg8 *) Transmit_Output__LCD_COM_SEG)
/* Enable Segment LCD */
#define Transmit_Output_LCD_EN                 (* (reg8 *) Transmit_Output__LCD_EN)
/* Slew Rate Control */
#define Transmit_Output_SLW                    (* (reg8 *) Transmit_Output__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Transmit_Output_PRTDSI__CAPS_SEL       (* (reg8 *) Transmit_Output__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Transmit_Output_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Transmit_Output__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Transmit_Output_PRTDSI__OE_SEL0        (* (reg8 *) Transmit_Output__PRTDSI__OE_SEL0) 
#define Transmit_Output_PRTDSI__OE_SEL1        (* (reg8 *) Transmit_Output__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Transmit_Output_PRTDSI__OUT_SEL0       (* (reg8 *) Transmit_Output__PRTDSI__OUT_SEL0) 
#define Transmit_Output_PRTDSI__OUT_SEL1       (* (reg8 *) Transmit_Output__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Transmit_Output_PRTDSI__SYNC_OUT       (* (reg8 *) Transmit_Output__PRTDSI__SYNC_OUT) 


#if defined(Transmit_Output__INTSTAT)  /* Interrupt Registers */

    #define Transmit_Output_INTSTAT                (* (reg8 *) Transmit_Output__INTSTAT)
    #define Transmit_Output_SNAP                   (* (reg8 *) Transmit_Output__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Transmit_Output_H */


/* [] END OF FILE */
