#pragma once

#include "stm32f103xb.h"

#include "init.hpp"

#define TFT_PORT_BLK        GPIOA
#define TFT_PORT_RST        GPIOA
#define TFT_PORT_DC         GPIOA
#define TFT_PORT_SCE        GPIOA
#define TFT_PORT_MISO       GPIOB
#define TFT_PORT_MOSI       GPIOB
#define TFT_PORT_CLK        GPIOB

#define MADCTLGRAPHICS      0x6
#define MADCTLBMP           0x2

#define ST7735_WIDTH        128
#define ST7735_HEIGHT       160
