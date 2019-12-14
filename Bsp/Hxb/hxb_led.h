#ifndef __HXB_LED_H__
#define __HXB_LED_H__

#include "stm32f4xx.h"

//口A0 定义为键输入
#define HXB_KEY_PIN             GPIO_Pin_0
#define HXB_KEY_PORT            GPIOA

//键为低电平有效，片内上拉电阻有效
#define hxb_key_value()       (GPIOA->IDR & 0x0001)   //初始化为下拉电阻，不取反

//口D12 定义为发光二极管
#define HXB_LED         GPIO_Pin_12
#define LEDPORT         GPIOD

#define hxb_led_on()        GPIO_ResetBits(LEDPORT, HXB_LED)
#define hxb_led_off()       GPIO_SetBits(LEDPORT, HXB_LED)
#define hxb_led_toggle()    GPIO_ToggleBits(LEDPORT,HXB_LED)





#ifndef HXB_LED_MODULE
#define HXB_LED_EXT   extern
#else
#define HXB_LED_EXT
#endif





#ifdef __cplusplus
extern "C" {
#endif

void HXB_Led_Configuration(void);


#ifdef __cplusplus
}
#endif
#endif