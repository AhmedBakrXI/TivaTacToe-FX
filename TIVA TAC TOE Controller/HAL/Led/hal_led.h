#ifndef __HAL_LED_H__
#define __HAL_LED_H__

#include "../../MCAL/GPIO/mcal_gpio.h"

// Macros

#define RED             0x02
#define BLUE            0x04
#define GREEN           0x08
#define PINK            0x06
#define YELLOW          0x0A
#define SKY             0x0C
#define WHITE           0x0E

// SW interfaces

extern Std_ReturnType Led_Init(void);
extern Std_ReturnType Led_RGB(uint8 color);

#endif /**<__HAL_LED_H__*/
