#pragma once

#include "stm32f103xb.h"

#include <inc/ST7735S.hpp>

extern JST7735S *display;

inline void disableDMA()
{
    DMA1_Channel5->CCR &= ~(DMA_CCR_EN);
}

#ifdef __cplusplus
extern "C"
{
    #endif //__cplusplus

    void DMA1_Channel5_IRQHandler();

    #ifdef __cplusplus
}
#endif //__cplusplus
