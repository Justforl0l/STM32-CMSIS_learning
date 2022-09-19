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
        sendCommand(command, _commandList, numberOfArgs);
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

void JST7735S::sendCommand(uint8_t command, const uint8_t *address,
                           uint8_t numberOfArgs)
{
    _interfaceImplementation->selectDisplay();
    _interfaceImplementation->setCommandMode();
    _interfaceImplementation->sendData((uint16_t *)&command, 1);
    _interfaceImplementation->waitUntilDataIsSent();
    _interfaceImplementation->deselectDisplay();
    if (numberOfArgs)
    {
        while (numberOfArgs)
        {
            _interfaceImplementation->selectDisplay();
            _interfaceImplementation->setDataMode();
            _interfaceImplementation->sendData((uint16_t *)address, 1);
            _interfaceImplementation->waitUntilDataIsSent();
            _interfaceImplementation->deselectDisplay();
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
    uint8_t x, y;

    uint8_t ramwr = ST7735S_CMD_RAMWR;
    _interfaceImplementation->selectDisplay();
    _interfaceImplementation->setCommandMode();
    _interfaceImplementation->sendData((uint16_t *)&ramwr, 1);
    _interfaceImplementation->waitUntilDataIsSent();
    _interfaceImplementation->deselectDisplay();

    for (x = 0; x < ST7735_WIDTH; x++)
    {
        for (y = 0; y < ST7735_HEIGHT; y++)
        {
            pushColor(color, 1);
        }
        
    }
    
}

void JST7735S::pushColor(uint16_t color, uint8_t count)
{
    _interfaceImplementation->selectDisplay();
    _interfaceImplementation->setDataMode();
    _interfaceImplementation->sendData(&color, count);
    _interfaceImplementation->waitUntilDataIsSent();
    _interfaceImplementation->deselectDisplay();
}
