#include "stm32f1xx_hal.h"
#include "stdio.h"
#include "sw.h"

int LedState = LED_DARK;

void SW_Init(void)
{
  GPIO_InitTypeDef gpio;
  __HAL_RCC_GPIOA_CLK_ENABLE();
  gpio.Pin = SW_GPIO;
  gpio.Mode = GPIO_MODE_INPUT;
  gpio.Pull = GPIO_PULLDOWN;
  HAL_GPIO_Init(GPIOA, &gpio);
}

// mode: LIFT_TRIGGER_MODE 按钮抬起时触发动作
//       PRESS_TRIGGER_MODE 按钮按下时就触发动作
uint8_t SW_Scan(uint8_t mode)
{
  if (SW_IN == 1 && LedState == LED_DARK) {
    for (int i = 0; i < PRESS_DELAY_TIME; i++) {
      if (SW_IN == 0) {
        return BUTTON_DO_NOTHING;
      }
    }
		LedState = LED_LIGHT;
		// LIFT_TRIGGER_MODE 时只是将 LedState 改回LED_LIGHT
    if (mode == PRESS_TRIGGER_MODE) {
      return BUTTON_PRESSED;
    }
  } else if (SW_IN == 0 && LedState == LED_LIGHT) {
    for (int i = 0; i < LIFT_DELAY_TIME; i++) {
      if (SW_IN == 1) {
        return BUTTON_DO_NOTHING;
      }
    }
		LedState = LED_DARK;
		// PRESS_TRIGGER_MODE 时只是将 LedState 改回 LED_DARK
    if (mode == LIFT_TRIGGER_MODE) {
      return BUTTON_PRESSED;
    }
  }
  return BUTTON_DO_NOTHING;
}
