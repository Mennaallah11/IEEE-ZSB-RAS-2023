/*****************************************/
/******* Name : menna allah mohamed ******
/********** Date : 29 / 04 / 2023 ********/
/**************** SWC : DIO **************/
/*************  Version : 1.0 ************/
/*****************************************/
#ifndef INT_H
#define INT_H
#include "DIO_config.h"
#include "../../Lib/STD_TYPES.h"
#include "../../Lib/ES.h"

ERROR DIO_enuInit(void);         // void in case of p re processing
ERROR DIO_enuSetPinDirection (u8 Copy_u8PortID , u8 Copy_u8PinID , u8 Copy_u8PortDirection);  //output,input
ERROR DIO_enuTogPinValue (u8 Copy_u8PortID , u8 Copy_u8PinID );      //1>>0 , 0>>1
ERROR DIO_enuSetPinValue (u8 Copy_u8PortID , u8 Copy_u8PinID , u8 Copy_u8PinValue);      //0,1
ERROR DIO_enuGetPinValue (u8 Copy_u8PortID , u8 Copy_u8PinID , u8 * Copy_pu8PinValue);      //0,1
ERROR DIO_enuSetPortDirection(u8 Copy_u8PortId, u8 Copy_u8PortDirection);
ERROR DIO_enuSetPortValue(u8 Copy_u8PortId, u8 Copy_u8PortValue);
ERROR DIO_enuGetPortValue(u8 Copy_u8PortId, u8 *Copy_pu8ReturnedPortValue);

/*enum
{
	DIO_u8PORTA 		,
	DIO_u8PORTB 		,
	DIO_u8PORTC 		,
	DIO_u8PORTD 		,

	DIO_u8PIN0=0		,
	DIO_u8PIN1			,
	DIO_u8PIN2			,
	DIO_u8PIN3			,
	DIO_u8PIN4			,
	DIO_u8PIN5			,
	DIO_u8PIN6			,
	DIO_u8PIN7			,

	DIO_u8INPUT=0		,
	DIO_u8OUTPUT 		,

	DIO_u8LOW=0			,
	DIO_u8HIGH			,

	DIO_u8FLOAT=0		,
	DIO_u8PULL_UP
};*/
#define DIO_u8PORTA     0
#define DIO_u8PORTB     1
#define DIO_u8PORTC     2
#define DIO_u8PORTD     3

/*Macros for PINS*/
#define DIO_u8PIN0      0
#define DIO_u8PIN1      1
#define DIO_u8PIN2      2
#define DIO_u8PIN3      3
#define DIO_u8PIN4      4
#define DIO_u8PIN5      5
#define DIO_u8PIN6      6
#define DIO_u8PIN7      7

/*Macros for Pin Direction*/
#define DIO_u8OUTPUT    1
#define DIO_u8INPUT     0

/*Macros for Pin Value*/
#define DIO_u8LOW       0
#define DIO_u8HIGH      1

#define DIO_u8PULL_UP			0
#define DIO_u8FLOAT		     	1

#endif
