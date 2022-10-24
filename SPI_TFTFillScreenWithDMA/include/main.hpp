#pragma once

#include "stm32f103xb.h"

#include "config.hpp"
#include "tft/colors.hpp"
#include "tft/commands.hpp"
#include "tft/TFT16BitMode.hpp"

#include <inc/ST7735S.hpp>

extern uint16_t const colors[] = {
    _RED,
    _GREEN,
    _BLUE
};

#include "init.hpp"

volatile uint32_t TICK = 0;

void delay(uint32_t delay_ms);

inline void enableDMA()
{
    DMA1_Channel5->CCR |= DMA_CCR_EN;
}

inline bool isDMAEnabled()
{
    return ((DMA1_Channel5->CCR & DMA_CCR_EN_Msk) >> DMA_CCR_EN_Pos);
}

#ifdef __cplusplus
extern "C"
{
    #endif // __cplusplus

    void SysTick_Handler();

    #ifdef __cplusplus
}
#endif // __cplusplus
