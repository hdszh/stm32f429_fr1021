#include "TaskDef.h"
#include "AppSemrCfg.h"
#include "kfb_cfg.h"

void TaskInitialization(void *parg)
{
    static RCC_ClocksTypeDef RCC_Clocks;
    RCC_GetClocksFreq(&RCC_Clocks);
    
    AppSemrCfgInitialization();
    KFB_Init();
    TaskCreate();
    
    while (1)
    {
        if(hxb_key_value())
        {
            vTaskDelay(1000);
            hxb_led_toggle();
        }
        else {
            hxb_led_toggle();
            vTaskDelay(250);
        }
        
        
        _NOP();
    }
}