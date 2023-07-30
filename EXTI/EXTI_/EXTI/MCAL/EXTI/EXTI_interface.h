/*****************************************/
/******* Name : menna allah mohamed ******
/********** Date : 27 / 06 / 2023 ********/
/**************** SWC : EXTI **************/
/*************  Version : 1.0 ************/
/*****************************************/
#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

#include "../../Lib/STD_TYPES.h"
#include "../../Lib/ES.h"

#define  EXTI_u8_RISING_EDGE            0
#define  EXTI_u8_FALLING_EDGE            1
#define  EXTI_u8_ANY_LOGICAL_CHANGE      2
#define  EXTI_u8_LOW_LEVEL               3


#define EXTI_u8_INT0   0
#define EXTI_u8_INT1   1
#define EXTI_u8_INT2   2

ERROR  EXTI_enuExtiEnable(u8 Copy_u8EXTIIndex,u8 Copy_u8EdgeIndex);
ERROR  EXTI_enuExtiDisable(u8 Copy_u8EXTIIndex);
ERROR  EXTI_enuExtiSetCallBack(void(*pf_ISR)(void), u8 Copy_u8ISRIndex);



#endif
