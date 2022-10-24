#include "init.hpp"

void mcu_init()
{
    clock_init();
    gpio_init();
    dmaInit();
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
    enableSpiClock();
    setBaudRate(SPI_BaudRate_Prescaler_2);
    clearSpiSettings();
    set16BitMode();
    configureNss();
    setMode();
    enableTxDMABuffer();
    enableSpi();
}

void dmaInit()
{
    enableDMAClock();
    setPeripheralAddress();
    setMemoryAddress();
    setNumberOfTransfers();
    setChannelPriority();
    configureDMAProperties();
}
