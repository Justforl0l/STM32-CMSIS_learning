#pragma once

#include "stm32f103xb.h"

void SPI_SendRecieveData(SPI_TypeDef *SPIx, uint8_t *TxBuffer,
                         uint8_t *RxBuffer, int count);
void SPI_SendRecieveData16(SPI_TypeDef *SPIx, uint16_t *TxBuffer16,
                           uint16_t *RxBuffer16, int count);
