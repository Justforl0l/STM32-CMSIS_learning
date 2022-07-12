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
    RCC->CFGR |= RCC_CFGR_PPRE1_DIV2;
    RCC->CFGR |= RCC_CFGR_SW_PLL;
    while (!(RCC->CFGR & RCC_CFGR_SWS_PLL));
    RCC->CR &= ~RCC_CR_HSION;
}

void gpio_init()
{
    RCC->APB2ENR |= (RCC_APB2ENR_IOPBEN | RCC_APB2ENR_AFIOEN);
    GPIOB->CRH |= (GPIO_CRH_MODE13_1 | GPIO_CRH_CNF13_1 |
                   GPIO_CRH_CNF14_1 |
                   GPIO_CRH_MODE15_1 | GPIO_CRH_CNF15_1);
}

void spi_init()
{
    RCC->APB1ENR |= RCC_APB1ENR_SPI2EN;
    SPI2->CR1 |= SPI_BaudRate_Prescaler_64;
    SPI2->CR1 &= ~SPI_CR1_CPHA;
    SPI2->CR1 &= ~SPI_CR1_CPOL;
    SPI2->CR1 &= ~SPI_CR1_DFF;
    SPI2->CR1 &= ~SPI_CR1_LSBFIRST;
    SPI2->CR1 |= (SPI_CR1_SSM | SPI_CR1_SSI);
    SPI2->CR1 |= (SPI_CR1_MSTR | SPI_CR1_SPE);
}
