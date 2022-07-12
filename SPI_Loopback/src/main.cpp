#include "main.hpp"

int main()
{
    mcu_init();

    while (1)
    {
        __NOP();
    }
}
