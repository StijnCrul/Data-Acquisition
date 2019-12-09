 /* ____  ____      _    __  __  ____ ___
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
 *         File: serial.c
 *      Created: 2019-04-11
 *       Author: Stijn Crul
 *      Version: 0.1
 *
 *  Description: UART library for sending messages on a PSOC 6 development kit using an RTOS task
 */    

#include "serial.h"
#include "FreeRTOS.h"
#include "task.h"
#include "i2c.h"

/* 
* Name: UARTTask
* Description: UART RTOS tasks that prints something at a set interval of time
*
* Arguments:    none
* Output:       none
*/
void UARTTask(){
    TickType_t xLastWakeTime ;
    const TickType_t xFrequency = 10000;
    xLastWakeTime = xTaskGetTickCount();    
    for(;;){
        vTaskDelayUntil(&xLastWakeTime, xFrequency);
        printf("I am alive\r\n");
    }
}    


/*
* Name: selectUARTDMADescriptors
* Description: Once a sensor buffer has been filled, its DMA channel generates an interrupt. That specific ISR will call this function to set the corresponding dma descriptors to send the data via the uart. If a second interrupt is generated while the other descriptor is still busy, it should be queued.
* Hence, this function  is also called once a uart descriptor is also complete.
*
*/ 
void selectUARTDMADescriptors(int sensor){
    
    if(sending == false){
        switch(sensor){
            case NONE:      sending = false;
                            break;
            case ADC0:      Cy_DMA_Channel_SetDescriptor(UARTDMA_HW, UARTDMA_DW_CHANNEL, &UARTDMA_Descriptor_Analog0_Command);
    	                    Cy_DMA_Channel_Enable(UARTDMA_HW, UARTDMA_DW_CHANNEL);
                            sending = true;
                            break;
            case ADC1:      Cy_DMA_Channel_SetDescriptor(UARTDMA_HW, UARTDMA_DW_CHANNEL, &UARTDMA_Descriptor_Analog1_Command);
    	                    Cy_DMA_Channel_Enable(UARTDMA_HW, UARTDMA_DW_CHANNEL);
                            sending = true;
                            break;
            case ADC2:      Cy_DMA_Channel_SetDescriptor(UARTDMA_HW, UARTDMA_DW_CHANNEL, &UARTDMA_Descriptor_Analog2_Command);
    	                    Cy_DMA_Channel_Enable(UARTDMA_HW, UARTDMA_DW_CHANNEL);
                            sending = true;
                            break;
            case ADC3:      Cy_DMA_Channel_SetDescriptor(UARTDMA_HW, UARTDMA_DW_CHANNEL, &UARTDMA_Descriptor_Analog3_Command);
    	                    Cy_DMA_Channel_Enable(UARTDMA_HW, UARTDMA_DW_CHANNEL);
                            sending = true;
                            break;
            case ACCELERO:  Cy_DMA_Channel_SetDescriptor(UARTDMA_HW, UARTDMA_DW_CHANNEL, &UARTDMA_Descriptor_Accelero_Command);     // set descriptor to send i2c data
    	                    Cy_DMA_Channel_Enable(UARTDMA_HW, UARTDMA_DW_CHANNEL);
                            sending = true;
                            break;
            case RHT:       Cy_DMA_Channel_SetDescriptor(UARTDMA_HW, UARTDMA_DW_CHANNEL, &UARTDMA_Descriptor_Temp_Command);     // set descriptor to send i2c data
    	                    Cy_DMA_Channel_Enable(UARTDMA_HW, UARTDMA_DW_CHANNEL);
                            sending = true;
                            break;
            default:        handle_error();
                            break;
        }
    }
}


void configureUARTDMA(){
    cy_en_dma_status_t dma_init_status;
	cy_stc_dma_channel_config_t channelConfig;	
    
    // Initialize descriptors
    dma_init_status = Cy_DMA_Descriptor_Init(&UARTDMA_Descriptor_Analog0_Command, &UARTDMA_Descriptor_Analog0_Command_config);
	if(dma_init_status!=CY_DMA_SUCCESS){
        handle_error();
    }
    dma_init_status = Cy_DMA_Descriptor_Init(&UARTDMA_Descriptor_Analog0_Data, &UARTDMA_Descriptor_Analog0_Data_config);
	if(dma_init_status!=CY_DMA_SUCCESS){
        handle_error();
    }
    
    dma_init_status = Cy_DMA_Descriptor_Init(&UARTDMA_Descriptor_Analog1_Command, &UARTDMA_Descriptor_Analog1_Command_config);
	if(dma_init_status!=CY_DMA_SUCCESS){
        handle_error();
    }
    dma_init_status = Cy_DMA_Descriptor_Init(&UARTDMA_Descriptor_Analog1_Data, &UARTDMA_Descriptor_Analog1_Data_config);
	if(dma_init_status!=CY_DMA_SUCCESS){
        handle_error();
    }
    
    dma_init_status = Cy_DMA_Descriptor_Init(&UARTDMA_Descriptor_Analog2_Command, &UARTDMA_Descriptor_Analog2_Command_config);
	if(dma_init_status!=CY_DMA_SUCCESS){
        handle_error();
    }
    dma_init_status = Cy_DMA_Descriptor_Init(&UARTDMA_Descriptor_Analog2_Data, &UARTDMA_Descriptor_Analog2_Data_config);
	if(dma_init_status!=CY_DMA_SUCCESS){
        handle_error();
    }
    
    dma_init_status = Cy_DMA_Descriptor_Init(&UARTDMA_Descriptor_Analog3_Command, &UARTDMA_Descriptor_Analog3_Command_config);
	if(dma_init_status!=CY_DMA_SUCCESS){
        handle_error();
    }
    dma_init_status = Cy_DMA_Descriptor_Init(&UARTDMA_Descriptor_Analog3_Data, &UARTDMA_Descriptor_Analog3_Data_config);
	if(dma_init_status!=CY_DMA_SUCCESS){
        handle_error();
    }
    // Initialize descriptor accelero
    dma_init_status = Cy_DMA_Descriptor_Init(&UARTDMA_Descriptor_Accelero_Command, &UARTDMA_Descriptor_Accelero_Command_config);
	if(dma_init_status!=CY_DMA_SUCCESS){
        handle_error();
    }
    // Initialize descriptor accelero
    dma_init_status = Cy_DMA_Descriptor_Init(&UARTDMA_Descriptor_Accelero_Data, &UARTDMA_Descriptor_Accelero_Data_config);
	if(dma_init_status!=CY_DMA_SUCCESS){
        handle_error();
    }
    // Initialize descriptor temp
    dma_init_status = Cy_DMA_Descriptor_Init(&UARTDMA_Descriptor_Temp_Command, &UARTDMA_Descriptor_Temp_Command_config);
	if(dma_init_status!=CY_DMA_SUCCESS){
        handle_error();
    }
    // Initialize descriptor temp
    dma_init_status = Cy_DMA_Descriptor_Init(&UARTDMA_Descriptor_Temp_Data, &UARTDMA_Descriptor_Temp_Data_config);
	if(dma_init_status!=CY_DMA_SUCCESS){
        handle_error();
    }
    // Initialize descriptor humid
    dma_init_status = Cy_DMA_Descriptor_Init(&UARTDMA_Descriptor_Humid_Command, &UARTDMA_Descriptor_Humid_Command_config);
	if(dma_init_status!=CY_DMA_SUCCESS){
        handle_error();
    }
    // Initialize descriptor humid
    dma_init_status = Cy_DMA_Descriptor_Init(&UARTDMA_Descriptor_Humid_Data, &UARTDMA_Descriptor_Humid_Data_config);
	if(dma_init_status!=CY_DMA_SUCCESS){
        handle_error();
    }
    
    // Initialize the DMA channel 
    channelConfig.descriptor  = &UARTDMA_Descriptor_Analog0_Command;
    channelConfig.preemptable = UARTDMA_PREEMPTABLE;
    channelConfig.priority    = UARTDMA_PRIORITY;
    channelConfig.enable      = false;
    dma_init_status = Cy_DMA_Channel_Init(UARTDMA_HW, UARTDMA_DW_CHANNEL, &channelConfig);
	if(dma_init_status!=CY_DMA_SUCCESS){
        handle_error();
    }
    
    // Set source and destination address for DMA transfer
    Cy_DMA_Descriptor_SetSrcAddress(&UARTDMA_Descriptor_Analog0_Command, &bufferADC0[0]); //hardcoded buffer for now (make it work?)
    Cy_DMA_Descriptor_SetDstAddress(&UARTDMA_Descriptor_Analog0_Command, (uint32_t *) &UART_HW->TX_FIFO_WR);
    
    Cy_DMA_Descriptor_SetSrcAddress(&UARTDMA_Descriptor_Analog0_Data, &bufferADC0[2]); //hardcoded buffer for now (make it work?)
    Cy_DMA_Descriptor_SetDstAddress(&UARTDMA_Descriptor_Analog0_Data, (uint32_t *) &UART_HW->TX_FIFO_WR);
    
    Cy_DMA_Descriptor_SetSrcAddress(&UARTDMA_Descriptor_Analog1_Command, &bufferADC1[0]); //hardcoded buffer for now (make it work?)
    Cy_DMA_Descriptor_SetDstAddress(&UARTDMA_Descriptor_Analog1_Command, (uint32_t *) &UART_HW->TX_FIFO_WR);
    
    Cy_DMA_Descriptor_SetSrcAddress(&UARTDMA_Descriptor_Analog1_Data, &bufferADC1[2]); //hardcoded buffer for now (make it work?)
    Cy_DMA_Descriptor_SetDstAddress(&UARTDMA_Descriptor_Analog1_Data, (uint32_t *) &UART_HW->TX_FIFO_WR);
    
    Cy_DMA_Descriptor_SetSrcAddress(&UARTDMA_Descriptor_Analog2_Command, &bufferADC2[0]); //hardcoded buffer for now (make it work?)
    Cy_DMA_Descriptor_SetDstAddress(&UARTDMA_Descriptor_Analog2_Command, (uint32_t *) &UART_HW->TX_FIFO_WR);
    
    Cy_DMA_Descriptor_SetSrcAddress(&UARTDMA_Descriptor_Analog2_Data, &bufferADC2[2]); //hardcoded buffer for now (make it work?)
    Cy_DMA_Descriptor_SetDstAddress(&UARTDMA_Descriptor_Analog2_Data, (uint32_t *) &UART_HW->TX_FIFO_WR);
    
    Cy_DMA_Descriptor_SetSrcAddress(&UARTDMA_Descriptor_Analog3_Command, &bufferADC3[0]); //hardcoded buffer for now (make it work?)
    Cy_DMA_Descriptor_SetDstAddress(&UARTDMA_Descriptor_Analog3_Command, (uint32_t *) &UART_HW->TX_FIFO_WR);
    
    Cy_DMA_Descriptor_SetSrcAddress(&UARTDMA_Descriptor_Analog3_Data, &bufferADC3[2]); //hardcoded buffer for now (make it work?)
    Cy_DMA_Descriptor_SetDstAddress(&UARTDMA_Descriptor_Analog3_Data, (uint32_t *) &UART_HW->TX_FIFO_WR);
    
    Cy_DMA_Descriptor_SetSrcAddress(&UARTDMA_Descriptor_Accelero_Command, &bufferAccelero[0]); //hardcoded buffer
    Cy_DMA_Descriptor_SetDstAddress(&UARTDMA_Descriptor_Accelero_Command, (uint32_t *) &UART_HW->TX_FIFO_WR);
    
    Cy_DMA_Descriptor_SetSrcAddress(&UARTDMA_Descriptor_Accelero_Data, &bufferAccelero[2]); //hardcoded buffer
    Cy_DMA_Descriptor_SetDstAddress(&UARTDMA_Descriptor_Accelero_Data, (uint32_t *) &UART_HW->TX_FIFO_WR);
    
    Cy_DMA_Descriptor_SetSrcAddress(&UARTDMA_Descriptor_Temp_Command, &bufferTemp[0]); //hardcoded buffer
    Cy_DMA_Descriptor_SetDstAddress(&UARTDMA_Descriptor_Temp_Command, (uint32_t *) &UART_HW->TX_FIFO_WR);
    
    Cy_DMA_Descriptor_SetSrcAddress(&UARTDMA_Descriptor_Temp_Data, &bufferTemp[2]); //hardcoded buffer
    Cy_DMA_Descriptor_SetDstAddress(&UARTDMA_Descriptor_Temp_Data, (uint32_t *) &UART_HW->TX_FIFO_WR);
    
    Cy_DMA_Descriptor_SetSrcAddress(&UARTDMA_Descriptor_Humid_Command, &bufferHumid[0]); //hardcoded buffer
    Cy_DMA_Descriptor_SetDstAddress(&UARTDMA_Descriptor_Humid_Command, (uint32_t *) &UART_HW->TX_FIFO_WR);
    
    Cy_DMA_Descriptor_SetSrcAddress(&UARTDMA_Descriptor_Humid_Data, &bufferHumid[2]); //hardcoded buffer
    Cy_DMA_Descriptor_SetDstAddress(&UARTDMA_Descriptor_Humid_Data, (uint32_t *) &UART_HW->TX_FIFO_WR);
    
    // Enable DMA interrupt
    Cy_SysInt_Init(&UART_DMA_INT_cfg, &UARTDMAComplete);
    NVIC_EnableIRQ(UART_DMA_INT_cfg.intrSrc);
    Cy_DMA_Channel_SetInterruptMask(UARTDMA_HW, UARTDMA_DW_CHANNEL, CY_DMA_INTR_MASK);
    
    Cy_DMA_Channel_Enable(UARTDMA_HW, UARTDMA_DW_CHANNEL);
    Cy_DMA_Enable(UARTDMA_HW);

}

void UARTDMAComplete(){
    Cy_DMA_Channel_ClearInterrupt(UARTDMA_HW, UARTDMA_DW_CHANNEL);
    sending = false;
    selectUARTDMADescriptors(NONE);
}

/* 
* Name: handle_error
* Description: Disables interrupts and halts the CPU when an error occurs. Todo: do something better
*
* Arguments:    none
* Output:       none
*/
void handle_serial_error(void){    
     // Disable all interrupts
    __disable_irq();
	
    // Do something better
    while(1u) {}
}