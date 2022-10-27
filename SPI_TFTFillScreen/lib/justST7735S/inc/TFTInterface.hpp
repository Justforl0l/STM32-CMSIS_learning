#pragma once

class TFTInterface
{
    public:
        void operator=(const TFTInterface&) = delete;
        virtual void setCommandMode() = 0;
        virtual void setDataMode() = 0;
        virtual void waitUntilDataIsSent() = 0;
        virtual void waitUntilTransmissionComplete() = 0;
        virtual void toggleBacklight() = 0;
        virtual void selectDisplay() = 0;
        virtual void deselectDisplay() = 0;
        virtual void resetDisplay() = 0;
        virtual void enableDisplay() = 0;
        virtual void sendData(uint16_t* data, uint8_t count) = 0;

    protected:
        TFTInterface() = default;
        ~TFTInterface() = default;
};
