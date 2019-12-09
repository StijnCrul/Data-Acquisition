/*******************************************************************************
* File Name: cyfitter.h
* 
* PSoC Creator  4.2
*
* Description:
* 
* This file is automatically generated by PSoC Creator.
*
********************************************************************************
* Copyright (c) 2007-2018 Cypress Semiconductor.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#ifndef INCLUDED_CYFITTER_H
#define INCLUDED_CYFITTER_H
#include "cy_device_headers.h"
#include "cyfitter_gpio.h"
#include "cyfitter_sysint.h"

/* T0 */
#define T0_TCPWM__CNT_HW TCPWM0_CNT4
#define T0_TCPWM__CNT_IDX 4u
#define T0_TCPWM__HW TCPWM0
#define T0_TCPWM__IDX 0u

/* T1 */
#define T1_TCPWM__CNT_HW TCPWM0_CNT0
#define T1_TCPWM__CNT_IDX 0u
#define T1_TCPWM__HW TCPWM0
#define T1_TCPWM__IDX 0u

/* T2 */
#define T2_TCPWM__CNT_HW TCPWM0_CNT2
#define T2_TCPWM__CNT_IDX 2u
#define T2_TCPWM__HW TCPWM0
#define T2_TCPWM__IDX 0u

/* T3 */
#define T3_TCPWM__CNT_HW TCPWM0_CNT1
#define T3_TCPWM__CNT_IDX 1u
#define T3_TCPWM__HW TCPWM0
#define T3_TCPWM__IDX 0u

/* ADC */
#define ADC_intSarClock__DIV_IDX 4
#define ADC_intSarClock__DIV_NUM 4
#define ADC_intSarClock__DIV_TYPE CY_SYSCLK_DIV_8_BIT
#define ADC_SAR__HW SAR
#define ADC_SAR__IDX 0
#define ADC_SAR__TR_SAR_IN TRIG6_OUT_PASS_TR_SAR_IN

/* UART */
#define UART_SCB__HW SCB5
#define UART_SCB__IDX 5
#define UART_SCB__SS0_POSITION 0u
#define UART_SCB__SS1_POSITION 1u
#define UART_SCB__SS2_POSITION 2u
#define UART_SCB__SS3_POSITION 3u
#define UART_SCB__TR_TX_REQ TRIG13_IN_SCB5_TR_TX_REQ
#define UART_SCBCLK__DIV_IDX 3
#define UART_SCBCLK__DIV_NUM 3
#define UART_SCBCLK__DIV_TYPE CY_SYSCLK_DIV_8_BIT

/* mI2C */
#define mI2C_SCB__HW SCB3
#define mI2C_SCB__IDX 3
#define mI2C_SCB__SS0_POSITION 0u
#define mI2C_SCB__SS1_POSITION 1u
#define mI2C_SCB__SS2_POSITION 2u
#define mI2C_SCB__SS3_POSITION 3u
#define mI2C_SCBCLK__DIV_IDX 2
#define mI2C_SCBCLK__DIV_NUM 2
#define mI2C_SCBCLK__DIV_TYPE CY_SYSCLK_DIV_8_BIT

/* SRClk */
#define SRClk__DIV_IDX 0
#define SRClk__DIV_NUM 0
#define SRClk__DIV_TYPE CY_SYSCLK_DIV_8_BIT

/* I2CDMA */
#define I2CDMA_DW__BLOCK_HW DW0
#define I2CDMA_DW__BLOCK_NUMBER 0u
#define I2CDMA_DW__CHANNEL_HW DW0_CH_STRUCT5
#define I2CDMA_DW__CHANNEL_NUMBER 5u
#define I2CDMA_DW__TR_IN TRIG0_OUT_CPUSS_DW0_TR_IN5

/* UARTDMA */
#define UARTDMA_DW__BLOCK_HW DW0
#define UARTDMA_DW__BLOCK_NUMBER 0u
#define UARTDMA_DW__CHANNEL_HW DW0_CH_STRUCT2
#define UARTDMA_DW__CHANNEL_NUMBER 2u
#define UARTDMA_DW__TR_IN TRIG0_OUT_CPUSS_DW0_TR_IN2

/* ADCDMA_0 */
#define ADCDMA_0_DW__BLOCK_HW DW0
#define ADCDMA_0_DW__BLOCK_NUMBER 0u
#define ADCDMA_0_DW__CHANNEL_HW DW0_CH_STRUCT1
#define ADCDMA_0_DW__CHANNEL_NUMBER 1u
#define ADCDMA_0_DW__TR_IN TRIG0_OUT_CPUSS_DW0_TR_IN1
#define ADCDMA_0_DW__TR_OUT TRIG10_IN_CPUSS_DW0_TR_OUT1

/* ADCDMA_1 */
#define ADCDMA_1_DW__BLOCK_HW DW0
#define ADCDMA_1_DW__BLOCK_NUMBER 0u
#define ADCDMA_1_DW__CHANNEL_HW DW0_CH_STRUCT4
#define ADCDMA_1_DW__CHANNEL_NUMBER 4u
#define ADCDMA_1_DW__TR_IN TRIG0_OUT_CPUSS_DW0_TR_IN4

/* ADCDMA_2 */
#define ADCDMA_2_DW__BLOCK_HW DW0
#define ADCDMA_2_DW__BLOCK_NUMBER 0u
#define ADCDMA_2_DW__CHANNEL_HW DW0_CH_STRUCT3
#define ADCDMA_2_DW__CHANNEL_NUMBER 3u
#define ADCDMA_2_DW__TR_IN TRIG0_OUT_CPUSS_DW0_TR_IN3

/* ADCDMA_3 */
#define ADCDMA_3_DW__BLOCK_HW DW0
#define ADCDMA_3_DW__BLOCK_NUMBER 0u
#define ADCDMA_3_DW__CHANNEL_HW DW0_CH_STRUCT0
#define ADCDMA_3_DW__CHANNEL_NUMBER 0u
#define ADCDMA_3_DW__TR_IN TRIG0_OUT_CPUSS_DW0_TR_IN0
#define ADCDMA_3_DW__TR_OUT TRIG10_IN_CPUSS_DW0_TR_OUT0

/* ADCCounterClk */
#define ADCCounterClk__DIV_IDX 1
#define ADCCounterClk__DIV_NUM 1
#define ADCCounterClk__DIV_TYPE CY_SYSCLK_DIV_8_BIT

/* ADCSOCCounter */
#define ADCSOCCounter_TCPWM__CNT_HW TCPWM0_CNT3
#define ADCSOCCounter_TCPWM__CNT_IDX 3u
#define ADCSOCCounter_TCPWM__HW TCPWM0
#define ADCSOCCounter_TCPWM__IDX 0u
#define ADCSOCCounter_TCPWM__TR_COMPARE_MATCH TRIG11_IN_TCPWM0_TR_COMPARE_MATCH3

/* Miscellaneous */
#define CPUSS__CTI_TR_IN_0 TRIG5_OUT_CPUSS_CTI_TR_IN0
#define CPUSS__CTI_TR_IN_1 TRIG5_OUT_CPUSS_CTI_TR_IN1
#define CY_CPUSS_SWJ_SWCLK_TCLK_0_DRIVEMODE CY_GPIO_DM_PULLDOWN
#define CY_CPUSS_SWJ_SWCLK_TCLK_0_INBUF_ENABLED 1u
#define CY_CPUSS_SWJ_SWCLK_TCLK_0_INIT_DRIVESTATE 0u
#define CY_CPUSS_SWJ_SWCLK_TCLK_0_INIT_MUXSEL 29u
#define CY_CPUSS_SWJ_SWCLK_TCLK_0_INPUT_SYNC 2u
#define CY_CPUSS_SWJ_SWCLK_TCLK_0_INTERRUPT_MODE CY_GPIO_INTR_DISABLE
#define CY_CPUSS_SWJ_SWCLK_TCLK_0_NUM 7u
#define CY_CPUSS_SWJ_SWCLK_TCLK_0_PORT GPIO_PRT6
#define CY_CPUSS_SWJ_SWCLK_TCLK_0_SLEWRATE CY_GPIO_SLEW_FAST
#define CY_CPUSS_SWJ_SWCLK_TCLK_0_THRESHOLD_LEVEL CY_GPIO_VTRIP_CMOS
#define CY_CPUSS_SWJ_SWCLK_TCLK_DRIVEMODE CY_GPIO_DM_PULLDOWN
#define CY_CPUSS_SWJ_SWCLK_TCLK_INBUF_ENABLED 1u
#define CY_CPUSS_SWJ_SWCLK_TCLK_INIT_DRIVESTATE 0u
#define CY_CPUSS_SWJ_SWCLK_TCLK_INIT_MUXSEL 29u
#define CY_CPUSS_SWJ_SWCLK_TCLK_INPUT_SYNC 2u
#define CY_CPUSS_SWJ_SWCLK_TCLK_INTERRUPT_MODE CY_GPIO_INTR_DISABLE
#define CY_CPUSS_SWJ_SWCLK_TCLK_NUM 7u
#define CY_CPUSS_SWJ_SWCLK_TCLK_PORT GPIO_PRT6
#define CY_CPUSS_SWJ_SWCLK_TCLK_SLEWRATE CY_GPIO_SLEW_FAST
#define CY_CPUSS_SWJ_SWCLK_TCLK_THRESHOLD_LEVEL CY_GPIO_VTRIP_CMOS
#define CY_CPUSS_SWJ_SWDIO_TMS_0_DRIVEMODE CY_GPIO_DM_PULLUP
#define CY_CPUSS_SWJ_SWDIO_TMS_0_INBUF_ENABLED 1u
#define CY_CPUSS_SWJ_SWDIO_TMS_0_INIT_DRIVESTATE 0u
#define CY_CPUSS_SWJ_SWDIO_TMS_0_INIT_MUXSEL 29u
#define CY_CPUSS_SWJ_SWDIO_TMS_0_INPUT_SYNC 2u
#define CY_CPUSS_SWJ_SWDIO_TMS_0_INTERRUPT_MODE CY_GPIO_INTR_DISABLE
#define CY_CPUSS_SWJ_SWDIO_TMS_0_NUM 6u
#define CY_CPUSS_SWJ_SWDIO_TMS_0_PORT GPIO_PRT6
#define CY_CPUSS_SWJ_SWDIO_TMS_0_SLEWRATE CY_GPIO_SLEW_FAST
#define CY_CPUSS_SWJ_SWDIO_TMS_0_THRESHOLD_LEVEL CY_GPIO_VTRIP_CMOS
#define CY_CPUSS_SWJ_SWDIO_TMS_DRIVEMODE CY_GPIO_DM_PULLUP
#define CY_CPUSS_SWJ_SWDIO_TMS_INBUF_ENABLED 1u
#define CY_CPUSS_SWJ_SWDIO_TMS_INIT_DRIVESTATE 0u
#define CY_CPUSS_SWJ_SWDIO_TMS_INIT_MUXSEL 29u
#define CY_CPUSS_SWJ_SWDIO_TMS_INPUT_SYNC 2u
#define CY_CPUSS_SWJ_SWDIO_TMS_INTERRUPT_MODE CY_GPIO_INTR_DISABLE
#define CY_CPUSS_SWJ_SWDIO_TMS_NUM 6u
#define CY_CPUSS_SWJ_SWDIO_TMS_PORT GPIO_PRT6
#define CY_CPUSS_SWJ_SWDIO_TMS_SLEWRATE CY_GPIO_SLEW_FAST
#define CY_CPUSS_SWJ_SWDIO_TMS_THRESHOLD_LEVEL CY_GPIO_VTRIP_CMOS
#define CY_PROJECT_NAME "IoT_Generic_DAQ"
#define CY_VERSION "PSoC Creator  4.2"
#define CYDEV_CHIP_DIE_LEOPARD 1u
#define CYDEV_CHIP_DIE_PSOC4A 19u
#define CYDEV_CHIP_DIE_PSOC5LP 2u
#define CYDEV_CHIP_DIE_PSOC5TM 3u
#define CYDEV_CHIP_DIE_TMA4 4u
#define CYDEV_CHIP_DIE_UNKNOWN 0u
#define CYDEV_CHIP_FAMILY_FM0P 5u
#define CYDEV_CHIP_FAMILY_FM3 6u
#define CYDEV_CHIP_FAMILY_FM4 7u
#define CYDEV_CHIP_FAMILY_PSOC3 1u
#define CYDEV_CHIP_FAMILY_PSOC4 2u
#define CYDEV_CHIP_FAMILY_PSOC5 3u
#define CYDEV_CHIP_FAMILY_PSOC6 4u
#define CYDEV_CHIP_FAMILY_UNKNOWN 0u
#define CYDEV_CHIP_FAMILY_USED CYDEV_CHIP_FAMILY_PSOC6
#define CYDEV_CHIP_JTAG_ID 0xE2062100u
#define CYDEV_CHIP_MEMBER_3A 1u
#define CYDEV_CHIP_MEMBER_4A 19u
#define CYDEV_CHIP_MEMBER_4D 14u
#define CYDEV_CHIP_MEMBER_4E 6u
#define CYDEV_CHIP_MEMBER_4F 20u
#define CYDEV_CHIP_MEMBER_4G 4u
#define CYDEV_CHIP_MEMBER_4H 18u
#define CYDEV_CHIP_MEMBER_4I 24u
#define CYDEV_CHIP_MEMBER_4J 15u
#define CYDEV_CHIP_MEMBER_4K 16u
#define CYDEV_CHIP_MEMBER_4L 23u
#define CYDEV_CHIP_MEMBER_4M 22u
#define CYDEV_CHIP_MEMBER_4N 10u
#define CYDEV_CHIP_MEMBER_4O 7u
#define CYDEV_CHIP_MEMBER_4P 21u
#define CYDEV_CHIP_MEMBER_4Q 13u
#define CYDEV_CHIP_MEMBER_4R 8u
#define CYDEV_CHIP_MEMBER_4S 11u
#define CYDEV_CHIP_MEMBER_4T 9u
#define CYDEV_CHIP_MEMBER_4U 5u
#define CYDEV_CHIP_MEMBER_4V 17u
#define CYDEV_CHIP_MEMBER_4W 12u
#define CYDEV_CHIP_MEMBER_5A 3u
#define CYDEV_CHIP_MEMBER_5B 2u
#define CYDEV_CHIP_MEMBER_6A 25u
#define CYDEV_CHIP_MEMBER_FM3 29u
#define CYDEV_CHIP_MEMBER_FM4 30u
#define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE1 26u
#define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE2 27u
#define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE3 28u
#define CYDEV_CHIP_MEMBER_UNKNOWN 0u
#define CYDEV_CHIP_MEMBER_USED CYDEV_CHIP_MEMBER_6A
#define CYDEV_CHIP_DIE_EXPECT CYDEV_CHIP_MEMBER_USED
#define CYDEV_CHIP_DIE_ACTUAL CYDEV_CHIP_DIE_EXPECT
#define CYDEV_CHIP_REV_LEOPARD_ES1 0u
#define CYDEV_CHIP_REV_LEOPARD_ES2 1u
#define CYDEV_CHIP_REV_LEOPARD_ES3 3u
#define CYDEV_CHIP_REV_LEOPARD_PRODUCTION 3u
#define CYDEV_CHIP_REV_PSOC4A_ES0 17u
#define CYDEV_CHIP_REV_PSOC4A_PRODUCTION 17u
#define CYDEV_CHIP_REV_PSOC5LP_ES0 0u
#define CYDEV_CHIP_REV_PSOC5LP_PRODUCTION 0u
#define CYDEV_CHIP_REV_PSOC5TM_ES0 0u
#define CYDEV_CHIP_REV_PSOC5TM_ES1 1u
#define CYDEV_CHIP_REV_PSOC5TM_PRODUCTION 1u
#define CYDEV_CHIP_REV_TMA4_ES 17u
#define CYDEV_CHIP_REV_TMA4_ES2 33u
#define CYDEV_CHIP_REV_TMA4_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_3A_ES1 0u
#define CYDEV_CHIP_REVISION_3A_ES2 1u
#define CYDEV_CHIP_REVISION_3A_ES3 3u
#define CYDEV_CHIP_REVISION_3A_PRODUCTION 3u
#define CYDEV_CHIP_REVISION_4A_ES0 17u
#define CYDEV_CHIP_REVISION_4A_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_4D_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4E_CCG2_NO_USBPD 0u
#define CYDEV_CHIP_REVISION_4E_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION_256K 0u
#define CYDEV_CHIP_REVISION_4G_ES 17u
#define CYDEV_CHIP_REVISION_4G_ES2 33u
#define CYDEV_CHIP_REVISION_4G_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_4H_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4I_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4J_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4K_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4L_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4M_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4N_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4O_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4P_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4Q_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4R_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4S_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4T_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4U_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4V_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4W_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_5A_ES0 0u
#define CYDEV_CHIP_REVISION_5A_ES1 1u
#define CYDEV_CHIP_REVISION_5A_PRODUCTION 1u
#define CYDEV_CHIP_REVISION_5B_ES0 0u
#define CYDEV_CHIP_REVISION_5B_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_6A_ES 17u
#define CYDEV_CHIP_REVISION_6A_NO_UDB 33u
#define CYDEV_CHIP_REVISION_6A_PRODUCTION 33u
#define CYDEV_CHIP_REVISION_FM3_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_FM4_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE1_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE2_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE3_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_USED CYDEV_CHIP_REVISION_6A_PRODUCTION
#define CYDEV_CHIP_REV_EXPECT CYDEV_CHIP_REVISION_USED
#define CYDEV_CLK_ALTSYSTICKCLK__HZ 32000U
#define CYDEV_CLK_ALTSYSTICKCLK__KHZ 32U
#define CYDEV_CLK_ALTSYSTICKCLK__MHZ 0U
#define CYDEV_CLK_BAKCLK__HZ 32000U
#define CYDEV_CLK_BAKCLK__KHZ 32U
#define CYDEV_CLK_BAKCLK__MHZ 0U
#define CYDEV_CLK_FASTCLK__HZ 100000000U
#define CYDEV_CLK_FASTCLK__KHZ 100000U
#define CYDEV_CLK_FASTCLK__MHZ 100U
#define CYDEV_CLK_FLL__HZ 100000000U
#define CYDEV_CLK_FLL__KHZ 100000U
#define CYDEV_CLK_FLL__MHZ 100U
#define CYDEV_CLK_HFCLK0__HZ 100000000U
#define CYDEV_CLK_HFCLK0__KHZ 100000U
#define CYDEV_CLK_HFCLK0__MHZ 100U
#define CYDEV_CLK_ILO__HZ 32000U
#define CYDEV_CLK_ILO__KHZ 32U
#define CYDEV_CLK_ILO__MHZ 0U
#define CYDEV_CLK_IMO__HZ 8000000U
#define CYDEV_CLK_IMO__KHZ 8000U
#define CYDEV_CLK_IMO__MHZ 8U
#define CYDEV_CLK_LFCLK__HZ 32000U
#define CYDEV_CLK_LFCLK__KHZ 32U
#define CYDEV_CLK_LFCLK__MHZ 0U
#define CYDEV_CLK_PATHMUX0__HZ 8000000U
#define CYDEV_CLK_PATHMUX0__KHZ 8000U
#define CYDEV_CLK_PATHMUX0__MHZ 8U
#define CYDEV_CLK_PATHMUX1__HZ 8000000U
#define CYDEV_CLK_PATHMUX1__KHZ 8000U
#define CYDEV_CLK_PATHMUX1__MHZ 8U
#define CYDEV_CLK_PATHMUX2__HZ 8000000U
#define CYDEV_CLK_PATHMUX2__KHZ 8000U
#define CYDEV_CLK_PATHMUX2__MHZ 8U
#define CYDEV_CLK_PATHMUX3__HZ 8000000U
#define CYDEV_CLK_PATHMUX3__KHZ 8000U
#define CYDEV_CLK_PATHMUX3__MHZ 8U
#define CYDEV_CLK_PATHMUX4__HZ 8000000U
#define CYDEV_CLK_PATHMUX4__KHZ 8000U
#define CYDEV_CLK_PATHMUX4__MHZ 8U
#define CYDEV_CLK_PERICLK__HZ 50000000U
#define CYDEV_CLK_PERICLK__KHZ 50000U
#define CYDEV_CLK_PERICLK__MHZ 50U
#define CYDEV_CLK_PUMPCLK__HZ 25000000U
#define CYDEV_CLK_PUMPCLK__KHZ 25000U
#define CYDEV_CLK_PUMPCLK__MHZ 25U
#define CYDEV_CLK_SLOWCLK__HZ 50000000U
#define CYDEV_CLK_SLOWCLK__KHZ 50000U
#define CYDEV_CLK_SLOWCLK__MHZ 50U
#define CYDEV_CLK_TIMERCLK__HZ 8000000U
#define CYDEV_CLK_TIMERCLK__KHZ 8000U
#define CYDEV_CLK_TIMERCLK__MHZ 8U
#define CYDEV_CONFIG_READ_ACCELERATOR 1
#define CYDEV_CONFIG_UNUSED_IO_AllowButWarn 0
#define CYDEV_CONFIG_UNUSED_IO CYDEV_CONFIG_UNUSED_IO_AllowButWarn
#define CYDEV_CONFIG_UNUSED_IO_AllowWithInfo 1
#define CYDEV_CONFIG_UNUSED_IO_Disallowed 2
#define CYDEV_CONFIGURATION_COMPRESSED 1
#define CYDEV_CONFIGURATION_MODE_COMPRESSED 0
#define CYDEV_CONFIGURATION_MODE CYDEV_CONFIGURATION_MODE_COMPRESSED
#define CYDEV_CONFIGURATION_MODE_DMA 2
#define CYDEV_CONFIGURATION_MODE_UNCOMPRESSED 1
#define CYDEV_CORE_VOLTAGE CY_SYSPM_LDO_VOLTAGE_1_1V
#define CYDEV_DEBUGGING_DPS_Disable 3
#define CYDEV_DEBUGGING_DPS_JTAG_4 1
#define CYDEV_DEBUGGING_DPS_JTAG_5 0
#define CYDEV_DEBUGGING_DPS_SWD 2
#define CYDEV_DEBUGGING_DPS CYDEV_DEBUGGING_DPS_SWD
#define CYDEV_DEBUGGING_DPS_SWD_SWV 6
#define CYDEV_DEBUGGING_ENABLE 1
#define CYDEV_ENABLE_SIMO_BUCK false
#define CYDEV_IS_EXPORTING_CODE 0
#define CYDEV_IS_IMPORTING_CODE 0
#define CYDEV_PMIC_ENABLED 0
#define CYDEV_PMIC_MODE CYDEV_PMIC_MODE_DISABLED
#define CYDEV_POWER_MODE CYDEV_POWER_MODE_LDO_LINEAR_REG_1_1V
#define CYDEV_PROJ_TYPE 0
#define CYDEV_PROJ_TYPE_BOOTLOADER 1
#define CYDEV_PROJ_TYPE_LAUNCHER 5
#define CYDEV_PROJ_TYPE_LOADABLE 2
#define CYDEV_PROJ_TYPE_LOADABLEANDBOOTLOADER 4
#define CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER 3
#define CYDEV_PROJ_TYPE_STANDARD 0
#define CYDEV_SYSTEM_AREF_CURRENT_HIGH 1
#define CYDEV_SYSTEM_AREF_CURRENT CYDEV_SYSTEM_AREF_CURRENT_HIGH
#define CYDEV_SYSTEM_AREF_CURRENT_LOW 0
#define CYDEV_SYSTEM_AREF_DEEPSLEEP 0
#define CYDEV_SYSTEM_AREF_SOURCE CY_SYSANALOG_VREF_SOURCE_LOCAL_1_2V
#define CYDEV_VARIABLE_VDDA 0
#define CYDEV_VBAC_SUPPLY CYDEV_VBAC_SUPPLY_VDDD
#define CYDEV_VBACKUP 3.3
#define CYDEV_VBACKUP_MV 3300
#define CYDEV_VDD_NS 3.3
#define CYDEV_VDD_NS_MV 3300
#define CYDEV_VDDA 3.3
#define CYDEV_VDDA_MV 3300
#define CYDEV_VDDD 3.3
#define CYDEV_VDDD_MV 3300
#define CYDEV_VDDIO0 3.3
#define CYDEV_VDDIO0_MV 3300
#define CYDEV_VDDIO1 3.3
#define CYDEV_VDDIO1_MV 3300
#define CYDEV_VDDIOA 3.3
#define CYDEV_VDDIOA_MV 3300
#define CYDEV_VDDIOR 3.3
#define CYDEV_VDDIOR_MV 3300
#define CYDEV_VDDUSB 3.3
#define CYDEV_VDDUSB_MV 3300
#define CYDEV_BOOTLOADER_ENABLE 0

#endif /* INCLUDED_CYFITTER_H */
