#include "utils/spi.hpp"

void SPI_SendData(SPI_TypeDef *SPIx, uint8_t *TxBuffer, int count)
{
    while (count != 0)
    {
        while (!(SPIx->SR & SPI_SR_TXE_Msk));
        SPIx->DR = *TxBuffer++;
        count--;
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
