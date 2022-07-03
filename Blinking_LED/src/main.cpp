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
    return;
}

void delay(uint8_t delay_ms)
{
    return;
}
