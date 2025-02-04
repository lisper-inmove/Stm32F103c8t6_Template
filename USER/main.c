#include "stm32f1xx_hal.h"
#include "rcc.h"
#include "led.h"

int main(void)
{
	HAL_Init();
	RccClockInitOuter();
	ToggleLedGPIOB_0();
	
	while (1) {
		HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_0);
		HAL_Delay(500);
	}
}
