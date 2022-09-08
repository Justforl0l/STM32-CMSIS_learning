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
