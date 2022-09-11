#pragma once

#include "stm32f103xb.h"

#include "config.hpp"
#include "TFTBaseInterfaceImpl.hpp"

class TFT16BitMode : public TFTBaseInterfaceImpl
{
    public:
        TFT16BitMode(SPI_TypeDef* SPIx) : TFTBaseInterfaceImpl(SPIx){};
        inline void sendData(uint16_t* data, uint8_t count) override;
};

inline void TFT16BitMode::sendData(uint16_t* data, uint8_t count)
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
