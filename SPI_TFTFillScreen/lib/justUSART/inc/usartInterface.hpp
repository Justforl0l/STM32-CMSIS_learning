#pragma once

class UsartInterface
{
    protected:
        UsartInterface() = default;
        ~UsartInterface() = default;

    public:
        void operator=(const UsartInterface&) = delete;
        virtual void waitUntilDataIsSent() = 0;
        virtual bool isDataReadyToBeRead() = 0;
        virtual void waitUntilTransmissionIsComplete() = 0;
        virtual void sendData(uint8_t* data, uint8_t count) = 0;
        virtual uint8_t receiveData() = 0;
        virtual void setBaudrate(uint16_t mantissa, uint8_t fraction) = 0;
        virtual void enableUsart() = 0;
        virtual void setWordLength(uint8_t wordLength) = 0;
        virtual void setParity(uint8_t parity) = 0;
};
