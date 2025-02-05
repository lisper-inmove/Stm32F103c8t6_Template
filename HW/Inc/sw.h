#ifndef __SW_H
#define __SW_H

#include "stm32f1xx_hal.h"

#define SW_GPIO GPIO_PIN_13
#define LED_GPIO GPIO_PIN_12

#define SW8_IN HAL_GPIO_ReadPin(GPIOC, SW_GPIO)

void SW_Init(void);
uint8_t SW_Scan(uint8_t mode);
#endif
