#include "utils/spi.hpp"

void SPI_SendData(SPI_TypeDef *SPIx, uint8_t *TxBuffer, int count)
{
    for (int i = 0; i < count; i++)
    {
        if (TxBuffer)
        {
            SPIx->DR = *TxBuffer++;
        }
    }
}

void SPI_RecieveData(SPI_TypeDef *SPIx, uint8_t *RxBuffer, int count)
{
    for (int i = 0; i < count; i++)
    {
        while (!(SPIx->SR & SPI_SR_RXNE_Msk));
        if (RxBuffer)
        {
            *RxBuffer++ = SPIx->DR;
        }
    }
}
