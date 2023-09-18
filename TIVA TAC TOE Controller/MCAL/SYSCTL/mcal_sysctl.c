#include "mcal_sysctl.h"

Std_ReturnType SysCtl_ClockSet(uint32 ui32Config)
{
    Std_ReturnType ret = E_NOT_OK;

    uint32 ui32Delay, ui32RCC, ui32RCC2;

    //
    // Get the current value of the RCC and RCC2 registers.
    //
    ui32RCC = SYSCTL_RCC_R;
    ui32RCC2 = SYSCTL_RCC2_R;

    //
    // Bypass the PLL and system clock dividers for now.
    //
    ui32RCC |= SYSCTL_RCC_BYPASS;
    ui32RCC &= ~(SYSCTL_RCC_USESYSDIV);
    ui32RCC2 |= SYSCTL_RCC2_BYPASS2;

    //
    // Write the new RCC value.
    //
    SYSCTL_RCC_R = ui32RCC;
    SYSCTL_RCC2_R = ui32RCC2;

    //
    // See if the oscillator needs to be enabled.
    //
    if ((ui32RCC & SYSCTL_RCC_MOSCDIS) && !(ui32Config & SYSCTL_MAIN_OSC_DIS))
    {
        //
        // Make sure that the required oscillators are enabled.  For now, the
        // previously enabled oscillators must be enabled along with the newly
        // requested oscillators.
        //
        ui32RCC &= (~SYSCTL_RCC_MOSCDIS | (ui32Config & SYSCTL_MAIN_OSC_DIS));

        //
        // Clear the MOSC power up raw interrupt status to be sure it is not
        // set when waiting below.
        //
        SYSCTL_MISC_R = SYSCTL_MISC_MOSCPUPMIS;

        //
        // Write the new RCC value.
        //
        SYSCTL_RCC_R = ui32RCC;

        //
        // Timeout using the legacy delay value.
        //
        ui32Delay = 524288;

        while ((SYSCTL_RIS_R & SYSCTL_RIS_MOSCPUPRIS) == 0)
        {
            ui32Delay--;

            if (ui32Delay == 0)
            {
                break;
            }
        }

        //
        // If the main oscillator failed to start up then do not switch to
        // it and return.
        //
        if (ui32Delay == 0)
        {
            return;
        }
        ret = E_OK;
    }
    return ret;
}

Std_ReturnType SysCtl_PortEnable(uint8 port)
{
    Std_ReturnType ret = E_NOT_OK;

    switch (port)
    {
    case PORTA:
        /* code */
        SET_BIT(SYSCTL_RCGCGPIO_R, PORTA);
        while (READ_BIT(SYSCTL_PRGPIO_R, PORTA) == 0)
            ;
        ret = E_OK;
        break;
    case PORTB:
        /* code */
        SET_BIT(SYSCTL_RCGCGPIO_R, PORTB);
        while (READ_BIT(SYSCTL_PRGPIO_R, PORTB) == 0)
            ;
        ret = E_OK;
        break;
    case PORTC:
        /* code */
        SET_BIT(SYSCTL_RCGCGPIO_R, PORTC);
        while (READ_BIT(SYSCTL_PRGPIO_R, PORTC) == 0)
            ;
        ret = E_OK;
        break;
    case PORTD:
        /* code */
        SET_BIT(SYSCTL_RCGCGPIO_R, PORTD);
        while (READ_BIT(SYSCTL_PRGPIO_R, PORTD) == 0)
            ;
        ret = E_OK;
        break;
    case PORTE:
        /* code */
        SET_BIT(SYSCTL_RCGCGPIO_R, PORTE);
        while (READ_BIT(SYSCTL_PRGPIO_R, PORTE) == 0)
            ;
        ret = E_OK;
        break;
    case PORTF:
        /* code */
        SET_BIT(SYSCTL_RCGCGPIO_R, PORTF);
        while (READ_BIT(SYSCTL_PRGPIO_R, PORTF) == 0)
            ;
        ret = E_OK;
        break;

    default:
        ret = E_NOT_OK;
        break;
    }
    return ret;
}

Std_ReturnType SysCtl_PortDisable(uint8 port)
{
    Std_ReturnType ret = E_NOT_OK;
    switch (port)
    {
    case PORTA:
        /* code */
        CLEAR_BIT(SYSCTL_RCGCGPIO_R, PORTA);
        ret = E_OK;
        break;
    case PORTB:
        /* code */
        CLEAR_BIT(SYSCTL_RCGCGPIO_R, PORTB);
        ret = E_OK;
        break;
    case PORTC:
        /* code */
        CLEAR_BIT(SYSCTL_RCGCGPIO_R, PORTC);
        ret = E_OK;
        break;
    case PORTD:
        /* code */
        CLEAR_BIT(SYSCTL_RCGCGPIO_R, PORTD);
        ret = E_OK;
        break;
    case PORTE:
        /* code */
        CLEAR_BIT(SYSCTL_RCGCGPIO_R, PORTE);
        ret = E_OK;
        break;
    case PORTF:
        /* code */
        CLEAR_BIT(SYSCTL_RCGCGPIO_R, PORTF);
        ret = E_OK;
        break;

    default:
        ret = E_NOT_OK;
        break;
    }

    return ret;
}

Std_ReturnType SysCtl_UartxEnable(uint8 uartx)
{
    Std_ReturnType ret = E_NOT_OK;

    switch (uartx)
    {
    case UART0:
        /* code */
        SET_BIT(SYSCTL_RCGCUART_R, UART0);
        while(READ_BIT(SYSCTL_PRUART_R, UART0) == 0);
        ret = E_OK;
        break;
    
    case UART1:
        /* code */
        SET_BIT(SYSCTL_RCGCUART_R, UART1);
        while(READ_BIT(SYSCTL_PRUART_R, UART1) == 0);
        ret = E_OK;
        break;
        
    case UART2:
        /* code */
        SET_BIT(SYSCTL_RCGCUART_R, UART2);
        while(READ_BIT(SYSCTL_PRUART_R, UART2) == 0);
        ret = E_OK;
        break;

    case UART3:
        /* code */
        SET_BIT(SYSCTL_RCGCUART_R, UART3);
        while(READ_BIT(SYSCTL_PRUART_R, UART3) == 0);
        ret = E_OK;
        break;

    case UART4:
        /* code */
        SET_BIT(SYSCTL_RCGCUART_R, UART4);
        while(READ_BIT(SYSCTL_PRUART_R, UART4) == 0);
        ret = E_OK;
        break;

    case UART5:
        /* code */
        SET_BIT(SYSCTL_RCGCUART_R, UART5);
        while(READ_BIT(SYSCTL_PRUART_R, UART5) == 0);
        ret = E_OK;
        break;

    case UART6:
        /* code */
        SET_BIT(SYSCTL_RCGCUART_R, UART6);
        while(READ_BIT(SYSCTL_PRUART_R, UART6) == 0);
        ret = E_OK;
        break;

    case UART7:
        /* code */
        SET_BIT(SYSCTL_RCGCUART_R, UART7);
        while(READ_BIT(SYSCTL_PRUART_R, UART7) == 0);
        ret = E_OK;
        break;

    default:
        ret = E_NOT_OK;
        break;
    }

    return ret;
}

Std_ReturnType SysCtl_UartxDisable(uint8 uartx)
{
    Std_ReturnType ret = E_NOT_OK;

    switch (uartx)
    {
    case UART0:
        /* code */
        CLEAR_BIT(SYSCTL_RCGCUART_R, UART0);
        ret = E_OK;
        break;
    
    case UART1:
        /* code */
        CLEAR_BIT(SYSCTL_RCGCUART_R, UART1);
        ret = E_OK;
        break;
        
    case UART2:
        /* code */
        CLEAR_BIT(SYSCTL_RCGCUART_R, UART2);
        ret = E_OK;
        break;

    case UART3:
        /* code */
        CLEAR_BIT(SYSCTL_RCGCUART_R, UART3);
        ret = E_OK;
        break;

    case UART4:
        /* code */
        CLEAR_BIT(SYSCTL_RCGCUART_R, UART4);
        ret = E_OK;
        break;

    case UART5:
        /* code */
        CLEAR_BIT(SYSCTL_RCGCUART_R, UART5);
        ret = E_OK;
        break;

    case UART6:
        /* code */
        CLEAR_BIT(SYSCTL_RCGCUART_R, UART6);
        ret = E_OK;
        break;

    case UART7:
        /* code */
        CLEAR_BIT(SYSCTL_RCGCUART_R, UART7);
        ret = E_OK;
        break;

    default:
        ret = E_NOT_OK;
        break;
    }

    return ret;
}
