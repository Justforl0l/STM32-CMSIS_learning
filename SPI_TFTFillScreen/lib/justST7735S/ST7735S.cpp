#include <inc/ST7735S.hpp>

JST7735S::JST7735S(SPI_TypeDef *SPIx, const uint8_t *commandList)
{
    this->_SPI = SPIx;
    this->_commandList = commandList;
    _initDisplay();
}

void JST7735S::_initDisplay()
{
    uint8_t numberOfCommands, command, numberOfArgs;
    uint16_t ms;

    numberOfCommands = *_commandList;
    while (numberOfCommands--)
    {
        command = *_commandList++;
        numberOfArgs = *_commandList++;
        ms = numberOfArgs & ST7735S_CMD_DELAY;
        numberOfArgs &= ~ST7735S_CMD_DELAY;
        sendCommand(command, _commandList, numberOfArgs);
        _commandList += numberOfArgs;

        if (ms)
        {
            ms = *_commandList++;
            if (ms == 255)
            {
                ms = 500;
            }
            // TODO: Нужно передать функцию задержки
        }
    }
}

// TODO: Подумать, как можно переписать метод (мне в принципе не нравиться как он написан)
void JST7735S::sendCommand(uint8_t command, const uint8_t *address,
                           uint8_t numArgs)
{
    setCommandMode();
    SPI_SendData(_SPI, &command, 1);
    waitUntilDataIsSent();
}

void JST7735S::setCommandMode()
{
    return;
}

void JST7735S::waitUntilDataIsSent()
{
    return;
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
