#include "init.hpp"

void mcu_init()
{
    clock_init();
    gpio_init();
    spi_init();
}

void clock_init()
{
    RCC->CR |= RCC_CR_HSEON;
    while (!(RCC->CR & RCC_CR_HSERDY_Msk));
    RCC->CFGR |= (RCC_CFGR_PLLMULL9 | RCC_CFGR_PLLSRC);
    RCC->CR |= RCC_CR_PLLON;
    while (!(RCC->CR & RCC_CR_PLLRDY_Msk));
    FLASH->ACR |= FLASH_ACR_LATENCY_2;
    RCC->CFGR |= RCC_CFGR_PPRE1_DIV2 | RCC_CFGR_SW_PLL;
    while (!(RCC->CFGR & RCC_CFGR_SWS_PLL));
    RCC->CR &= ~RCC_CR_HSION;
}

void gpio_init()
{
    __NOP();
}

void spi_init()
{
    __NOP();
}
