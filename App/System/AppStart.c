/**
  *****************************************************************************
  *                                主控MCU主函数
  *
  *                       (C) Copyright 2017-2020, ***
  *                            All Rights Reserved
  *****************************************************************************
  *
  * @File    : main.c
  * @By      : 孙振海
  * @Version : V10.2.1
  * @Date    : 2019 / 12 / 12
  *
  *****************************************************************************
**/
#define APP_START_MODULE
#include "AppStart.h"

//static uint8_t ucHeap[ configTOTAL_HEAP_SIZE ] @ ".ccram";

int main()
{
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);     //FReeRTOS must NVIC_PriorityGroup_4
    SystemInit();
#ifdef RAMDBGMCU
    NVIC_SetVectorTable(NVIC_VectTab_RAM, 0x00);          //RAM 调试时使用
#endif
    HXB_Init();
    
#if (configSUPPORT_STATIC_ALLOCATION == 1)
    xTaskCreateStatic(
                      (TaskFunction_t )TaskInitialization,      //任务函数
                      (const char*    )"Initialization",        //任务名称
                      (uint16_t       )INITIAL_TASK_STACK_SIZE, //任务堆栈大小
                      (void* 		  )NULL,                    //传递给任务函数的参数
                      (UBaseType_t    )INITIAL_TASK_PRIO,       //任务优先级
                      (StackType_t*   )Initial_Task_Stack,      //任务堆栈
                      (StaticTask_t*  )&Initial_Task_TCB        //任务控制块
                     );
#else
    xTaskCreate((TaskFunction_t )TaskInitialization,     	
                (const char*    )"Initialization",   	
                (uint16_t       )INITIAL_TASK_STACK_SIZE, 
                (void*          )NULL,				
                (UBaseType_t    )INITIAL_TASK_PRIO,	
                //(TaskHandle_t*  )&LEDTask_Handler); 
                                 NULL); 
#endif    

    vTaskStartScheduler();          //开始任务调度

    while(1);       //正常执行不到这里
}

__weak void TaskInitialization(void *parg)
{
    static RCC_ClocksTypeDef RCC_Clocks;
    RCC_GetClocksFreq(&RCC_Clocks);
    TaskCreate();
    while (1)
    {
        if(!hxb_key_value())vTaskDelay(1000);
        else vTaskDelay(250);
        hxb_led_toggle();
        
        _NOP();
    }
}
#if (configSUPPORT_STATIC_ALLOCATION == 1)
/**
  **********************************************************************
  * @brief  获取空闲任务的任务堆栈和任务控制块内存
	*					ppxTimerTaskTCBBuffer	:		任务控制块内存
	*					ppxTimerTaskStackBuffer	:	任务堆栈内存
	*					pulTimerTaskStackSize	:		任务堆栈大小
  * @author  fire
  * @version V1.0
  * @date    2018-xx-xx
  **********************************************************************
  */ 
__weak void vApplicationGetIdleTaskMemory(StaticTask_t **ppxIdleTaskTCBBuffer, 
								   StackType_t **ppxIdleTaskStackBuffer, 
								   uint32_t *pulIdleTaskStackSize)
{
	*ppxIdleTaskTCBBuffer=&Idle_Task_TCB;/* 任务控制块内存 */
	*ppxIdleTaskStackBuffer=Idle_Task_Stack;/* 任务堆栈内存 */
	*pulIdleTaskStackSize=configMINIMAL_STACK_SIZE;/* 任务堆栈大小 */
}

/**
  *********************************************************************
  * @brief  获取定时器任务的任务堆栈和任务控制块内存
	*					ppxTimerTaskTCBBuffer	:		任务控制块内存
	*					ppxTimerTaskStackBuffer	:	任务堆栈内存
	*					pulTimerTaskStackSize	:		任务堆栈大小
  * @author  fire
  * @version V1.0
  * @date    2018-xx-xx
  **********************************************************************
  */ 
__weak void vApplicationGetTimerTaskMemory(StaticTask_t **ppxTimerTaskTCBBuffer, 
									StackType_t **ppxTimerTaskStackBuffer, 
									uint32_t *pulTimerTaskStackSize)
{
	*ppxTimerTaskTCBBuffer=&Timer_Task_TCB;/* 任务控制块内存 */
	*ppxTimerTaskStackBuffer=Timer_Task_Stack;/* 任务堆栈内存 */
	*pulTimerTaskStackSize=configTIMER_TASK_STACK_DEPTH;/* 任务堆栈大小 */
}
#endif

__weak void vApplicationMallocFailedHook( void )
{
}
__weak void vApplicationStackOverflowHook( void )
{
}
__weak void TaskCreate(void)
{
}

__weak void vApplicationIdleHook( void )
{
}
__weak void vApplicationTickHook( void )
{
}

