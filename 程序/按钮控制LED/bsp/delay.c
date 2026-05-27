#include "delay.h"

static uint8_t  fac_us = 0; // 微秒延时倍乘数
static uint16_t fac_ms = 0; // 毫秒延时倍乘数

/**
  * @brief  初始化SysTick定时器
  * @note   根据系统时钟（默认72MHz）计算出延时基准
  */
void Delay_Init(void)
{
    // 选择外部时钟 HCLK/8。如果系统时钟是72MHz，SysTick时钟就是72/8 = 9MHz
    SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8); 
    
    fac_us = SystemCoreClock / 8000000; // 72,000,000 / 8,000,000 = 9（即延时1us需要9个时钟节拍）
    fac_ms = (uint16_t)fac_us * 1000;   // 延时1ms需要9000个时钟节拍
}

/**
  * @brief  微秒级延时
  * @param  nus: 要延时的微秒数
  */
void delay_us(uint32_t nus)
{		
    uint32_t temp;             
    SysTick->LOAD = nus * fac_us;           // 时间加载 
    SysTick->VAL = 0x00;                    // 清空计数器
    SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk ; // 开始倒计时 
    do
    {
        temp = SysTick->CTRL;
    }while((temp & 0x01) && !(temp & (1 << 16))); // 等待计数时间到达（标志位置1）
    
    SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk; // 关闭计数器
    SysTick->VAL = 0X00;                    // 清空计数器	 
}

/**
  * @brief  毫秒级延时
  * @param  nms: 要延时的毫秒数
  * @note   SysTick的LOAD寄存器只有24位，所以单次延时有最大值限制（72MHz下最大约1864ms）
  */
void delay_ms(uint32_t nms)
{	 		  	  
    uint32_t temp;		   
    SysTick->LOAD = (uint32_t)nms * fac_ms; // 时间加载(SysTick->LOAD为24bit)
    SysTick->VAL = 0x00;                    // 清空计数器
    SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk ; // 开始倒计时  
    do
    {
        temp = SysTick->CTRL;
    }while((temp & 0x01) && !(temp & (1 << 16))); // 等待计数时间到达   
    
    SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk; // 关闭计数器
    SysTick->VAL = 0X00;                    // 清空计数器	  	    
}

// 注意：确保最后有一行空行