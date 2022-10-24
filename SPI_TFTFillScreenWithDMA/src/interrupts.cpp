#include "interrupts.hpp"

void DMA1_Channel5_IRQHandler()
{
    DMA1->IFCR |= DMA_IFCR_CGIF5;
    disableDMA();
}
