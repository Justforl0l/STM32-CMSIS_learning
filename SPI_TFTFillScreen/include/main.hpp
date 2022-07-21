#pragma once

#include "stm32f103xb.h"

#include "init.hpp"
#include "utils/spi.hpp"
#include "tft/commands.hpp"
#include "tft/colors.hpp"

#define TFT_PORT_BLK        GPIOA   // Pin 1
#define TFT_PORT_RST        GPIOA   // Pin 4
#define TFT_PORT_DC         GPIOA   // Pin 2
#define TFT_PORT_SCE        GPIOA   // Pin 3
#define TFT_PORT_MISO       GPIOB   // Pin 14
#define TFT_PORT_MOSI       GPIOB   // Pin 15
#define TFT_PORT_CLK        GPIOB   // Pin 13

#define MADCTLGRAPHICS      0x6
#define MADCTLBMP           0x2

#define ST7735_WIDTH        128
#define ST7735_HEIGHT       160

volatile uint32_t TICK = 0;

void ST7735_init(SPI_TypeDef *SPIx, const uint8_t *commandList);
void sendCommand(SPI_TypeDef *SPIx, uint8_t command,
                 const uint8_t *address, uint8_t numArgs);
void ST7735_backlight(uint8_t on);
void fillScreen(SPI_TypeDef *SPIx, uint16_t color);
void ST7735_pushColor(SPI_TypeDef *SPIx, uint16_t color, int count);
void delay(uint32_t delay_ms);

#ifdef __cplusplus
extern "C"
{
    #endif // __cplusplus

    void SysTick_Handler();

    #ifdef __cplusplus
}
#endif // __cplusplus
