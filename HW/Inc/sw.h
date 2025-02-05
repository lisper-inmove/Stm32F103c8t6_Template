#ifndef __SW_H
#define __SW_H

#include "stm32f1xx_hal.h"

#define SW_GPIO GPIO_PIN_5
#define LED_GPIO GPIO_PIN_0

#define SW_IN HAL_GPIO_ReadPin(GPIOA, SW_GPIO)

#define LED_LIGHT 1
#define LED_DARK 0
// ��ť����ʱ����
#define PRESS_TRIGGER_MODE 0
// ��ţ̌��ʱ����
#define LIFT_TRIGGER_MODE 1
// �����˰��¶����Ч���̰�������
#define PRESS_DELAY_TIME   0x7FFF
// �ӳ����ֵ�������� LIFT_TRIGGER_MODE �ﵽ��ʱ������Ч��
#define LIFT_DELAY_TIME    0x75FFF
#define BUTTON_PRESSED 0x0011
#define BUTTON_DO_NOTHING 0x0001

void SW_Init(void);
uint8_t SW_Scan(uint8_t mode);
#endif
