#include "main.hpp"

int main()
{
    mcu_init();

    static const uint8_t __attribute__((section(".rodata.ST7735S_InitCommandList"), used))
        commandList[] = {
            19,
            ST7735S_CMD_SWRESET,    ST7735S_CMD_DELAY,
                120,
            ST7735S_CMD_SLPOUT,     ST7735S_CMD_DELAY,
                255,
            ST7735S_CMD_FRMCTR1,    3,
                0x01, 0x2C, 0x2D,
            ST7735S_CMD_FRMCTR2,    3,
                0x01, 0x2C, 0x2D,
            ST7735S_CMD_FRMCTR3,    6,
                0x01, 0x2C, 0x2D,
                0x01, 0x2C, 0x2D,
            ST7735S_CMD_INVCTR,     1,
                0x07,
            ST7735S_CMD_PWRCTR1,    3,
                0xA2, 0x02, 0x84,
            ST7735S_CMD_PWRCTR2,    1,
                0xC5,
            ST7735S_CMD_PWRCTR3,    2,
                0x0A, 0x00,
            ST7735S_CMD_PWRCTR4,    2,
                0x8A, 0x2A,
            ST7735S_CMD_PWRCTR5,    2,
                0x8A, 0xEE,
            ST7735S_CMD_VMCTR1,     1,
                0x0E,
            ST7735S_CMD_INVOFF,     0,
            ST7735S_CMD_MADCTL,     1,
                0x08,
            ST7735S_CMD_COLMOD,     1,
                0x05,
            ST7735S_CMD_CASET,      4,
                0x00, 0x00,
                0x00, 0x7F,
            ST7735S_CMD_RASET,      4,
                0x00, 0x00,
                0x00, 0x9F,
            ST7735S_CMD_NORON,      ST7735S_CMD_DELAY,
                10,
            ST7735S_CMD_DISPON,     ST7735S_CMD_DELAY,
                255
        };

    ST7735_init(SPI2, commandList);
    ST7735_backlight(1);

    while (1)
    {
        fillScreen(SPI2, _RED);
        delay(1000);
        fillScreen(SPI2, _GREEN);
        delay(1000);
        fillScreen(SPI2, _BLUE);
        delay(1000);
    }
}

void SysTick_Handler()
{
    TICK++;
}

void ST7735_init(SPI_TypeDef *SPIx, const uint8_t *commandList)
{
    uint8_t numCommands, command, numArgs;
    uint16_t ms;

    numCommands = *commandList++;
    while (numCommands--)
    {
        command = *commandList++;
        numArgs = *commandList++;
        ms = numArgs & ST7735S_CMD_DELAY;
        numArgs &= ~ST7735S_CMD_DELAY;
        sendCommand(SPI2, command, commandList, numArgs);
        commandList += numArgs;

        if (ms)
        {
            ms = *commandList++;
            if (ms == 255)
            {
                ms = 500;
            }
            delay(ms);
        }
    }
}

void sendCommand(SPI_TypeDef *SPIx, uint8_t command,
                 const uint8_t *address, uint8_t numArgs)
{
    TFT_PORT_DC->BRR |= GPIO_BRR_BR2;           // Command mode
    TFT_PORT_SCE-> BRR |= GPIO_BRR_BR3;
    SPI_SendData(SPIx, &command, 1);
    while (SPIx->SR & SPI_SR_BSY_Msk);
    TFT_PORT_SCE-> BSRR |= GPIO_BSRR_BS3;
    if (numArgs)
    {
        while (numArgs)
        {
            TFT_PORT_DC->BSRR |= GPIO_BSRR_BS2;
            TFT_PORT_SCE-> BRR |= GPIO_BRR_BR3;
            SPI_SendData(SPIx, (uint8_t *)address, 1);
            while (SPIx->SR & SPI_SR_BSY_Msk);
            TFT_PORT_SCE-> BSRR |= GPIO_BSRR_BS3;
            address++;
            numArgs--;
        }
    }
}

void ST7735_backlight(uint8_t on)
{
    if (on)
    {
        TFT_PORT_BLK->BSRR |= GPIO_BSRR_BS1;
    }
    else
    {
        TFT_PORT_BLK->BRR |= GPIO_BRR_BR1;
    }
}

void fillScreen(SPI_TypeDef *SPIx, uint16_t color)
{
    uint8_t x, y;

    for (x = 0; x < ST7735_WIDTH; x++)
    {
        for (y = 0; y < ST7735_HEIGHT; y++)
        {
            ST7735_pushColor(SPIx, color, 1);
        }
    }
}

void ST7735_pushColor(SPI_TypeDef *SPIx, uint16_t color, int count)
{
    uint8_t msb_color = color >> 8;
    uint8_t lsb_color = color & 0xFF;

    TFT_PORT_DC->BSRR |= GPIO_BSRR_BS2;
    TFT_PORT_SCE-> BRR |= GPIO_BRR_BR3;
    SPI_SendData(SPIx, &msb_color, count);
    SPI_SendData(SPIx, &lsb_color, count);
    while (SPIx->SR & SPI_SR_BSY_Msk);
    TFT_PORT_SCE-> BSRR |= GPIO_BSRR_BS3;
}

void delay(uint32_t delay_ms)
{
    uint32_t timeStamp = TICK;
    while (TICK - timeStamp < delay_ms);
}
