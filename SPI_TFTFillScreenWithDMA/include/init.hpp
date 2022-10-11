#pragma once

#include "stm32f103xb.h"

#include "config.hpp"

void mcu_init();
void clock_init();
void gpio_init();
void spi_init();

inline void enableHse()
{
    RCC->CR |= RCC_CR_HSEON;
    while (!(RCC->CR & RCC_CR_HSERDY_Msk));
}

inline void setupPll()
{
    RCC->CFGR |= (RCC_CFGR_PLLMULL9 | RCC_CFGR_PLLSRC);
    RCC->CR |= RCC_CR_PLLON;
    while (!(RCC->CR & RCC_CR_PLLRDY_Msk));
}

inline void setupFlashLatency()
{
    FLASH->ACR |= FLASH_ACR_LATENCY_2;
}

inline void setupSystemClock()
{
    RCC->CFGR |= RCC_CFGR_PPRE1_DIV2 | RCC_CFGR_SW_PLL;
    while(!(RCC->CFGR & RCC_CFGR_SWS_PLL));
    RCC->CR &= ~RCC_CR_HSION;
}
