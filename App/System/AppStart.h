#ifndef __APP_START_H__
#define __APP_START_H__

#include "user_def.h"
//操作系统定义
#include "FreeRTOS.h"
#include "task.h"
//#include "timers.h"
//#include "semphr.h"

//固件库定义
#include "stm32f4xx.h"

#include "hxb_cfg.h"


#define APP_LOWEST_PRIORITY         2   //应用程序最低优先级
#define SYSTEM_DEFAULT_STACK_SIZE   256

#define INITIAL_TASK_PRIO           1
#define INITIAL_TASK_STACK_SIZE     SYSTEM_DEFAULT_STACK_SIZE

#ifndef APP_START_MODULE
#define APP_START_EXT   extern
#else
#define APP_START_EXT
#endif

#if (configSUPPORT_STATIC_ALLOCATION == 1)

APP_START_EXT StackType_t    Idle_Task_Stack[configMINIMAL_STACK_SIZE] @ ".ccram";
APP_START_EXT StackType_t    Timer_Task_Stack[configMINIMAL_STACK_SIZE] @ ".ccram";

APP_START_EXT StaticTask_t   Idle_Task_TCB @ ".ccram";
APP_START_EXT StaticTask_t   Timer_Task_TCB @ ".ccram";

APP_START_EXT StackType_t    Initial_Task_Stack[INITIAL_TASK_STACK_SIZE] @ ".ccram";
APP_START_EXT StaticTask_t   Initial_Task_TCB @ ".ccram";
#endif








#ifdef __cplusplus
extern "C" {
#endif

void TaskInitialization(void *parg);
void TaskCreate(void);

#ifdef __cplusplus
}
#endif
#endif