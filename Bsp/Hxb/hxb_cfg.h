#ifndef __HXB_CFG_H__
#define __HXB_CFG_H__


#include "hxb_led.h"
#include "hxb_sdram.h"
#include "hxb_spi5.h"

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