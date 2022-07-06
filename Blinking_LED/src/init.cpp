#include "init.hpp"

void mcu_init()
{
    clock_init();
    gpio_init();
    systick_init();
}

void clock_init()
{
    /* Включаем HSE как источник тактирования и ждем
       пока HSE не будет готов */
    RCC->CR |= RCC_CR_HSEON;
    RCC->CR &= ~RCC_CR_HSION;
    while (!(RCC->CR &= RCC_CR_HSERDY));
    // Настройка PLL, множитель 9, частота 8 * 9 = 72 МГц
    RCC->CFGR |= ((1 << 20) | (1 << 19) | (1 << 18) | (1 << 16));
    // Включаем PLL и ждём его готовности
    RCC->CR |= RCC_CR_PLLON;
    while (!(RCC->CR &= RCC_CR_PLLRDY));
    // Настройка и включение буфера Flash-памяти
    FLASH->ACR |= (1 << 1);
    // Установка предделителей шин:
    // HCLK - не делится
    // PCLK1 - делится на 2
    // PCLK2 - не делится
    RCC->CFGR |= (1 << 10);
    // Переключение SYSCLK на PLL и ожидание готовности
    RCC->CFGR |= RCC_CFGR_SW_PLL;
    while (!(RCC->CFGR &= RCC_CFGR_SWS_PLL));
    // Обновление SystemCoreClock
    SystemCoreClockUpdate();

    /*// Настраиваем тактирование микроконтроллера
    RCC->CFGR = (RCC->CFGR & ~CFGRREG_MASK_BITS) | ((1 << 20) | (1 << 19) |
                 (1 << 18) | (1 << 16) | (1 << 10) | (1 << 1));
    // Включаем PLL и HSE
    RCC->CR = (RCC->CR & ~CRREG_MASK_BITS) | ((1 << 24) | (1 << 16));*/
}

void gpio_init()
{
    // Включаем тактирование GPIOC
    RCC->APB2ENR = (RCC->APB2ENR & ~RCC_APB2ENR_MASK_BITS) | IOPCEN_MASK_BIT;
    // Настраиваем PC13 как GPIO output push-pull
    GPIOC->CRH = (GPIOC->CRH & ~(CNF13_MASK_BITS | MODE13_MASK_BITS)) |
                 (1 << 21);
}

void systick_init()
{
    SysTick->LOAD = TimerTick;
    SysTick->VAL = TimerTick;

    SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk |
                    SysTick_CTRL_TICKINT_Msk |
                    SysTick_CTRL_ENABLE_Msk;
}
