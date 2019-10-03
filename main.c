#include "stm32f10x.h"
GPIO_InitTypeDef GPIO_InitStructure;
static __IO uint32_t TimingDelay;
void InitGPIO()
{
        RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
        GPIO_Init(GPIOC, &GPIO_InitStructure);
}
void InitTimer()
{
        SysTick_Config(SystemCoreClock / 1000);
}
void SysTick_Handler(void)
{
        if (TimingDelay != 0x00)
        {
                TimingDelay--;
        }
}
void Delay(__IO uint32_t nTime)
{
         TimingDelay = nTime;
         while(TimingDelay != 0);
}
int main()
{
        InitGPIO();
        InitTimer();
                       
        while(1)
        {
                GPIOC->BSRR = GPIO_Pin_13;
                Delay(500);
                /* Reset PD0 and PD2 */
                GPIOC->BRR  = GPIO_Pin_13;
                Delay(500);
        }
}