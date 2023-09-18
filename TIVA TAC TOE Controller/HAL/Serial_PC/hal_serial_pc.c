#include "hal_serial_pc.h"

Std_ReturnType Serial_BeginComm()
{
    Std_ReturnType ret = E_OK;
    ret &= SysCtl_PortEnable(PORTA);
    ret &= SysCtl_UartxEnable(UART0);

    ret &= Uart_xInit(UART0, 9600, PARITY_NONE, STOP_BITS_ONE);
    ret &= GPIO_PortxInit(PORTA);

    return ret;
}

Std_ReturnType Serial_EndComm()
{
    Std_ReturnType ret = E_OK;

    ret &= SysCtl_PortDisable(PORTA);
    ret &= SysCtl_UartxDisable(UART0);

    return ret;
}

Std_ReturnType Serial_SendChar(uint8 c)
{
    Std_ReturnType ret = Uart_xSendChar(UART0, c);
    return ret;
}

Std_ReturnType Serial_ReceiveChar(uint8 *c)
{
    Std_ReturnType ret = Uart_xReceiveChar(UART0, c);
    return ret;
}
