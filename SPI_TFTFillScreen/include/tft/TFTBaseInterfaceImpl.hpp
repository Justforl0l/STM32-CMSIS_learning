#pragma once

#include "stm32f103xb.h"

#include "config.hpp"
#include <inc/TFTInterface.hpp>

class TFTBaseInterfaceImpl : public TFTInterface
{
    public:
        TFTBaseInterfaceImpl(SPI_TypeDef* SPIx);
        inline void setCommandMode() override;
        inline void setDataMode() override;
        inline void waitUntilDataIsSent() override;
        inline void toggleBacklight() override;
        inline void selectDisplay() override;
        inline void deselectDisplay() override;
        inline void resetDisplay() override;
        inline void enableDisplay() override;
        virtual void sendData(uint16_t* data, uint8_t count) = 0;

    protected:
        SPI_TypeDef* _SPI;
        ~TFTBaseInterfaceImpl() = default;
};

TFTBaseInterfaceImpl::TFTBaseInterfaceImpl(SPI_TypeDef* SPIx)
{
    _SPI = SPIx;
}

inline void TFTBaseInterfaceImpl::setCommandMode()
{
    TFT_PORT_DC->BRR |= TFT_PIN_DC;
}

inline void TFTBaseInterfaceImpl::setDataMode()
{
    TFT_PORT_DC->BSRR |= TFT_PIN_DC;
}

inline void TFTBaseInterfaceImpl::waitUntilDataIsSent()
{
    while (!(_SPI->SR & SPI_SR_TXE_Msk));
}

inline void TFTBaseInterfaceImpl::toggleBacklight()
{
    TFT_PORT_BLK->BSRR ^= TFT_PIN_BLK_BSRR_BS1;
}

inline void TFTBaseInterfaceImpl::selectDisplay()
{
    TFT_PORT_SCE->BRR |= TFT_PIN_SCE;
}

inline void TFTBaseInterfaceImpl::deselectDisplay()
{
    TFT_PORT_SCE->BSRR |= TFT_PIN_SCE;
}

inline void TFTBaseInterfaceImpl::resetDisplay()
{
    TFT_PORT_RST->BRR |= TFT_PIN_RST;
}

inline void TFTBaseInterfaceImpl::enableDisplay()
{
    TFT_PORT_RST->BSRR |= TFT_PIN_RST;
}
