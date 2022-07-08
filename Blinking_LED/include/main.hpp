#pragma once

#include "stm32f103xb.h"
#include "init.hpp"

volatile uint32_t TICK = 0;

void led_toggle();
void delay(uint32_t delay_ms);

#ifdef __cplusplus
extern "C"
{
    #endif // __cplusplus

    void SysTick_Handler();

    #ifdef __cplusplus
}
#endif // _cplusplus
