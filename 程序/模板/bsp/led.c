#include "led.h"

void LED_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
	
    // 1. 开启 GPIOB 的外设时钟
    RCC_APB2PeriphClockCmd(LED_CLK, ENABLE);
    
    // 2. 配置 PB0 和 PB1 
    GPIO_InitStructure.GPIO_Pin = LED_PIN ; 
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;      // 推挽输出
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;     // 50MHz输出速度
    
    // 3. 初始化 GPIOB
    GPIO_Init(LED_PORT, &GPIO_InitStructure);
    
    // 4. 默认让引脚输出高电平（也就是让 LED1 和 LED2 初始状态为熄灭）
    GPIO_WriteBit(LED_PORT, LED_PIN,Bit_SET);
}
