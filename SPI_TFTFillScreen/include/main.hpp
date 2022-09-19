#pragma once

#include "stm32f103xb.h"

#include "config.hpp"
#include "init.hpp"

#if (_8BIT_MODE == 1)
    #include "tft/TFT8BitMode.hpp"
#elif (_16BIT_MODE == 1)
    #include "tft/TFT16BitMode.hpp"
#endif

#include <inc/ST7735S.hpp>

#define MADCTLGRAPHICS      0x6
#define MADCTLBMP           0x2

#define ST7735_WIDTH        128
#define ST7735_HEIGHT       160

volatile uint32_t TICK = 0;

void delay(uint32_t delay_ms);

#ifdef __cplusplus
extern "C"
{
    #endif // __cplusplus

    void SysTick_Handler();

    #ifdef __cplusplus
}
#endif // __cplusplus
