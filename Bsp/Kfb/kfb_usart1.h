#ifndef __KFB_USART1_H__
#define __KFB_USART1_H__

#include "stm32f4xx.h"

// 串口对应的DMA请求通道
#define  USART_RX_DMA_CHANNEL      DMA_Channel_4
#define  DEBUG_USART_DMA_STREAM    DMA2_Stream2

// 外设寄存器地址
#define  USART_DR_ADDRESS        (&DEBUG_USART->DR)

// 一次发送的数据量
#define  USART_RBUFF_SIZE            1000

//引脚定义
/*******************************************************/
#define DEBUG_USART                             USART1
#define DEBUG_USART_CLK                         RCC_APB2Periph_USART1
#define DEBUG_USART_BAUDRATE                    115200  //串口波特率

#define DEBUG_USART_RX_GPIO_PORT                GPIOA
#define DEBUG_USART_RX_GPIO_CLK                 RCC_AHB1Periph_GPIOA
#define DEBUG_USART_RX_PIN                      GPIO_Pin_10
#define DEBUG_USART_RX_AF                       GPIO_AF_USART1
#define DEBUG_USART_RX_SOURCE                   GPIO_PinSource10

#define DEBUG_USART_TX_GPIO_PORT                GPIOA
#define DEBUG_USART_TX_GPIO_CLK                 RCC_AHB1Periph_GPIOA
#define DEBUG_USART_TX_PIN                      GPIO_Pin_9
#define DEBUG_USART_TX_AF                       GPIO_AF_USART1
#define DEBUG_USART_TX_SOURCE                   GPIO_PinSource9

#define DEBUG_USART_IRQHandler                  USART1_IRQHandler
#define DEBUG_USART_IRQ                 				USART1_IRQn
/************************************************************/

#ifndef KFB_USART1_MODULE
#define KFB_USART1_EXT   extern
#else
#define KFB_USART1_EXT
#endif


KFB_USART1_EXT char Usart_Rx_Buf[USART_RBUFF_SIZE];







#ifdef __cplusplus
extern "C" {
#endif

void Debug_USART_Config(void);
void USARTx_DMA_Config(void);
void Usart_SendByte( USART_TypeDef * pUSARTx, uint8_t ch);
void Usart_SendString( USART_TypeDef * pUSARTx, char *str);

void Usart_SendHalfWord( USART_TypeDef * pUSARTx, uint16_t ch);

#ifdef __cplusplus
}
#endif
#endif