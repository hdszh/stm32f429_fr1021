#include "stdio.h"
#include <string.h>
#include "TaskDef.h"
#include "AppSemrCfg.h"
#include "kfb_usart1.h"

void taskDbgUart(void *parg)
{
    while (1)
    {
        if(xSemaphoreTake(BinSem_Handle_Usart1,portMAX_DELAY))
        {
            hxb_led_toggle();
            printf("收到数据:%s\n",Usart_Rx_Buf);
            memset(Usart_Rx_Buf,0,USART_RBUFF_SIZE);/* 清零 */
        }
        //vTaskDelay(20);
        _NOP();
    }
}