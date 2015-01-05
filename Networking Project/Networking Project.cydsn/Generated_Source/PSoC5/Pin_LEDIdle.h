/*******************************************************************************
* File Name: Pin_LEDIdle.h  
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

#if !defined(CY_PINS_Pin_LEDIdle_H) /* Pins Pin_LEDIdle_H */
#define CY_PINS_Pin_LEDIdle_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Pin_LEDIdle_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_0 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Pin_LEDIdle__PORT == 15 && ((Pin_LEDIdle__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    Pin_LEDIdle_Write(uint8 value) ;
void    Pin_LEDIdle_SetDriveMode(uint8 mode) ;
uint8   Pin_LEDIdle_ReadDataReg(void) ;
uint8   Pin_LEDIdle_Read(void) ;
uint8   Pin_LEDIdle_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Pin_LEDIdle_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Pin_LEDIdle_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Pin_LEDIdle_DM_RES_UP          PIN_DM_RES_UP
#define Pin_LEDIdle_DM_RES_DWN         PIN_DM_RES_DWN
#define Pin_LEDIdle_DM_OD_LO           PIN_DM_OD_LO
#define Pin_LEDIdle_DM_OD_HI           PIN_DM_OD_HI
#define Pin_LEDIdle_DM_STRONG          PIN_DM_STRONG
#define Pin_LEDIdle_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Pin_LEDIdle_MASK               Pin_LEDIdle__MASK
#define Pin_LEDIdle_SHIFT              Pin_LEDIdle__SHIFT
#define Pin_LEDIdle_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Pin_LEDIdle_PS                     (* (reg8 *) Pin_LEDIdle__PS)
/* Data Register */
#define Pin_LEDIdle_DR                     (* (reg8 *) Pin_LEDIdle__DR)
/* Port Number */
#define Pin_LEDIdle_PRT_NUM                (* (reg8 *) Pin_LEDIdle__PRT) 
/* Connect to Analog Globals */                                                  
#define Pin_LEDIdle_AG                     (* (reg8 *) Pin_LEDIdle__AG)                       
/* Analog MUX bux enable */
#define Pin_LEDIdle_AMUX                   (* (reg8 *) Pin_LEDIdle__AMUX) 
/* Bidirectional Enable */                                                        
#define Pin_LEDIdle_BIE                    (* (reg8 *) Pin_LEDIdle__BIE)
/* Bit-mask for Aliased Register Access */
#define Pin_LEDIdle_BIT_MASK               (* (reg8 *) Pin_LEDIdle__BIT_MASK)
/* Bypass Enable */
#define Pin_LEDIdle_BYP                    (* (reg8 *) Pin_LEDIdle__BYP)
/* Port wide control signals */                                                   
#define Pin_LEDIdle_CTL                    (* (reg8 *) Pin_LEDIdle__CTL)
/* Drive Modes */
#define Pin_LEDIdle_DM0                    (* (reg8 *) Pin_LEDIdle__DM0) 
#define Pin_LEDIdle_DM1                    (* (reg8 *) Pin_LEDIdle__DM1)
#define Pin_LEDIdle_DM2                    (* (reg8 *) Pin_LEDIdle__DM2) 
/* Input Buffer Disable Override */
#define Pin_LEDIdle_INP_DIS                (* (reg8 *) Pin_LEDIdle__INP_DIS)
/* LCD Common or Segment Drive */
#define Pin_LEDIdle_LCD_COM_SEG            (* (reg8 *) Pin_LEDIdle__LCD_COM_SEG)
/* Enable Segment LCD */
#define Pin_LEDIdle_LCD_EN                 (* (reg8 *) Pin_LEDIdle__LCD_EN)
/* Slew Rate Control */
#define Pin_LEDIdle_SLW                    (* (reg8 *) Pin_LEDIdle__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Pin_LEDIdle_PRTDSI__CAPS_SEL       (* (reg8 *) Pin_LEDIdle__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Pin_LEDIdle_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Pin_LEDIdle__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Pin_LEDIdle_PRTDSI__OE_SEL0        (* (reg8 *) Pin_LEDIdle__PRTDSI__OE_SEL0) 
#define Pin_LEDIdle_PRTDSI__OE_SEL1        (* (reg8 *) Pin_LEDIdle__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Pin_LEDIdle_PRTDSI__OUT_SEL0       (* (reg8 *) Pin_LEDIdle__PRTDSI__OUT_SEL0) 
#define Pin_LEDIdle_PRTDSI__OUT_SEL1       (* (reg8 *) Pin_LEDIdle__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Pin_LEDIdle_PRTDSI__SYNC_OUT       (* (reg8 *) Pin_LEDIdle__PRTDSI__SYNC_OUT) 


#if defined(Pin_LEDIdle__INTSTAT)  /* Interrupt Registers */

    #define Pin_LEDIdle_INTSTAT                (* (reg8 *) Pin_LEDIdle__INTSTAT)
    #define Pin_LEDIdle_SNAP                   (* (reg8 *) Pin_LEDIdle__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Pin_LEDIdle_H */


/* [] END OF FILE */
