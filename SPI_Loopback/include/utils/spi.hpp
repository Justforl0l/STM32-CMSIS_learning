#pragma once

#include "stm32f103xb.h"

void SPI_SendData(SPI_TypeDef *SPIx, uint8_t *TxBuffer, int count);
void SPI_RecieveData(SPI_TypeDef *SPIx, uint8_t *RxBuffer, int count);
