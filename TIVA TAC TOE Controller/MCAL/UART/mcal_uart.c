#include "mcal_uart.h"


Std_ReturnType Uart_xInit(uint8 uartx, uint32 baudrate, uint8 parity_bits, uint8 stop_bits)
{
    Std_ReturnType ret = E_OK;

    switch (uartx)
    {
    case UART0:
        /* code */
        UART0_CTL_R = 0; // Disable Uart module

        // Calculate Baud Rate
        UART0_IBRD_R = (uint16)(F_CPU / (16 * baudrate));
        UART0_FBRD_R = (uint16)(((F_CPU / (16 * baudrate)) - UART0_IBRD_R) * 64 + 0.5);

        UART0_CC_R = 0; // Choose System Clk

        ADD_VALUE_REG(UART0_LCRH_R, UART_LCRH_WLEN_8);   // 8 bits message
        ADD_VALUE_REG(UART0_LCRH_R, UART_LCRH_FEN);      // enable FIFO

        if (STOP_BITS_ONE == stop_bits)
        {
            CLEAR_VALUE_REG(UART0_LCRH_R, UART_LCRH_STP2);    // One Stop bit
        } 
        else if(STOP_BITS_TWO == stop_bits)
        {
            ADD_VALUE_REG(UART0_LCRH_R, UART_LCRH_STP2);  // Two Stop bits
        }
        else {/**<Nothing*/}

        if(PARITY_NONE == parity_bits)
        {
            CLEAR_VALUE_REG(UART0_LCRH_R, UART_LCRH_PEN);
        }
        else if(PARITY_EVEN == parity_bits)
        {
            ADD_VALUE_REG(UART0_LCRH_R, UART_LCRH_PEN);
            ADD_VALUE_REG(UART0_LCRH_R, UART_LCRH_EPS);
        }
        else if(PARITY_ODD == parity_bits)
        {
            ADD_VALUE_REG(UART0_LCRH_R, UART_LCRH_PEN);
            CLEAR_VALUE_REG(UART0_LCRH_R, UART_LCRH_EPS);
        }
        else {/**<Nothing*/}

        // Enable uart, tx, rx
        ADD_VALUE_REG(UART0_CTL_R, UART_CTL_UARTEN);
        ADD_VALUE_REG(UART0_CTL_R, UART_CTL_TXE);
        ADD_VALUE_REG(UART0_CTL_R, UART_CTL_RXE);

        ret = E_OK;
        break;


    case UART1:
        /* code */
        UART1_CTL_R = 0; // Disable Uart module

        // Calculate Baud Rate
        UART1_IBRD_R = (uint16)(F_CPU / (16 * baudrate));
        UART1_FBRD_R = (uint16)(((F_CPU / (16 * baudrate)) - UART1_IBRD_R) * 64 + 0.5);

        UART1_CC_R = 0; // Choose System Clk

        ADD_VALUE_REG(UART1_LCRH_R, UART_LCRH_WLEN_8);   // 8 bits message
        ADD_VALUE_REG(UART1_LCRH_R, UART_LCRH_FEN);      // enable FIFO

        if (STOP_BITS_ONE == stop_bits)
        {
            CLEAR_VALUE_REG(UART1_LCRH_R, UART_LCRH_STP2);    // One Stop bit
        } 
        else if(STOP_BITS_TWO == stop_bits)
        {
            ADD_VALUE_REG(UART1_LCRH_R, UART_LCRH_STP2);  // Two Stop bits
        }
        else {/**<Nothing*/}

        if(PARITY_NONE == parity_bits)
        {
            CLEAR_VALUE_REG(UART1_LCRH_R, UART_LCRH_PEN);
        }
        else if(PARITY_EVEN == parity_bits)
        {
            ADD_VALUE_REG(UART1_LCRH_R, UART_LCRH_PEN);
            ADD_VALUE_REG(UART1_LCRH_R, UART_LCRH_EPS);
        }
        else if(PARITY_ODD == parity_bits)
        {
            ADD_VALUE_REG(UART1_LCRH_R, UART_LCRH_PEN);
            CLEAR_VALUE_REG(UART1_LCRH_R, UART_LCRH_EPS);
        }
        else {/**<Nothing*/}

        // Enable uart, tx, rx
        ADD_VALUE_REG(UART1_CTL_R, UART_CTL_UARTEN);
        ADD_VALUE_REG(UART1_CTL_R, UART_CTL_TXE);
        ADD_VALUE_REG(UART1_CTL_R, UART_CTL_RXE);

        ret = E_OK;
        break;

    case UART2:
        /* code */
        UART2_CTL_R = 0; // Disable Uart module

        // Calculate Baud Rate
        UART2_IBRD_R = (uint16)(F_CPU / (16 * baudrate));
        UART2_FBRD_R = (uint16)(((F_CPU / (16 * baudrate)) - UART2_IBRD_R) * 64 + 0.5);

        UART2_CC_R = 0; // Choose System Clk

        ADD_VALUE_REG(UART2_LCRH_R, UART_LCRH_WLEN_8);   // 8 bits message
        ADD_VALUE_REG(UART2_LCRH_R, UART_LCRH_FEN);      // enable FIFO

        if (STOP_BITS_ONE == stop_bits)
        {
            CLEAR_VALUE_REG(UART2_LCRH_R, UART_LCRH_STP2);    // One Stop bit
        } 
        else if(STOP_BITS_TWO == stop_bits)
        {
            ADD_VALUE_REG(UART2_LCRH_R, UART_LCRH_STP2);  // Two Stop bits
        }
        else {/**<Nothing*/}

        if(PARITY_NONE == parity_bits)
        {
            CLEAR_VALUE_REG(UART2_LCRH_R, UART_LCRH_PEN);
        }
        else if(PARITY_EVEN == parity_bits)
        {
            ADD_VALUE_REG(UART2_LCRH_R, UART_LCRH_PEN);
            ADD_VALUE_REG(UART2_LCRH_R, UART_LCRH_EPS);
        }
        else if(PARITY_ODD == parity_bits)
        {
            ADD_VALUE_REG(UART2_LCRH_R, UART_LCRH_PEN);
            CLEAR_VALUE_REG(UART2_LCRH_R, UART_LCRH_EPS);
        }
        else {/**<Nothing*/}

        // Enable uart, tx, rx
        ADD_VALUE_REG(UART2_CTL_R, UART_CTL_UARTEN);
        ADD_VALUE_REG(UART2_CTL_R, UART_CTL_TXE);
        ADD_VALUE_REG(UART2_CTL_R, UART_CTL_RXE);

        ret = E_OK;
        break;


    case UART3:
        /* code */
        UART3_CTL_R = 0; // Disable Uart module

        // Calculate Baud Rate
        UART3_IBRD_R = (uint16)(F_CPU / (16 * baudrate));
        UART3_FBRD_R = (uint16)(((F_CPU / (16 * baudrate)) - UART3_IBRD_R) * 64 + 0.5);

        UART3_CC_R = 0; // Choose System Clk

        ADD_VALUE_REG(UART3_LCRH_R, UART_LCRH_WLEN_8);   // 8 bits message
        ADD_VALUE_REG(UART3_LCRH_R, UART_LCRH_FEN);      // enable FIFO

        if (STOP_BITS_ONE == stop_bits)
        {
            CLEAR_VALUE_REG(UART3_LCRH_R, UART_LCRH_STP2);    // One Stop bit
        } 
        else if(STOP_BITS_TWO == stop_bits)
        {
            ADD_VALUE_REG(UART3_LCRH_R, UART_LCRH_STP2);  // Two Stop bits
        }
        else {/**<Nothing*/}

        if(PARITY_NONE == parity_bits)
        {
            CLEAR_VALUE_REG(UART3_LCRH_R, UART_LCRH_PEN);
        }
        else if(PARITY_EVEN == parity_bits)
        {
            ADD_VALUE_REG(UART3_LCRH_R, UART_LCRH_PEN);
            ADD_VALUE_REG(UART3_LCRH_R, UART_LCRH_EPS);
        }
        else if(PARITY_ODD == parity_bits)
        {
            ADD_VALUE_REG(UART3_LCRH_R, UART_LCRH_PEN);
            CLEAR_VALUE_REG(UART3_LCRH_R, UART_LCRH_EPS);
        }
        else {/**<Nothing*/}

        // Enable uart, tx, rx
        ADD_VALUE_REG(UART3_CTL_R, UART_CTL_UARTEN);
        ADD_VALUE_REG(UART3_CTL_R, UART_CTL_TXE);
        ADD_VALUE_REG(UART3_CTL_R, UART_CTL_RXE);

        ret = E_OK;
        break;


    case UART4:
        /* code */
        UART4_CTL_R = 0; // Disable Uart module

        // Calculate Baud Rate
        UART4_IBRD_R = (uint16)(F_CPU / (16 * baudrate));
        UART4_FBRD_R = (uint16)(((F_CPU / (16 * baudrate)) - UART4_IBRD_R) * 64 + 0.5);

        UART0_CC_R = 0; // Choose System Clk

        ADD_VALUE_REG(UART4_LCRH_R, UART_LCRH_WLEN_8);   // 8 bits message
        ADD_VALUE_REG(UART4_LCRH_R, UART_LCRH_FEN);      // enable FIFO

        if (STOP_BITS_ONE == stop_bits)
        {
            CLEAR_VALUE_REG(UART4_LCRH_R, UART_LCRH_STP2);    // One Stop bit
        } 
        else if(STOP_BITS_TWO == stop_bits)
        {
            ADD_VALUE_REG(UART4_LCRH_R, UART_LCRH_STP2);  // Two Stop bits
        }
        else {/**<Nothing*/}

        if(PARITY_NONE == parity_bits)
        {
            CLEAR_VALUE_REG(UART4_LCRH_R, UART_LCRH_PEN);
        }
        else if(PARITY_EVEN == parity_bits)
        {
            ADD_VALUE_REG(UART4_LCRH_R, UART_LCRH_PEN);
            ADD_VALUE_REG(UART4_LCRH_R, UART_LCRH_EPS);
        }
        else if(PARITY_ODD == parity_bits)
        {
            ADD_VALUE_REG(UART4_LCRH_R, UART_LCRH_PEN);
            CLEAR_VALUE_REG(UART4_LCRH_R, UART_LCRH_EPS);
        }
        else {/**<Nothing*/}

        // Enable uart, tx, rx
        ADD_VALUE_REG(UART4_CTL_R, UART_CTL_UARTEN);
        ADD_VALUE_REG(UART4_CTL_R, UART_CTL_TXE);
        ADD_VALUE_REG(UART4_CTL_R, UART_CTL_RXE);

        ret = E_OK;
        break;


    case UART5:
        /* code */
        UART5_CTL_R = 0; // Disable Uart module

        // Calculate Baud Rate
        UART5_IBRD_R = (uint16)(F_CPU / (16 * baudrate));
        UART5_FBRD_R = (uint16)(((F_CPU / (16 * baudrate)) - UART5_IBRD_R) * 64 + 0.5);

        UART5_CC_R = 0; // Choose System Clk

        ADD_VALUE_REG(UART5_LCRH_R, UART_LCRH_WLEN_8);   // 8 bits message
        ADD_VALUE_REG(UART5_LCRH_R, UART_LCRH_FEN);      // enable FIFO

        if (STOP_BITS_ONE == stop_bits)
        {
            CLEAR_VALUE_REG(UART5_LCRH_R, UART_LCRH_STP2);    // One Stop bit
        } 
        else if(STOP_BITS_TWO == stop_bits)
        {
            ADD_VALUE_REG(UART5_LCRH_R, UART_LCRH_STP2);  // Two Stop bits
        }
        else {/**<Nothing*/}

        if(PARITY_NONE == parity_bits)
        {
            CLEAR_VALUE_REG(UART5_LCRH_R, UART_LCRH_PEN);
        }
        else if(PARITY_EVEN == parity_bits)
        {
            ADD_VALUE_REG(UART5_LCRH_R, UART_LCRH_PEN);
            ADD_VALUE_REG(UART5_LCRH_R, UART_LCRH_EPS);
        }
        else if(PARITY_ODD == parity_bits)
        {
            ADD_VALUE_REG(UART5_LCRH_R, UART_LCRH_PEN);
            CLEAR_VALUE_REG(UART5_LCRH_R, UART_LCRH_EPS);
        }
        else {/**<Nothing*/}

        // Enable uart, tx, rx
        ADD_VALUE_REG(UART5_CTL_R, UART_CTL_UARTEN);
        ADD_VALUE_REG(UART5_CTL_R, UART_CTL_TXE);
        ADD_VALUE_REG(UART5_CTL_R, UART_CTL_RXE);

        ret = E_OK;
        break;


    case UART6:
        /* code */
        UART6_CTL_R = 0; // Disable Uart module

        // Calculate Baud Rate
        UART6_IBRD_R = (uint16)(F_CPU / (16 * baudrate));
        UART6_FBRD_R = (uint16)(((F_CPU / (16 * baudrate)) - UART6_IBRD_R) * 64 + 0.5);

        UART6_CC_R = 0; // Choose System Clk

        ADD_VALUE_REG(UART6_LCRH_R, UART_LCRH_WLEN_8);   // 8 bits message
        ADD_VALUE_REG(UART6_LCRH_R, UART_LCRH_FEN);      // enable FIFO

        if (STOP_BITS_ONE == stop_bits)
        {
            CLEAR_VALUE_REG(UART6_LCRH_R, UART_LCRH_STP2);    // One Stop bit
        } 
        else if(STOP_BITS_TWO == stop_bits)
        {
            ADD_VALUE_REG(UART6_LCRH_R, UART_LCRH_STP2);  // Two Stop bits
        }
        else {/**<Nothing*/}

        if(PARITY_NONE == parity_bits)
        {
            CLEAR_VALUE_REG(UART6_LCRH_R, UART_LCRH_PEN);
        }
        else if(PARITY_EVEN == parity_bits)
        {
            ADD_VALUE_REG(UART6_LCRH_R, UART_LCRH_PEN);
            ADD_VALUE_REG(UART6_LCRH_R, UART_LCRH_EPS);
        }
        else if(PARITY_ODD == parity_bits)
        {
            ADD_VALUE_REG(UART6_LCRH_R, UART_LCRH_PEN);
            CLEAR_VALUE_REG(UART6_LCRH_R, UART_LCRH_EPS);
        }
        else {/**<Nothing*/}

        // Enable uart, tx, rx
        ADD_VALUE_REG(UART6_CTL_R, UART_CTL_UARTEN);
        ADD_VALUE_REG(UART6_CTL_R, UART_CTL_TXE);
        ADD_VALUE_REG(UART6_CTL_R, UART_CTL_RXE);

        ret = E_OK;
        break;


    case UART7:
        /* code */
        UART7_CTL_R = 0; // Disable Uart module

        // Calculate Baud Rate
        UART7_IBRD_R = (uint16)(F_CPU / (16 * baudrate));
        UART7_FBRD_R = (uint16)(((F_CPU / (16 * baudrate)) - UART0_IBRD_R) * 64 + 0.5);

        UART7_CC_R = 0; // Choose System Clk

        ADD_VALUE_REG(UART7_LCRH_R, UART_LCRH_WLEN_8);   // 8 bits message
        ADD_VALUE_REG(UART7_LCRH_R, UART_LCRH_FEN);      // enable FIFO

        if (STOP_BITS_ONE == stop_bits)
        {
            CLEAR_VALUE_REG(UART7_LCRH_R, UART_LCRH_STP2);    // One Stop bit
        } 
        else if(STOP_BITS_TWO == stop_bits)
        {
            ADD_VALUE_REG(UART7_LCRH_R, UART_LCRH_STP2);  // Two Stop bits
        }
        else {/**<Nothing*/}

        if(PARITY_NONE == parity_bits)
        {
            CLEAR_VALUE_REG(UART7_LCRH_R, UART_LCRH_PEN);
        }
        else if(PARITY_EVEN == parity_bits)
        {
            ADD_VALUE_REG(UART7_LCRH_R, UART_LCRH_PEN);
            ADD_VALUE_REG(UART7_LCRH_R, UART_LCRH_EPS);
        }
        else if(PARITY_ODD == parity_bits)
        {
            ADD_VALUE_REG(UART7_LCRH_R, UART_LCRH_PEN);
            CLEAR_VALUE_REG(UART7_LCRH_R, UART_LCRH_EPS);
        }
        else {/**<Nothing*/}

        // Enable uart, tx, rx
        ADD_VALUE_REG(UART7_CTL_R, UART_CTL_UARTEN);
        ADD_VALUE_REG(UART7_CTL_R, UART_CTL_TXE);
        ADD_VALUE_REG(UART7_CTL_R, UART_CTL_RXE);

        ret = E_OK;
        break;

    default:
        ret = E_NOT_OK;
        break;
    }

    return ret;
}

Std_ReturnType Uart_xSendChar(uint8 uartx, uint8 data)
{
    Std_ReturnType ret = E_OK;
    switch (uartx)
    {
    case UART0:
        /* code */
        while((UART0_FR_R & UART_FR_TXFF) != 0);
        UART0_DR_R = data;
        break;
    case UART1:
        /* code */
        while((UART1_FR_R & UART_FR_TXFF) != 0);
        UART1_DR_R = data;
        break;
    case UART2:
        /* code */
        while((UART2_FR_R & UART_FR_TXFF) != 0);
        UART2_DR_R = data;
        break;
    case UART3:
        /* code */
        while((UART3_FR_R & UART_FR_TXFF) != 0);
        UART3_DR_R = data;
        break;
    case UART4:
        /* code */
        while((UART4_FR_R & UART_FR_TXFF) != 0);
        UART4_DR_R = data;
        break;
    case UART5:
        /* code */
        while((UART5_FR_R & UART_FR_TXFF) != 0);
        UART5_DR_R = data;
        break;
    case UART6:
        /* code */
        while((UART6_FR_R & UART_FR_TXFF) != 0);
        UART6_DR_R = data;
        break;
    case UART7:
        /* code */
        while((UART7_FR_R & UART_FR_TXFF) != 0);
        UART7_DR_R = data;
        break;
    
    default:
        ret = E_NOT_OK;
        break;
    }
    return ret;
}

Std_ReturnType Uart_xReceiveChar(uint8 uartx, uint8 *data)
{
    Std_ReturnType ret = E_OK;
    switch (uartx)
    {
    case UART0:
        /* code */
        while((UART0_FR_R & UART_FR_RXFE) != 0); 
        *data = (uint8) UART0_DR_R;
        break;
    case UART1:
        /* code */
        while((UART1_FR_R & UART_FR_RXFE) != 0);
        *data = (uint8) UART1_DR_R;
        break;
    case UART2:
        /* code */
        while((UART2_FR_R & UART_FR_RXFE) != 0);
        *data = (uint8) UART2_DR_R;
        break;
    case UART3:
        /* code */
        while((UART3_FR_R & UART_FR_RXFE) != 0);
        *data = (uint8) UART3_DR_R;
        break;
    case UART4:
        /* code */
        while((UART4_FR_R & UART_FR_RXFE) != 0);
        *data = (uint8) UART4_DR_R;
        break;
    case UART5:
        /* code */
        while((UART5_FR_R & UART_FR_RXFE) != 0);
        *data = (uint8) UART5_DR_R;
        break;
    case UART6:
        /* code */
        while((UART6_FR_R & UART_FR_RXFE) != 0);
        *data = (uint8) UART6_DR_R;
        break;
    case UART7:
        /* code */
        while((UART7_FR_R & UART_FR_RXFE) != 0);
        *data = (uint8) UART7_DR_R;
        break;
    
    default:
        ret = E_NOT_OK;
        break;
    }
    return ret;
}

