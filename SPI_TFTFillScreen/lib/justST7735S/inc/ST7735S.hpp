#pragma once

#include "colors.hpp"
#include "commands.hpp"

#include "stm32f103xb.h"

#include "utils/spi.hpp"

class JST7735S
{
    private:
        SPI_TypeDef *_SPI;
        const uint8_t *_commandList;
    public:
        JST7735S(SPI_TypeDef *SPIx, const uint8_t *commandList);
        void initDisplay();
        void sendCommand(uint8_t command, const uint8_t *address,
                         uint8_t numArgs);
        void toggleBacklight();
        void fillScreen(uint16_t color);
        void pushColor(uint16_t color, int count);
    protected:
};
