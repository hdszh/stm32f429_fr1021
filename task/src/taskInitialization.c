#include "TaskDef.h"
#include "AppSemrCfg.h"
#include "kfb_usart1.h"

void TaskInitialization(void *parg)
{
    static RCC_ClocksTypeDef RCC_Clocks;
    RCC_GetClocksFreq(&RCC_Clocks);
    
    AppSemrCfgInitialization();
    USARTx_DMA_Config();
    Debug_USART_Config();
    
    TaskCreate();
    
    while (1)
    {
        if(hxb_key_value())
        {
            vTaskDelay(1000);
            hxb_led_toggle();
        }
        else vTaskDelay(250);
        
        
        _NOP();
    }
}