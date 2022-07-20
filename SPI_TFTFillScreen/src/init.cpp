#include "init.hpp"

void mcu_init()
{
    clock_init();
    gpio_init();
    spi_init();
}

void clock_init()
{
    __NOP();
}

void gpio_init()
{
    __NOP();
}

void spi_init()
{
    __NOP();
}
