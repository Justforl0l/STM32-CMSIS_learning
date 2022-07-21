#pragma once

#include "stm32f103xb.h"

#define SPI_BaudRate_Prescaler_64           (0x5 << 3)      // SPI_SLOW
#define SPI_BaudRate_Prescaler_8            (0x2 << 3)      // SPI_MEDIUM
#define SPI_BaudRate_Prescaler_2            (0x0 << 3)      // SPI_FAST

#define TIMERTICK                           (F_CPU / 1000) - 1

void mcu_init();
void clock_init();
void gpio_init();
void spi_init();
