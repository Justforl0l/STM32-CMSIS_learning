#pragma once

#include "stm32f103xb.h"

/**
 * @brief Clock control register (RCC_CR)
 * 
 */
#define PLLON_MASK_BIT          (1 << 25)
#define CSSON_MASK_BIT          (1 << 19)
#define HSEBYP_MASK_BIT         (1 << 18)
#define HSEON_MASK_BIT          (1 << 16)
#define HSION_MASK_BIT          1
#define CRREG_MASK_BITS         (PLLON_MASK_BIT | CSSON_MASK_BIT |\
                                 HSEBYP_MASK_BIT | HSEON_MASK_BIT |\
                                 HSION_MASK_BIT)

/**
 * @brief Clock configuration register (RCC_CFGR)
 * 
 */
#define MCO_MASK_BITS           ((1 << 26) | (1 << 25) | (1 << 24))
#define PLLMUL_MASK_BITS        ((1 << 21) | (1 << 20) |\
                                 (1 << 19) | (1 << 18))
#define PLLXTPRE_MASK_BIT       (1 << 17)
#define PLLSRC_MASK_BIT         (1 << 16)
#define ADCPRE_MASK_BITS        ((1 << 15) | (1 << 14))
#define PPRE2_MASK_BITS         ((1 << 13) | (1 << 12) | (1 << 11))
#define PPRE1_MASK_BITS         ((1 << 10) | (1 << 9) | (1 << 8))
#define HPRE_MASK_BITS          ((1 << 7) | (1 << 6) |\
                                 (1 << 5) | (1 << 4))
#define SW_MASK_BITS            ((1 << 1) | 1)
#define CFGRREG_MASK_BITS       (MCO_MASK_BITS | PLLMUL_MASK_BITS |\
                                 PLLXTPRE_MASK_BIT | PLLSRC_MASK_BIT |\
                                 ADCPRE_MASK_BITS | PPRE2_MASK_BITS |\
                                 PPRE1_MASK_BITS | HPRE_MASK_BITS | SW_MASK_BITS)

/**
 * @brief Clock configuration register 2 (RCC_CFGR2)
 * 
 */

/**
 * @brief APB2 peripheral clock enable register (RCC_APB2ENR)
 * 
 */
#define IOPCEN_MASK_BIT         (1 << 4)
#define RCC_APB2ENR_MASK_BITS   IOPCEN_MASK_BIT

/**
 * @brief APB1 peripheral clock enable register (RCC_APB1ENR)
 * 
 */
#define PWREN_MASK_BIT          (1 << 28)
#define RCC_APB1ENR_MASK_BITS   PWREN_MASK_BIT

/**
 * @brief Port configuration register high (GPIOx_CRH)
 * 
 */
#define CNF13_MASK_BITS         ((1 << 23) | (1 << 22))
#define MODE13_MASK_BITS        ((1 << 21) | (1 << 20))

#define TimerTick               F_CPU/1000 - 1

void mcu_init();
void clock_init();
void gpio_init();
void systick_init();
