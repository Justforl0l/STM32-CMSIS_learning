#pragma once

#include "stm32f103xb.h"

#include "config.hpp"

void mcu_init();
void clock_init();
void gpio_init();
void spi_init();
void dmaInit();

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

inline void enableGpioClocks()
{
    RCC->APB2ENR |= (RCC_APB2ENR_IOPBEN | RCC_APB2ENR_AFIOEN |
                     RCC_APB2ENR_IOPAEN);
}

inline void setupGpioB()
{
    GPIOB->CRH &= ~(GPIO_CRH_CNF13_Msk | GPIO_CRH_CNF14_Msk |
                    GPIO_CRH_CNF15_Msk | GPIO_CRH_CNF10_Msk);
    GPIOB->CRH |= (GPIO_CRH_MODE13_1 | GPIO_CRH_CNF13_1 |
                   GPIO_CRH_CNF14_1 |
                   GPIO_CRH_MODE15_1 | GPIO_CRH_CNF15_1 |
                   GPIO_CRH_CNF10_1);
    GPIOB->BSRR |= (GPIO_BSRR_BS14 | GPIO_BSRR_BS10);
}

inline void setupGpioA()
{
    GPIOA->CRL &= ~(GPIO_CRL_CNF1_Msk | GPIO_CRL_CNF2_Msk |
                    GPIO_CRL_CNF3_Msk | GPIO_CRL_CNF4_Msk);
    GPIOA->CRL |= (GPIO_CRL_MODE1_1 | GPIO_CRL_MODE2_1 |
                   GPIO_CRL_MODE3_1 | GPIO_CRL_MODE4_1);
}

inline void enableSpiClock()
{
    RCC->APB1ENR |= RCC_APB1ENR_SPI2EN;
}

inline void setBaudRate(uint8_t prescaler)
{
    SPI2->CR1 |= prescaler;
}

inline void clearSpiSettings()
{
    SPI2->CR1 &= ~(SPI_CR1_CPHA | SPI_CR1_CPOL |
                   SPI_CR1_DFF | SPI_CR1_LSBFIRST);
}

inline void configureNss()
{
    SPI2->CR1 |= (SPI_CR1_SSM | SPI_CR1_SSI);
}

inline void setMode()
{
    SPI2->CR1 |= SPI_CR1_MSTR;
}

inline void enableSpi()
{
    SPI2->CR1 |= SPI_CR1_SPE;
}

inline void setPeripheralAddress()
{
    return;
}

inline void setMemoryAddress()
{
    return;
}

inline void setNumberOfTransfers()
{
    return;
}

inline void setChannelPriority()
{
    return;
}

inline void configureDMAProperties()
{
    return;
}

inline void enableDMA()
{
    return;
}
