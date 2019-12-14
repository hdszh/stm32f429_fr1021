#ifndef __APP_SEMR_H__
#define __APP_SEMR_H__

#include "user_def.h"
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"





#ifndef APP_SEMR_MODULE
#define APP_SEMR_EXT   extern
#else
#define APP_SEMR_EXT
#endif

APP_SEMR_EXT SemaphoreHandle_t BinSem_Handle_Usart1;
APP_SEMR_EXT StaticSemaphore_t xBinSem_Buffer_Usart1;


#ifdef __cplusplus
extern "C" {
#endif

void AppSemrCfgInitialization(void);


#ifdef __cplusplus
}
#endif
#endif