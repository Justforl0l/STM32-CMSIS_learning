#pragma once

class TFTInterface
{
    public:
        void operator=(const TFTInterface&) = delete;
        virtual inline void setCommandMode() = 0;
        virtual inline void setDataMode() = 0;
        virtual inline void waitUntilDataIsSent() = 0;
        virtual inline void toggleBacklight() = 0;
        virtual inline void selectDisplay() = 0;
        virtual inline void deselectDisplay() = 0;
        virtual inline void resetDisplay() = 0;
        virtual inline void enableDisplay() = 0;

    protected:
        TFTInterface() = default;
        ~TFTInterface() = default;
};
