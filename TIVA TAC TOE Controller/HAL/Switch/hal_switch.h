#ifndef __HAL_SWITCH_H__
#define __HAL_SWITCH_H__

#include "../../MCAL/GPIO/mcal_gpio.h"

#define SWITCH_PRESSED  0x00
#define SWITCH_RELEASED 0x01
// SW interfaces

extern Std_ReturnType Switch_Init(void);
extern Std_ReturnType Switch1_Read(uint8 *switch1);
extern Std_ReturnType Switch2_Read(uint8 *switch2);

#endif /**<__HAL_SWITCH_H__*/
