#ifndef __MCAL_GPIO_H__
#define __MCAL_GPIO_H__

#include "../mcal_std_types.h"
#include "../tm4c123gh6pm.h"
#include "mcal_gpio_config.h"

// Macros
#define PORTA   0
#define PORTB   1
#define PORTC   2
#define PORTD   3
#define PORTE   4
#define PORTF   5

#define PIN0    0
#define PIN1    1
#define PIN2    2
#define PIN3    3
#define PIN4    4
#define PIN5    5
#define PIN6    6
#define PIN7    7

#define GPIO_HIGH   1
#define GPIO_LOW    0

// SW Interfaces
extern Std_ReturnType GPIO_PortxInit(uint8 port);
extern Std_ReturnType GPIO_PortxPinRead(uint8 port, uint8 pin, uint8 *logic);
extern Std_ReturnType GPIO_PortxWrite(uint8 port, uint8 value);


#endif /**<__MCAL_GPIO_H__*/
