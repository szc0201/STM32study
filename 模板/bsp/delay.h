#ifndef __DELAY_H
#define __DELAY_H

#include "stm32f10x.h"

// 函数声明
void Delay_Init(void);  // 延时初始化函数
void delay_us(uint32_t nus); // 微秒级延时 (1us 级)
void delay_ms(uint32_t nms); // 毫秒级延时 (1ms 级)

#endif

// 注意：确保最后有一行空行