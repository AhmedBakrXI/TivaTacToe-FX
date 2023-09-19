#include "mcal_gpio.h"

/*
 * Note : This driver is to be continued and tested later
 */

Std_ReturnType GPIO_PortxInit(uint8 port)
{
    Std_ReturnType ret = E_OK;

    
    switch (port)
    {
    case PORTA:
        /* code */
        GPIO_PORTA_DEN_R = 0x3;
        GPIO_PORTA_AFSEL_R = 0x3;
        GPIO_PORTA_AMSEL_R = 0x0;
        GPIO_PORTA_PCTL_R = 0x11;
        break;

    case PORTF:
        /* code */
        GPIO_PORTF_LOCK_R = 0x4C4F434B; // 1) unlock PortF PF0
        GPIO_PORTF_CR_R = 0x1F;         // allow changes to PF4-0
        GPIO_PORTF_AMSEL_R = 0x00;      // 2) disable analog function
        GPIO_PORTF_PCTL_R = 0x00000000; // 3) GPIO clear bit PCTL
        GPIO_PORTF_DIR_R = 0x0E;        // 4) PF4,PF0 input, PF3,PF2,PF1 output
        GPIO_PORTF_AFSEL_R = 0x00;      // 5) no alternate function
        GPIO_PORTF_PUR_R = 0x11;        // enable pullup resistors on PF4,PF0
        GPIO_PORTF_DEN_R = 0x1F;        // 6) enable digital pins PF4-PF0
        break;
    default:
        ret = E_NOT_OK;
        break;
    }
    return ret;
}

Std_ReturnType GPIO_PortxPinRead(uint8 port, uint8 pin, uint8 *logic)
{
    Std_ReturnType ret = E_OK;

    switch (port)
    {
    case PORTA:
        /* code */
        *logic = READ_BIT(GPIO_PORTA_DATA_R, pin);
        break;
    case PORTB:
        /* code */
        *logic = READ_BIT(GPIO_PORTB_DATA_R, pin);
        break;
    case PORTC:
        /* code */
        *logic = READ_BIT(GPIO_PORTC_DATA_R, pin);
        break;
    case PORTD:
        /* code */
        *logic = READ_BIT(GPIO_PORTD_DATA_R, pin);
        break;
    case PORTE:
        /* code */
        *logic = READ_BIT(GPIO_PORTE_DATA_R, pin);
        break;
    case PORTF:
        /* code */
        *logic = READ_BIT(GPIO_PORTF_DATA_R, pin);
        break;
    
    default:
        ret = E_NOT_OK;
        break;
    }

    return ret;
}

Std_ReturnType GPIO_PortxWrite(uint8 port, uint8 value)
{
    Std_ReturnType ret = E_OK;

    switch (port)
    {
    case PORTA:
        /* code */
        ADD_VALUE_REG(GPIO_PORTA_DATA_R, value);
        break;
    case PORTB:
        /* code */
        ADD_VALUE_REG(GPIO_PORTB_DATA_R, value);
        break;
    case PORTC:
        /* code */
        ADD_VALUE_REG(GPIO_PORTC_DATA_R, value);
        break;
    case PORTD:
        /* code */
        ADD_VALUE_REG(GPIO_PORTD_DATA_R, value);
        break;
    case PORTE:
        /* code */
        ADD_VALUE_REG(GPIO_PORTE_DATA_R, value);
        break;
    case PORTF:
        /* code */
        ADD_VALUE_REG(GPIO_PORTF_DATA_R, value);
        break;
    
    default:
        ret = E_NOT_OK;
        break;
    }

    return ret;
}
