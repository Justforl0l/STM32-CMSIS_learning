#pragma once

#include "stm32f103xb.h"

#include "config.hpp"
#include "tft/colors.hpp"
#include "tft/commands.hpp"
#include "TFTInterface.hpp"

#ifndef ST7735_WIDTH
    #define ST7735_WIDTH    128
#endif
#ifndef ST7735_HEIGHT
    #define ST7735_HEIGHT   160
#endif

#define COMMAND_MODE        0
#define DATA_MODE           1

#if !defined(TFT_PORT_BLK) || !defined(TFT_PORT_RST) || \
    !defined(TFT_PORT_DC) || !defined(TFT_PORT_SCE)
    #error "Необходимо определить TFT_PORT_BLK, TFT_PORT_RST, TFT_PORT_DC и TFT_PORT_SCE"
#endif

class JST7735S
{
    private:
        SPI_TypeDef* _SPI;
        const uint8_t* _commandList;
        TFTInterface* _interfaceImplementation;

        void (*_delay)(uint32_t);
        void _preInitDisplay();
        void _initDisplay();
        void _sendFunctionCommand(uint8_t command, const uint8_t *address,
                                  uint8_t numberOfArgs);
        inline void _initBacklightPin();

    public:
        JST7735S(SPI_TypeDef *SPIx, const uint8_t *commandList,
                 TFTInterface* interfaceImplementation, void(*delay)(uint32_t));
        void setCommandMode();
        void waitUntilDataIsSent();
        void toggleBacklight();
        void fillScreen(uint16_t color);
        void sendCommandOrData(uint8_t mode, uint16_t color, uint8_t count);
        void noOperation();
        void select();
        void deselect();
};

inline void JST7735S::_initBacklightPin()
{
    TFT_PORT_BLK->BSRR |= TFT_PIN_BLK_BSRR_BR1;
}
