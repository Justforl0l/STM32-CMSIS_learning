#include "main.hpp"

uint8_t TxBuffer[4], RxBuffer[4];
uint16_t TxBuffer16[4], RxBuffer16[4];

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
            GPIOB->BRR |= GPIO_BRR_BR10;
            SPI_SendRecieveData(SPI2, TxBuffer, RxBuffer, 4);
            GPIOB->BSRR |= GPIO_BSRR_BS10;
            for (j = 0; j < 4; j++)
            {
                if (RxBuffer[j] != TxBuffer[j])
                {
                    assert_failed((uint8_t *)__FILE__, __LINE__);
                }
            }
        }

        for (i = 0; i < 8; i++)
        {
            for (j = 0; j < 4; j++)
            {
                TxBuffer16[j] = i * 4 + j + (i << 8);
            }
            GPIOB->BRR |= GPIO_BRR_BR10;
            SPI_SendRecieveData16(SPI2, TxBuffer16, RxBuffer16, 4);
            GPIOB->BSRR |= GPIO_BSRR_BS10;
            for (j = 0; j < 4; j++)
            {
                if (RxBuffer16[j] != TxBuffer16[j])
                {
                    assert_failed((uint8_t *)__FILE__, __LINE__);
                }
            }
        }
    }
}

void assert_failed(uint8_t *file, uint32_t line)
{
    while (1);
}
