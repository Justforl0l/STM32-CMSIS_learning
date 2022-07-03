#include "init.hpp"

void mcu_init()
{
    clock_init();
    gpio_init();
}

void clock_init()
{
    // Настраиваем тактирование микроконтроллера
    RCC->CFGR = (RCC->CFGR & ~CFGRREG_MASK_BITS) | ((1 << 20) | (1 << 19) |
                 (1 << 18) | (1 << 16) | (1 << 10) | (1 << 1));
    // Включаем PLL и HSE
    RCC->CR = (RCC->CR & ~CRREG_MASK_BITS) | ((1 << 24) | (1 << 16));
}

void gpio_init()
{
    // Включаем тактирование GPIOC
    RCC->APB2ENR = (RCC->APB2ENR & ~RCC_APB2ENR_MASK_BITS) | IOPCEN_MASK_BIT;
    // Настраиваем PC13 как GPIO output push-pull
    GPIOC->CRH = (GPIOC->CRH & ~(CNF13_MASK_BITS | MODE13_MASK_BITS)) |
                 (1 << 21);
}
