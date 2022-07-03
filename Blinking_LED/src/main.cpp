#include "main.hpp"

int main()
{
    mcu_init();
    
    while (1)
    {
        led_toggle();
        delay(500);
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

void delay(uint8_t delay_ms)
{
    return;
}
