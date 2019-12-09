/***************************************************************************//**
* \file UARTDMA.c
* \version 2.0
*
*  This file provides the source code to the API for the
*  UARTDMA component.
*
********************************************************************************
* \copyright
* Copyright 2016-2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "UARTDMA.h"

#if defined(__cplusplus)
extern "C" {
#endif

/* Generated code */
const cy_stc_dma_descriptor_config_t UARTDMA_Descriptor_Analog0_Data_config =
{
    .retrigger       = CY_DMA_RETRIG_IM,
    .interruptType   = CY_DMA_DESCR,
    .triggerOutType  = CY_DMA_DESCR,
    .channelState    = CY_DMA_CHANNEL_ENABLED,
    .triggerInType   = CY_DMA_1ELEMENT,
    .dataSize        = CY_DMA_BYTE,
    .srcTransferSize = CY_DMA_TRANSFER_SIZE_DATA,
    .dstTransferSize = CY_DMA_TRANSFER_SIZE_WORD,
    .descriptorType  = CY_DMA_2D_TRANSFER,
    .srcAddress      = NULL,
    .dstAddress      = NULL,
    .srcXincrement   = 1L,
    .dstXincrement   = 0L,
    .xCount          = 256UL,
    .srcYincrement   = 256L,
    .dstYincrement   = 0L,
    .yCount          = 16UL,
    .nextDescriptor  = NULL
};

cy_stc_dma_descriptor_t UARTDMA_Descriptor_Analog0_Data =
{
    .ctl = 0UL,
    .src = 0UL,
    .dst = 0UL,
    .xCtl = 0UL,
    .yCtl = 0UL,
    .nextPtr = 0UL
};

const cy_stc_dma_descriptor_config_t UARTDMA_Descriptor_Analog0_Command_config =
{
    .retrigger       = CY_DMA_RETRIG_IM,
    .interruptType   = CY_DMA_DESCR_CHAIN,
    .triggerOutType  = CY_DMA_DESCR_CHAIN,
    .channelState    = CY_DMA_CHANNEL_ENABLED,
    .triggerInType   = CY_DMA_1ELEMENT,
    .dataSize        = CY_DMA_BYTE,
    .srcTransferSize = CY_DMA_TRANSFER_SIZE_DATA,
    .dstTransferSize = CY_DMA_TRANSFER_SIZE_WORD,
    .descriptorType  = CY_DMA_1D_TRANSFER,
    .srcAddress      = NULL,
    .dstAddress      = NULL,
    .srcXincrement   = 1L,
    .dstXincrement   = 0L,
    .xCount          = 2UL,
    .srcYincrement   = 0L,
    .dstYincrement   = 0L,
    .yCount          = 1UL,
    .nextDescriptor  = &UARTDMA_Descriptor_Analog0_Data
};

cy_stc_dma_descriptor_t UARTDMA_Descriptor_Analog0_Command =
{
    .ctl = 0UL,
    .src = 0UL,
    .dst = 0UL,
    .xCtl = 0UL,
    .yCtl = 0UL,
    .nextPtr = 0UL
};

const cy_stc_dma_descriptor_config_t UARTDMA_Descriptor_Analog1_Data_config =
{
    .retrigger       = CY_DMA_RETRIG_IM,
    .interruptType   = CY_DMA_DESCR,
    .triggerOutType  = CY_DMA_DESCR,
    .channelState    = CY_DMA_CHANNEL_ENABLED,
    .triggerInType   = CY_DMA_1ELEMENT,
    .dataSize        = CY_DMA_BYTE,
    .srcTransferSize = CY_DMA_TRANSFER_SIZE_DATA,
    .dstTransferSize = CY_DMA_TRANSFER_SIZE_WORD,
    .descriptorType  = CY_DMA_2D_TRANSFER,
    .srcAddress      = NULL,
    .dstAddress      = NULL,
    .srcXincrement   = 1L,
    .dstXincrement   = 0L,
    .xCount          = 256UL,
    .srcYincrement   = 256L,
    .dstYincrement   = 0L,
    .yCount          = 16UL,
    .nextDescriptor  = NULL
};

cy_stc_dma_descriptor_t UARTDMA_Descriptor_Analog1_Data =
{
    .ctl = 0UL,
    .src = 0UL,
    .dst = 0UL,
    .xCtl = 0UL,
    .yCtl = 0UL,
    .nextPtr = 0UL
};

const cy_stc_dma_descriptor_config_t UARTDMA_Descriptor_Analog1_Command_config =
{
    .retrigger       = CY_DMA_RETRIG_IM,
    .interruptType   = CY_DMA_DESCR_CHAIN,
    .triggerOutType  = CY_DMA_DESCR_CHAIN,
    .channelState    = CY_DMA_CHANNEL_ENABLED,
    .triggerInType   = CY_DMA_1ELEMENT,
    .dataSize        = CY_DMA_BYTE,
    .srcTransferSize = CY_DMA_TRANSFER_SIZE_DATA,
    .dstTransferSize = CY_DMA_TRANSFER_SIZE_WORD,
    .descriptorType  = CY_DMA_1D_TRANSFER,
    .srcAddress      = NULL,
    .dstAddress      = NULL,
    .srcXincrement   = 1L,
    .dstXincrement   = 0L,
    .xCount          = 2UL,
    .srcYincrement   = 0L,
    .dstYincrement   = 0L,
    .yCount          = 1UL,
    .nextDescriptor  = &UARTDMA_Descriptor_Analog1_Data
};

cy_stc_dma_descriptor_t UARTDMA_Descriptor_Analog1_Command =
{
    .ctl = 0UL,
    .src = 0UL,
    .dst = 0UL,
    .xCtl = 0UL,
    .yCtl = 0UL,
    .nextPtr = 0UL
};

const cy_stc_dma_descriptor_config_t UARTDMA_Descriptor_Analog2_Data_config =
{
    .retrigger       = CY_DMA_RETRIG_IM,
    .interruptType   = CY_DMA_DESCR,
    .triggerOutType  = CY_DMA_DESCR,
    .channelState    = CY_DMA_CHANNEL_ENABLED,
    .triggerInType   = CY_DMA_1ELEMENT,
    .dataSize        = CY_DMA_BYTE,
    .srcTransferSize = CY_DMA_TRANSFER_SIZE_DATA,
    .dstTransferSize = CY_DMA_TRANSFER_SIZE_WORD,
    .descriptorType  = CY_DMA_2D_TRANSFER,
    .srcAddress      = NULL,
    .dstAddress      = NULL,
    .srcXincrement   = 1L,
    .dstXincrement   = 0L,
    .xCount          = 256UL,
    .srcYincrement   = 256L,
    .dstYincrement   = 0L,
    .yCount          = 16UL,
    .nextDescriptor  = NULL
};

cy_stc_dma_descriptor_t UARTDMA_Descriptor_Analog2_Data =
{
    .ctl = 0UL,
    .src = 0UL,
    .dst = 0UL,
    .xCtl = 0UL,
    .yCtl = 0UL,
    .nextPtr = 0UL
};

const cy_stc_dma_descriptor_config_t UARTDMA_Descriptor_Analog2_Command_config =
{
    .retrigger       = CY_DMA_RETRIG_IM,
    .interruptType   = CY_DMA_DESCR_CHAIN,
    .triggerOutType  = CY_DMA_DESCR_CHAIN,
    .channelState    = CY_DMA_CHANNEL_ENABLED,
    .triggerInType   = CY_DMA_1ELEMENT,
    .dataSize        = CY_DMA_BYTE,
    .srcTransferSize = CY_DMA_TRANSFER_SIZE_DATA,
    .dstTransferSize = CY_DMA_TRANSFER_SIZE_WORD,
    .descriptorType  = CY_DMA_1D_TRANSFER,
    .srcAddress      = NULL,
    .dstAddress      = NULL,
    .srcXincrement   = 1L,
    .dstXincrement   = 0L,
    .xCount          = 2UL,
    .srcYincrement   = 0L,
    .dstYincrement   = 0L,
    .yCount          = 1UL,
    .nextDescriptor  = &UARTDMA_Descriptor_Analog2_Data
};

cy_stc_dma_descriptor_t UARTDMA_Descriptor_Analog2_Command =
{
    .ctl = 0UL,
    .src = 0UL,
    .dst = 0UL,
    .xCtl = 0UL,
    .yCtl = 0UL,
    .nextPtr = 0UL
};

const cy_stc_dma_descriptor_config_t UARTDMA_Descriptor_Analog3_Data_config =
{
    .retrigger       = CY_DMA_RETRIG_IM,
    .interruptType   = CY_DMA_DESCR,
    .triggerOutType  = CY_DMA_DESCR,
    .channelState    = CY_DMA_CHANNEL_ENABLED,
    .triggerInType   = CY_DMA_1ELEMENT,
    .dataSize        = CY_DMA_BYTE,
    .srcTransferSize = CY_DMA_TRANSFER_SIZE_DATA,
    .dstTransferSize = CY_DMA_TRANSFER_SIZE_WORD,
    .descriptorType  = CY_DMA_2D_TRANSFER,
    .srcAddress      = NULL,
    .dstAddress      = NULL,
    .srcXincrement   = 1L,
    .dstXincrement   = 0L,
    .xCount          = 256UL,
    .srcYincrement   = 256L,
    .dstYincrement   = 0L,
    .yCount          = 16UL,
    .nextDescriptor  = NULL
};

cy_stc_dma_descriptor_t UARTDMA_Descriptor_Analog3_Data =
{
    .ctl = 0UL,
    .src = 0UL,
    .dst = 0UL,
    .xCtl = 0UL,
    .yCtl = 0UL,
    .nextPtr = 0UL
};

const cy_stc_dma_descriptor_config_t UARTDMA_Descriptor_Analog3_Command_config =
{
    .retrigger       = CY_DMA_RETRIG_IM,
    .interruptType   = CY_DMA_DESCR_CHAIN,
    .triggerOutType  = CY_DMA_DESCR_CHAIN,
    .channelState    = CY_DMA_CHANNEL_ENABLED,
    .triggerInType   = CY_DMA_1ELEMENT,
    .dataSize        = CY_DMA_BYTE,
    .srcTransferSize = CY_DMA_TRANSFER_SIZE_DATA,
    .dstTransferSize = CY_DMA_TRANSFER_SIZE_WORD,
    .descriptorType  = CY_DMA_1D_TRANSFER,
    .srcAddress      = NULL,
    .dstAddress      = NULL,
    .srcXincrement   = 1L,
    .dstXincrement   = 0L,
    .xCount          = 2UL,
    .srcYincrement   = 0L,
    .dstYincrement   = 0L,
    .yCount          = 1UL,
    .nextDescriptor  = &UARTDMA_Descriptor_Analog3_Data
};

cy_stc_dma_descriptor_t UARTDMA_Descriptor_Analog3_Command =
{
    .ctl = 0UL,
    .src = 0UL,
    .dst = 0UL,
    .xCtl = 0UL,
    .yCtl = 0UL,
    .nextPtr = 0UL
};

const cy_stc_dma_descriptor_config_t UARTDMA_Descriptor_Accelero_Data_config =
{
    .retrigger       = CY_DMA_RETRIG_IM,
    .interruptType   = CY_DMA_DESCR,
    .triggerOutType  = CY_DMA_DESCR,
    .channelState    = CY_DMA_CHANNEL_ENABLED,
    .triggerInType   = CY_DMA_1ELEMENT,
    .dataSize        = CY_DMA_BYTE,
    .srcTransferSize = CY_DMA_TRANSFER_SIZE_DATA,
    .dstTransferSize = CY_DMA_TRANSFER_SIZE_WORD,
    .descriptorType  = CY_DMA_2D_TRANSFER,
    .srcAddress      = NULL,
    .dstAddress      = NULL,
    .srcXincrement   = 1L,
    .dstXincrement   = 0L,
    .xCount          = 256UL,
    .srcYincrement   = 256L,
    .dstYincrement   = 0L,
    .yCount          = 24UL,
    .nextDescriptor  = NULL
};

cy_stc_dma_descriptor_t UARTDMA_Descriptor_Accelero_Data =
{
    .ctl = 0UL,
    .src = 0UL,
    .dst = 0UL,
    .xCtl = 0UL,
    .yCtl = 0UL,
    .nextPtr = 0UL
};

const cy_stc_dma_descriptor_config_t UARTDMA_Descriptor_Accelero_Command_config =
{
    .retrigger       = CY_DMA_RETRIG_IM,
    .interruptType   = CY_DMA_DESCR_CHAIN,
    .triggerOutType  = CY_DMA_DESCR_CHAIN,
    .channelState    = CY_DMA_CHANNEL_ENABLED,
    .triggerInType   = CY_DMA_1ELEMENT,
    .dataSize        = CY_DMA_BYTE,
    .srcTransferSize = CY_DMA_TRANSFER_SIZE_DATA,
    .dstTransferSize = CY_DMA_TRANSFER_SIZE_WORD,
    .descriptorType  = CY_DMA_1D_TRANSFER,
    .srcAddress      = NULL,
    .dstAddress      = NULL,
    .srcXincrement   = 1L,
    .dstXincrement   = 0L,
    .xCount          = 2UL,
    .srcYincrement   = 0L,
    .dstYincrement   = 0L,
    .yCount          = 1UL,
    .nextDescriptor  = &UARTDMA_Descriptor_Accelero_Data
};

cy_stc_dma_descriptor_t UARTDMA_Descriptor_Accelero_Command =
{
    .ctl = 0UL,
    .src = 0UL,
    .dst = 0UL,
    .xCtl = 0UL,
    .yCtl = 0UL,
    .nextPtr = 0UL
};

const cy_stc_dma_descriptor_config_t UARTDMA_Descriptor_Temp_Data_config =
{
    .retrigger       = CY_DMA_RETRIG_IM,
    .interruptType   = CY_DMA_DESCR_CHAIN,
    .triggerOutType  = CY_DMA_DESCR_CHAIN,
    .channelState    = CY_DMA_CHANNEL_ENABLED,
    .triggerInType   = CY_DMA_1ELEMENT,
    .dataSize        = CY_DMA_BYTE,
    .srcTransferSize = CY_DMA_TRANSFER_SIZE_DATA,
    .dstTransferSize = CY_DMA_TRANSFER_SIZE_DATA,
    .descriptorType  = CY_DMA_1D_TRANSFER,
    .srcAddress      = NULL,
    .dstAddress      = NULL,
    .srcXincrement   = 1L,
    .dstXincrement   = 0L,
    .xCount          = 2UL,
    .srcYincrement   = 0L,
    .dstYincrement   = 0L,
    .yCount          = 1UL,
    .nextDescriptor  = &UARTDMA_Descriptor_Humid_Command
};

cy_stc_dma_descriptor_t UARTDMA_Descriptor_Temp_Data =
{
    .ctl = 0UL,
    .src = 0UL,
    .dst = 0UL,
    .xCtl = 0UL,
    .yCtl = 0UL,
    .nextPtr = 0UL
};

const cy_stc_dma_descriptor_config_t UARTDMA_Descriptor_Temp_Command_config =
{
    .retrigger       = CY_DMA_RETRIG_IM,
    .interruptType   = CY_DMA_DESCR_CHAIN,
    .triggerOutType  = CY_DMA_DESCR_CHAIN,
    .channelState    = CY_DMA_CHANNEL_ENABLED,
    .triggerInType   = CY_DMA_1ELEMENT,
    .dataSize        = CY_DMA_BYTE,
    .srcTransferSize = CY_DMA_TRANSFER_SIZE_DATA,
    .dstTransferSize = CY_DMA_TRANSFER_SIZE_DATA,
    .descriptorType  = CY_DMA_1D_TRANSFER,
    .srcAddress      = NULL,
    .dstAddress      = NULL,
    .srcXincrement   = 1L,
    .dstXincrement   = 0L,
    .xCount          = 2UL,
    .srcYincrement   = 0L,
    .dstYincrement   = 0L,
    .yCount          = 1UL,
    .nextDescriptor  = &UARTDMA_Descriptor_Temp_Command
};

cy_stc_dma_descriptor_t UARTDMA_Descriptor_Temp_Command =
{
    .ctl = 0UL,
    .src = 0UL,
    .dst = 0UL,
    .xCtl = 0UL,
    .yCtl = 0UL,
    .nextPtr = 0UL
};

const cy_stc_dma_descriptor_config_t UARTDMA_Descriptor_Humid_Data_config =
{
    .retrigger       = CY_DMA_RETRIG_IM,
    .interruptType   = CY_DMA_DESCR,
    .triggerOutType  = CY_DMA_DESCR,
    .channelState    = CY_DMA_CHANNEL_ENABLED,
    .triggerInType   = CY_DMA_1ELEMENT,
    .dataSize        = CY_DMA_BYTE,
    .srcTransferSize = CY_DMA_TRANSFER_SIZE_DATA,
    .dstTransferSize = CY_DMA_TRANSFER_SIZE_DATA,
    .descriptorType  = CY_DMA_1D_TRANSFER,
    .srcAddress      = NULL,
    .dstAddress      = NULL,
    .srcXincrement   = 1L,
    .dstXincrement   = 0L,
    .xCount          = 2UL,
    .srcYincrement   = 0L,
    .dstYincrement   = 0L,
    .yCount          = 1UL,
    .nextDescriptor  = NULL
};

cy_stc_dma_descriptor_t UARTDMA_Descriptor_Humid_Data =
{
    .ctl = 0UL,
    .src = 0UL,
    .dst = 0UL,
    .xCtl = 0UL,
    .yCtl = 0UL,
    .nextPtr = 0UL
};

const cy_stc_dma_descriptor_config_t UARTDMA_Descriptor_Humid_Command_config =
{
    .retrigger       = CY_DMA_RETRIG_IM,
    .interruptType   = CY_DMA_DESCR_CHAIN,
    .triggerOutType  = CY_DMA_DESCR_CHAIN,
    .channelState    = CY_DMA_CHANNEL_ENABLED,
    .triggerInType   = CY_DMA_1ELEMENT,
    .dataSize        = CY_DMA_BYTE,
    .srcTransferSize = CY_DMA_TRANSFER_SIZE_DATA,
    .dstTransferSize = CY_DMA_TRANSFER_SIZE_DATA,
    .descriptorType  = CY_DMA_1D_TRANSFER,
    .srcAddress      = NULL,
    .dstAddress      = NULL,
    .srcXincrement   = 1L,
    .dstXincrement   = 0L,
    .xCount          = 2UL,
    .srcYincrement   = 0L,
    .dstYincrement   = 0L,
    .yCount          = 1UL,
    .nextDescriptor  = &UARTDMA_Descriptor_Humid_Data
};

cy_stc_dma_descriptor_t UARTDMA_Descriptor_Humid_Command =
{
    .ctl = 0UL,
    .src = 0UL,
    .dst = 0UL,
    .xCtl = 0UL,
    .yCtl = 0UL,
    .nextPtr = 0UL
};


/** UARTDMA_initVar indicates whether the UARTDMA 
*  component has been initialized. The variable is initialized to 0 
*  and set to 1 the first time UARTDMA_Start() is called. This allows 
*  the component to restart without reinitialization after the first 
*  call to the UARTDMA_Start() routine.
*
*  If re-initialization of the component is required, then the 
*  UARTDMA_Init() function can be called before the 
*  UARTDMA_Start() or UARTDMA_ChEnable() function.
*/
uint8 UARTDMA_initVar = 0u;


/*******************************************************************************
* Function Name: UARTDMA_Start
****************************************************************************//**
*
* Based on the settings for descriptor in the customizer this function runs the
* DMA_Descriptor_Init() and then initializes the channel using
* DMA_Chnl_Init(). Enables the UARTDMA block using the DMA_Chnl_Enable().
*  
*******************************************************************************/
void UARTDMA_Start(void const * srcAddress, void const * dstAddress)
{
    if (0U == UARTDMA_initVar)
    {
        UARTDMA_Init();
        UARTDMA_initVar = 1u;
    }
    
    Cy_DMA_Descriptor_SetSrcAddress(&UARTDMA_Descriptor_Analog0_Data, srcAddress);
    Cy_DMA_Descriptor_SetDstAddress(&UARTDMA_Descriptor_Analog0_Data, dstAddress);
    Cy_DMA_Channel_Enable(UARTDMA_HW, UARTDMA_DW_CHANNEL);
}


/*******************************************************************************
* Function Name: UARTDMA_Init
****************************************************************************//**
*
* Based on the settings for the descriptor in the customizer this function runs the
* DMA_Descriptor_Init() and then initializes the channel using
* DMA_Chnl_Init().
*  
*******************************************************************************/
void UARTDMA_Init(void)
{
    cy_stc_dma_channel_config_t channelConfig;

    /* Init all descriptors */
    (void)Cy_DMA_Descriptor_Init(&UARTDMA_Descriptor_Analog0_Data, &UARTDMA_Descriptor_Analog0_Data_config);
    (void)Cy_DMA_Descriptor_Init(&UARTDMA_Descriptor_Analog0_Command, &UARTDMA_Descriptor_Analog0_Command_config);
    (void)Cy_DMA_Descriptor_Init(&UARTDMA_Descriptor_Analog1_Data, &UARTDMA_Descriptor_Analog1_Data_config);
    (void)Cy_DMA_Descriptor_Init(&UARTDMA_Descriptor_Analog1_Command, &UARTDMA_Descriptor_Analog1_Command_config);
    (void)Cy_DMA_Descriptor_Init(&UARTDMA_Descriptor_Analog2_Data, &UARTDMA_Descriptor_Analog2_Data_config);
    (void)Cy_DMA_Descriptor_Init(&UARTDMA_Descriptor_Analog2_Command, &UARTDMA_Descriptor_Analog2_Command_config);
    (void)Cy_DMA_Descriptor_Init(&UARTDMA_Descriptor_Analog3_Data, &UARTDMA_Descriptor_Analog3_Data_config);
    (void)Cy_DMA_Descriptor_Init(&UARTDMA_Descriptor_Analog3_Command, &UARTDMA_Descriptor_Analog3_Command_config);
    (void)Cy_DMA_Descriptor_Init(&UARTDMA_Descriptor_Accelero_Data, &UARTDMA_Descriptor_Accelero_Data_config);
    (void)Cy_DMA_Descriptor_Init(&UARTDMA_Descriptor_Accelero_Command, &UARTDMA_Descriptor_Accelero_Command_config);
    (void)Cy_DMA_Descriptor_Init(&UARTDMA_Descriptor_Temp_Data, &UARTDMA_Descriptor_Temp_Data_config);
    (void)Cy_DMA_Descriptor_Init(&UARTDMA_Descriptor_Temp_Command, &UARTDMA_Descriptor_Temp_Command_config);
    (void)Cy_DMA_Descriptor_Init(&UARTDMA_Descriptor_Humid_Data, &UARTDMA_Descriptor_Humid_Data_config);
    (void)Cy_DMA_Descriptor_Init(&UARTDMA_Descriptor_Humid_Command, &UARTDMA_Descriptor_Humid_Command_config);


    channelConfig.descriptor  = &UARTDMA_Descriptor_Analog0_Data;
    channelConfig.preemptable = UARTDMA_PREEMPTABLE;
    channelConfig.priority    = UARTDMA_PRIORITY;
    channelConfig.enable      = false;
    channelConfig.bufferable  = UARTDMA_BUFFERABLE;

    (void)Cy_DMA_Channel_Init(UARTDMA_HW, UARTDMA_DW_CHANNEL, &channelConfig);

    Cy_DMA_Enable(UARTDMA_HW);
}


#if defined(__cplusplus)
}
#endif

/* [] END OF FILE */
