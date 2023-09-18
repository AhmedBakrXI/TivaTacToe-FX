#ifndef __HAL_SERIAL_PC_H__
#define __HAL_SERIAL_PC_H__

#include "../../MCAL/GPIO/mcal_gpio.h"
#include "../../MCAL/SYSCTL/mcal_sysctl.h"
#include "../../MCAL/UART/mcal_uart.h"


extern Std_ReturnType Serial_BeginComm();
extern Std_ReturnType Serial_EndComm();
extern Std_ReturnType Serial_SendChar(uint8 c);
extern Std_ReturnType Serial_ReceiveChar(uint8 *c);


#endif /**<__HAL_SERIAL_PC_H__*/
