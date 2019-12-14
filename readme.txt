这是STM32F429IG的FReeRTOS v10.2.1 的第一个移植版。
硬件包含一个LED灯，D12，KEY，A0。
USART1 用作监视输出，已经重定向fputc,可以使用printf输出