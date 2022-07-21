#pragma once

/**
 * @brief System Function Command List
 * 
 */

#define ST7735S_CMD_NOP                 0x00
#define ST7735S_CMD_SWRESET             0x01
#define ST7735S_CMD_RDDID               0x04
#define ST7735S_CMD_RDDST               0x09
#define ST7735S_CMD_RDDPM               0x0A
#define ST7735S_CMD_RDDMADCTL           0x0B
#define ST7735S_CMD_RDDCOLMOD           0x0C
#define ST7735S_CMD_RDDIM               0x0D
#define ST7735S_CMD_RDDSM               0x0E
#define ST7735S_CMD_RDDSDR              0x0F

#define ST7735S_CMD_SLPIN               0x10
#define ST7735S_CMD_SLPOUT              0x11
#define ST7735S_CMD_PTLON               0x12
#define ST7735S_CMD_NORON               0x13

#define ST7735S_CMD_INVOFF              0x20
#define ST7735S_CMD_INVON               0x21
#define ST7735S_CMD_GAMSET              0x26
#define ST7735S_CMD_DISPOFF             0x28
#define ST7735S_CMD_DISPON              0x29
#define ST7735S_CMD_CASET               0x2A
#define ST7735S_CMD_RASET               0x2B
#define ST7735S_CMD_RAMWR               0x2C
#define ST7735S_CMD_RGBSET              0x2D
#define ST7735S_CMD_RAMRD               0x2E

#define ST7735S_CMD_PTLAR               0x30
#define ST7735S_CMD_SCRLAR              0x33
#define ST7735S_CMD_TEOFF               0x34
#define ST7735S_CMD_TEON                0x35
#define ST7735S_CMD_MADCTL              0x36
#define ST7735S_CMD_VSCSAD              0x37
#define ST7735S_CMD_IDMOFF              0x38
#define ST7735S_CMD_IDMON               0x39
#define ST7735S_CMD_COLMOD              0x3A

#define ST7735S_CMD_RDID1               0xDA
#define ST7735S_CMD_RDID2               0xDB
#define ST7735S_CMD_RDID3               0xDC

/**
 * @brief Panel Function Command List
 * 
 */

#define ST7735S_CMD_FRMCTR1             0xB1
#define ST7735S_CMD_FRMCTR2             0xB2
#define ST7735S_CMD_FRMCTR3             0xB3
#define ST7735S_CMD_INVCTR              0xB4

#define ST7735S_CMD_PWRCTR1             0xC0
#define ST7735S_CMD_PWRCTR2             0xC1
#define ST7735S_CMD_PWRCTR3             0xC2
#define ST7735S_CMD_PWRCTR4             0xC3
#define ST7735S_CMD_PWRCTR5             0xC4
#define ST7735S_CMD_VMCTR1              0xC5
#define ST7735S_CMD_VMOFCTR             0xC7

#define ST7735S_CMD_WRID2               0xD1
#define ST7735S_CMD_WRID3               0xD2
#define ST7735S_CMD_NVCTR1              0xD9
#define ST7735S_CMD_NVCTR2              0xDE
#define ST7735S_CMD_NVCTR3              0xDF

#define ST7735S_CMD_GMCTRP1             0xE0
#define ST7735S_CMD_GMCTRN1             0xE1

#define ST7735S_CMD_GCV                 0xFC

/**
 * @brief Custom Commands
 * 
 */

#define ST7735S_CMD_DELAY               0x80
