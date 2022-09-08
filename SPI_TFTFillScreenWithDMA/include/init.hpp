#pragma once

#include "stm32f103xb.h"

#include "config.hpp"

void mcu_init();
void clock_init();
void gpio_init();
void spi_init();
