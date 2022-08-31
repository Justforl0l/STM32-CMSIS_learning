#include <inc/ST7735S.hpp>

JST7735S::JST7735S(SPI_TypeDef *SPIx, const uint8_t *commandList)
{
    this->_SPI = SPIx;
    this->_commandList = commandList;
}

void JST7735S::initDisplay()
{
    uint8_t numberOfCommands, command, numberOfArgs;
    uint16_t ms;

    numberOfCommands = *this->_commandList;
    while (numberOfCommands--)
    {
        command = *this->_commandList++;
        numberOfArgs = *this->_commandList++;
        ms = numberOfArgs & ST7735S_CMD_DELAY;
        numberOfArgs &= ~ST7735S_CMD_DELAY;
        this->sendCommand(command, this->_commandList, numberOfArgs);
        this->_commandList += numberOfArgs;

        if (ms)
        {
            ms = *this->_commandList++;
            if (ms == 255)
            {
                ms = 500;
            }
            // TODO: Нужно передать функцию задержки
        }
    }
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
