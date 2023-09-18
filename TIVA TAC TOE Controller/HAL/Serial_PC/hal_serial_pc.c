#include "hal_serial_pc.h"

Std_ReturnType Serial_BeginComm()
{
    Std_ReturnType ret = E_OK;
    ret &= SysCtl_PortEnable(PORTA);
    ret &= SysCtl_UartxEnable(UART0);

    return ret;
}

Std_ReturnType Serial_EndComm()
{
    Std_ReturnType ret = E_OK;

    ret &= SysCtl_PortDisable(PORTA);
    ret &= SysCtl_UartxDisable(UART0);

    return ret;
}

Std_ReturnType Serial_SendChar(char c)
{
}

Std_ReturnType Serial_ReceiveChar(char *c)
{
}
