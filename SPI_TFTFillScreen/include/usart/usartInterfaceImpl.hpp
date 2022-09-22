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
        inline void disableUsart();
        inline void enableTransmitter();
        inline void disableTransmitter();
        inline void enableReceiver();
        inline void disableReceiver();
        inline void setWordLength(uint8_t wordLength);
        inline void setParity(uint8_t parity);
        inline void setStopBits(uint8_t stopBit);
        inline void sendIdleFrame();
        inline void sendBreakFrame();
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

inline void UsartInterfaceImpl::disableUsart()
{
    _USART->CR1 &= ~(USART_CR1_UE_Msk);
}

inline void UsartInterfaceImpl::enableTransmitter()
{
    _USART->CR1 |= USART_CR1_TE;
}

inline void UsartInterfaceImpl::disableTransmitter()
{
    _USART->CR1 &= ~(USART_CR1_TE_Msk);
}

inline void UsartInterfaceImpl::enableReceiver()
{
    _USART->CR1 |= USART_CR1_RE;
}

inline void UsartInterfaceImpl::disableReceiver()
{
    _USART->CR1 &= ~(USART_CR1_RE_Msk);
}

inline void UsartInterfaceImpl::setWordLength(uint8_t wordLength)
{
    _USART->CR1 |= (wordLength << 12);
}

inline void UsartInterfaceImpl::setParity(uint8_t parity)
{
    _USART->CR1 |= (parity << 9);
}

inline void UsartInterfaceImpl::setStopBits(uint8_t stopBit)
{
    _USART->CR2 |= ((stopBit & 0x3) << 12);
}

inline void UsartInterfaceImpl::sendIdleFrame()
{
    _USART->CR1 |= USART_CR1_TE;
}

inline void UsartInterfaceImpl::sendBreakFrame()
{
    _USART->CR1 |= USART_CR1_SBK;
}
