#define HXB_CFG_MODULE
#include "hxb_cfg.h"

void HXB_Init(void)
{
    GPIO_InitTypeDef  gpio_init;

    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);

    gpio_init.GPIO_Pin  = HXB_KEY_PIN;
    gpio_init.GPIO_Speed = GPIO_Speed_50MHz;
    gpio_init.GPIO_Mode = GPIO_Mode_IN;        //PA.00下拉输入
    gpio_init.GPIO_PuPd = GPIO_PuPd_DOWN;
    GPIO_Init(HXB_KEY_PORT, &gpio_init);

    gpio_init.GPIO_Pin   = HXB_LED;
    gpio_init.GPIO_Mode = GPIO_Mode_OUT;
    gpio_init.GPIO_OType = GPIO_OType_PP;
    gpio_init.GPIO_Speed = GPIO_Speed_50MHz;//100MHz
    GPIO_Init(LEDPORT, &gpio_init);
}
