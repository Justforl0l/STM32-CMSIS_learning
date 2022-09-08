#pragma once

#include "stm32f103xb.h"

#define TFT_PORT_BLK        GPIOA
#define TFT_PIN_BLK_POSITION        1
#define TFT_PIN_BLK_BSRR_BS1        (0x1UL << TFT_PIN_BLK_POSITION)
#define TFT_PIN_BLK_BSRR_BR1        (0x1UL << (TFT_PIN_BLK_POSITION + 16))

#define TFT_PORT_RST        GPIOA
#define TFT_PIN_RST_POSITION        4
#define TFT_PIN_RST         (0x1UL << TFT_PIN_RST_POSITION)

#define TFT_PORT_DC         GPIOA
#define TFT_PIN_DC_POSITION         2
#define TFT_PIN_DC          (0x1UL << TFT_PIN_DC_POSITION)

#define TFT_PORT_SCE        GPIOA
#define TFT_PIN_SCE_POSITION        3
#define TFT_PIN_SCE         (0x1UL << TFT_PIN_SCE_POSITION)

#define TFT_PORT_MISO       GPIOB
#define TFT_PIN_MISO_POSITION       14
#define TFT_PIN_MISO        (0x1UL << TFT_PIN_MISO_POSITION)

#define TFT_PORT_MOSI       GPIOB
#define TFT_PIN_MOSI_POSITION       15
#define TFT_PIN_MOSI        (0x1UL << TFT_PIN_MISO_POSITION)

#define TFT_PORT_CLK        GPIOB
#define TFT_PIN_CLK_POSITION        13
#define TFT_PIN_CLK         (0x1UL << TFT_PIN_CLK_POSITION)

#define ST7735_WIDTH        128
#define ST7735_HEIGHT       160
