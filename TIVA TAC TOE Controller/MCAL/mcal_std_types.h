/*
 * File:   mcal_std_types.h
 * Author: AHMED BAKR
 *
 * Created on September 15, 2023, 3:49 PM
 */

#ifndef MCAL_STD_TYPES_H
#define MCAL_STD_TYPES_H

/*  Section :   includes    */
#include "std_library.h"



/*  Section :   Data Type Declarations    */

typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned long uint32;
typedef signed char int8;
typedef signed short int16;
typedef signed long int32;

typedef uint8 Std_ReturnType;

/*  Section :   Macro Declarations    */
#define STD_HIGH 0x01
#define STD_LOW 0x00

#define STD_ON 0x01
#define STD_OFF 0x00

#define STD_ACTIVE 0x01
#define STD_IDLE 0x00

#define E_OK ((Std_ReturnType)0x01)
#define E_NOT_OK ((Std_ReturnType)0x00)

#define ZERO_INIT   0

#define BIT_MASK ((uint8)1)

/*  Section :   Macro Functions Declarations    */
#define SET_BIT(REG, BIT_POSN)      (REG |= (1 << BIT_POSN))
#define CLEAR_BIT(REG, BIT_POSN)    (REG &= ~(1 << BIT_POSN))
#define TOGGLE_BIT(REG, BIT_POSN)   (REG ^= (1 << BIT_POSN))
#define READ_BIT(REG, BIT_POSN)     ((REG >> BIT_POSN) & BIT_MASK)

#define ADD_VALUE_REG(REG, VALUE)       (REG |= VALUE)
#define CLEAR_VALUE_REG(REG, VALUE)     (REG &= ~VALUE)

/*  Section :   Function Declarations    */

#endif /* MCAL_STD_TYPES_H */
