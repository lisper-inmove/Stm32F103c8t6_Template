1. USER: 工程和代码
2. HW: 自己操作硬件
3. LIB: HAL库的源码
4. CMSIS: CM内核相关

5. stm32f103c8t6芯片配置如下
  1. 创建新的工程
    1.1. Target 上右键 'Manage Project Items' 新建 USER, LIB, HW, CMSIS
    1.2. 为LIB 'Add Files' stm32f1xx_hal.c, stm32f1xx_hal_cortex.c, stm32f1xx_hal_gpio.c, stm32f1xx_hal_gpio_ex.c, stm32f1xx_hal_rcc.c, stm32f1xx_hal_rcc_ex.c
    1.3. 为CMSIS 'Add Files' system_stm32f1xx.c, startup_stm32f103xb.s
    1.4. 在USER下新建文件main.c
  2. 点击Options for Target(魔法棒)，
        2.1 在C/C++一栏配置 将'Preprocessor Symbols'设置为 'STM32F103xB'
    2.2 在Include Paths中分别添加 HalTemplate\HW\Inc, HalTemplate\LIB\Inc, HalTemplateCMSIS\Include
  3. 在 USER/main.c中添加代码如下:
        #include "stm32f1xx_hal.h"

    int main(void) {

    }
    然后执行Translate(Ctrl+F7) 和 Build(F7)
    注：可能会报错找不到 stm32f1xx_hal_conf.h，需要去 HalTemplate\Lib\Inc中将stm32f1xx_hal_conf_template.h改为stm32f1xx_hal_conf.h