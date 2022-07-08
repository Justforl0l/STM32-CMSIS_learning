#include "main.hpp"

int main()
{
    mcu_init();
    
    while (1)
    {
        led_toggle();
        delay(1000);
    }
}

void led_toggle()
{
    if (GPIOC->ODR & (1 << 13))
    {
        GPIOC->BRR |= (1 << 13);
    }
    else
    {
        GPIOC->BSRR |= (1 << 13);
    }
}

void delay(uint32_t delay_ms)
{
    uint32_t timeStamp = TICK;
    while (TICK - timeStamp < delay_ms);
}

void SysTick_Handler()
{
    TICK++;
}
