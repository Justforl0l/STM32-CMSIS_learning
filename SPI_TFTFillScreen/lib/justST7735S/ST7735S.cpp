#include <inc/ST7735S.hpp>

JST7735S::JST7735S(SPI_TypeDef *SPIx, const uint8_t *commandList)
{
    this->_SPI = SPIx;
    this->_commandList = commandList;
}

void JST7735S::initDisplay()
{
    __NOP();
}

void JST7735S::sendCommand(uint8_t command, const uint8_t *address,
                           uint8_t numArgs)
{
    __NOP();
}

void JST7735S::toggleBacklight()
{
    __NOP();
}

void JST7735S::fillScreen(uint16_t color)
{
    __NOP();
}

void JST7735S::pushColor(uint16_t color, int count)
{
    __NOP();
}
