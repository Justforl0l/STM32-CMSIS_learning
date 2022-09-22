#pragma once

#include "stm32f103xb.h"

#include "config.hpp"
#include <inc/usartInterface.hpp>

// TODO: Реализовать проверку определения служебных констант

class UsartInterfaceImpl : public UsartInterface
{
    private:
        USART_TypeDef* _USART;

    public:
        UsartInterfaceImpl(USART_TypeDef* USARTx);
        inline bool isDataReadyToBeRead();
        inline void waitUntilDataIsSent();
        inline void waitUntilTransmissionIsComplete();
        inline void sendData(uint8_t* data, uint8_t count);
        inline uint8_t receiveData();
        inline void setBaudrate(uint16_t mantissa, uint8_t fraction);
        inline void enableUsart();
        inline void setWordLength(uint8_t wordLength);
        inline void setParity(uint8_t parity);
};

UsartInterfaceImpl::UsartInterfaceImpl(USART_TypeDef* USARTx)
{
    _USART = USARTx;
}

inline bool UsartInterfaceImpl::isDataReadyToBeRead()
{
    return (_USART->SR & USART_SR_RXNE_Msk);
}

inline void UsartInterfaceImpl::waitUntilDataIsSent()
{
    while (!(_USART->SR & USART_SR_TXE_Msk));
}

inline void UsartInterfaceImpl::waitUntilTransmissionIsComplete()
{
    while (!(_USART->SR & USART_SR_TC_Msk));
}

inline void UsartInterfaceImpl::sendData(uint8_t* data, uint8_t count)
{
    while (!count)
    {
        waitUntilDataIsSent();
        if (data)
        {
            _USART->DR = *data++;
        }
        else
        {
            _USART->DR = 0xFF;
        }
        count--;
    }
}

inline uint8_t UsartInterfaceImpl::receiveData()
{
    return (_USART->DR & 0xFF);
}

inline void UsartInterfaceImpl::setBaudrate(uint16_t mantissa, uint8_t fraction)
{
    _USART->BRR = (((mantissa & 0xFFF) << 4) | (fraction & 0xF));
}

inline void UsartInterfaceImpl::enableUsart()
{
    _USART->CR1 |= USART_CR1_UE;
}

inline void UsartInterfaceImpl::setWordLength(uint8_t wordLength)
{
    _USART->CR1 |= (wordLength << 12);
}

inline void UsartInterfaceImpl::setParity(uint8_t parity)
{
    _USART->CR1 |= (parity << 9);
}
