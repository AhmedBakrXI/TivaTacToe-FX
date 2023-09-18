#ifndef __MCAL_UART_H__
#define __MCAL_UART_H__

#include "../tm4c123gh6pm.h"
#include "../mcal_std_types.h"
#include "../device_config.h"

/**<__MACROS Definition__*/
#define PARITY_NONE     0
#define PARITY_EVEN     1
#define PARITY_ODD      2

#define STOP_BITS_ONE   1
#define STOP_BITS_TWO   2

#define UART0   0
#define UART1   1
#define UART2   2
#define UART3   3
#define UART4   4
#define UART5   5
#define UART6   6
#define UART7   7

/**<__SoftWare Interfaces__*/
extern Std_ReturnType Uart_xInit(uint8 uartx, uint32 baudrate, uint8 parity_bits, uint8 stop_bits);
extern Std_ReturnType Uart_xSendChar(uint8 uartx, uint8 data);
extern Std_ReturnType Uart_xReceiveChar(uint8 uartx, uint8 *data);

#endif /**<__MCAL_UART_H__*/
