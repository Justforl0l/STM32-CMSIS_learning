#pragma once

#include "stm32f103xb.h"
#include "init.hpp"

void led_toggle();
void delay(uint8_t delay_ms);

#ifdef __cplusplus
extern "C"
{
    #endif // __cplusplus

    void SysTick_Handler();
    void HardFault_Handler();

    #ifdef __cplusplus
}
#endif // _cplusplus
