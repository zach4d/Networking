/*******************************************************************************
* File Name: Recieve_Input.h  
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

#if !defined(CY_PINS_Recieve_Input_H) /* Pins Recieve_Input_H */
#define CY_PINS_Recieve_Input_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Recieve_Input_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_0 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Recieve_Input__PORT == 15 && ((Recieve_Input__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    Recieve_Input_Write(uint8 value) ;
void    Recieve_Input_SetDriveMode(uint8 mode) ;
uint8   Recieve_Input_ReadDataReg(void) ;
uint8   Recieve_Input_Read(void) ;
uint8   Recieve_Input_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Recieve_Input_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Recieve_Input_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Recieve_Input_DM_RES_UP          PIN_DM_RES_UP
#define Recieve_Input_DM_RES_DWN         PIN_DM_RES_DWN
#define Recieve_Input_DM_OD_LO           PIN_DM_OD_LO
#define Recieve_Input_DM_OD_HI           PIN_DM_OD_HI
#define Recieve_Input_DM_STRONG          PIN_DM_STRONG
#define Recieve_Input_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Recieve_Input_MASK               Recieve_Input__MASK
#define Recieve_Input_SHIFT              Recieve_Input__SHIFT
#define Recieve_Input_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Recieve_Input_PS                     (* (reg8 *) Recieve_Input__PS)
/* Data Register */
#define Recieve_Input_DR                     (* (reg8 *) Recieve_Input__DR)
/* Port Number */
#define Recieve_Input_PRT_NUM                (* (reg8 *) Recieve_Input__PRT) 
/* Connect to Analog Globals */                                                  
#define Recieve_Input_AG                     (* (reg8 *) Recieve_Input__AG)                       
/* Analog MUX bux enable */
#define Recieve_Input_AMUX                   (* (reg8 *) Recieve_Input__AMUX) 
/* Bidirectional Enable */                                                        
#define Recieve_Input_BIE                    (* (reg8 *) Recieve_Input__BIE)
/* Bit-mask for Aliased Register Access */
#define Recieve_Input_BIT_MASK               (* (reg8 *) Recieve_Input__BIT_MASK)
/* Bypass Enable */
#define Recieve_Input_BYP                    (* (reg8 *) Recieve_Input__BYP)
/* Port wide control signals */                                                   
#define Recieve_Input_CTL                    (* (reg8 *) Recieve_Input__CTL)
/* Drive Modes */
#define Recieve_Input_DM0                    (* (reg8 *) Recieve_Input__DM0) 
#define Recieve_Input_DM1                    (* (reg8 *) Recieve_Input__DM1)
#define Recieve_Input_DM2                    (* (reg8 *) Recieve_Input__DM2) 
/* Input Buffer Disable Override */
#define Recieve_Input_INP_DIS                (* (reg8 *) Recieve_Input__INP_DIS)
/* LCD Common or Segment Drive */
#define Recieve_Input_LCD_COM_SEG            (* (reg8 *) Recieve_Input__LCD_COM_SEG)
/* Enable Segment LCD */
#define Recieve_Input_LCD_EN                 (* (reg8 *) Recieve_Input__LCD_EN)
/* Slew Rate Control */
#define Recieve_Input_SLW                    (* (reg8 *) Recieve_Input__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Recieve_Input_PRTDSI__CAPS_SEL       (* (reg8 *) Recieve_Input__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Recieve_Input_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Recieve_Input__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Recieve_Input_PRTDSI__OE_SEL0        (* (reg8 *) Recieve_Input__PRTDSI__OE_SEL0) 
#define Recieve_Input_PRTDSI__OE_SEL1        (* (reg8 *) Recieve_Input__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Recieve_Input_PRTDSI__OUT_SEL0       (* (reg8 *) Recieve_Input__PRTDSI__OUT_SEL0) 
#define Recieve_Input_PRTDSI__OUT_SEL1       (* (reg8 *) Recieve_Input__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Recieve_Input_PRTDSI__SYNC_OUT       (* (reg8 *) Recieve_Input__PRTDSI__SYNC_OUT) 


#if defined(Recieve_Input__INTSTAT)  /* Interrupt Registers */

    #define Recieve_Input_INTSTAT                (* (reg8 *) Recieve_Input__INTSTAT)
    #define Recieve_Input_SNAP                   (* (reg8 *) Recieve_Input__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Recieve_Input_H */


/* [] END OF FILE */
