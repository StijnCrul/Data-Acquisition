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
 *         File: Si7021.h
 *      Created: 2019-07-15
 *       Author: Stijn Crul
 *      Version: 0.1
 *
 *  Description: Si7021 library for PSOC6 including its I2C functions
 */

#ifndef __SI7021__
#define __SI7021__
  
#include "project.h"
    
// I2C commands 
#define SI7021_DEFAULT_ADDRESS	         0x40

#define SI7021_MEASRH_HOLD_CMD           0xE5 /**< Measure Relative Humidity, Hold Master Mode */
#define SI7021_MEASRH_NOHOLD_CMD         0xF5 /**< Measure Relative Humidity, No Hold Master Mode */
#define SI7021_MEASTEMP_HOLD_CMD         0xE3 /**< Measure Temperature, Hold Master Mode */
#define SI7021_MEASTEMP_NOHOLD_CMD       0xF3 /**< Measure Temperature, No Hold Master Mode */
#define SI7021_READPREVTEMP_CMD          0xE0 /**< Read Temperature Value from Previous RH Measurement */
#define SI7021_RESET_CMD                 0xFE /**< Reset Command */
#define SI7021_WRITERHT_REG_CMD          0xE6 /**< Write RH/T User Register 1 */
#define SI7021_READRHT_REG_CMD           0xE7 /**< Read RH/T User Register 1 */
#define SI7021_WRITEHEATER_REG_CMD       0x51 /**< Write Heater Control Register */
#define SI7021_READHEATER_REG_CMD        0x11 /**< Read Heater Control Register */
#define SI7021_ID1_CMD                   0xFA0F /**< Read Electronic ID 1st Byte */
#define SI7021_ID2_CMD                   0xFCC9 /**< Read Electronic ID 2nd Byte */
#define SI7021_FIRMVERS_CMD              0x84B8 /**< Read Firmware Revision */

#define SI7021_REV_1					 0xff  /**< Sensor revision 1 */
#define SI7021_REV_2					 0x20  /**< Sensor revision 2 */
    
// PROTOTYPING
uint8_t initSI7021(cy_stc_scb_i2c_master_xfer_config_t masterTransferCfg);
uint8_t readTemp(cy_stc_scb_i2c_master_xfer_config_t masterTransferCfg);
uint8_t readHumidity(cy_stc_scb_i2c_master_xfer_config_t masterTransferCfg);
uint8_t readSerial(cy_stc_scb_i2c_master_xfer_config_t masterTransferCfg);
void Si7021Task(void * masterTransfer);
    
// VARIABLES

    
#endif