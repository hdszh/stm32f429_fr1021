#define HXB_CFG_MODULE
#include "hxb_cfg.h"

void HXB_Init(void)
{
    HXB_Led_Configuration();

    SDRAM_Init();
}
