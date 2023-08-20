/*****************************************/
/******* Name : menna allah mohamed ******/
/********** Date : 29 / 04 / 2023 ********/
/**************** SWC :  Dc Motor **************/
/*************  Version : 1.0 ************/
/*****************************************/

/*LIBRARIES Layer*/
#include "../../Lib/STD_TYPES.h"
#include "../../Lib/ES.h"

/*MCAL*/
#include "../../MCAL/DIO/DIO_interface.h"

/*HAL*/
#include "DcMotor_private.h"
#include "DcMotor_config.h"
#include "DcMotor_interface.h"


//#define F_CPU 8000000UL
//#include <util/delay.h>


ERROR DcMotor_voidInit(void)
{
	DIO_enuSetPinDirection(DcMotor_u8_PORT,DcMotor_u8_TRANSISTORS14_PIN, DIO_u8OUTPUT);
	DIO_enuSetPinDirection(DcMotor_u8_PORT,DcMotor_u8_TRANSISTORS23_PIN, DIO_u8OUTPUT);
	DIO_enuSetPinValue(DcMotor_u8_PORT,DcMotor_u8_TRANSISTORS14_PIN, DIO_u8LOW);
	DIO_enuSetPinValue(DcMotor_u8_PORT,DcMotor_u8_TRANSISTORS23_PIN, DIO_u8LOW);
	return STD_OK ;
}

/**************************************************/

ERROR DcMotor_enuStart(u8 DcMoroe_u8Direction)
{
	if (DcMoroe_u8Direction == CW){
	DIO_enuSetPinValue(DcMotor_u8_PORT,DcMotor_u8_TRANSISTORS14_PIN, DIO_u8HIGH);
	DIO_enuSetPinValue(DcMotor_u8_PORT,DcMotor_u8_TRANSISTORS23_PIN, DIO_u8LOW);
	
	}
	else if (DcMoroe_u8Direction == ACW)
	{
	DIO_enuSetPinValue(DcMotor_u8_PORT,DcMotor_u8_TRANSISTORS14_PIN, DIO_u8LOW);
	DIO_enuSetPinValue(DcMotor_u8_PORT,DcMotor_u8_TRANSISTORS23_PIN, DIO_u8HIGH);	
	}
	
		return STD_OK ;
	
}
 
 /****************************************************/
 ERROR  DcMotor_enuStop(void)
 {
    
	     DIO_enuSetPinValue(DcMotor_u8_PORT,DcMotor_u8_TRANSISTORS14_PIN, DIO_u8LOW);
	     DIO_enuSetPinValue(DcMotor_u8_PORT,DcMotor_u8_TRANSISTORS23_PIN, DIO_u8LOW);
		
		return STD_OK ; 
 }
