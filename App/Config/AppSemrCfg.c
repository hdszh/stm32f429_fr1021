#define APP_SEMR_MODULE
#include "AppSemrCfg.h"

void AppSemrCfgInitialization(void)
{
    BinSem_Handle_Usart1 = NULL;
    BinSem_Handle_Usart1 = xSemaphoreCreateBinaryStatic(&xBinSem_Buffer_Usart1);
}