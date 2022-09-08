#include "tft/TFTInterfaceImplementation.hpp"

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
    // TODO: Не забыть проинициализировать BR1 в TFT_PORT_BLK->BSRR в 1
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
