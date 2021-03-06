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
 *         File: main_cm4.c
 *      Created: 2019-04-11
 *       Author: Stijn Crul
 *      Version: 0.1
 *
 *  Description: RTOS test project for testing various implementations of technologies. 
 *  Right now I2C, UART, ADC, Blink and RTOS tasks are implemented.
 */

#include "project.h"
#include <stdio.h>
#include "FreeRTOS.h"
#include "task.h"
#include "LSM303DLHC.h"
#include "wait.h"
#include "i2c.h"
#include "blink.h"
#include "analog.h"
#include "serial.h"
#include "stdio.h"
#include "Si7021.h"

// Some constants for fast testing
#define RED_PERIOD      10000
#define BLUE_PERIOD     25000
#define GREEN_PERIOD    50000
#define CHANNEL0_PERIOD 100000
#define CHANNEL1_PERIOD 100000
#define CHANNEL2_PERIOD 100000
#define CHANNEL3_PERIOD 100000

// Initialization of all RTOS tasks and variables
// Structs for is alive blink
static PIN pin0 = {RED_PIN_PORT, RED_PIN_NUM, RED_PERIOD};
static PIN pin1 = {BLUE_PIN_PORT, BLUE_PIN_NUM, BLUE_PERIOD};
static PIN pin2 = {GREEN_PIN_PORT, GREEN_PIN_NUM, GREEN_PERIOD};

// Structs for different ADC channels
static CH channel0 = {O_0_PORT, O_0_NUM, CHANNEL0_PERIOD, 0};
static CH channel1 = {O_1_PORT, O_1_NUM, CHANNEL1_PERIOD, 1};
static CH channel2 = {O_2_PORT, O_2_NUM, CHANNEL2_PERIOD, 2};
static CH channel3 = {O_3_PORT, O_3_NUM, CHANNEL3_PERIOD, 3};



// Structure for master transfer configuration
cy_stc_scb_i2c_master_xfer_config_t masterTransferCfg ={
    .slaveAddress = LSM303_ADDRESS_ACCEL,
    .buffer       = NULL,
    .bufferSize   = 0U,
    .xferPending  = false
};


int main(void){
    // Enable global interrupts
    __enable_irq(); 
    
    // Configure communication interfaces
    UART_Start();

    printf("I am alive\r\n");
    //initI2C();
    initADC();
    
    
    // Initialize DMA channels for the ADC
    configureDMA0();
    configureDMA1();
    configureDMA2();
    configureDMA3();
    configureUARTDMA();
    configureI2CDMA();
    
    initI2C();
    
    // Create all the tasks
    //xTaskCreate(BlinkTask, "BlinkTask1", 100, (void*) &pin0, 0, NULL);
    //xTaskCreate(BlinkTask, "BlinkTask2", 100, (void*) &pin1, 0, NULL);
    //xTaskCreate(BlinkTask, "BlinkTask3", 100, (void*) &pin2, 0, NULL);*/
    
    
    // Create tasks for analog channels. Reduce priority for lower speeds
    //xTaskCreate(ADCSampleTask, "ADCSampleTask0", 100, (void*) &channel0, 5, NULL);
    //xTaskCreate(ADCSampleTask, "ADCSampleTask1", 100, (void*) &channel1, 5, NULL);
    //xTaskCreate(ADCSampleTask, "ADCSampleTask2", 100, (void*) &channel2, 5, NULL);
    //xTaskCreate(ADCSampleTask, "ADCSampleTask3", 100, (void*) &channel3, 5, NULL);
    
    
    // Create tasks for digital sensors.
    //xTaskCreate(acceleroTask, "acceleroTask", 100, (void*) &masterTransferCfg, 6, NULL);
    xTaskCreate(Si7021Task, "Si7021Task", 100, (void*) &masterTransferCfg, 6, NULL);
    vTaskStartScheduler();
    
    for(;;);
}


/* [] END OF FILE */
