#include "stm32f10x.h"
#include "led.h"          // 引入你的 LED 驱动头文件

int main(void)
{
    // 1. 系统底层硬件初始化
    LED_Init();
    
    // 2. 点亮 LED1 和 LED2（因为低电平有效，所以调用 ResetBits 拉低引脚）
    GPIO_ResetBits(LED_PORT, LED1_PIN);  // 点亮 LED1
    GPIO_ResetBits(LED_PORT, LED2_PIN);  // 点亮 LED2
    
    while(1)
    {
        // 这里可以让单片机空转，灯会一直保持亮起状态
    }
}

