/******************************************************************
*******************************************************************
********************* Name     : Ahmed Bakr     *******************
********************* File     : application.c  *******************
********************* Version  : 1.0            *******************
*******************************************************************
*******************************************************************/

#include "application.h"

Std_ReturnType ret = E_OK;

uint8 sw1 = SWITCH_RELEASED;
uint8 sw2 = SWITCH_RELEASED;

int main()
{
    app_init();

    while(1)
    {
        ret &= Switch1_Read(&sw1);
        ret &= Switch2_Read(&sw2);

        if(SWITCH_PRESSED == sw1)
        {
            Serial_SendChar('A');
            Led_RGB(GREEN);
            delay();
        }
        else if(SWITCH_PRESSED == sw2)
        {
            Serial_SendChar('B');
            Led_RGB(GREEN);
            delay();
        }
        else
        {
            Led_RGB(RED);
        }
    }
}

void app_init(void)
{
    ret = SysCtl_ClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC | SYSCTL_OSC_INT | SYSCTL_MAIN_OSC_DIS);

    ret &= Led_Init();
    ret &= Switch_Init();

    ret &= Serial_BeginComm();

    ret &= Led_RGB(PINK);

    int delay_counter = 0;
    for(delay_counter = 0; delay_counter < 14; delay_counter++)
    {
        delay();
    }
}

void delay(void)
{
    volatile uint32 time;
    time = 727240 * 50 / 91; 
    while (time)
    {
        time--;
    }
}
