#include "main.hpp"

uint8_t TxBuffer[4], RxBuffer[4];

int main()
{
    int i, j;

    mcu_init();

    while (1)
    {
        for (i = 0; i < 8; i++)
        {
            for (j = 0; j < 4; j++)
            {
                TxBuffer[j] = i * 4 + j;
            }
            SPI_SendRecieveData(SPI2, TxBuffer, RxBuffer, 4);
        }
    }
}
