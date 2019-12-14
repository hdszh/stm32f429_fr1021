#define TASK_DEFINE_MODULE
#include "TaskDef.h"

__weak void taskDbgUart(void *parg)
{
    while (1)
    {
        vTaskDelay(20);
        _NOP();
    }
}

void TaskCreate(void)
{
    xTaskCreateStatic(
                      (TaskFunction_t )taskDbgUart,                 //任务函数
                      (const char*    )"DBG_Uart",                  //任务名称
                      (uint16_t       )TASK_DEBUG_UART_STACK_SIZE,  //任务堆栈大小
                      (void* 		  )NULL,                        //传递给任务函数的参数
                      (UBaseType_t    )TASK_DEBUG_UART_PRIORITY,    //任务优先级
                      (StackType_t*   )Debug_uart_Task_Stack,       //任务堆栈
                      (StaticTask_t*  )&Debug_uart_Task_TCB         //任务控制块
                     );
}


