    IF :LNOT::DEF:INCLUDED_CYFITTERRV_INC
INCLUDED_CYFITTERRV_INC EQU 1
    GET cydevicerv.inc
    GET cydevicerv_trm.inc

; USB_arb_int
USB_arb_int__INTC_CLR_EN_REG EQU CYREG_NVIC_CLRENA0
USB_arb_int__INTC_CLR_PD_REG EQU CYREG_NVIC_CLRPEND0
USB_arb_int__INTC_MASK EQU 0x400000
USB_arb_int__INTC_NUMBER EQU 22
USB_arb_int__INTC_PRIOR_NUM EQU 7
USB_arb_int__INTC_PRIOR_REG EQU CYREG_NVIC_PRI_22
USB_arb_int__INTC_SET_EN_REG EQU CYREG_NVIC_SETENA0
USB_arb_int__INTC_SET_PD_REG EQU CYREG_NVIC_SETPEND0

; USB_bus_reset
USB_bus_reset__INTC_CLR_EN_REG EQU CYREG_NVIC_CLRENA0
USB_bus_reset__INTC_CLR_PD_REG EQU CYREG_NVIC_CLRPEND0
USB_bus_reset__INTC_MASK EQU 0x800000
USB_bus_reset__INTC_NUMBER EQU 23
USB_bus_reset__INTC_PRIOR_NUM EQU 7
USB_bus_reset__INTC_PRIOR_REG EQU CYREG_NVIC_PRI_23
USB_bus_reset__INTC_SET_EN_REG EQU CYREG_NVIC_SETENA0
USB_bus_reset__INTC_SET_PD_REG EQU CYREG_NVIC_SETPEND0

; USB_Dm
USB_Dm__0__MASK EQU 0x80
USB_Dm__0__PC EQU CYREG_IO_PC_PRT15_7_6_PC1
USB_Dm__0__PORT EQU 15
USB_Dm__0__SHIFT EQU 7
USB_Dm__AG EQU CYREG_PRT15_AG
USB_Dm__AMUX EQU CYREG_PRT15_AMUX
USB_Dm__BIE EQU CYREG_PRT15_BIE
USB_Dm__BIT_MASK EQU CYREG_PRT15_BIT_MASK
USB_Dm__BYP EQU CYREG_PRT15_BYP
USB_Dm__CTL EQU CYREG_PRT15_CTL
USB_Dm__DM0 EQU CYREG_PRT15_DM0
USB_Dm__DM1 EQU CYREG_PRT15_DM1
USB_Dm__DM2 EQU CYREG_PRT15_DM2
USB_Dm__DR EQU CYREG_PRT15_DR
USB_Dm__INP_DIS EQU CYREG_PRT15_INP_DIS
USB_Dm__LCD_COM_SEG EQU CYREG_PRT15_LCD_COM_SEG
USB_Dm__LCD_EN EQU CYREG_PRT15_LCD_EN
USB_Dm__MASK EQU 0x80
USB_Dm__PORT EQU 15
USB_Dm__PRT EQU CYREG_PRT15_PRT
USB_Dm__PRTDSI__CAPS_SEL EQU CYREG_PRT15_CAPS_SEL
USB_Dm__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT15_DBL_SYNC_IN
USB_Dm__PRTDSI__OE_SEL0 EQU CYREG_PRT15_OE_SEL0
USB_Dm__PRTDSI__OE_SEL1 EQU CYREG_PRT15_OE_SEL1
USB_Dm__PRTDSI__OUT_SEL0 EQU CYREG_PRT15_OUT_SEL0
USB_Dm__PRTDSI__OUT_SEL1 EQU CYREG_PRT15_OUT_SEL1
USB_Dm__PRTDSI__SYNC_OUT EQU CYREG_PRT15_SYNC_OUT
USB_Dm__PS EQU CYREG_PRT15_PS
USB_Dm__SHIFT EQU 7
USB_Dm__SLW EQU CYREG_PRT15_SLW

; USB_Dp
USB_Dp__0__MASK EQU 0x40
USB_Dp__0__PC EQU CYREG_IO_PC_PRT15_7_6_PC0
USB_Dp__0__PORT EQU 15
USB_Dp__0__SHIFT EQU 6
USB_Dp__AG EQU CYREG_PRT15_AG
USB_Dp__AMUX EQU CYREG_PRT15_AMUX
USB_Dp__BIE EQU CYREG_PRT15_BIE
USB_Dp__BIT_MASK EQU CYREG_PRT15_BIT_MASK
USB_Dp__BYP EQU CYREG_PRT15_BYP
USB_Dp__CTL EQU CYREG_PRT15_CTL
USB_Dp__DM0 EQU CYREG_PRT15_DM0
USB_Dp__DM1 EQU CYREG_PRT15_DM1
USB_Dp__DM2 EQU CYREG_PRT15_DM2
USB_Dp__DR EQU CYREG_PRT15_DR
USB_Dp__INP_DIS EQU CYREG_PRT15_INP_DIS
USB_Dp__INTSTAT EQU CYREG_PICU15_INTSTAT
USB_Dp__LCD_COM_SEG EQU CYREG_PRT15_LCD_COM_SEG
USB_Dp__LCD_EN EQU CYREG_PRT15_LCD_EN
USB_Dp__MASK EQU 0x40
USB_Dp__PORT EQU 15
USB_Dp__PRT EQU CYREG_PRT15_PRT
USB_Dp__PRTDSI__CAPS_SEL EQU CYREG_PRT15_CAPS_SEL
USB_Dp__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT15_DBL_SYNC_IN
USB_Dp__PRTDSI__OE_SEL0 EQU CYREG_PRT15_OE_SEL0
USB_Dp__PRTDSI__OE_SEL1 EQU CYREG_PRT15_OE_SEL1
USB_Dp__PRTDSI__OUT_SEL0 EQU CYREG_PRT15_OUT_SEL0
USB_Dp__PRTDSI__OUT_SEL1 EQU CYREG_PRT15_OUT_SEL1
USB_Dp__PRTDSI__SYNC_OUT EQU CYREG_PRT15_SYNC_OUT
USB_Dp__PS EQU CYREG_PRT15_PS
USB_Dp__SHIFT EQU 6
USB_Dp__SLW EQU CYREG_PRT15_SLW
USB_Dp__SNAP EQU CYREG_PICU_15_SNAP_15

; USB_dp_int
USB_dp_int__INTC_CLR_EN_REG EQU CYREG_NVIC_CLRENA0
USB_dp_int__INTC_CLR_PD_REG EQU CYREG_NVIC_CLRPEND0
USB_dp_int__INTC_MASK EQU 0x1000
USB_dp_int__INTC_NUMBER EQU 12
USB_dp_int__INTC_PRIOR_NUM EQU 7
USB_dp_int__INTC_PRIOR_REG EQU CYREG_NVIC_PRI_12
USB_dp_int__INTC_SET_EN_REG EQU CYREG_NVIC_SETENA0
USB_dp_int__INTC_SET_PD_REG EQU CYREG_NVIC_SETPEND0

; USB_ep_0
USB_ep_0__INTC_CLR_EN_REG EQU CYREG_NVIC_CLRENA0
USB_ep_0__INTC_CLR_PD_REG EQU CYREG_NVIC_CLRPEND0
USB_ep_0__INTC_MASK EQU 0x1000000
USB_ep_0__INTC_NUMBER EQU 24
USB_ep_0__INTC_PRIOR_NUM EQU 7
USB_ep_0__INTC_PRIOR_REG EQU CYREG_NVIC_PRI_24
USB_ep_0__INTC_SET_EN_REG EQU CYREG_NVIC_SETENA0
USB_ep_0__INTC_SET_PD_REG EQU CYREG_NVIC_SETPEND0

; USB_ep_1
USB_ep_1__INTC_CLR_EN_REG EQU CYREG_NVIC_CLRENA0
USB_ep_1__INTC_CLR_PD_REG EQU CYREG_NVIC_CLRPEND0
USB_ep_1__INTC_MASK EQU 0x01
USB_ep_1__INTC_NUMBER EQU 0
USB_ep_1__INTC_PRIOR_NUM EQU 7
USB_ep_1__INTC_PRIOR_REG EQU CYREG_NVIC_PRI_0
USB_ep_1__INTC_SET_EN_REG EQU CYREG_NVIC_SETENA0
USB_ep_1__INTC_SET_PD_REG EQU CYREG_NVIC_SETPEND0

; USB_ep_2
USB_ep_2__INTC_CLR_EN_REG EQU CYREG_NVIC_CLRENA0
USB_ep_2__INTC_CLR_PD_REG EQU CYREG_NVIC_CLRPEND0
USB_ep_2__INTC_MASK EQU 0x02
USB_ep_2__INTC_NUMBER EQU 1
USB_ep_2__INTC_PRIOR_NUM EQU 7
USB_ep_2__INTC_PRIOR_REG EQU CYREG_NVIC_PRI_1
USB_ep_2__INTC_SET_EN_REG EQU CYREG_NVIC_SETENA0
USB_ep_2__INTC_SET_PD_REG EQU CYREG_NVIC_SETPEND0

; USB_ep_3
USB_ep_3__INTC_CLR_EN_REG EQU CYREG_NVIC_CLRENA0
USB_ep_3__INTC_CLR_PD_REG EQU CYREG_NVIC_CLRPEND0
USB_ep_3__INTC_MASK EQU 0x04
USB_ep_3__INTC_NUMBER EQU 2
USB_ep_3__INTC_PRIOR_NUM EQU 7
USB_ep_3__INTC_PRIOR_REG EQU CYREG_NVIC_PRI_2
USB_ep_3__INTC_SET_EN_REG EQU CYREG_NVIC_SETENA0
USB_ep_3__INTC_SET_PD_REG EQU CYREG_NVIC_SETPEND0

; USB_ord_int
USB_ord_int__INTC_CLR_EN_REG EQU CYREG_NVIC_CLRENA0
USB_ord_int__INTC_CLR_PD_REG EQU CYREG_NVIC_CLRPEND0
USB_ord_int__INTC_MASK EQU 0x2000000
USB_ord_int__INTC_NUMBER EQU 25
USB_ord_int__INTC_PRIOR_NUM EQU 7
USB_ord_int__INTC_PRIOR_REG EQU CYREG_NVIC_PRI_25
USB_ord_int__INTC_SET_EN_REG EQU CYREG_NVIC_SETENA0
USB_ord_int__INTC_SET_PD_REG EQU CYREG_NVIC_SETPEND0

; USB_sof_int
USB_sof_int__INTC_CLR_EN_REG EQU CYREG_NVIC_CLRENA0
USB_sof_int__INTC_CLR_PD_REG EQU CYREG_NVIC_CLRPEND0
USB_sof_int__INTC_MASK EQU 0x200000
USB_sof_int__INTC_NUMBER EQU 21
USB_sof_int__INTC_PRIOR_NUM EQU 7
USB_sof_int__INTC_PRIOR_REG EQU CYREG_NVIC_PRI_21
USB_sof_int__INTC_SET_EN_REG EQU CYREG_NVIC_SETENA0
USB_sof_int__INTC_SET_PD_REG EQU CYREG_NVIC_SETPEND0

; USB_USB
USB_USB__ARB_CFG EQU CYREG_USB_ARB_CFG
USB_USB__ARB_EP1_CFG EQU CYREG_USB_ARB_EP1_CFG
USB_USB__ARB_EP1_INT_EN EQU CYREG_USB_ARB_EP1_INT_EN
USB_USB__ARB_EP1_SR EQU CYREG_USB_ARB_EP1_SR
USB_USB__ARB_EP2_CFG EQU CYREG_USB_ARB_EP2_CFG
USB_USB__ARB_EP2_INT_EN EQU CYREG_USB_ARB_EP2_INT_EN
USB_USB__ARB_EP2_SR EQU CYREG_USB_ARB_EP2_SR
USB_USB__ARB_EP3_CFG EQU CYREG_USB_ARB_EP3_CFG
USB_USB__ARB_EP3_INT_EN EQU CYREG_USB_ARB_EP3_INT_EN
USB_USB__ARB_EP3_SR EQU CYREG_USB_ARB_EP3_SR
USB_USB__ARB_EP4_CFG EQU CYREG_USB_ARB_EP4_CFG
USB_USB__ARB_EP4_INT_EN EQU CYREG_USB_ARB_EP4_INT_EN
USB_USB__ARB_EP4_SR EQU CYREG_USB_ARB_EP4_SR
USB_USB__ARB_EP5_CFG EQU CYREG_USB_ARB_EP5_CFG
USB_USB__ARB_EP5_INT_EN EQU CYREG_USB_ARB_EP5_INT_EN
USB_USB__ARB_EP5_SR EQU CYREG_USB_ARB_EP5_SR
USB_USB__ARB_EP6_CFG EQU CYREG_USB_ARB_EP6_CFG
USB_USB__ARB_EP6_INT_EN EQU CYREG_USB_ARB_EP6_INT_EN
USB_USB__ARB_EP6_SR EQU CYREG_USB_ARB_EP6_SR
USB_USB__ARB_EP7_CFG EQU CYREG_USB_ARB_EP7_CFG
USB_USB__ARB_EP7_INT_EN EQU CYREG_USB_ARB_EP7_INT_EN
USB_USB__ARB_EP7_SR EQU CYREG_USB_ARB_EP7_SR
USB_USB__ARB_EP8_CFG EQU CYREG_USB_ARB_EP8_CFG
USB_USB__ARB_EP8_INT_EN EQU CYREG_USB_ARB_EP8_INT_EN
USB_USB__ARB_EP8_SR EQU CYREG_USB_ARB_EP8_SR
USB_USB__ARB_INT_EN EQU CYREG_USB_ARB_INT_EN
USB_USB__ARB_INT_SR EQU CYREG_USB_ARB_INT_SR
USB_USB__ARB_RW1_DR EQU CYREG_USB_ARB_RW1_DR
USB_USB__ARB_RW1_RA EQU CYREG_USB_ARB_RW1_RA
USB_USB__ARB_RW1_RA_MSB EQU CYREG_USB_ARB_RW1_RA_MSB
USB_USB__ARB_RW1_WA EQU CYREG_USB_ARB_RW1_WA
USB_USB__ARB_RW1_WA_MSB EQU CYREG_USB_ARB_RW1_WA_MSB
USB_USB__ARB_RW2_DR EQU CYREG_USB_ARB_RW2_DR
USB_USB__ARB_RW2_RA EQU CYREG_USB_ARB_RW2_RA
USB_USB__ARB_RW2_RA_MSB EQU CYREG_USB_ARB_RW2_RA_MSB
USB_USB__ARB_RW2_WA EQU CYREG_USB_ARB_RW2_WA
USB_USB__ARB_RW2_WA_MSB EQU CYREG_USB_ARB_RW2_WA_MSB
USB_USB__ARB_RW3_DR EQU CYREG_USB_ARB_RW3_DR
USB_USB__ARB_RW3_RA EQU CYREG_USB_ARB_RW3_RA
USB_USB__ARB_RW3_RA_MSB EQU CYREG_USB_ARB_RW3_RA_MSB
USB_USB__ARB_RW3_WA EQU CYREG_USB_ARB_RW3_WA
USB_USB__ARB_RW3_WA_MSB EQU CYREG_USB_ARB_RW3_WA_MSB
USB_USB__ARB_RW4_DR EQU CYREG_USB_ARB_RW4_DR
USB_USB__ARB_RW4_RA EQU CYREG_USB_ARB_RW4_RA
USB_USB__ARB_RW4_RA_MSB EQU CYREG_USB_ARB_RW4_RA_MSB
USB_USB__ARB_RW4_WA EQU CYREG_USB_ARB_RW4_WA
USB_USB__ARB_RW4_WA_MSB EQU CYREG_USB_ARB_RW4_WA_MSB
USB_USB__ARB_RW5_DR EQU CYREG_USB_ARB_RW5_DR
USB_USB__ARB_RW5_RA EQU CYREG_USB_ARB_RW5_RA
USB_USB__ARB_RW5_RA_MSB EQU CYREG_USB_ARB_RW5_RA_MSB
USB_USB__ARB_RW5_WA EQU CYREG_USB_ARB_RW5_WA
USB_USB__ARB_RW5_WA_MSB EQU CYREG_USB_ARB_RW5_WA_MSB
USB_USB__ARB_RW6_DR EQU CYREG_USB_ARB_RW6_DR
USB_USB__ARB_RW6_RA EQU CYREG_USB_ARB_RW6_RA
USB_USB__ARB_RW6_RA_MSB EQU CYREG_USB_ARB_RW6_RA_MSB
USB_USB__ARB_RW6_WA EQU CYREG_USB_ARB_RW6_WA
USB_USB__ARB_RW6_WA_MSB EQU CYREG_USB_ARB_RW6_WA_MSB
USB_USB__ARB_RW7_DR EQU CYREG_USB_ARB_RW7_DR
USB_USB__ARB_RW7_RA EQU CYREG_USB_ARB_RW7_RA
USB_USB__ARB_RW7_RA_MSB EQU CYREG_USB_ARB_RW7_RA_MSB
USB_USB__ARB_RW7_WA EQU CYREG_USB_ARB_RW7_WA
USB_USB__ARB_RW7_WA_MSB EQU CYREG_USB_ARB_RW7_WA_MSB
USB_USB__ARB_RW8_DR EQU CYREG_USB_ARB_RW8_DR
USB_USB__ARB_RW8_RA EQU CYREG_USB_ARB_RW8_RA
USB_USB__ARB_RW8_RA_MSB EQU CYREG_USB_ARB_RW8_RA_MSB
USB_USB__ARB_RW8_WA EQU CYREG_USB_ARB_RW8_WA
USB_USB__ARB_RW8_WA_MSB EQU CYREG_USB_ARB_RW8_WA_MSB
USB_USB__BUF_SIZE EQU CYREG_USB_BUF_SIZE
USB_USB__BUS_RST_CNT EQU CYREG_USB_BUS_RST_CNT
USB_USB__CR0 EQU CYREG_USB_CR0
USB_USB__CR1 EQU CYREG_USB_CR1
USB_USB__CWA EQU CYREG_USB_CWA
USB_USB__CWA_MSB EQU CYREG_USB_CWA_MSB
USB_USB__DMA_THRES EQU CYREG_USB_DMA_THRES
USB_USB__DMA_THRES_MSB EQU CYREG_USB_DMA_THRES_MSB
USB_USB__DYN_RECONFIG EQU CYREG_USB_DYN_RECONFIG
USB_USB__EP_ACTIVE EQU CYREG_USB_EP_ACTIVE
USB_USB__EP_TYPE EQU CYREG_USB_EP_TYPE
USB_USB__EP0_CNT EQU CYREG_USB_EP0_CNT
USB_USB__EP0_CR EQU CYREG_USB_EP0_CR
USB_USB__EP0_DR0 EQU CYREG_USB_EP0_DR0
USB_USB__EP0_DR1 EQU CYREG_USB_EP0_DR1
USB_USB__EP0_DR2 EQU CYREG_USB_EP0_DR2
USB_USB__EP0_DR3 EQU CYREG_USB_EP0_DR3
USB_USB__EP0_DR4 EQU CYREG_USB_EP0_DR4
USB_USB__EP0_DR5 EQU CYREG_USB_EP0_DR5
USB_USB__EP0_DR6 EQU CYREG_USB_EP0_DR6
USB_USB__EP0_DR7 EQU CYREG_USB_EP0_DR7
USB_USB__MEM_DATA EQU CYREG_USB_MEM_DATA_MBASE
USB_USB__PM_ACT_CFG EQU CYREG_PM_ACT_CFG5
USB_USB__PM_ACT_MSK EQU 0x01
USB_USB__PM_STBY_CFG EQU CYREG_PM_STBY_CFG5
USB_USB__PM_STBY_MSK EQU 0x01
USB_USB__SIE_EP_INT_EN EQU CYREG_USB_SIE_EP_INT_EN
USB_USB__SIE_EP_INT_SR EQU CYREG_USB_SIE_EP_INT_SR
USB_USB__SIE_EP1_CNT0 EQU CYREG_USB_SIE_EP1_CNT0
USB_USB__SIE_EP1_CNT1 EQU CYREG_USB_SIE_EP1_CNT1
USB_USB__SIE_EP1_CR0 EQU CYREG_USB_SIE_EP1_CR0
USB_USB__SIE_EP2_CNT0 EQU CYREG_USB_SIE_EP2_CNT0
USB_USB__SIE_EP2_CNT1 EQU CYREG_USB_SIE_EP2_CNT1
USB_USB__SIE_EP2_CR0 EQU CYREG_USB_SIE_EP2_CR0
USB_USB__SIE_EP3_CNT0 EQU CYREG_USB_SIE_EP3_CNT0
USB_USB__SIE_EP3_CNT1 EQU CYREG_USB_SIE_EP3_CNT1
USB_USB__SIE_EP3_CR0 EQU CYREG_USB_SIE_EP3_CR0
USB_USB__SIE_EP4_CNT0 EQU CYREG_USB_SIE_EP4_CNT0
USB_USB__SIE_EP4_CNT1 EQU CYREG_USB_SIE_EP4_CNT1
USB_USB__SIE_EP4_CR0 EQU CYREG_USB_SIE_EP4_CR0
USB_USB__SIE_EP5_CNT0 EQU CYREG_USB_SIE_EP5_CNT0
USB_USB__SIE_EP5_CNT1 EQU CYREG_USB_SIE_EP5_CNT1
USB_USB__SIE_EP5_CR0 EQU CYREG_USB_SIE_EP5_CR0
USB_USB__SIE_EP6_CNT0 EQU CYREG_USB_SIE_EP6_CNT0
USB_USB__SIE_EP6_CNT1 EQU CYREG_USB_SIE_EP6_CNT1
USB_USB__SIE_EP6_CR0 EQU CYREG_USB_SIE_EP6_CR0
USB_USB__SIE_EP7_CNT0 EQU CYREG_USB_SIE_EP7_CNT0
USB_USB__SIE_EP7_CNT1 EQU CYREG_USB_SIE_EP7_CNT1
USB_USB__SIE_EP7_CR0 EQU CYREG_USB_SIE_EP7_CR0
USB_USB__SIE_EP8_CNT0 EQU CYREG_USB_SIE_EP8_CNT0
USB_USB__SIE_EP8_CNT1 EQU CYREG_USB_SIE_EP8_CNT1
USB_USB__SIE_EP8_CR0 EQU CYREG_USB_SIE_EP8_CR0
USB_USB__SOF0 EQU CYREG_USB_SOF0
USB_USB__SOF1 EQU CYREG_USB_SOF1
USB_USB__USB_CLK_EN EQU CYREG_USB_USB_CLK_EN
USB_USB__USBIO_CR0 EQU CYREG_USB_USBIO_CR0
USB_USB__USBIO_CR1 EQU CYREG_USB_USBIO_CR1

; Pin_LEDBusy
Pin_LEDBusy__0__MASK EQU 0x04
Pin_LEDBusy__0__PC EQU CYREG_PRT6_PC2
Pin_LEDBusy__0__PORT EQU 6
Pin_LEDBusy__0__SHIFT EQU 2
Pin_LEDBusy__AG EQU CYREG_PRT6_AG
Pin_LEDBusy__AMUX EQU CYREG_PRT6_AMUX
Pin_LEDBusy__BIE EQU CYREG_PRT6_BIE
Pin_LEDBusy__BIT_MASK EQU CYREG_PRT6_BIT_MASK
Pin_LEDBusy__BYP EQU CYREG_PRT6_BYP
Pin_LEDBusy__CTL EQU CYREG_PRT6_CTL
Pin_LEDBusy__DM0 EQU CYREG_PRT6_DM0
Pin_LEDBusy__DM1 EQU CYREG_PRT6_DM1
Pin_LEDBusy__DM2 EQU CYREG_PRT6_DM2
Pin_LEDBusy__DR EQU CYREG_PRT6_DR
Pin_LEDBusy__INP_DIS EQU CYREG_PRT6_INP_DIS
Pin_LEDBusy__LCD_COM_SEG EQU CYREG_PRT6_LCD_COM_SEG
Pin_LEDBusy__LCD_EN EQU CYREG_PRT6_LCD_EN
Pin_LEDBusy__MASK EQU 0x04
Pin_LEDBusy__PORT EQU 6
Pin_LEDBusy__PRT EQU CYREG_PRT6_PRT
Pin_LEDBusy__PRTDSI__CAPS_SEL EQU CYREG_PRT6_CAPS_SEL
Pin_LEDBusy__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT6_DBL_SYNC_IN
Pin_LEDBusy__PRTDSI__OE_SEL0 EQU CYREG_PRT6_OE_SEL0
Pin_LEDBusy__PRTDSI__OE_SEL1 EQU CYREG_PRT6_OE_SEL1
Pin_LEDBusy__PRTDSI__OUT_SEL0 EQU CYREG_PRT6_OUT_SEL0
Pin_LEDBusy__PRTDSI__OUT_SEL1 EQU CYREG_PRT6_OUT_SEL1
Pin_LEDBusy__PRTDSI__SYNC_OUT EQU CYREG_PRT6_SYNC_OUT
Pin_LEDBusy__PS EQU CYREG_PRT6_PS
Pin_LEDBusy__SHIFT EQU 2
Pin_LEDBusy__SLW EQU CYREG_PRT6_SLW

; Pin_LEDIdle
Pin_LEDIdle__0__MASK EQU 0x08
Pin_LEDIdle__0__PC EQU CYREG_PRT6_PC3
Pin_LEDIdle__0__PORT EQU 6
Pin_LEDIdle__0__SHIFT EQU 3
Pin_LEDIdle__AG EQU CYREG_PRT6_AG
Pin_LEDIdle__AMUX EQU CYREG_PRT6_AMUX
Pin_LEDIdle__BIE EQU CYREG_PRT6_BIE
Pin_LEDIdle__BIT_MASK EQU CYREG_PRT6_BIT_MASK
Pin_LEDIdle__BYP EQU CYREG_PRT6_BYP
Pin_LEDIdle__CTL EQU CYREG_PRT6_CTL
Pin_LEDIdle__DM0 EQU CYREG_PRT6_DM0
Pin_LEDIdle__DM1 EQU CYREG_PRT6_DM1
Pin_LEDIdle__DM2 EQU CYREG_PRT6_DM2
Pin_LEDIdle__DR EQU CYREG_PRT6_DR
Pin_LEDIdle__INP_DIS EQU CYREG_PRT6_INP_DIS
Pin_LEDIdle__LCD_COM_SEG EQU CYREG_PRT6_LCD_COM_SEG
Pin_LEDIdle__LCD_EN EQU CYREG_PRT6_LCD_EN
Pin_LEDIdle__MASK EQU 0x08
Pin_LEDIdle__PORT EQU 6
Pin_LEDIdle__PRT EQU CYREG_PRT6_PRT
Pin_LEDIdle__PRTDSI__CAPS_SEL EQU CYREG_PRT6_CAPS_SEL
Pin_LEDIdle__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT6_DBL_SYNC_IN
Pin_LEDIdle__PRTDSI__OE_SEL0 EQU CYREG_PRT6_OE_SEL0
Pin_LEDIdle__PRTDSI__OE_SEL1 EQU CYREG_PRT6_OE_SEL1
Pin_LEDIdle__PRTDSI__OUT_SEL0 EQU CYREG_PRT6_OUT_SEL0
Pin_LEDIdle__PRTDSI__OUT_SEL1 EQU CYREG_PRT6_OUT_SEL1
Pin_LEDIdle__PRTDSI__SYNC_OUT EQU CYREG_PRT6_SYNC_OUT
Pin_LEDIdle__PS EQU CYREG_PRT6_PS
Pin_LEDIdle__SHIFT EQU 3
Pin_LEDIdle__SLW EQU CYREG_PRT6_SLW

; timer_clock_2
timer_clock_2__CFG0 EQU CYREG_CLKDIST_DCFG0_CFG0
timer_clock_2__CFG1 EQU CYREG_CLKDIST_DCFG0_CFG1
timer_clock_2__CFG2 EQU CYREG_CLKDIST_DCFG0_CFG2
timer_clock_2__CFG2_SRC_SEL_MASK EQU 0x07
timer_clock_2__INDEX EQU 0x00
timer_clock_2__PM_ACT_CFG EQU CYREG_PM_ACT_CFG2
timer_clock_2__PM_ACT_MSK EQU 0x01
timer_clock_2__PM_STBY_CFG EQU CYREG_PM_STBY_CFG2
timer_clock_2__PM_STBY_MSK EQU 0x01

; isr_sendData
isr_sendData__INTC_CLR_EN_REG EQU CYREG_NVIC_CLRENA0
isr_sendData__INTC_CLR_PD_REG EQU CYREG_NVIC_CLRPEND0
isr_sendData__INTC_MASK EQU 0x20000
isr_sendData__INTC_NUMBER EQU 17
isr_sendData__INTC_PRIOR_NUM EQU 7
isr_sendData__INTC_PRIOR_REG EQU CYREG_NVIC_PRI_17
isr_sendData__INTC_SET_EN_REG EQU CYREG_NVIC_SETENA0
isr_sendData__INTC_SET_PD_REG EQU CYREG_NVIC_SETPEND0

; Recieve_Input
Recieve_Input__0__MASK EQU 0x01
Recieve_Input__0__PC EQU CYREG_PRT6_PC0
Recieve_Input__0__PORT EQU 6
Recieve_Input__0__SHIFT EQU 0
Recieve_Input__AG EQU CYREG_PRT6_AG
Recieve_Input__AMUX EQU CYREG_PRT6_AMUX
Recieve_Input__BIE EQU CYREG_PRT6_BIE
Recieve_Input__BIT_MASK EQU CYREG_PRT6_BIT_MASK
Recieve_Input__BYP EQU CYREG_PRT6_BYP
Recieve_Input__CTL EQU CYREG_PRT6_CTL
Recieve_Input__DM0 EQU CYREG_PRT6_DM0
Recieve_Input__DM1 EQU CYREG_PRT6_DM1
Recieve_Input__DM2 EQU CYREG_PRT6_DM2
Recieve_Input__DR EQU CYREG_PRT6_DR
Recieve_Input__INP_DIS EQU CYREG_PRT6_INP_DIS
Recieve_Input__LCD_COM_SEG EQU CYREG_PRT6_LCD_COM_SEG
Recieve_Input__LCD_EN EQU CYREG_PRT6_LCD_EN
Recieve_Input__MASK EQU 0x01
Recieve_Input__PORT EQU 6
Recieve_Input__PRT EQU CYREG_PRT6_PRT
Recieve_Input__PRTDSI__CAPS_SEL EQU CYREG_PRT6_CAPS_SEL
Recieve_Input__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT6_DBL_SYNC_IN
Recieve_Input__PRTDSI__OE_SEL0 EQU CYREG_PRT6_OE_SEL0
Recieve_Input__PRTDSI__OE_SEL1 EQU CYREG_PRT6_OE_SEL1
Recieve_Input__PRTDSI__OUT_SEL0 EQU CYREG_PRT6_OUT_SEL0
Recieve_Input__PRTDSI__OUT_SEL1 EQU CYREG_PRT6_OUT_SEL1
Recieve_Input__PRTDSI__SYNC_OUT EQU CYREG_PRT6_SYNC_OUT
Recieve_Input__PS EQU CYREG_PRT6_PS
Recieve_Input__SHIFT EQU 0
Recieve_Input__SLW EQU CYREG_PRT6_SLW

; Transm_Output
Transm_Output__0__MASK EQU 0x40
Transm_Output__0__PC EQU CYREG_PRT6_PC6
Transm_Output__0__PORT EQU 6
Transm_Output__0__SHIFT EQU 6
Transm_Output__AG EQU CYREG_PRT6_AG
Transm_Output__AMUX EQU CYREG_PRT6_AMUX
Transm_Output__BIE EQU CYREG_PRT6_BIE
Transm_Output__BIT_MASK EQU CYREG_PRT6_BIT_MASK
Transm_Output__BYP EQU CYREG_PRT6_BYP
Transm_Output__CTL EQU CYREG_PRT6_CTL
Transm_Output__DM0 EQU CYREG_PRT6_DM0
Transm_Output__DM1 EQU CYREG_PRT6_DM1
Transm_Output__DM2 EQU CYREG_PRT6_DM2
Transm_Output__DR EQU CYREG_PRT6_DR
Transm_Output__INP_DIS EQU CYREG_PRT6_INP_DIS
Transm_Output__LCD_COM_SEG EQU CYREG_PRT6_LCD_COM_SEG
Transm_Output__LCD_EN EQU CYREG_PRT6_LCD_EN
Transm_Output__MASK EQU 0x40
Transm_Output__PORT EQU 6
Transm_Output__PRT EQU CYREG_PRT6_PRT
Transm_Output__PRTDSI__CAPS_SEL EQU CYREG_PRT6_CAPS_SEL
Transm_Output__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT6_DBL_SYNC_IN
Transm_Output__PRTDSI__OE_SEL0 EQU CYREG_PRT6_OE_SEL0
Transm_Output__PRTDSI__OE_SEL1 EQU CYREG_PRT6_OE_SEL1
Transm_Output__PRTDSI__OUT_SEL0 EQU CYREG_PRT6_OUT_SEL0
Transm_Output__PRTDSI__OUT_SEL1 EQU CYREG_PRT6_OUT_SEL1
Transm_Output__PRTDSI__SYNC_OUT EQU CYREG_PRT6_SYNC_OUT
Transm_Output__PS EQU CYREG_PRT6_PS
Transm_Output__SHIFT EQU 6
Transm_Output__SLW EQU CYREG_PRT6_SLW

; Timer_sendData_TimerHW
Timer_sendData_TimerHW__CAP0 EQU CYREG_TMR0_CAP0
Timer_sendData_TimerHW__CAP1 EQU CYREG_TMR0_CAP1
Timer_sendData_TimerHW__CFG0 EQU CYREG_TMR0_CFG0
Timer_sendData_TimerHW__CFG1 EQU CYREG_TMR0_CFG1
Timer_sendData_TimerHW__CFG2 EQU CYREG_TMR0_CFG2
Timer_sendData_TimerHW__CNT_CMP0 EQU CYREG_TMR0_CNT_CMP0
Timer_sendData_TimerHW__CNT_CMP1 EQU CYREG_TMR0_CNT_CMP1
Timer_sendData_TimerHW__PER0 EQU CYREG_TMR0_PER0
Timer_sendData_TimerHW__PER1 EQU CYREG_TMR0_PER1
Timer_sendData_TimerHW__PM_ACT_CFG EQU CYREG_PM_ACT_CFG3
Timer_sendData_TimerHW__PM_ACT_MSK EQU 0x01
Timer_sendData_TimerHW__PM_STBY_CFG EQU CYREG_PM_STBY_CFG3
Timer_sendData_TimerHW__PM_STBY_MSK EQU 0x01
Timer_sendData_TimerHW__RT0 EQU CYREG_TMR0_RT0
Timer_sendData_TimerHW__RT1 EQU CYREG_TMR0_RT1
Timer_sendData_TimerHW__SR0 EQU CYREG_TMR0_SR0

; isr_BusyToIdle
isr_BusyToIdle__INTC_CLR_EN_REG EQU CYREG_NVIC_CLRENA0
isr_BusyToIdle__INTC_CLR_PD_REG EQU CYREG_NVIC_CLRPEND0
isr_BusyToIdle__INTC_MASK EQU 0x10
isr_BusyToIdle__INTC_NUMBER EQU 4
isr_BusyToIdle__INTC_PRIOR_NUM EQU 7
isr_BusyToIdle__INTC_PRIOR_REG EQU CYREG_NVIC_PRI_4
isr_BusyToIdle__INTC_SET_EN_REG EQU CYREG_NVIC_SETENA0
isr_BusyToIdle__INTC_SET_PD_REG EQU CYREG_NVIC_SETPEND0

; isr_RisingEdge
isr_RisingEdge__INTC_CLR_EN_REG EQU CYREG_NVIC_CLRENA0
isr_RisingEdge__INTC_CLR_PD_REG EQU CYREG_NVIC_CLRPEND0
isr_RisingEdge__INTC_MASK EQU 0x40
isr_RisingEdge__INTC_NUMBER EQU 6
isr_RisingEdge__INTC_PRIOR_NUM EQU 7
isr_RisingEdge__INTC_PRIOR_REG EQU CYREG_NVIC_PRI_6
isr_RisingEdge__INTC_SET_EN_REG EQU CYREG_NVIC_SETENA0
isr_RisingEdge__INTC_SET_PD_REG EQU CYREG_NVIC_SETPEND0

; isr_FallingEdge
isr_FallingEdge__INTC_CLR_EN_REG EQU CYREG_NVIC_CLRENA0
isr_FallingEdge__INTC_CLR_PD_REG EQU CYREG_NVIC_CLRPEND0
isr_FallingEdge__INTC_MASK EQU 0x20
isr_FallingEdge__INTC_NUMBER EQU 5
isr_FallingEdge__INTC_PRIOR_NUM EQU 7
isr_FallingEdge__INTC_PRIOR_REG EQU CYREG_NVIC_PRI_5
isr_FallingEdge__INTC_SET_EN_REG EQU CYREG_NVIC_SETENA0
isr_FallingEdge__INTC_SET_PD_REG EQU CYREG_NVIC_SETPEND0

; Pin_LEDCollision
Pin_LEDCollision__0__MASK EQU 0x80
Pin_LEDCollision__0__PC EQU CYREG_PRT3_PC7
Pin_LEDCollision__0__PORT EQU 3
Pin_LEDCollision__0__SHIFT EQU 7
Pin_LEDCollision__AG EQU CYREG_PRT3_AG
Pin_LEDCollision__AMUX EQU CYREG_PRT3_AMUX
Pin_LEDCollision__BIE EQU CYREG_PRT3_BIE
Pin_LEDCollision__BIT_MASK EQU CYREG_PRT3_BIT_MASK
Pin_LEDCollision__BYP EQU CYREG_PRT3_BYP
Pin_LEDCollision__CTL EQU CYREG_PRT3_CTL
Pin_LEDCollision__DM0 EQU CYREG_PRT3_DM0
Pin_LEDCollision__DM1 EQU CYREG_PRT3_DM1
Pin_LEDCollision__DM2 EQU CYREG_PRT3_DM2
Pin_LEDCollision__DR EQU CYREG_PRT3_DR
Pin_LEDCollision__INP_DIS EQU CYREG_PRT3_INP_DIS
Pin_LEDCollision__LCD_COM_SEG EQU CYREG_PRT3_LCD_COM_SEG
Pin_LEDCollision__LCD_EN EQU CYREG_PRT3_LCD_EN
Pin_LEDCollision__MASK EQU 0x80
Pin_LEDCollision__PORT EQU 3
Pin_LEDCollision__PRT EQU CYREG_PRT3_PRT
Pin_LEDCollision__PRTDSI__CAPS_SEL EQU CYREG_PRT3_CAPS_SEL
Pin_LEDCollision__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT3_DBL_SYNC_IN
Pin_LEDCollision__PRTDSI__OE_SEL0 EQU CYREG_PRT3_OE_SEL0
Pin_LEDCollision__PRTDSI__OE_SEL1 EQU CYREG_PRT3_OE_SEL1
Pin_LEDCollision__PRTDSI__OUT_SEL0 EQU CYREG_PRT3_OUT_SEL0
Pin_LEDCollision__PRTDSI__OUT_SEL1 EQU CYREG_PRT3_OUT_SEL1
Pin_LEDCollision__PRTDSI__SYNC_OUT EQU CYREG_PRT3_SYNC_OUT
Pin_LEDCollision__PS EQU CYREG_PRT3_PS
Pin_LEDCollision__SHIFT EQU 7
Pin_LEDCollision__SLW EQU CYREG_PRT3_SLW

; Timer_BusyToIdle_TimerUDB
Timer_BusyToIdle_TimerUDB_rstSts_stsreg__0__MASK EQU 0x01
Timer_BusyToIdle_TimerUDB_rstSts_stsreg__0__POS EQU 0
Timer_BusyToIdle_TimerUDB_rstSts_stsreg__16BIT_STATUS_AUX_CTL_REG EQU CYREG_B0_UDB13_14_ACTL
Timer_BusyToIdle_TimerUDB_rstSts_stsreg__16BIT_STATUS_REG EQU CYREG_B0_UDB13_14_ST
Timer_BusyToIdle_TimerUDB_rstSts_stsreg__2__MASK EQU 0x04
Timer_BusyToIdle_TimerUDB_rstSts_stsreg__2__POS EQU 2
Timer_BusyToIdle_TimerUDB_rstSts_stsreg__3__MASK EQU 0x08
Timer_BusyToIdle_TimerUDB_rstSts_stsreg__3__POS EQU 3
Timer_BusyToIdle_TimerUDB_rstSts_stsreg__MASK EQU 0x0D
Timer_BusyToIdle_TimerUDB_rstSts_stsreg__MASK_REG EQU CYREG_B0_UDB13_MSK
Timer_BusyToIdle_TimerUDB_rstSts_stsreg__MASK_ST_AUX_CTL_REG EQU CYREG_B0_UDB13_MSK_ACTL
Timer_BusyToIdle_TimerUDB_rstSts_stsreg__PER_ST_AUX_CTL_REG EQU CYREG_B0_UDB13_MSK_ACTL
Timer_BusyToIdle_TimerUDB_rstSts_stsreg__STATUS_AUX_CTL_REG EQU CYREG_B0_UDB13_ACTL
Timer_BusyToIdle_TimerUDB_rstSts_stsreg__STATUS_CNT_REG EQU CYREG_B0_UDB13_ST_CTL
Timer_BusyToIdle_TimerUDB_rstSts_stsreg__STATUS_CONTROL_REG EQU CYREG_B0_UDB13_ST_CTL
Timer_BusyToIdle_TimerUDB_rstSts_stsreg__STATUS_REG EQU CYREG_B0_UDB13_ST
Timer_BusyToIdle_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_CONTROL_AUX_CTL_REG EQU CYREG_B0_UDB13_14_ACTL
Timer_BusyToIdle_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_CONTROL_CONTROL_REG EQU CYREG_B0_UDB13_14_CTL
Timer_BusyToIdle_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_CONTROL_COUNT_REG EQU CYREG_B0_UDB13_14_CTL
Timer_BusyToIdle_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_COUNT_CONTROL_REG EQU CYREG_B0_UDB13_14_CTL
Timer_BusyToIdle_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_COUNT_COUNT_REG EQU CYREG_B0_UDB13_14_CTL
Timer_BusyToIdle_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_MASK_MASK_REG EQU CYREG_B0_UDB13_14_MSK
Timer_BusyToIdle_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_MASK_PERIOD_REG EQU CYREG_B0_UDB13_14_MSK
Timer_BusyToIdle_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_PERIOD_MASK_REG EQU CYREG_B0_UDB13_14_MSK
Timer_BusyToIdle_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_PERIOD_PERIOD_REG EQU CYREG_B0_UDB13_14_MSK
Timer_BusyToIdle_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__7__MASK EQU 0x80
Timer_BusyToIdle_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__7__POS EQU 7
Timer_BusyToIdle_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_AUX_CTL_REG EQU CYREG_B0_UDB13_ACTL
Timer_BusyToIdle_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_REG EQU CYREG_B0_UDB13_CTL
Timer_BusyToIdle_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_ST_REG EQU CYREG_B0_UDB13_ST_CTL
Timer_BusyToIdle_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__COUNT_REG EQU CYREG_B0_UDB13_CTL
Timer_BusyToIdle_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__COUNT_ST_REG EQU CYREG_B0_UDB13_ST_CTL
Timer_BusyToIdle_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__MASK EQU 0x80
Timer_BusyToIdle_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__MASK_CTL_AUX_CTL_REG EQU CYREG_B0_UDB13_MSK_ACTL
Timer_BusyToIdle_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__PER_CTL_AUX_CTL_REG EQU CYREG_B0_UDB13_MSK_ACTL
Timer_BusyToIdle_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__PERIOD_REG EQU CYREG_B0_UDB13_MSK
Timer_BusyToIdle_TimerUDB_sT16_timerdp_u0__16BIT_A0_REG EQU CYREG_B0_UDB12_13_A0
Timer_BusyToIdle_TimerUDB_sT16_timerdp_u0__16BIT_A1_REG EQU CYREG_B0_UDB12_13_A1
Timer_BusyToIdle_TimerUDB_sT16_timerdp_u0__16BIT_D0_REG EQU CYREG_B0_UDB12_13_D0
Timer_BusyToIdle_TimerUDB_sT16_timerdp_u0__16BIT_D1_REG EQU CYREG_B0_UDB12_13_D1
Timer_BusyToIdle_TimerUDB_sT16_timerdp_u0__16BIT_DP_AUX_CTL_REG EQU CYREG_B0_UDB12_13_ACTL
Timer_BusyToIdle_TimerUDB_sT16_timerdp_u0__16BIT_F0_REG EQU CYREG_B0_UDB12_13_F0
Timer_BusyToIdle_TimerUDB_sT16_timerdp_u0__16BIT_F1_REG EQU CYREG_B0_UDB12_13_F1
Timer_BusyToIdle_TimerUDB_sT16_timerdp_u0__A0_A1_REG EQU CYREG_B0_UDB12_A0_A1
Timer_BusyToIdle_TimerUDB_sT16_timerdp_u0__A0_REG EQU CYREG_B0_UDB12_A0
Timer_BusyToIdle_TimerUDB_sT16_timerdp_u0__A1_REG EQU CYREG_B0_UDB12_A1
Timer_BusyToIdle_TimerUDB_sT16_timerdp_u0__D0_D1_REG EQU CYREG_B0_UDB12_D0_D1
Timer_BusyToIdle_TimerUDB_sT16_timerdp_u0__D0_REG EQU CYREG_B0_UDB12_D0
Timer_BusyToIdle_TimerUDB_sT16_timerdp_u0__D1_REG EQU CYREG_B0_UDB12_D1
Timer_BusyToIdle_TimerUDB_sT16_timerdp_u0__DP_AUX_CTL_REG EQU CYREG_B0_UDB12_ACTL
Timer_BusyToIdle_TimerUDB_sT16_timerdp_u0__F0_F1_REG EQU CYREG_B0_UDB12_F0_F1
Timer_BusyToIdle_TimerUDB_sT16_timerdp_u0__F0_REG EQU CYREG_B0_UDB12_F0
Timer_BusyToIdle_TimerUDB_sT16_timerdp_u0__F1_REG EQU CYREG_B0_UDB12_F1
Timer_BusyToIdle_TimerUDB_sT16_timerdp_u1__16BIT_A0_REG EQU CYREG_B0_UDB13_14_A0
Timer_BusyToIdle_TimerUDB_sT16_timerdp_u1__16BIT_A1_REG EQU CYREG_B0_UDB13_14_A1
Timer_BusyToIdle_TimerUDB_sT16_timerdp_u1__16BIT_D0_REG EQU CYREG_B0_UDB13_14_D0
Timer_BusyToIdle_TimerUDB_sT16_timerdp_u1__16BIT_D1_REG EQU CYREG_B0_UDB13_14_D1
Timer_BusyToIdle_TimerUDB_sT16_timerdp_u1__16BIT_DP_AUX_CTL_REG EQU CYREG_B0_UDB13_14_ACTL
Timer_BusyToIdle_TimerUDB_sT16_timerdp_u1__16BIT_F0_REG EQU CYREG_B0_UDB13_14_F0
Timer_BusyToIdle_TimerUDB_sT16_timerdp_u1__16BIT_F1_REG EQU CYREG_B0_UDB13_14_F1
Timer_BusyToIdle_TimerUDB_sT16_timerdp_u1__A0_A1_REG EQU CYREG_B0_UDB13_A0_A1
Timer_BusyToIdle_TimerUDB_sT16_timerdp_u1__A0_REG EQU CYREG_B0_UDB13_A0
Timer_BusyToIdle_TimerUDB_sT16_timerdp_u1__A1_REG EQU CYREG_B0_UDB13_A1
Timer_BusyToIdle_TimerUDB_sT16_timerdp_u1__D0_D1_REG EQU CYREG_B0_UDB13_D0_D1
Timer_BusyToIdle_TimerUDB_sT16_timerdp_u1__D0_REG EQU CYREG_B0_UDB13_D0
Timer_BusyToIdle_TimerUDB_sT16_timerdp_u1__D1_REG EQU CYREG_B0_UDB13_D1
Timer_BusyToIdle_TimerUDB_sT16_timerdp_u1__DP_AUX_CTL_REG EQU CYREG_B0_UDB13_ACTL
Timer_BusyToIdle_TimerUDB_sT16_timerdp_u1__F0_F1_REG EQU CYREG_B0_UDB13_F0_F1
Timer_BusyToIdle_TimerUDB_sT16_timerdp_u1__F0_REG EQU CYREG_B0_UDB13_F0
Timer_BusyToIdle_TimerUDB_sT16_timerdp_u1__F1_REG EQU CYREG_B0_UDB13_F1
Timer_BusyToIdle_TimerUDB_sT16_timerdp_u1__MSK_DP_AUX_CTL_REG EQU CYREG_B0_UDB13_MSK_ACTL
Timer_BusyToIdle_TimerUDB_sT16_timerdp_u1__PER_DP_AUX_CTL_REG EQU CYREG_B0_UDB13_MSK_ACTL

; isr_BusyToCollision
isr_BusyToCollision__INTC_CLR_EN_REG EQU CYREG_NVIC_CLRENA0
isr_BusyToCollision__INTC_CLR_PD_REG EQU CYREG_NVIC_CLRPEND0
isr_BusyToCollision__INTC_MASK EQU 0x08
isr_BusyToCollision__INTC_NUMBER EQU 3
isr_BusyToCollision__INTC_PRIOR_NUM EQU 7
isr_BusyToCollision__INTC_PRIOR_REG EQU CYREG_NVIC_PRI_3
isr_BusyToCollision__INTC_SET_EN_REG EQU CYREG_NVIC_SETENA0
isr_BusyToCollision__INTC_SET_PD_REG EQU CYREG_NVIC_SETPEND0

; Timer_BusyToCollision_TimerUDB
Timer_BusyToCollision_TimerUDB_rstSts_stsreg__0__MASK EQU 0x01
Timer_BusyToCollision_TimerUDB_rstSts_stsreg__0__POS EQU 0
Timer_BusyToCollision_TimerUDB_rstSts_stsreg__2__MASK EQU 0x04
Timer_BusyToCollision_TimerUDB_rstSts_stsreg__2__POS EQU 2
Timer_BusyToCollision_TimerUDB_rstSts_stsreg__3__MASK EQU 0x08
Timer_BusyToCollision_TimerUDB_rstSts_stsreg__3__POS EQU 3
Timer_BusyToCollision_TimerUDB_rstSts_stsreg__MASK EQU 0x0D
Timer_BusyToCollision_TimerUDB_rstSts_stsreg__MASK_REG EQU CYREG_B0_UDB15_MSK
Timer_BusyToCollision_TimerUDB_rstSts_stsreg__MASK_ST_AUX_CTL_REG EQU CYREG_B0_UDB15_MSK_ACTL
Timer_BusyToCollision_TimerUDB_rstSts_stsreg__PER_ST_AUX_CTL_REG EQU CYREG_B0_UDB15_MSK_ACTL
Timer_BusyToCollision_TimerUDB_rstSts_stsreg__STATUS_AUX_CTL_REG EQU CYREG_B0_UDB15_ACTL
Timer_BusyToCollision_TimerUDB_rstSts_stsreg__STATUS_CNT_REG EQU CYREG_B0_UDB15_ST_CTL
Timer_BusyToCollision_TimerUDB_rstSts_stsreg__STATUS_CONTROL_REG EQU CYREG_B0_UDB15_ST_CTL
Timer_BusyToCollision_TimerUDB_rstSts_stsreg__STATUS_REG EQU CYREG_B0_UDB15_ST
Timer_BusyToCollision_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__7__MASK EQU 0x80
Timer_BusyToCollision_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__7__POS EQU 7
Timer_BusyToCollision_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_AUX_CTL_REG EQU CYREG_B0_UDB15_ACTL
Timer_BusyToCollision_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_REG EQU CYREG_B0_UDB15_CTL
Timer_BusyToCollision_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_ST_REG EQU CYREG_B0_UDB15_ST_CTL
Timer_BusyToCollision_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__COUNT_REG EQU CYREG_B0_UDB15_CTL
Timer_BusyToCollision_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__COUNT_ST_REG EQU CYREG_B0_UDB15_ST_CTL
Timer_BusyToCollision_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__MASK EQU 0x80
Timer_BusyToCollision_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__MASK_CTL_AUX_CTL_REG EQU CYREG_B0_UDB15_MSK_ACTL
Timer_BusyToCollision_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__PER_CTL_AUX_CTL_REG EQU CYREG_B0_UDB15_MSK_ACTL
Timer_BusyToCollision_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__PERIOD_REG EQU CYREG_B0_UDB15_MSK
Timer_BusyToCollision_TimerUDB_sT16_timerdp_u0__16BIT_A0_REG EQU CYREG_B0_UDB14_15_A0
Timer_BusyToCollision_TimerUDB_sT16_timerdp_u0__16BIT_A1_REG EQU CYREG_B0_UDB14_15_A1
Timer_BusyToCollision_TimerUDB_sT16_timerdp_u0__16BIT_D0_REG EQU CYREG_B0_UDB14_15_D0
Timer_BusyToCollision_TimerUDB_sT16_timerdp_u0__16BIT_D1_REG EQU CYREG_B0_UDB14_15_D1
Timer_BusyToCollision_TimerUDB_sT16_timerdp_u0__16BIT_DP_AUX_CTL_REG EQU CYREG_B0_UDB14_15_ACTL
Timer_BusyToCollision_TimerUDB_sT16_timerdp_u0__16BIT_F0_REG EQU CYREG_B0_UDB14_15_F0
Timer_BusyToCollision_TimerUDB_sT16_timerdp_u0__16BIT_F1_REG EQU CYREG_B0_UDB14_15_F1
Timer_BusyToCollision_TimerUDB_sT16_timerdp_u0__A0_A1_REG EQU CYREG_B0_UDB14_A0_A1
Timer_BusyToCollision_TimerUDB_sT16_timerdp_u0__A0_REG EQU CYREG_B0_UDB14_A0
Timer_BusyToCollision_TimerUDB_sT16_timerdp_u0__A1_REG EQU CYREG_B0_UDB14_A1
Timer_BusyToCollision_TimerUDB_sT16_timerdp_u0__D0_D1_REG EQU CYREG_B0_UDB14_D0_D1
Timer_BusyToCollision_TimerUDB_sT16_timerdp_u0__D0_REG EQU CYREG_B0_UDB14_D0
Timer_BusyToCollision_TimerUDB_sT16_timerdp_u0__D1_REG EQU CYREG_B0_UDB14_D1
Timer_BusyToCollision_TimerUDB_sT16_timerdp_u0__DP_AUX_CTL_REG EQU CYREG_B0_UDB14_ACTL
Timer_BusyToCollision_TimerUDB_sT16_timerdp_u0__F0_F1_REG EQU CYREG_B0_UDB14_F0_F1
Timer_BusyToCollision_TimerUDB_sT16_timerdp_u0__F0_REG EQU CYREG_B0_UDB14_F0
Timer_BusyToCollision_TimerUDB_sT16_timerdp_u0__F1_REG EQU CYREG_B0_UDB14_F1
Timer_BusyToCollision_TimerUDB_sT16_timerdp_u1__A0_A1_REG EQU CYREG_B0_UDB15_A0_A1
Timer_BusyToCollision_TimerUDB_sT16_timerdp_u1__A0_REG EQU CYREG_B0_UDB15_A0
Timer_BusyToCollision_TimerUDB_sT16_timerdp_u1__A1_REG EQU CYREG_B0_UDB15_A1
Timer_BusyToCollision_TimerUDB_sT16_timerdp_u1__D0_D1_REG EQU CYREG_B0_UDB15_D0_D1
Timer_BusyToCollision_TimerUDB_sT16_timerdp_u1__D0_REG EQU CYREG_B0_UDB15_D0
Timer_BusyToCollision_TimerUDB_sT16_timerdp_u1__D1_REG EQU CYREG_B0_UDB15_D1
Timer_BusyToCollision_TimerUDB_sT16_timerdp_u1__DP_AUX_CTL_REG EQU CYREG_B0_UDB15_ACTL
Timer_BusyToCollision_TimerUDB_sT16_timerdp_u1__F0_F1_REG EQU CYREG_B0_UDB15_F0_F1
Timer_BusyToCollision_TimerUDB_sT16_timerdp_u1__F0_REG EQU CYREG_B0_UDB15_F0
Timer_BusyToCollision_TimerUDB_sT16_timerdp_u1__F1_REG EQU CYREG_B0_UDB15_F1
Timer_BusyToCollision_TimerUDB_sT16_timerdp_u1__MSK_DP_AUX_CTL_REG EQU CYREG_B0_UDB15_MSK_ACTL
Timer_BusyToCollision_TimerUDB_sT16_timerdp_u1__PER_DP_AUX_CTL_REG EQU CYREG_B0_UDB15_MSK_ACTL

; Miscellaneous
BCLK__BUS_CLK__HZ EQU 24000000
BCLK__BUS_CLK__KHZ EQU 24000
BCLK__BUS_CLK__MHZ EQU 24
CYDEV_CHIP_DIE_LEOPARD EQU 1
CYDEV_CHIP_DIE_PANTHER EQU 4
CYDEV_CHIP_DIE_PSOC4A EQU 2
CYDEV_CHIP_DIE_PSOC5LP EQU 5
CYDEV_CHIP_DIE_UNKNOWN EQU 0
CYDEV_CHIP_FAMILY_PSOC3 EQU 1
CYDEV_CHIP_FAMILY_PSOC4 EQU 2
CYDEV_CHIP_FAMILY_PSOC5 EQU 3
CYDEV_CHIP_FAMILY_UNKNOWN EQU 0
CYDEV_CHIP_FAMILY_USED EQU CYDEV_CHIP_FAMILY_PSOC5
CYDEV_CHIP_JTAG_ID EQU 0x2E123069
CYDEV_CHIP_MEMBER_3A EQU 1
CYDEV_CHIP_MEMBER_4A EQU 2
CYDEV_CHIP_MEMBER_4D EQU 3
CYDEV_CHIP_MEMBER_5A EQU 4
CYDEV_CHIP_MEMBER_5B EQU 5
CYDEV_CHIP_MEMBER_UNKNOWN EQU 0
CYDEV_CHIP_MEMBER_USED EQU CYDEV_CHIP_MEMBER_5B
CYDEV_CHIP_DIE_EXPECT EQU CYDEV_CHIP_MEMBER_USED
CYDEV_CHIP_DIE_ACTUAL EQU CYDEV_CHIP_DIE_EXPECT
CYDEV_CHIP_REV_LEOPARD_ES1 EQU 0
CYDEV_CHIP_REV_LEOPARD_ES2 EQU 1
CYDEV_CHIP_REV_LEOPARD_ES3 EQU 3
CYDEV_CHIP_REV_LEOPARD_PRODUCTION EQU 3
CYDEV_CHIP_REV_PANTHER_ES0 EQU 0
CYDEV_CHIP_REV_PANTHER_ES1 EQU 1
CYDEV_CHIP_REV_PANTHER_PRODUCTION EQU 1
CYDEV_CHIP_REV_PSOC4A_ES0 EQU 17
CYDEV_CHIP_REV_PSOC4A_PRODUCTION EQU 17
CYDEV_CHIP_REV_PSOC5LP_ES0 EQU 0
CYDEV_CHIP_REV_PSOC5LP_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_3A_ES1 EQU 0
CYDEV_CHIP_REVISION_3A_ES2 EQU 1
CYDEV_CHIP_REVISION_3A_ES3 EQU 3
CYDEV_CHIP_REVISION_3A_PRODUCTION EQU 3
CYDEV_CHIP_REVISION_4A_ES0 EQU 17
CYDEV_CHIP_REVISION_4A_PRODUCTION EQU 17
CYDEV_CHIP_REVISION_4D_ES0 EQU 0
CYDEV_CHIP_REVISION_4D_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_5A_ES0 EQU 0
CYDEV_CHIP_REVISION_5A_ES1 EQU 1
CYDEV_CHIP_REVISION_5A_PRODUCTION EQU 1
CYDEV_CHIP_REVISION_5B_ES0 EQU 0
CYDEV_CHIP_REVISION_5B_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_USED EQU CYDEV_CHIP_REVISION_5B_PRODUCTION
CYDEV_CHIP_REV_EXPECT EQU CYDEV_CHIP_REVISION_USED
CYDEV_CONFIG_FASTBOOT_ENABLED EQU 1
CYDEV_CONFIG_UNUSED_IO_AllowButWarn EQU 0
CYDEV_CONFIG_UNUSED_IO EQU CYDEV_CONFIG_UNUSED_IO_AllowButWarn
CYDEV_CONFIG_UNUSED_IO_AllowWithInfo EQU 1
CYDEV_CONFIG_UNUSED_IO_Disallowed EQU 2
CYDEV_CONFIGURATION_COMPRESSED EQU 1
CYDEV_CONFIGURATION_DMA EQU 0
CYDEV_CONFIGURATION_ECC EQU 1
CYDEV_CONFIGURATION_IMOENABLED EQU CYDEV_CONFIG_FASTBOOT_ENABLED
CYDEV_CONFIGURATION_MODE_COMPRESSED EQU 0
CYDEV_CONFIGURATION_MODE EQU CYDEV_CONFIGURATION_MODE_COMPRESSED
CYDEV_CONFIGURATION_MODE_DMA EQU 2
CYDEV_CONFIGURATION_MODE_UNCOMPRESSED EQU 1
CYDEV_DEBUG_ENABLE_MASK EQU 0x20
CYDEV_DEBUG_ENABLE_REGISTER EQU CYREG_MLOGIC_DEBUG
CYDEV_DEBUGGING_DPS_Disable EQU 3
CYDEV_DEBUGGING_DPS_JTAG_4 EQU 1
CYDEV_DEBUGGING_DPS_JTAG_5 EQU 0
CYDEV_DEBUGGING_DPS_SWD EQU 2
CYDEV_DEBUGGING_DPS_SWD_SWV EQU 6
CYDEV_DEBUGGING_DPS EQU CYDEV_DEBUGGING_DPS_SWD_SWV
CYDEV_DEBUGGING_ENABLE EQU 1
CYDEV_DEBUGGING_XRES EQU 0
CYDEV_DMA_CHANNELS_AVAILABLE EQU 24
CYDEV_ECC_ENABLE EQU 0
CYDEV_HEAP_SIZE EQU 0x1000
CYDEV_INSTRUCT_CACHE_ENABLED EQU 1
CYDEV_INTR_RISING EQU 0x00000078
CYDEV_PROJ_TYPE EQU 0
CYDEV_PROJ_TYPE_BOOTLOADER EQU 1
CYDEV_PROJ_TYPE_LOADABLE EQU 2
CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER EQU 3
CYDEV_PROJ_TYPE_STANDARD EQU 0
CYDEV_PROTECTION_ENABLE EQU 0
CYDEV_STACK_SIZE EQU 0x4000
CYDEV_USB_CLK_OSC_LOCKING_ENABLED_AT_PWR_UP EQU 1
CYDEV_USE_BUNDLED_CMSIS EQU 1
CYDEV_VARIABLE_VDDA EQU 0
CYDEV_VDDA_MV EQU 5000
CYDEV_VDDD_MV EQU 5000
CYDEV_VDDIO0_MV EQU 5000
CYDEV_VDDIO1_MV EQU 5000
CYDEV_VDDIO2_MV EQU 5000
CYDEV_VDDIO3_MV EQU 5000
CYDEV_VIO0 EQU 5
CYDEV_VIO0_MV EQU 5000
CYDEV_VIO1 EQU 5
CYDEV_VIO1_MV EQU 5000
CYDEV_VIO2 EQU 5
CYDEV_VIO2_MV EQU 5000
CYDEV_VIO3 EQU 5
CYDEV_VIO3_MV EQU 5000
CYIPBLOCK_ARM_CM3_VERSION EQU 0
CYIPBLOCK_P3_ANAIF_VERSION EQU 0
CYIPBLOCK_P3_CAN_VERSION EQU 0
CYIPBLOCK_P3_CAPSENSE_VERSION EQU 0
CYIPBLOCK_P3_COMP_VERSION EQU 0
CYIPBLOCK_P3_DECIMATOR_VERSION EQU 0
CYIPBLOCK_P3_DFB_VERSION EQU 0
CYIPBLOCK_P3_DMA_VERSION EQU 0
CYIPBLOCK_P3_DRQ_VERSION EQU 0
CYIPBLOCK_P3_DSM_VERSION EQU 0
CYIPBLOCK_P3_EMIF_VERSION EQU 0
CYIPBLOCK_P3_I2C_VERSION EQU 0
CYIPBLOCK_P3_LCD_VERSION EQU 0
CYIPBLOCK_P3_LPF_VERSION EQU 0
CYIPBLOCK_P3_OPAMP_VERSION EQU 0
CYIPBLOCK_P3_PM_VERSION EQU 0
CYIPBLOCK_P3_SCCT_VERSION EQU 0
CYIPBLOCK_P3_TIMER_VERSION EQU 0
CYIPBLOCK_P3_USB_VERSION EQU 0
CYIPBLOCK_P3_VIDAC_VERSION EQU 0
CYIPBLOCK_P3_VREF_VERSION EQU 0
CYIPBLOCK_S8_GPIO_VERSION EQU 0
CYIPBLOCK_S8_IRQ_VERSION EQU 0
CYIPBLOCK_S8_SAR_VERSION EQU 0
CYIPBLOCK_S8_SIO_VERSION EQU 0
CYIPBLOCK_S8_UDB_VERSION EQU 0
DMA_CHANNELS_USED__MASK0 EQU 0x00000000
CYDEV_BOOTLOADER_ENABLE EQU 0
    ENDIF
    END
