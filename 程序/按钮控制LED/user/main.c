#include "stm32f10x.h"

int main(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;

    // 1. 同时开启 GPIOA 和 GPIOB 的时钟
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB, ENABLE);

    // 2. 配置 PA1 按钮（输入，上拉）
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1; // 确认是 PA1
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    // 3. 配置 PB0 LED（输出，推挽）
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0; // 确认是 PB0
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);

    while(1)
    {     
        // 读取 PA1。如果按下（低电平），就把 PB0 拉高（亮灯）；否则拉低（灭灯）
        if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_1) == Bit_RESET) 
        { 
            GPIO_WriteBit(GPIOB, GPIO_Pin_0, Bit_SET);   // PB0 输出高电平
        }
        else 
        {
            GPIO_WriteBit(GPIOB, GPIO_Pin_0, Bit_RESET); // PB0 输出低电平
        }
    }
}