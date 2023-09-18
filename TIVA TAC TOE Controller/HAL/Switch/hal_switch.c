#include "hal_switch.h"

Std_ReturnType Switch_Init(void)
{
    Std_ReturnType ret = GPIO_PortxInit(PORTF);
    return ret;
}

Std_ReturnType Switch1_Read(uint8 *switch1)
{
    Std_ReturnType ret = GPIO_PortxPinRead(PORTF, PIN0, switch1);
    return ret;
}

Std_ReturnType Switch2_Read(uint8 *switch2)
{
    Std_ReturnType ret = GPIO_PortxPinRead(PORTF, PIN4, switch2);
    return ret;
}
