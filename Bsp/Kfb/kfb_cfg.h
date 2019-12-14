#ifndef __KFB_CFG_H__
#define __KFB_CFG_H__

#include "kfb_led.h"
#include "kfb_usart1.h"





#ifndef KFB_CFG_MODULE
#define KFB_CFG_EXT   extern
#else
#define KFB_CFG_EXT
#endif





#ifdef __cplusplus
extern "C" {
#endif

void KFB_Init(void);


#ifdef __cplusplus
}
#endif
#endif