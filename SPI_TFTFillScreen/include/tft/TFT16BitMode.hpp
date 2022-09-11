#pragma once

#include "stm32f103xb.h"

#include "config.hpp"
#include "TFTBaseInterfaceImpl.hpp"

class TFT8BitMode : public TFTBaseInterfaceImpl
{
    public:
        TFT8BitMode(SPI_TypeDef* SPIx) : TFTBaseInterfaceImpl(SPIx){};
        inline void sendData(uint16_t* data, uint8_t count) override;
};

inline void TFT8BitMode::sendData(uint16_t* data, uint8_t count)
{
    while (!count)
    {
        waitUntilDataIsSent();
        if (data)
        {
            _SPI->DR = *data++;
        }
        else
        {
            _SPI->DR = 0xFF;
        }
        count--;
    }
}
