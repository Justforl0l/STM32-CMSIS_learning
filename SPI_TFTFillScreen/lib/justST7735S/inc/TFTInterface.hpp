#pragma once

class TFTInterface
{
    public:
        void operator=(const TFTInterface&) = delete;
        virtual void setCommandMode() = 0;
        virtual void setDataMode() = 0;
        virtual void waitUntilDataIsSent() = 0;
        virtual void toggleBacklight() = 0;
        virtual void selectDisplay() = 0;
        virtual void deselectDisplay() = 0;
        virtual void resetDisplay() = 0;
        virtual void enableDisplay() = 0;

    protected:
        TFTInterface() = default;
        ~TFTInterface() = default;
};
