#include <inc/ST7735S.hpp>

JST7735S::JST7735S(SPI_TypeDef *SPIx, const uint8_t *commandList,
                   TFTInterface* interfaceImplementation, void(*delay)(uint32_t))
{
    _SPI = SPIx;
    _commandList = commandList;
    _interfaceImplementation = interfaceImplementation;
    _delay = delay;
    _preInitDisplay();
    _initDisplay();
}

void JST7735S::_preInitDisplay()
{
    _initBacklightPin();
    _interfaceImplementation->selectDisplay();
    _interfaceImplementation->resetDisplay();
    _delay(5);
    _interfaceImplementation->enableDisplay();
    toggleBacklight();
}

void JST7735S::_initDisplay()
{
    uint8_t numberOfCommands, command, numberOfArgs;
    uint16_t ms;

    numberOfCommands = *_commandList++;
    while (numberOfCommands--)
    {
        command = *_commandList++;
        numberOfArgs = *_commandList++;
        ms = numberOfArgs & ST7735S_CMD_DELAY;
        numberOfArgs &= ~ST7735S_CMD_DELAY;
        _sendFunctionCommand(command, _commandList, numberOfArgs);
        _commandList += numberOfArgs;

        if (ms)
        {
            ms = *_commandList++;
            if (ms == 255)
            {
                ms = 500;
            }
            _delay(ms);
        }
    }
}

void JST7735S::_sendFunctionCommand(uint8_t command, const uint8_t *address,
                                    uint8_t numberOfArgs)
{
    sendCommandOrData(COMMAND_MODE, &command, 1);
    if (numberOfArgs)
    {
        while (numberOfArgs)
        {
            sendCommandOrData(DATA_MODE, (uint8_t *) address, 1);
            address++;
            numberOfArgs--;
        }
    }
}

void JST7735S::toggleBacklight()
{
    _interfaceImplementation->toggleBacklight();
}

void JST7735S::fillScreen(uint16_t color)
{
    uint8_t ramwrCommand = ST7735S_CMD_RAMWR;
    sendCommandOrData(COMMAND_MODE, &ramwrCommand, 1);

    for (uint8_t x = 0; x < ST7735_WIDTH; x++)
    {
        for (uint8_t y = 0; y < ST7735_HEIGHT; y++)
        {
            sendCommandOrData(DATA_MODE, &color, 1);
        }
        
    }
}

void JST7735S::sendCommandOrData(uint8_t mode, uint8_t *data, uint8_t count)
{
    _interfaceImplementation->selectDisplay();

    if (mode == COMMAND_MODE)
    {
        _interfaceImplementation->setCommandMode();
    }
    else if (mode == DATA_MODE)
    {
        _interfaceImplementation->setDataMode();
    }

    _interfaceImplementation->sendData(data, count);
    _interfaceImplementation->waitUntilDataIsSent();
    _interfaceImplementation->waitUntilTransmissionComplete();
    _interfaceImplementation->deselectDisplay();
}

void JST7735S::sendCommandOrData(uint8_t mode, uint16_t *data, uint8_t count)
{
    _interfaceImplementation->selectDisplay();

    if (mode == COMMAND_MODE)
    {
        _interfaceImplementation->setCommandMode();
    }
    else if (mode == DATA_MODE)
    {
        _interfaceImplementation->setDataMode();
    }

    _interfaceImplementation->sendData(data, count);
    _interfaceImplementation->waitUntilDataIsSent();
    _interfaceImplementation->waitUntilTransmissionComplete();
    _interfaceImplementation->deselectDisplay();
}

void JST7735S::noOperation()
{
    __NOP();
}

void JST7735S::select()
{
    _interfaceImplementation->selectDisplay();
}

void JST7735S::deselect()
{
    _interfaceImplementation->deselectDisplay();
}
