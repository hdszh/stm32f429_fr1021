#ifndef __KFB_LED_H__
#define	__KFB_LED_H__

#include "stm32f4xx.h"

//引脚定义
/*******************************************************/
//R 红色灯
#define LED1_PIN                  GPIO_Pin_10                 
#define LED1_GPIO_PORT            GPIOH                      
#define LED1_GPIO_CLK             RCC_AHB1Periph_GPIOH

//G 绿色灯
#define LED2_PIN                  GPIO_Pin_11                 
#define LED2_GPIO_PORT            GPIOH                      
#define LED2_GPIO_CLK             RCC_AHB1Periph_GPIOH

//B 蓝色灯
#define LED3_PIN                  GPIO_Pin_12                 
#define LED3_GPIO_PORT            GPIOH                       
#define LED3_GPIO_CLK             RCC_AHB1Periph_GPIOH
/************************************************************/


/** 控制LED灯亮灭的宏，
	* LED低电平亮，设置ON=0，OFF=1
	* 若LED高电平亮，把宏设置成ON=1 ，OFF=0 即可
	*/
#define ON  0
#define OFF 1

/* 带参宏，可以像内联函数一样使用 */
#define LED1(a)	if (a)	\
					GPIO_SetBits(LED1_GPIO_PORT,LED1_PIN);\
					else		\
					GPIO_ResetBits(LED1_GPIO_PORT,LED1_PIN)

#define LED2(a)	if (a)	\
					GPIO_SetBits(LED2_GPIO_PORT,LED2_PIN);\
					else		\
					GPIO_ResetBits(LED2_GPIO_PORT,LED2_PIN)

#define LED3(a)	if (a)	\
					GPIO_SetBits(LED3_GPIO_PORT,LED3_PIN);\
					else		\
					GPIO_ResetBits(LED3_GPIO_PORT,LED3_PIN)


/* 直接操作寄存器的方法控制IO */
#define	digitalHi(p,i)			 {p->BSRRL=i;}		//设置为高电平
#define digitalLo(p,i)			 {p->BSRRH=i;}		//输出低电平
#define digitalToggle(p,i)	 {p->ODR ^=i;}		//输出反转状态

/* 定义控制IO的宏 */
#define RED_TOGGLE		digitalToggle(LED1_GPIO_PORT,LED1_PIN)
#define RED_OFF			digitalHi(LED1_GPIO_PORT,LED1_PIN)
#define RED_ON				digitalLo(LED1_GPIO_PORT,LED1_PIN)

#define GREEN_TOGGLE		digitalToggle(LED2_GPIO_PORT,LED2_PIN)
#define GREEN_OFF			digitalHi(LED2_GPIO_PORT,LED2_PIN)
#define GREEN_ON				digitalLo(LED2_GPIO_PORT,LED2_PIN)

#define BLUE_TOGGLE		digitalToggle(LED3_GPIO_PORT,LED3_PIN)
#define BLUE_OFF			digitalHi(LED3_GPIO_PORT,LED3_PIN)
#define BLUE_ON				digitalLo(LED3_GPIO_PORT,LED3_PIN)

/* 基本混色，后面高级用法使用PWM可混出全彩颜色,且效果更好 */

//红
#define LED_RED  \
					RED_ON;\
					GREEN_OFF;\
					BLUE_OFF

//绿
#define LED_GREEN		\
					RED_OFF;\
					GREEN_ON;\
					BLUE_OFF

//蓝
#define LED_BLUE	\
					RED_OFF;\
					GREEN_OFF;\
					BLUE_ON

					
//黄(红+绿)					
#define LED_YELLOW	\
					RED_ON;\
					GREEN_ON;\
					BLUE_OFF
//紫(红+蓝)
#define LED_PURPLE	\
					RED_ON;\
					GREEN_OFF;\
					BLUE_ON

//青(绿+蓝)
#define LED_CYAN \
					RED_OFF;\
					GREEN_ON;\
					BLUE_ON
					
//白(红+绿+蓝)
#define LED_WHITE	\
					RED_ON;\
					GREEN_ON;\
					BLUE_ON
					
//黑(全部关闭)
#define LED_RGBOFF	\
					RED_OFF;\
					GREEN_OFF;\
					BLUE_OFF		

/*开发板上按键  K2,C13*/
#define KFB_KEY_PIN             GPIO_Pin_13
#define KFB_KEY_PORT            GPIOC

#define kfb_key_value()       (GPIOC->IDR & GPIO_Pin_13)	//板上有下拉电阻

void LED_GPIO_Config(void);

#endif /* __LED_H */
