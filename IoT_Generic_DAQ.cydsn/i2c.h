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
 *         File: i2c.h
 *      Created: 2019-04-11
 *       Author: Stijn Crul
 *      Version: 0.1
 *
 *  Description: I2C library for PSOC6
 */

#ifndef __I2C__
#define __I2C__
    
#include "project.h"
#include "serial.h"
    
// I2C commands
// Command valid status 
#define TRANSFER_CMPLT    (0x00UL)
#define TRANSFER_ERROR    (0xFFUL)
#define READ_CMPLT        (TRANSFER_CMPLT)
#define READ_ERROR        (TRANSFER_ERROR)
    
// Buffer and packet size
#define WRITE_PACKET_SIZE (0x02UL)  // Used to reserve some space in memory for I2C buffer. Make as long as your longest packets
#define READ_PACKET_SIZE  (0x06UL)
    
#define BUFFER_ACCELERO 6146    // 2 places for command, 6x1024 for all accelerosamples
#define BUFFER_TEMP     4       // 2 places for command, 2 bytes for data
#define BUFFER_HUMID    4       // 2 places for command, 2 bytes for data

// Combine master error statuses in single mask 
#define MASTER_ERROR_MASK  (CY_SCB_I2C_MASTER_DATA_NAK | CY_SCB_I2C_MASTER_ADDR_NAK    | \
                            CY_SCB_I2C_MASTER_ARB_LOST | CY_SCB_I2C_MASTER_ABORT_START | \
                            CY_SCB_I2C_MASTER_BUS_ERR)       
   
    // Variables
    // Structure for master transfer configuration */
    // (todo: Possibly redundant?)
    uint8_t writebuffer[WRITE_PACKET_SIZE];
    uint8_t readBuffer[READ_PACKET_SIZE];
    
    uint8_t bufferAccelero[BUFFER_ACCELERO];
    uint8_t bufferTemp[BUFFER_TEMP];
    uint8_t bufferHumid[BUFFER_HUMID];
    
    // PROTOTYPING
    static void HandleError(void);
    void initI2C(void);
    void configureI2CDMA();
    void I2CDMAComplete();
    uint8_t WriteCommandPacketToI2C(cy_stc_scb_i2c_master_xfer_config_t masterTransferCfg, uint8_t address, uint8_t *msg, uint32_t packet_size);
    uint8_t ReadStatusPacketFromI2C(cy_stc_scb_i2c_master_xfer_config_t masterTransferCfg, uint8_t address, uint32_t packet_size);

    
#endif