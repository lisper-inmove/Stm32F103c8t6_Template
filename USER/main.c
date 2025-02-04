#include "stm32f1xx_hal.h"
#include "rcc.h"
#include <cstdint>

uint32_t HCLKFreq;
uint32_t PCLK1Freq;
uint32_t PCLK2Freq;

void SystemInitDefaultConfig(void);

int main(void)
{
	HAL_Init();
	// RccClockInit();
	RccClockInitOuter();
	HAL_RCC_MCOConfig(RCC_MCO1, RCC_MCO1SOURCE_SYSCLK, RCC_MCODIV_1);
	SystemCoreClockUpdate();
	SystemInitDefaultConfig();
	HAL_Delay(500);
}

void SystemInitDefaultConfig()
{
	// 汇编启动文件调用SystemInit对时钟的默认配置
	HCLKFreq = HAL_RCC_GetHCLKFreq();
	PCLK1Freq = HAL_RCC_GetPCLK1Freq();
	PCLK2Freq = HAL_RCC_GetPCLK2Freq();
}
