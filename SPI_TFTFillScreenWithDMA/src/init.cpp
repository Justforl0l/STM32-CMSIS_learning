#include "init.hpp"

void mcu_init()
{
    clock_init();
    gpio_init();
    spi_init();
    dmaInit();
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
    enableSpiClock();
    setBaudRate(SPI_BaudRate_Prescaler_2);
    clearSpiSettings();
    configureNss();
    setMode();
    enableSpi();
}

void dmaInit()
{
    setPeripheralAddress();
    setMemoryAddress();
    setNumberOfTransfers();
    setChannelPriority();
    configureDMAProperties();
    enableDMA();
}
