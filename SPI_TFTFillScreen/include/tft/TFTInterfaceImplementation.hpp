#pragma once

#include "stm32f103xb.h"

#include <inc/TFTInterface.hpp>

class TFTInterfaceImplementation : public TFTInterface
{
    public:
        TFTInterfaceImplementation() = default;
        void setCommandMode() override;
        void setDataMode() override;
        void waitUntilDataIsSent() override;
        void toggleBacklight() override;
        void selectDisplay() override;
        void deselectDisplay() override;

    protected:
        ~TFTInterfaceImplementation() = default;
};
