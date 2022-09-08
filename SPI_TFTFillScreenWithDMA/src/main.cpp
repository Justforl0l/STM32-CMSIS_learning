#include "main.hpp"

int main()
{
    mcu_init();

    for(;;)
    {
        __NOP();
    }
}
