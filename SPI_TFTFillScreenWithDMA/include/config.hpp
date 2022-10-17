#pragma once

#define TIMERTICK           ((F_CPU / 1000) - 1)

#define SPI_BaudRate_Prescaler_64           (0x5 << 3)      // SPI_SLOW
#define SPI_BaudRate_Prescaler_8            (0x2 << 3)      // SPI_MEDIUM
#define SPI_BaudRate_Prescaler_2            (0x0 << 3)      // SPI_FAST

#define DMA_Priority_VeryHigh               (0x3 << 12)
#define DMA_Priority_High                   (0x1 << 13)
#define DMA_Priority_Medium                 (0x1 << 12)
#define DMA_Priority_Low                    0

#define ST7735S_WIDTH       128
#define ST7735S_HEIGHT      160
