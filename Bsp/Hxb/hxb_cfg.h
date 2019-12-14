#ifndef __HXB_CFG_H__
#define __HXB_CFG_H__

#include "stm32f4xx.h"

/*
开发板上二个按键，一个复位键，Key,唤醒，WK_UP，PA.00,
一个8M字节SRAM，一个串行FLASH ，16M bit;
一个液晶接口--RG888模式
*/
/*
    按键使用接口：PA.00
    8M字节SRAM使用接口：
    PC：0，
    PD：0，1，8，9，10，14，15，
    PE：0，1，7，8，9， 10，11，12，13，14，15，
    PF：0，1，2，3，4， 5， 11，12，13，14，15
    PG：0，1，4，5，8， 15，
    PH：6，7，
    串行FLASH使用接口：
    PF：6，7，8，9
    液晶接口--RG888模式（全部在排针引出）：
    
*/
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

#ifndef HXB_CFG_MODULE
#define HXB_CFG_EXT   extern
#else
#define HXB_CFG_EXT
#endif




#ifdef __cplusplus
extern "C" {
#endif

void HXB_Init(void);

#ifdef __cplusplus
}
#endif
#endif