#include "stdio.h"
#include <string.h>
#include "TaskDef.h"
#include "AppSemrCfg.h"
#include "hxb_cfg.h"
#include "kfb_cfg.h"

void Test(void);
static uint32_t testValue;
#if 0
__weak void taskDbgUart(void *parg)
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
#endif
void taskDbgUart(void *parg)
{
    Test();
    while (1)
    {
        if(kfb_key_value())
        {
            vTaskDelay(500);
            BLUE_TOGGLE;
        }
        else {
            //GREEN_TOGGLE;
            vTaskDelay(250);
        }
        //vTaskDelay(20);
        _NOP();
    }
}

void Test(void)
{
  /*蓝灯亮，表示正在读写SRAM测试*/
  LED_BLUE;
  
  /*对SRAM进行读写测试，检测SRAM是否正常*/
  if(SDRAM_Test()==1)
  {
		//测试正常 绿灯亮
    LED_GREEN;			  
  }
	else
	{
		//测试失败 红灯亮
		LED_RED;
	}
	
	/*指针方式访问SRAM*/
	{	
	 uint32_t temp;
	
	 printf("\r\n指针方式访问SDRAM\r\n");
	/*向SDRAM写入8位数据*/
	 *( uint8_t*) (SDRAM_BANK_ADDR ) = (uint8_t)0xAA;
	 printf("\r\n指针访问SDRAM，写入数据0xAA \r\n");

	 /*从SDRAM读取数据*/
	 temp =  *( uint8_t*) (SDRAM_BANK_ADDR );
	 printf("读取数据：0x%X \r\n",temp);

	 /*写/读 16位数据*/
	 *( uint16_t*) (SDRAM_BANK_ADDR+10 ) = (uint16_t)0xBBBB;
	 printf("指针访问SDRAM，写入数据0xBBBB \r\n");
	 
	 temp =  *( uint16_t*) (SDRAM_BANK_ADDR+10 );
	 printf("读取数据：0x%X \r\n",temp);


	 /*写/读 32位数据*/
	 *( uint32_t*) (SDRAM_BANK_ADDR+20 ) = (uint32_t)0xCCCCCCCC;
	 printf("指针访问SDRAM，写入数据0xCCCCCCCC \r\n");	 
	 temp =  *( uint32_t*) (SDRAM_BANK_ADDR+20 );
	 printf("读取数据：0x%X \r\n",temp);
 }
	
	/*绝对定位方式访问SRAM,这种方式必须定义成全局变量*/
	{
		testValue = 0xDD;
		printf("\r\n绝对定位访问SRAM，写入数据0xDD,读出数据0x%X,变量地址为%X\r\n",testValue,(uint32_t )&testValue);	 
	}
}
