#ifndef __SW_H
#define __SW_H

#include "stm32f1xx_hal.h"

#define SW_GPIO GPIO_PIN_5
#define LED_GPIO GPIO_PIN_0

#define SW_IN HAL_GPIO_ReadPin(GPIOA, SW_GPIO)

#define LED_LIGHT 1
#define LED_DARK 0
// 按钮按下时触发
#define PRESS_TRIGGER_MODE 0
// 按钮抬起时触发
#define LIFT_TRIGGER_MODE 1
// 决定了按下多久生效，短按，长按
#define PRESS_DELAY_TIME   0x7FFF
// 延长这个值，可以在 LIFT_TRIGGER_MODE 达到延时启动的效果
#define LIFT_DELAY_TIME    0x75FFF
#define BUTTON_PRESSED 0x0011
#define BUTTON_DO_NOTHING 0x0001

void SW_Init(void);
uint8_t SW_Scan(uint8_t mode);
#endif
