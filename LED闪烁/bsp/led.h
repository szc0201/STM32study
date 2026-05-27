#ifndef __LED_H
#define __LED_H

#include "stm32f10x.h"

// 为了以后方便修改引脚，建议使用宏定义
#define LED1_PIN        GPIO_Pin_0
#define LED2_PIN        GPIO_Pin_1
#define LED_PORT        GPIOB
#define LED_CLK         RCC_APB2Periph_GPIOB

// 函数声明
void LED_Init(void);

#endif
