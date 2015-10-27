/* mbed Microcontroller Library
 * Copyright (c) 2006-2013 ARM Limited
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef MBED_OBJECTS_H
#define MBED_OBJECTS_H

#include "PinNames.h"
#include "gpio_object.h"

#ifdef __cplusplus
extern "C" {
#endif

struct spi_port_s {
    PinName hardwire;
    PinName cs;
    char bitmode;
    char hardwareCS;
    void(*SPI_Start)();
    void(*SPI_Stop)();
    void (*SPI_WriteTxData)(uint8_t);
    uint8_t (*SPI_ReadTxStatus)();
    uint8_t (*SPI_GetRxBufferSize)();
    uint8_t (*SPI_ReadRxData)();
};
    
    
struct spi_s {
    int spiPortNum;
    struct spi_port_s *port;
    PinName cs;
    int bitmode;
};
    
struct i2c_s {
    PinName sda;
    PinName sdc;
    char initied;
};
    
struct gpio_irq_s
{
    int pinReg;         /**< CYREG_* address */
    uint8_t portNum;    /**< The port number for the PRT* */
    int inttypeReg;     /**< CYREG_PICU*_INTTYPE* register address */
    int picuStat;       /**< Address of the PICU*_STAT register */
    uint8_t irqLine;    /**< The interrypt line as defined by gpio_irq_piculines */
    int snapShotAddr;   /**< The address to the PICU snapshot register */
    uint8_t ch;         /**< The index for the channel, that hold a pointer to the InterruptIn object */
};

#ifdef __cplusplus
}
#endif

#endif
