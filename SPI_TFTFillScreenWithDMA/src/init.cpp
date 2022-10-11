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
    enableHse();
    setupPll();
    setupFlashLatency();
    setupSystemClock();
    SystemCoreClockUpdate();
}

void gpio_init()
{
    enableGpioClocks();
    setupGpioB();
    setupGpioA();
}

void spi_init()
{
    RCC->APB1ENR |= RCC_APB1ENR_SPI2EN;
    SPI2->CR1 |= SPI_BaudRate_Prescaler_2;
    SPI2->CR1 &= ~(SPI_CR1_CPHA | SPI_CR1_CPOL |
                   SPI_CR1_DFF | SPI_CR1_LSBFIRST);
    SPI2->CR1 |= (SPI_CR1_SSM | SPI_CR1_SSI |
                  SPI_CR1_MSTR | SPI_CR1_SPE);
}
