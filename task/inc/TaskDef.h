#ifndef __TASK_DEFINE_H__
#define __TASK_DEFINE_H__

#include "user_def.h"
#include "FreeRTOS.h"
#include "task.h"
#include "stm32f4xx.h"

#include "AppStart.h"

//定义任务优先级和栈长度
#define TASK_DEBUG_UART_PRIORITY    APP_LOWEST_PRIORITY
#define TASK_DEBUG_UART_STACK_SIZE  SYSTEM_DEFAULT_STACK_SIZE






#ifndef TASK_DEFINE_MODULE
#define TASK_DEFINE_EXT   extern
#else
#define TASK_DEFINE_EXT
#endif
//定义任务栈数组和任务控制块
TASK_DEFINE_EXT StackType_t    Debug_uart_Task_Stack[TASK_DEBUG_UART_STACK_SIZE] @ ".ccram";
TASK_DEFINE_EXT StaticTask_t   Debug_uart_Task_TCB @ ".ccram";

#ifdef __cplusplus
extern "C" {
#endif

void taskDbgUart(void *parg);

#ifdef __cplusplus
}
#endif
#endif