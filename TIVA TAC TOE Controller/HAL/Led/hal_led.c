#include "hal_led.h"

Std_ReturnType Led_Init(void)
{
    Std_ReturnType ret = GPIO_PortxInit(PORTF);
    return ret;
}

Std_ReturnType Led_RGB(uint8 color)
{
    Std_ReturnType ret = GPIO_PortxWrite(PORTF, color);
    return ret;
}
