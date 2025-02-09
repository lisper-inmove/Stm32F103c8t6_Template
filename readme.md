# Stm32f103c8t6芯片uVision下使用Hal库的模板

    1. User: 工程和代码
    2. Hw: 自己操作硬件
    3. Lib: HAL库的源码
    4. CMSIS: CM内核相关

    5. stm32f103c8t6芯片配置如下
      1. 点击Options for Target(魔法棒)，
            1.1 在C/C++一栏配置 将'Preprocessor Symbols'设置为 'STM32F103xB'
            1.2 在Include Paths中分别添加 HalTemplate\HW\Inc, HalTemplate\LIB\Inc, HalTemplateCMSIS\Include
