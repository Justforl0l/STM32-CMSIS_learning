#pragma once

#include "colors.hpp"
#include "commands.hpp"

#include "stm32f103xb.h"

#include "utils/spi.hpp"

class JST7735S
{
    private:
        SPI_TypeDef *_SPI;
    public:
        JST7735S(SPI_TypeDef *SPIx);
        void JST7735S_initDisplay(const uint8_t *commandList);
        void JST7735S_sendCommand(uint8_t command, const uint8_t *address,
                             uint8_t numArgs);
        void JST7735S_backlight(bool on);
        void JST7735S_fillScreen(uint16_t color);
        void JST7735S_pushColor(uint16_t color, int count);
    protected:
};
