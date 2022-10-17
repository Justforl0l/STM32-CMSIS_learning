#pragma once

#include "stm32f103xb.h"

#define TFT_PORT_BLK            GPIOA
#define TFT_PIN_BLK_POSITION    1
#define TFT_PIN_BLK_BSRR_BS1    (0x1UL << TFT_PIN_BLK_POSITION)
#define TFT_PIN_BLK_BSRR_BR1    (0x1UL << (TFT_PIN_BLK_POSITION + 16))

#define TFT_PORT_RST            GPIOA
#define TFT_PIN_RST_POSITION    4
#define TFT_PIN_RST             (0x1UL << TFT_PIN_RST_POSITION)

#define TFT_PORT_DC             GPIOA
#define TFT_PIN_DC_POSITION     2
#define TFT_PIN_DC              (0x1UL << TFT_PIN_DC_POSITION)

#define TFT_PORT_SCE            GPIOA
#define TFT_PIN_SCE_POSITION    3
#define TFT_PIN_SCE             (0x1UL << TFT_PIN_SCE_POSITION)

#define TFT_PORT_MISO           GPIOB
#define TFT_PIN_MISO_POSITION   14
#define TFT_PIN_MISO            (0x1UL << TFT_PIN_MISO_POSITION)

#define TFT_PORT_MOSI           GPIOB
#define TFT_PIN_MOSI_POSITION   15
#define TFT_PIN_MOSI            (0x1UL << TFT_PIN_MOSI_POSITION)

#define TFT_PORT_CLK            GPIOB
#define TFT_PIN_CLK_POSITION    13
#define TFT_PIN_CLK             (0x1UL << TFT_PIN_CLK_POSITION)

#define TIMERTICK           ((F_CPU / 1000) - 1)

#define SPI_BaudRate_Prescaler_64           (0x5 << 3)      // SPI_SLOW
#define SPI_BaudRate_Prescaler_8            (0x2 << 3)      // SPI_MEDIUM
#define SPI_BaudRate_Prescaler_2            (0x0 << 3)      // SPI_FAST

#define DMA_Priority_VeryHigh               (0x3 << 12)
#define DMA_Priority_High                   (0x1 << 13)
#define DMA_Priority_Medium                 (0x1 << 12)
#define DMA_Priority_Low                    0

#define DMA_MemorySize_8Bits                0
#define DMA_MemorySize_16Bits               (0x1 << 10)
#define DMA_MemorySize_32Bits               (0x1 << 11)

#define DMA_PeripheralSize_8Bits            0
#define DMA_PeripheralSize_16Bits           (0x1 << 8)
#define DMA_PeripheralSize_32Bits           (0x1 << 9)

#define ST7735S_WIDTH       128
#define ST7735S_HEIGHT      160
