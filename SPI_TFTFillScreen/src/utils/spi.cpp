#include "utils/spi.hpp"

void SPI_SendData(SPI_TypeDef *SPIx, uint8_t *TxBuffer, int count)
{
    while (count != 0)
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
        count--;
    }
}
