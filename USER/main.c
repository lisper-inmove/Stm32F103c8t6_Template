#include "stm32f1xx_hal.h"
#include "rcc.h"
#include "sw.h"
#include "led.h"

int main(void)
{
  HAL_Init();
  RccClockInitOuter();
  ToggleLedGPIOB_0();
  SW_Init();
  while (1) {
    int result = SW_Scan(0);
    switch(result) {
    case 8: HAL_GPIO_TogglePin(GPIOB, LED_GPIO);
      break;
    }
  }
}
