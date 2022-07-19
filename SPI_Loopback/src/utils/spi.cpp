#include "utils/spi.hpp"

void SPI_SendRecieveData(SPI_TypeDef *SPIx, uint8_t *TxBuffer,
                         uint8_t *RxBuffer, int count)
{
    for (int i = 0; i < count; i++)
    {
        while (!(SPIx->SR & SPI_SR_TXE_Msk));
        if (TxBuffer)
        {
            SPIx->DR = *TxBuffer++;
        }
        else
        {
            SPIx->DR = 0xFF;
        }
        while (!(SPIx->SR & SPI_SR_RXNE_Msk));
        if (RxBuffer)
        {
            *RxBuffer++ = SPIx->DR;
        }
        else
        {
            SPIx->DR;
        }
    }
}

void SPI_SendRecieveData16(SPI_TypeDef *SPIx, uint16_t *TxBuffer16,
                           uint16_t *RxBuffer16, int count)
{
    SPIx->CR1 |= SPI_CR1_DFF;
    for (int i = 0; i < count; i++)
    {
        while (!(SPIx->SR & SPI_SR_TXE_Msk));
        if (TxBuffer16)
        {
            SPIx->DR = *TxBuffer16++;
        }
        else
        {
            SPIx->DR = 0xFF;
        }
        while (!(SPIx->SR & SPI_SR_RXNE_Msk));
        if (RxBuffer16)
        {
            *RxBuffer16++ = SPIx->DR;
        }
        else
        {
            SPIx->DR;
        }
    }
    SPIx->CR1 &= ~SPI_CR1_DFF;
}