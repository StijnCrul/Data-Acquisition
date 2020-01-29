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
 *         File: Si7021.c
 *      Created: 2019-07-15
 *       Author: Stijn Crul
 *      Version: 0.1
 *
 *  Description: Si7021 library for PSOC6 including its I2C functions
 */

#include "project.h"
#include "Si7021.h"
#include "i2c.h"
#include "FreeRTOS.h"
#include "task.h"
#include "stdio.h"

/* 
* Name: initSI7021 
* Description: Setup up the Si7021 by resetting it
*
* Arguments:    cy_stc_scb_i2c_master_xfer_config_t masterTransferCfg = psoc I2C settings
* Output:       uint8_t status
*/
uint8_t initSI7021(cy_stc_scb_i2c_master_xfer_config_t masterTransferCfg){
    masterTransferCfg.slaveAddress = SI7021_DEFAULT_ADDRESS;
    uint8_t status = TRANSFER_ERROR; 
    uint8_t msg[WRITE_PACKET_SIZE] = {SI7021_RESET_CMD};
    
    status = WriteCommandPacketToI2C(masterTransferCfg, SI7021_DEFAULT_ADDRESS, msg, 1);
    CyDelay(50);
    
    // check if working
    msg[0] = SI7021_READRHT_REG_CMD;
    if(TRANSFER_CMPLT == WriteCommandPacketToI2C(masterTransferCfg, SI7021_DEFAULT_ADDRESS, msg, 1)){
        status = ReadStatusPacketFromI2C(masterTransferCfg, SI7021_DEFAULT_ADDRESS, 1);
        if(0x3A != ((uint16_t)readBuffer[0])){
            // todo, sensor not detected, fix
        }
    }
    
    // readSerialNumber
    readSerial(masterTransferCfg);
    
    // read revision
    
    return status;
}

/* 
* Function: readTemp  
* Description: Read values from Si7021 after it has been setup
*
* Arguments:  cy_stc_scb_i2c_master_xfer_config_t masterTransferCfg = psoc I2C settings
* Output:     uint8_t status
*/
uint8_t readTemp(cy_stc_scb_i2c_master_xfer_config_t masterTransferCfg){
    masterTransferCfg.slaveAddress = SI7021_DEFAULT_ADDRESS;
    uint8_t status = TRANSFER_ERROR;
    uint8_t msg[WRITE_PACKET_SIZE];
    msg[0] = (SI7021_MEASTEMP_NOHOLD_CMD);
    
    if(TRANSFER_CMPLT == WriteCommandPacketToI2C(masterTransferCfg, SI7021_DEFAULT_ADDRESS, msg, 1)){
        CyDelay(20); // wait for sensor to take a sample
        status = ReadStatusPacketFromI2C(masterTransferCfg, SI7021_DEFAULT_ADDRESS, 3); // read 3 bytes, 2 for temp and one for chksum
        // todo: Do something with read data
    }
    
    return status;
}

/* 
* Function: readHumidity  
* Description: Read values from Si7021 after it has been setup
*
* Arguments:  cy_stc_scb_i2c_master_xfer_config_t masterTransferCfg = psoc I2C settings
* Output:     uint8_t status
*/
uint8_t readHumidity(cy_stc_scb_i2c_master_xfer_config_t masterTransferCfg){
    masterTransferCfg.slaveAddress = SI7021_DEFAULT_ADDRESS;
    uint8_t status = TRANSFER_ERROR;
    uint8_t msg[WRITE_PACKET_SIZE];
    msg[0] = (SI7021_MEASRH_NOHOLD_CMD);
    
    if(TRANSFER_CMPLT == WriteCommandPacketToI2C(masterTransferCfg, SI7021_DEFAULT_ADDRESS, msg, 1)){
        CyDelay(20); // wait for sensor to take a sample
        status = ReadStatusPacketFromI2C(masterTransferCfg, SI7021_DEFAULT_ADDRESS, 3); // read 3 bytes, 2 for temp and one for chksum
        // todo: Do something with read data
    }
    
    return status;
}

/* 
* Function: readSerial 
* Description: Read values from Si7021 after it has been setup
*
* Arguments:  cy_stc_scb_i2c_master_xfer_config_t masterTransferCfg = psoc I2C settings
* Output:     uint8_t status
*/
uint8_t readSerial(cy_stc_scb_i2c_master_xfer_config_t masterTransferCfg){
    masterTransferCfg.slaveAddress = SI7021_DEFAULT_ADDRESS;
    uint8_t status = TRANSFER_ERROR;
    uint8_t msg[WRITE_PACKET_SIZE];
    msg[0] = (SI7021_ID1_CMD >> 8);
    msg[1] = (SI7021_ID1_CMD & 0xFF);
    
    if(TRANSFER_CMPLT == WriteCommandPacketToI2C(masterTransferCfg, SI7021_DEFAULT_ADDRESS, msg, 2)){
        status = ReadStatusPacketFromI2C(masterTransferCfg, SI7021_DEFAULT_ADDRESS, 1); // read 3 bytes, 2 for temp and one for chksum
        // todo: Do something with read data
    }
    
    return status;
}

/* 
* Function: readRevision 
* Description: Read values from Si7021 after it has been setup
*
* Arguments:  cy_stc_scb_i2c_master_xfer_config_t masterTransferCfg = psoc I2C settings
* Output:     uint8_t status
*/
uint8_t readRevision(cy_stc_scb_i2c_master_xfer_config_t masterTransferCfg){
    masterTransferCfg.slaveAddress = SI7021_DEFAULT_ADDRESS;
    uint8_t status = TRANSFER_ERROR;
    uint8_t msg[WRITE_PACKET_SIZE];
    msg[0] = (SI7021_FIRMVERS_CMD >> 8);
    msg[1] = (SI7021_FIRMVERS_CMD & 0xFF);
    
    if(TRANSFER_CMPLT == WriteCommandPacketToI2C(masterTransferCfg, SI7021_DEFAULT_ADDRESS, msg, 2)){
        status = ReadStatusPacketFromI2C(masterTransferCfg, SI7021_DEFAULT_ADDRESS, 2); // read 3 bytes, 2 for temp and one for chksum
        // todo: Do something with read data
    }
    
    return status;
}


/* 
* Function: Si7021Task  
* Description: start up a task to read out the Si7021 at a set interval
*
* Arguments:  void *masterTransfer
* Output:     none
*/
void Si7021Task(void *masterTransfer){
    uint16_t temp;
    uint16_t hum;
    float temperature;
    float humidity;
    
    cy_stc_scb_i2c_master_xfer_config_t masterTransferCfg;
    
    masterTransferCfg = *(cy_stc_scb_i2c_master_xfer_config_t *) masterTransfer;
    
    TickType_t xLastWakeTime;
    const TickType_t xFrequency = 50000;
      
    xLastWakeTime = xTaskGetTickCount();    
    
    if (TRANSFER_CMPLT == initSI7021(masterTransferCfg)){
        for(;;){
            vTaskDelayUntil(&xLastWakeTime, xFrequency);
            sensor = RHT;
            if(TRANSFER_CMPLT == readTemp(masterTransferCfg)){
                Cy_DMA_Channel_SetDescriptor(I2CDMA_HW, I2CDMA_DW_CHANNEL, &I2CDMA_Descriptor_Temp);      // Set correct descriptor and trigger channel
    	        Cy_DMA_Channel_Enable(I2CDMA_HW, I2CDMA_DW_CHANNEL);
                Cy_TrigMux_SwTrigger((uint32_t)I2CDMA_DW__TR_IN, 1);
                
                /*temp = ((uint16_t)readBuffer[0] << 8) | (uint16_t)readBuffer[1]; //todo: deal with chxsum
                temperature = (float) temp;
                temperature *= 175.72;
                temperature /= 65536;
                temperature -= 46.85;
                printf("%f\r\n", temperature);*/
            }
            if(TRANSFER_CMPLT == readHumidity(masterTransferCfg)){
                //Cy_DMA_Channel_SetDescriptor(I2CDMA_HW, I2CDMA_DW_CHANNEL, &I2CDMA_Descriptor_Temp);        // Set correct descriptor and trigger channel (not necessary to set descriptor because chain
    	        //Cy_DMA_Channel_Enable(I2CDMA_HW, I2CDMA_DW_CHANNEL);
                Cy_TrigMux_SwTrigger((uint32_t)I2CDMA_DW__TR_IN, 1);
                
                /*hum = ((uint16_t)readBuffer[0] << 8) | (uint16_t)readBuffer[1]; //todo: deal with chxsum
                humidity = (float) hum;
                humidity *= 125;
                humidity /= 65536;
                humidity -= 6;
                printf("%f\r\n", humidity);*/
            }
        }
    }
}