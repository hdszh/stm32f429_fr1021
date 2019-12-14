#define KFB_CFG_MODULE
#include "kfb_cfg.h"

void KFB_Init(void)
{
    USARTx_DMA_Config();
    Debug_USART_Config();

    LED_GPIO_Config();
}