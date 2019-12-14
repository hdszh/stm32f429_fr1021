#include "kfb_usart1.h"
#include "stm32f4xx_it.h"
#include "AppSemrCfg.h"

extern void Uart_DMA_Rx_Data(void);

void DEBUG_USART_IRQHandler(void)
{
  uint32_t ulReturn;
  /* 进入临界段，临界段可以嵌套 */
  ulReturn = taskENTER_CRITICAL_FROM_ISR();

	if(USART_GetITStatus(DEBUG_USART,USART_IT_IDLE)!=RESET)
	{		
		Uart_DMA_Rx_Data();       /* 释放一个信号量，表示数据已接收 */
		USART_ReceiveData(DEBUG_USART); /* 清除标志位 */
	}	 
  
  /* 退出临界段 */
  taskEXIT_CRITICAL_FROM_ISR( ulReturn );
}

