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
#ifndef MBED_GPIO_OBJECT_H
#define MBED_GPIO_OBJECT_H

#include "mbed_assert.h"

#ifdef __cplusplus
extern "C" {
#endif

#include <project.h>
    
typedef struct {
    PinName  pin;
    PinDirection dir;
//    uint32_t mask;
//
//    char *prt_dr;
//    char *prt_ps;
//    char *prt_dm;
//    char *prt_slw;
//    char *prt_byp;
//    char *prt_bie;
} gpio_t;

static inline void gpio_write(gpio_t *obj, int value) {
    MBED_ASSERT(obj->pin != (PinName)NC);
    if (value)
        CyPins_SetPin(obj->pin);
    else
        CyPins_ClearPin(obj->pin);
}

static inline int gpio_read(gpio_t *obj) {
    MBED_ASSERT(obj->pin != (PinName)NC);
    return CyPins_ReadPin(obj->pin);
}

static inline int gpio_is_connected(const gpio_t *obj) {
    return obj->pin != (PinName)NC;
}

#ifdef __cplusplus
}
#endif

#endif
