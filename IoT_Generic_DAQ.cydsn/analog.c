/*  ____  ____      _    __  __  ____ ___
 * |  _ \|  _ \    / \  |  \/  |/ ___/ _ \
 * | | | | |_) |  / _ \ | |\/| | |  | | | |
 * | |_| |  _ <  / ___ \| |  | | |__| |_| |
 * |____/|_| \_\/_/   \_\_|  |_|\____\___/
 *                           research group
 *                             dramco.be/
 *
 *  KU Leuven - Technology Campus Gent,
 *  Gebroeders De Smetstraat 1,
 *  B-9000 Gent, Belgium
 *
 *         File: analog.c
 *      Created: 2019-04-11
 *       Author: Stijn Crul
 *      Version: 0.1
 *
 *  Description: ADC library for reading the ADC on a PSOC 6 development kit using an RTOS task
 */

#include "analog.h"
#include "FreeRTOS.h"
#include "task.h"

/*
* Name: initADC
* Description: Initialize ADC things
*
* Arguments:    none
* Output:       none
*/
void initADC(){
    ADC_Start();
    ADC_IRQ_Enable();
    Cy_TCPWM_Counter_Init(T0_HW, T0_CNT_NUM, &T0_config);
    Cy_TCPWM_Enable_Multiple(T0_HW, T0_CNT_MASK);
    Cy_TCPWM_Counter_Init(T1_HW, T1_CNT_NUM, &T1_config);
    Cy_TCPWM_Enable_Multiple(T1_HW, T1_CNT_MASK);
    Cy_TCPWM_Counter_Init(T2_HW, T2_CNT_NUM, &T2_config);
    Cy_TCPWM_Enable_Multiple(T2_HW, T2_CNT_MASK);
    Cy_TCPWM_Counter_Init(T3_HW, T3_CNT_NUM, &T3_config);
    Cy_TCPWM_Enable_Multiple(T3_HW, T3_CNT_MASK);
    Cy_TCPWM_Counter_Init(ADCSOCCounter_HW, ADCSOCCounter_CNT_NUM, &ADCSOCCounter_config);
    Cy_TCPWM_Enable_Multiple(ADCSOCCounter_HW, ADCSOCCounter_CNT_MASK);
    bufferADC0[0] = 0x7A7A;
    bufferADC1[0] = 0x7979;
    bufferADC2[0] = 0x7878;
    bufferADC3[0] = 0x7777;
}

/* 
* Name: ADCTask
* Description: create a task where the data from the ADC (single shot triggered by the RTOS task (similar to a free running mode)) is processed 
*
* Arguments:    none
* Output:       none
*/
void ADCTask(){
    // Variables for creating a periodic function using delayUntil
    TickType_t xLastWakeTime ;
    const TickType_t xFrequency = 100000;
    
    int16_t newReading = 0;

    ADC_StartConvert();

    xLastWakeTime = xTaskGetTickCount();    
    for(;;){
        // Wait for the next cycle determined by xFrequency
        vTaskDelayUntil(&xLastWakeTime, xFrequency);
        if(dataReady != 0){
            dataReady = 0;
            newReading = result;
            // todo: Process newReading
        }
    }
}

/* 
* Name: ADCSampleTask
* Description: create a task where the data from the ADC is sampled by the RTOS, set timing and a pin for measurements
*
* Arguments:    CH pvChannel (with pvChannel->port pvChannel->pin, pvChannel->timing, pvChannel->channel)
* Output:       none
*/
void ADCSampleTask(void * pvChannel){
    CH *pxChannel = (CH*) pvChannel;
    
    // Variables for creating a periodic function using delayUntil
    TickType_t xLastWakeTime ;
    const TickType_t xFrequency = pxChannel->timing;
    
    GPIO_PRT_Type* port = pxChannel->port;
    unsigned int pin = pxChannel->pin;
    uint8_t channel = pxChannel->channel; 
    
    // Start task as specific tick times
    switch(channel){
            case(0):        vTaskDelay(0);
                            break;
            case(1):        vTaskDelay(25000);
                            break;
            case(2):        vTaskDelay(50000);
                            break;
            case(3):        vTaskDelay(75000);
                            break;
            default:        break;
        }
    
    xLastWakeTime = xTaskGetTickCount();    
    for(;;){
        // Wait for the next cycle determined by xFrequency
        vTaskDelayUntil(&xLastWakeTime, xFrequency);
        switch(channel){
            case(0):        Cy_TCPWM_TriggerStart(T0_HW, T0_CNT_MASK);
                            break;
            case(1):        Cy_TCPWM_TriggerStart(T1_HW, T1_CNT_MASK);
                            break;
            case(2):        Cy_TCPWM_TriggerStart(T2_HW, T2_CNT_MASK);
                            break;
            case(3):        Cy_TCPWM_TriggerStart(T3_HW, T3_CNT_MASK);
                            break;
            default:        break;
        }
        
        
    }
}

/* 
* Name: configureDMA0
* Description: Initialize DMA0
*
* Arguments:    none
* Output:       none
*/
void configureDMA0(){
    cy_en_dma_status_t dma_init_status;
	cy_stc_dma_channel_config_t channelConfig;	
    
    // Initialize descriptor 1
    dma_init_status = Cy_DMA_Descriptor_Init(&ADCDMA_0_Descriptor_1, &ADCDMA_0_Descriptor_1_config);
	if(dma_init_status!=CY_DMA_SUCCESS){
        handle_error();
    }
    
    // Initialize the DMA channel 
    channelConfig.descriptor  = &ADCDMA_0_Descriptor_1;
    channelConfig.preemptable = ADCDMA_0_PREEMPTABLE;
    channelConfig.priority    = ADCDMA_0_PRIORITY;
    channelConfig.enable      = false;
    dma_init_status = Cy_DMA_Channel_Init(ADCDMA_0_HW, ADCDMA_0_DW_CHANNEL, &channelConfig);
	if(dma_init_status!=CY_DMA_SUCCESS){
        handle_error();
    }
    
    // Set source and destination address for DMA transfer
    Cy_DMA_Descriptor_SetSrcAddress(&ADCDMA_0_Descriptor_1, (void *) 0x411D0180); // hardcoded sar adc result register: do something better
    Cy_DMA_Descriptor_SetDstAddress(&ADCDMA_0_Descriptor_1, &bufferADC0[2]);
    
    // Enable DMA interrupt
    Cy_SysInt_Init(&ADC_DMA_INT_0_cfg, &ADCDMA0Complete);
    NVIC_EnableIRQ(ADC_DMA_INT_0_cfg.intrSrc);
    Cy_DMA_Channel_SetInterruptMask(ADCDMA_0_HW, ADCDMA_0_DW_CHANNEL, CY_DMA_INTR_MASK);
    
    Cy_DMA_Channel_Enable(ADCDMA_0_HW, ADCDMA_0_DW_CHANNEL);
    Cy_DMA_Enable(ADCDMA_0_HW);

}

/* 
* Name: ADCDMA0Complete
* Description: ISR for DMA0
*
* Arguments:    none
* Output:       none
*/
void ADCDMA0Complete(){
    Cy_DMA_Channel_ClearInterrupt(ADCDMA_0_HW, ADCDMA_0_DW_CHANNEL);
    // Stop timer for sampling
    Cy_TCPWM_TriggerStopOrKill(T0_HW, T0_CNT_MASK);
    // Select descriptor
    selectUARTDMADescriptors(ADC0);
}

/* 
* Name: configureDMA1
* Description: Initialize DMA1
*
* Arguments:    none
* Output:       none
*/
void configureDMA1(){
    cy_en_dma_status_t dma_init_status;
	cy_stc_dma_channel_config_t channelConfig;	
    
    // Initialize descriptor 1
    dma_init_status = Cy_DMA_Descriptor_Init(&ADCDMA_1_Descriptor_1, &ADCDMA_1_Descriptor_1_config);
	if(dma_init_status!=CY_DMA_SUCCESS){
        handle_error();
    }
    
    // Initialize the DMA channel 
    channelConfig.descriptor  = &ADCDMA_1_Descriptor_1;
    channelConfig.preemptable = ADCDMA_1_PREEMPTABLE;
    channelConfig.priority    = ADCDMA_1_PRIORITY;
    channelConfig.enable      = false;
    dma_init_status = Cy_DMA_Channel_Init(ADCDMA_1_HW, ADCDMA_1_DW_CHANNEL, &channelConfig);
	if(dma_init_status!=CY_DMA_SUCCESS){
        handle_error();
    }
    
    // Set source and destination address for DMA transfer
    Cy_DMA_Descriptor_SetSrcAddress(&ADCDMA_1_Descriptor_1, (void *) 0x411D0180); // hardcoded sar adc result register: do something better
    Cy_DMA_Descriptor_SetDstAddress(&ADCDMA_1_Descriptor_1, &bufferADC1[2]);
    
    // Enable DMA interrupt
    Cy_SysInt_Init(&ADC_DMA_INT_1_cfg, &ADCDMA1Complete);
    NVIC_EnableIRQ(ADC_DMA_INT_1_cfg.intrSrc);
    Cy_DMA_Channel_SetInterruptMask(ADCDMA_1_HW, ADCDMA_1_DW_CHANNEL, CY_DMA_INTR_MASK);
    
    Cy_DMA_Channel_Enable(ADCDMA_1_HW, ADCDMA_1_DW_CHANNEL);
    Cy_DMA_Enable(ADCDMA_1_HW);

}

/* 
* Name: ADCDMA1Complete
* Description: ISR for DMA1
*
* Arguments:    none
* Output:       none
*/
void ADCDMA1Complete(){
    Cy_DMA_Channel_ClearInterrupt(ADCDMA_1_HW, ADCDMA_1_DW_CHANNEL);
    //Do something one DMA is full
    Cy_TCPWM_TriggerStopOrKill(T1_HW, T1_CNT_MASK);
    // Select descriptor
    selectUARTDMADescriptors(ADC1);
}

/* 
* Name: configureDMA2
* Description: Initialize DMA2
*
* Arguments:    none
* Output:       none
*/
void configureDMA2(){
    cy_en_dma_status_t dma_init_status;
	cy_stc_dma_channel_config_t channelConfig;	
    
    // Initialize descriptor 1
    dma_init_status = Cy_DMA_Descriptor_Init(&ADCDMA_2_Descriptor_1, &ADCDMA_2_Descriptor_1_config);
	if(dma_init_status!=CY_DMA_SUCCESS){
        handle_error();
    }
    
    // Initialize the DMA channel 
    channelConfig.descriptor  = &ADCDMA_2_Descriptor_1;
    channelConfig.preemptable = ADCDMA_2_PREEMPTABLE;
    channelConfig.priority    = ADCDMA_2_PRIORITY;
    channelConfig.enable      = false;
    dma_init_status = Cy_DMA_Channel_Init(ADCDMA_2_HW, ADCDMA_2_DW_CHANNEL, &channelConfig);
	if(dma_init_status!=CY_DMA_SUCCESS){
        handle_error();
    }
    
    // Set source and destination address for DMA transfer
    Cy_DMA_Descriptor_SetSrcAddress(&ADCDMA_2_Descriptor_1, (void *) 0x411D0180); // hardcoded sar adc result register: do something better
    Cy_DMA_Descriptor_SetDstAddress(&ADCDMA_2_Descriptor_1, &bufferADC2[2]);
    
    // Enable DMA interrupt
    Cy_SysInt_Init(&ADC_DMA_INT_2_cfg, &ADCDMA2Complete);
    NVIC_EnableIRQ(ADC_DMA_INT_2_cfg.intrSrc);
    Cy_DMA_Channel_SetInterruptMask(ADCDMA_2_HW, ADCDMA_2_DW_CHANNEL, CY_DMA_INTR_MASK);
    
    Cy_DMA_Channel_Enable(ADCDMA_2_HW, ADCDMA_2_DW_CHANNEL);
    Cy_DMA_Enable(ADCDMA_2_HW);

}

/* 
* Name: ADCDMA2Complete
* Description: ISR for DMA2
*
* Arguments:    none
* Output:       none
*/
void ADCDMA2Complete(){
    Cy_DMA_Channel_ClearInterrupt(ADCDMA_2_HW, ADCDMA_2_DW_CHANNEL);
    //Do something one DMA is full
    Cy_TCPWM_TriggerStopOrKill(T2_HW, T2_CNT_MASK);
    // Select descriptor
    selectUARTDMADescriptors(ADC2);
}

/* 
* Name: configureDMA3
* Description: Initialize DMA3
*
* Arguments:    none
* Output:       none
*/
void configureDMA3(){
    cy_en_dma_status_t dma_init_status;
	cy_stc_dma_channel_config_t channelConfig;	
    
    // Initialize descriptor 1
    dma_init_status = Cy_DMA_Descriptor_Init(&ADCDMA_3_Descriptor_1, &ADCDMA_3_Descriptor_1_config);
	if(dma_init_status!=CY_DMA_SUCCESS){
        handle_error();
    }
    
    // Initialize the DMA channel 
    channelConfig.descriptor  = &ADCDMA_3_Descriptor_1;
    channelConfig.preemptable = ADCDMA_3_PREEMPTABLE;
    channelConfig.priority    = ADCDMA_3_PRIORITY;
    channelConfig.enable      = false;
    dma_init_status = Cy_DMA_Channel_Init(ADCDMA_3_HW, ADCDMA_3_DW_CHANNEL, &channelConfig);
	if(dma_init_status!=CY_DMA_SUCCESS){
        handle_error();
    }
    
    // Set source and destination address for DMA transfer
    Cy_DMA_Descriptor_SetSrcAddress(&ADCDMA_3_Descriptor_1, (void *) 0x411D0180); // hardcoded sar adc result register: do something better
    Cy_DMA_Descriptor_SetDstAddress(&ADCDMA_3_Descriptor_1, &bufferADC3[2]);
    
    // Enable DMA interrupt
    Cy_SysInt_Init(&ADC_DMA_INT_3_cfg, &ADCDMA3Complete);
    NVIC_EnableIRQ(ADC_DMA_INT_3_cfg.intrSrc);
    Cy_DMA_Channel_SetInterruptMask(ADCDMA_3_HW, ADCDMA_3_DW_CHANNEL, CY_DMA_INTR_MASK);
    
    Cy_DMA_Channel_Enable(ADCDMA_3_HW, ADCDMA_3_DW_CHANNEL);
    Cy_DMA_Enable(ADCDMA_3_HW);

}

/* 
* Name: ADCDMA3Complete
* Description: ISR for DMA3
*
* Arguments:    none
* Output:       none
*/
void ADCDMA3Complete(){
    Cy_DMA_Channel_ClearInterrupt(ADCDMA_3_HW, ADCDMA_3_DW_CHANNEL);
    //Do something one DMA is full
    Cy_TCPWM_TriggerStopOrKill(T3_HW, T3_CNT_MASK);
    // Select descriptor
    selectUARTDMADescriptors(ADC3);
}

/* 
* Name: handle_error
* Description: Disables interrupts and halts the CPU when an error occurs. Todo: do something better
*
* Arguments:    none
* Output:       none
*/
void handle_error(void){    
     // Disable all interrupts
    __disable_irq();
	
    // Do something better
    while(1u) {}
}

/* 
* Name: ADC_ISR_Callback
* Description: ISR for when the ADC is running in free running mode
*
* Arguments:    none
* Output:       none
*/
void ADC_ISR_Callback(void){
    // Unused as DMA deals with results.
}

    