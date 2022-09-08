#include "init.hpp"

void mcu_init()
{
    clock_init();
    gpio_init();
    spi_init();
    SysTick_Config(TIMERTICK);
}

void clock_init()
{
    return;
}

void gpio_init()
{
    return;
}

void spi_init()
{
    return;
}
