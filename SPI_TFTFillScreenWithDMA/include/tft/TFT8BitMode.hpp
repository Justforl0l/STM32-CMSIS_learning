#pragma once

#include "stm32f103xb.h"

#include "config.hpp"
#include "TFTBaseInterfaceImpl.hpp"

class TFT8BitMode : public TFTBaseInterfaceImpl
{
    public:
        TFT8BitMode(SPI_TypeDef* SPIx) : TFTBaseInterfaceImpl(SPIx){};
        inline void sendData(uint8_t* data, uint8_t count) override;
        inline void sendData(uint16_t* data, uint8_t count) override;
};

inline void TFT8BitMode::sendData(uint16_t* data, uint8_t count)
{
    while (count)
    {
        if (data)
        {
            uint16_t temporaryData = *data;
            uint8_t msb_data = temporaryData >> 8;
            uint8_t lsb_data = temporaryData &0xFF;

            sendData(&msb_data, 1);
            sendData(&lsb_data, 1);
        }
        else
        {
            uint8_t dummyData = 0xFF;
            sendData(&dummyData, 2);
        }
        count--;
    }
}

inline void TFT8BitMode::sendData(uint8_t* data, uint8_t count)
{
    while (count)
    {
        waitUntilDataIsSent();
        if (data)
        {
            _SPI->DR = *data;
        }
        else
        {
            _SPI->DR = 0xFF;
        }
        count--;
    }
}
