#pragma once

#include "stm32f103xb.h"

void SPI_SendRecieveData(SPI_TypeDef *SPIx, uint8_t *TxBuffer,
                         uint8_t *RxBuffer, int count);
