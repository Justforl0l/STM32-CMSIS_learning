#pragma once

#include "stm32f103xb.h"

#include "config.hpp"
#include <inc/TFTInterface.hpp>

class TFTInterfaceImplementation : public TFTInterface
{
    private:
        SPI_TypeDef* _SPI;
        
    public:
        TFTInterfaceImplementation(SPI_TypeDef* SPIx);
        inline void setCommandMode() override;
        inline void setDataMode() override;
        inline void waitUntilDataIsSent() override;
        inline void toggleBacklight() override;
        inline void selectDisplay() override;
        inline void deselectDisplay() override;
        inline void resetDisplay() override;
        inline void enableDisplay() override;

    protected:
        ~TFTInterfaceImplementation() = default;
};

TFTInterfaceImplementation::TFTInterfaceImplementation(SPI_TypeDef* SPIx)
{
    _SPI = SPIx;
}

inline void TFTInterfaceImplementation::setCommandMode()
{
    TFT_PORT_DC->BRR |= TFT_PIN_DC;
}

inline void TFTInterfaceImplementation::setDataMode()
{
    TFT_PORT_DC->BSRR |= TFT_PIN_DC;
}

inline void TFTInterfaceImplementation::waitUntilDataIsSent()
{
    while (_SPI->SR & SPI_SR_BSY_Msk);
}

inline void TFTInterfaceImplementation::toggleBacklight()
{
    TFT_PORT_BLK->BSRR ^= TFT_PIN_BLK_BSRR_BS1;
}

inline void TFTInterfaceImplementation::selectDisplay()
{
    TFT_PORT_SCE->BRR |= TFT_PIN_SCE;
}

inline void TFTInterfaceImplementation::deselectDisplay()
{
    TFT_PORT_SCE->BSRR |= TFT_PIN_SCE;
}

inline void TFTInterfaceImplementation::resetDisplay()
{
    TFT_PORT_RST->BRR |= TFT_PIN_RST;
}

inline void TFTInterfaceImplementation::enableDisplay()
{
    TFT_PORT_RST->BSRR |= TFT_PIN_RST;
}
