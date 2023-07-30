/*****************************************/
/******* Name : menna allah mohamed ******
/********** Date : 27 / 06 / 2023 ********/
/**************** SWC : EXTI **************/
/*************  Version : 1.0 ************/
/*****************************************/

#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

/*
* INTERRUPT REGISTERS
*/

#define MCUCR 	*((volatile u8*) 0x55)   //Control Register for interrupt sense control

#define MCUCSR	*((volatile u8*) 0x54)   //Status regester

#define GICR 	*((volatile u8*) 0x5b)  // works as PIE for EXTI

#define GIFR  	*((volatile u8*) 0x5a) // works as PIF for EXTI

#define SREG       *((volatile u8*)0x5F)	

#define EXTI_u8_INT0   0
#define EXTI_u8_INT1   1
#define EXTI_u8_INT2   2


#define   EXTI_u8_INT0_ISC01         1
#define   EXTI_u8_INT0_ISC00         0
#define   EXTI_u8_INT1_ISC11         3
#define   EXTI_u8_INT1_ISC10         2
#define   EXTI_u8_INT2_ISC2          6

#define  EXTI_u8_RISING_EDGE            0
#define  EXTI_u8_FALLING_EDGE            1
#define  EXTI_u8_ANY_LOGICAL_CHANGE      2
#define  EXTI_u8_LOW_LEVEL               3

#define EXTI0_u8_PIN6                6
#define EXTI1_u8_PIN7                7
#define EXTI2_u8_PIN5                5

#define EXTI_u8_INT0   0
#define EXTI_u8_INT1   1
#define EXTI_u8_INT2   2



#define Number_OFISRFUN              3

#endif