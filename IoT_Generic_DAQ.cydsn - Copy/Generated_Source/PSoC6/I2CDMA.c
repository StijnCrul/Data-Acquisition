/***************************************************************************//**
* \file I2CDMA.c
* \version 2.0
*
*  This file provides the source code to the API for the
*  I2CDMA component.
*
********************************************************************************
* \copyright
* Copyright 2016-2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "I2CDMA.h"

#if defined(__cplusplus)
extern "C" {
#endif

/* Generated code */
const cy_stc_dma_descriptor_config_t I2CDMA_Descriptor_Accel1_config =
{
    .retrigger       = CY_DMA_RETRIG_IM,
    .interruptType   = CY_DMA_DESCR_CHAIN,
    .triggerOutType  = CY_DMA_DESCR_CHAIN,
    .channelState    = CY_DMA_CHANNEL_ENABLED,
    .triggerInType   = CY_DMA_X_LOOP,
    .dataSize        = CY_DMA_BYTE,
    .srcTransferSize = CY_DMA_TRANSFER_SIZE_DATA,
    .dstTransferSize = CY_DMA_TRANSFER_SIZE_DATA,
    .descriptorType  = CY_DMA_2D_TRANSFER,
    .srcAddress      = NULL,
    .dstAddress      = NULL,
    .srcXincrement   = 1L,
    .dstXincrement   = 1L,
    .xCount          = 6UL,
    .srcYincrement   = 0L,
    .dstYincrement   = 6L,
    .yCount          = 256UL,
    .nextDescriptor  = &I2CDMA_Descriptor_Accel2
};

cy_stc_dma_descriptor_t I2CDMA_Descriptor_Accel1 =
{
    .ctl = 0UL,
    .src = 0UL,
    .dst = 0UL,
    .xCtl = 0UL,
    .yCtl = 0UL,
    .nextPtr = 0UL
};

const cy_stc_dma_descriptor_config_t I2CDMA_Descriptor_Accel2_config =
{
    .retrigger       = CY_DMA_RETRIG_IM,
    .interruptType   = CY_DMA_DESCR_CHAIN,
    .triggerOutType  = CY_DMA_DESCR_CHAIN,
    .channelState    = CY_DMA_CHANNEL_ENABLED,
    .triggerInType   = CY_DMA_X_LOOP,
    .dataSize        = CY_DMA_BYTE,
    .srcTransferSize = CY_DMA_TRANSFER_SIZE_DATA,
    .dstTransferSize = CY_DMA_TRANSFER_SIZE_DATA,
    .descriptorType  = CY_DMA_2D_TRANSFER,
    .srcAddress      = NULL,
    .dstAddress      = NULL,
    .srcXincrement   = 1L,
    .dstXincrement   = 1L,
    .xCount          = 6UL,
    .srcYincrement   = 0L,
    .dstYincrement   = 6L,
    .yCount          = 256UL,
    .nextDescriptor  = &I2CDMA_Descriptor_Accel3
};

cy_stc_dma_descriptor_t I2CDMA_Descriptor_Accel2 =
{
    .ctl = 0UL,
    .src = 0UL,
    .dst = 0UL,
    .xCtl = 0UL,
    .yCtl = 0UL,
    .nextPtr = 0UL
};

const cy_stc_dma_descriptor_config_t I2CDMA_Descriptor_Accel3_config =
{
    .retrigger       = CY_DMA_RETRIG_IM,
    .interruptType   = CY_DMA_DESCR_CHAIN,
    .triggerOutType  = CY_DMA_DESCR_CHAIN,
    .channelState    = CY_DMA_CHANNEL_ENABLED,
    .triggerInType   = CY_DMA_X_LOOP,
    .dataSize        = CY_DMA_BYTE,
    .srcTransferSize = CY_DMA_TRANSFER_SIZE_DATA,
    .dstTransferSize = CY_DMA_TRANSFER_SIZE_DATA,
    .descriptorType  = CY_DMA_2D_TRANSFER,
    .srcAddress      = NULL,
    .dstAddress      = NULL,
    .srcXincrement   = 1L,
    .dstXincrement   = 1L,
    .xCount          = 6UL,
    .srcYincrement   = 0L,
    .dstYincrement   = 6L,
    .yCount          = 256UL,
    .nextDescriptor  = &I2CDMA_Descriptor_Accel4
};

cy_stc_dma_descriptor_t I2CDMA_Descriptor_Accel3 =
{
    .ctl = 0UL,
    .src = 0UL,
    .dst = 0UL,
    .xCtl = 0UL,
    .yCtl = 0UL,
    .nextPtr = 0UL
};

const cy_stc_dma_descriptor_config_t I2CDMA_Descriptor_Accel4_config =
{
    .retrigger       = CY_DMA_RETRIG_IM,
    .interruptType   = CY_DMA_DESCR,
    .triggerOutType  = CY_DMA_DESCR,
    .channelState    = CY_DMA_CHANNEL_ENABLED,
    .triggerInType   = CY_DMA_X_LOOP,
    .dataSize        = CY_DMA_BYTE,
    .srcTransferSize = CY_DMA_TRANSFER_SIZE_DATA,
    .dstTransferSize = CY_DMA_TRANSFER_SIZE_DATA,
    .descriptorType  = CY_DMA_2D_TRANSFER,
    .srcAddress      = NULL,
    .dstAddress      = NULL,
    .srcXincrement   = 1L,
    .dstXincrement   = 1L,
    .xCount          = 6UL,
    .srcYincrement   = 0L,
    .dstYincrement   = 6L,
    .yCount          = 256UL,
    .nextDescriptor  = &I2CDMA_Descriptor_Accel1
};

cy_stc_dma_descriptor_t I2CDMA_Descriptor_Accel4 =
{
    .ctl = 0UL,
    .src = 0UL,
    .dst = 0UL,
    .xCtl = 0UL,
    .yCtl = 0UL,
    .nextPtr = 0UL
};

const cy_stc_dma_descriptor_config_t I2CDMA_Descriptor_Temp_config =
{
    .retrigger       = CY_DMA_RETRIG_IM,
    .interruptType   = CY_DMA_DESCR_CHAIN,
    .triggerOutType  = CY_DMA_DESCR_CHAIN,
    .channelState    = CY_DMA_CHANNEL_ENABLED,
    .triggerInType   = CY_DMA_X_LOOP,
    .dataSize        = CY_DMA_BYTE,
    .srcTransferSize = CY_DMA_TRANSFER_SIZE_DATA,
    .dstTransferSize = CY_DMA_TRANSFER_SIZE_DATA,
    .descriptorType  = CY_DMA_1D_TRANSFER,
    .srcAddress      = NULL,
    .dstAddress      = NULL,
    .srcXincrement   = 1L,
    .dstXincrement   = 1L,
    .xCount          = 2UL,
    .srcYincrement   = 0L,
    .dstYincrement   = 2L,
    .yCount          = 1UL,
    .nextDescriptor  = &I2CDMA_Descriptor_Humid
};

cy_stc_dma_descriptor_t I2CDMA_Descriptor_Temp =
{
    .ctl = 0UL,
    .src = 0UL,
    .dst = 0UL,
    .xCtl = 0UL,
    .yCtl = 0UL,
    .nextPtr = 0UL
};

const cy_stc_dma_descriptor_config_t I2CDMA_Descriptor_Humid_config =
{
    .retrigger       = CY_DMA_RETRIG_IM,
    .interruptType   = CY_DMA_DESCR,
    .triggerOutType  = CY_DMA_DESCR,
    .channelState    = CY_DMA_CHANNEL_ENABLED,
    .triggerInType   = CY_DMA_X_LOOP,
    .dataSize        = CY_DMA_BYTE,
    .srcTransferSize = CY_DMA_TRANSFER_SIZE_DATA,
    .dstTransferSize = CY_DMA_TRANSFER_SIZE_DATA,
    .descriptorType  = CY_DMA_1D_TRANSFER,
    .srcAddress      = NULL,
    .dstAddress      = NULL,
    .srcXincrement   = 1L,
    .dstXincrement   = 1L,
    .xCount          = 2UL,
    .srcYincrement   = 0L,
    .dstYincrement   = 2L,
    .yCount          = 1UL,
    .nextDescriptor  = &I2CDMA_Descriptor_Temp
};

cy_stc_dma_descriptor_t I2CDMA_Descriptor_Humid =
{
    .ctl = 0UL,
    .src = 0UL,
    .dst = 0UL,
    .xCtl = 0UL,
    .yCtl = 0UL,
    .nextPtr = 0UL
};


/** I2CDMA_initVar indicates whether the I2CDMA 
*  component has been initialized. The variable is initialized to 0 
*  and set to 1 the first time I2CDMA_Start() is called. This allows 
*  the component to restart without reinitialization after the first 
*  call to the I2CDMA_Start() routine.
*
*  If re-initialization of the component is required, then the 
*  I2CDMA_Init() function can be called before the 
*  I2CDMA_Start() or I2CDMA_ChEnable() function.
*/
uint8 I2CDMA_initVar = 0u;


/*******************************************************************************
* Function Name: I2CDMA_Start
****************************************************************************//**
*
* Based on the settings for descriptor in the customizer this function runs the
* DMA_Descriptor_Init() and then initializes the channel using
* DMA_Chnl_Init(). Enables the I2CDMA block using the DMA_Chnl_Enable().
*  
*******************************************************************************/
void I2CDMA_Start(void const * srcAddress, void const * dstAddress)
{
    if (0U == I2CDMA_initVar)
    {
        I2CDMA_Init();
        I2CDMA_initVar = 1u;
    }
    
    Cy_DMA_Descriptor_SetSrcAddress(&I2CDMA_Descriptor_Accel1, srcAddress);
    Cy_DMA_Descriptor_SetDstAddress(&I2CDMA_Descriptor_Accel1, dstAddress);
    Cy_DMA_Channel_Enable(I2CDMA_HW, I2CDMA_DW_CHANNEL);
}


/*******************************************************************************
* Function Name: I2CDMA_Init
****************************************************************************//**
*
* Based on the settings for the descriptor in the customizer this function runs the
* DMA_Descriptor_Init() and then initializes the channel using
* DMA_Chnl_Init().
*  
*******************************************************************************/
void I2CDMA_Init(void)
{
    cy_stc_dma_channel_config_t channelConfig;

    /* Init all descriptors */
    (void)Cy_DMA_Descriptor_Init(&I2CDMA_Descriptor_Accel1, &I2CDMA_Descriptor_Accel1_config);
    (void)Cy_DMA_Descriptor_Init(&I2CDMA_Descriptor_Accel2, &I2CDMA_Descriptor_Accel2_config);
    (void)Cy_DMA_Descriptor_Init(&I2CDMA_Descriptor_Accel3, &I2CDMA_Descriptor_Accel3_config);
    (void)Cy_DMA_Descriptor_Init(&I2CDMA_Descriptor_Accel4, &I2CDMA_Descriptor_Accel4_config);
    (void)Cy_DMA_Descriptor_Init(&I2CDMA_Descriptor_Temp, &I2CDMA_Descriptor_Temp_config);
    (void)Cy_DMA_Descriptor_Init(&I2CDMA_Descriptor_Humid, &I2CDMA_Descriptor_Humid_config);


    channelConfig.descriptor  = &I2CDMA_Descriptor_Accel1;
    channelConfig.preemptable = I2CDMA_PREEMPTABLE;
    channelConfig.priority    = I2CDMA_PRIORITY;
    channelConfig.enable      = false;
    channelConfig.bufferable  = I2CDMA_BUFFERABLE;

    (void)Cy_DMA_Channel_Init(I2CDMA_HW, I2CDMA_DW_CHANNEL, &channelConfig);

    Cy_DMA_Enable(I2CDMA_HW);
}


#if defined(__cplusplus)
}
#endif

/* [] END OF FILE */
