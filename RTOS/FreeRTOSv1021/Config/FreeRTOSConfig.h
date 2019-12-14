/*
    FreeRTOS V10.2.1 - Copyright (C) 2019 Real Time Engineers Ltd.
    All rights reserved
*/
#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

#if defined(__ICCARM__) || defined(__CC_ARM) || defined(__GNUC__)
    #include <stdint.h>
    extern uint32_t SystemCoreClock;
#endif

#define configASSERT( x ) if( ( x ) == 0 ) { taskDISABLE_INTERRUPTS(); for( ;; ); }	

/************************************************************************
 *               FreeRTOS基础配置配置选项 
 *********************************************************************/
#define configUSE_PREEMPTION				    1


#define configUSE_TIME_SLICING					1   //1使能时间片调度(默认式使能的)
#define configUSE_PORT_OPTIMISED_TASK_SELECTION 1   //1，特殊方法（需要硬件支持），0，通用方法，                    
#define configUSE_TICKLESS_IDLE				    0   //置1：使能低功耗tickless模式；
#define configCPU_CLOCK_HZ					    (SystemCoreClock)
#define configMAX_PRIORITIES				    (32)
#define configMINIMAL_STACK_SIZE				((unsigned short)128)
#define configMAX_TASK_NAME_LEN					(16)
#define configUSE_16_BIT_TICKS					0   //1表示为16位无符号整形，0表示为32位无符号整形                   
#define configIDLE_SHOULD_YIELD					1   //空闲任务放弃CPU使用权给其他同优先级的用户任务        
#define configUSE_TASK_NOTIFICATIONS            1   //开启任务通知功能，默认开启
#define configUSE_APPLICATION_TASK_TAG		    0   //任务标签                    

#define configTICK_RATE_HZ						  (( TickType_t )1000)

#define configUSE_QUEUE_SETS			        1   //启用队列 
#define configUSE_MUTEXES				        1   //使用互斥信号量 
#define configUSE_RECURSIVE_MUTEXES			    1   //使用递归互斥信号量
#define configUSE_COUNTING_SEMAPHORES		    1   //为1时使用计数信号量
#define configQUEUE_REGISTRY_SIZE		        10  /* 设置可以注册的信号量和消息队列个数 */                             
                                                                       
                      

/*****************************************************************
              FreeRTOS与内存申请有关配置选项                                               
*****************************************************************/

#define configSUPPORT_DYNAMIC_ALLOCATION        0                   //1支持动态内存申请
#define configSUPPORT_STATIC_ALLOCATION		    1	                //1使用静态内存				
#define configTOTAL_HEAP_SIZE					((size_t)(36*1024)) //系统所有总的堆大小


/***************************************************************
             FreeRTOS与钩子函数有关的配置选项                                            
**************************************************************/
/* 置1：使用空闲钩子（Idle Hook类似于回调函数）；置0：忽略空闲钩子*/
#define configUSE_IDLE_HOOK						0      

/* 置1：使用时间片钩子（Tick Hook）；置0：忽略时间片钩子*/
/*xTaskIncrementTick函数是在xPortSysTickHandler中断函数中被调用的。因此，vApplicationTickHook()函数执行的时间必须很短才行*/
#define configUSE_TICK_HOOK						0

#define configUSE_MALLOC_FAILED_HOOK			0       //使用内存申请失败钩子函数
/*
 * 大于0时启用堆栈溢出检测功能，如果使用此功能 
 * 用户必须提供一个栈溢出钩子函数，如果使用的话
 * 此值可以为1或者2，因为有两种栈溢出检测方法 */
#define configCHECK_FOR_STACK_OVERFLOW			2   


/********************************************************************
          FreeRTOS与运行时间和任务状态收集有关的配置选项   
**********************************************************************/

#define configGENERATE_RUN_TIME_STATS	        0       //启用运行时间统计功能       
 
#define configUSE_TRACE_FACILITY			    0       //启用可视化跟踪调试
/* 与宏configUSE_TRACE_FACILITY同时为1时会编译下面3个函数
 * prvWriteNameToBuffer()
 * vTaskList(),
 * vTaskGetRunTimeStats()
*/
#define configUSE_STATS_FORMATTING_FUNCTIONS	1                       
                                                                        
                                                                        
/********************************************************************
                FreeRTOS与协程有关的配置选项                                                
*********************************************************************/

#define configUSE_CO_ROUTINES 			        0           //启用协程，启用协程以后必须添加文件croutine.c        
#define configMAX_CO_ROUTINE_PRIORITIES       ( 2 )         //协程的有效优先级数目          

/***********************************************************************
                FreeRTOS与软件定时器有关的配置选项      
**********************************************************************/
 
#define configUSE_TIMERS				        0                               //启用软件定时器                
#define configTIMER_TASK_PRIORITY		        (configMAX_PRIORITIES-1)        //软件定时器优先级  
#define configTIMER_QUEUE_LENGTH		        10                              //软件定时器队列长度             
#define configTIMER_TASK_STACK_DEPTH	        (configMINIMAL_STACK_SIZE*2)    //软件定时器任务堆栈大小

/************************************************************
            FreeRTOS可选函数配置选项                                                     
************************************************************/
#define INCLUDE_xTaskGetSchedulerState          1                       
#define INCLUDE_vTaskPrioritySet		        1
#define INCLUDE_uxTaskPriorityGet		        1
#define INCLUDE_vTaskDelete				        1
#define INCLUDE_vTaskCleanUpResources	        1
#define INCLUDE_vTaskSuspend			        1
#define INCLUDE_vTaskDelayUntil			        1
#define INCLUDE_vTaskDelay				        1
#define INCLUDE_eTaskGetState			        1
#define INCLUDE_xTimerPendFunctionCall	        0
//#define INCLUDE_xTaskGetCurrentTaskHandle       1
//#define INCLUDE_uxTaskGetStackHighWaterMark     0
//#define INCLUDE_xTaskGetIdleTaskHandle          0

/******************************************************************
            FreeRTOS与中断有关的配置选项                                                 
******************************************************************/
#ifdef __NVIC_PRIO_BITS
	#define configPRIO_BITS       		__NVIC_PRIO_BITS
#else
	#define configPRIO_BITS       		4                  
#endif

#define configLIBRARY_LOWEST_INTERRUPT_PRIORITY			15     //中断最低优先级
#define configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY	5 //系统可管理的最高中断优先级
#define configKERNEL_INTERRUPT_PRIORITY 		( configLIBRARY_LOWEST_INTERRUPT_PRIORITY << (8 - configPRIO_BITS) )	/* 240 */
#define configMAX_SYSCALL_INTERRUPT_PRIORITY 	( configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY << (8 - configPRIO_BITS) )

/****************************************************************
            FreeRTOS与中断服务函数有关的配置选项                         
****************************************************************/
#define xPortPendSVHandler 	PendSV_Handler
#define vPortSVCHandler 	SVC_Handler
#define xPortSysTickHandler SysTick_Handler

/* 以下为使用Percepio Tracealyzer需要的东西，不需要时将 configUSE_TRACE_FACILITY 定义为 0 */
#if ( configUSE_TRACE_FACILITY == 1 )
#include "trcRecorder.h"
#define INCLUDE_xTaskGetCurrentTaskHandle               1   // 启用一个可选函数（该函数被 Trace源码使用，默认该值为0 表示不用）
#endif

#endif