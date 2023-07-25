/*****************************************/
/******* Name : menna allah mohamed ******/
/********** Date : 08 / 07 / 2023 ********/
/**************** SWC : KPD**************/
/*************  Version : 1.0 ************/
/*****************************************/








/*Lib Layer*/
#include "../../5-LIBRARIES/STD_TYPES.h"
#include "../../5-LIBRARIES/ES.h"

/*MCAL*/
#include "../../1-MCAL/1-DIO/DIO_interface.h"

/*HAL*/
#include "KPD_private.h"
#include "KPD_config.h"
#include "KPD_interface.h"

#define F_CPU 8000000UL
#include <util/delay.h>

 
const u8 KPD_Au8Keys[4][4]=  KPD_KEYS;

const u8 KPD_Au8RowsPins[4] = {KPD_u8_R1_PIN,KPD_u8_R2_PIN,KPD_u8_R3_PIN,KPD_u8_R1_PIN};
const u8 KPD_Au8ColsPins[4] = {KPD_u8_C1_PIN,KPD_u8_C2_PIN,KPD_u8_C3_PIN,KPD_u8_C4_PIN};

/****************************************************/
ERROR KPD_enuGetKeyState(u8 *copy_pu8ReturnedKey){


	u8 Local_u8ColIter;
	u8 Local_u8RowIter;
	u8 Local_u8KeyValue;

	for(Local_u8ColIter = 0 ; Local_u8ColIter < 4 ; Local_u8ColIter++)
	{
		DIO_enuSetPinValue(KPD_u8_PORT ,KPD_Au8ColsPins[Local_u8ColIter],DIO_u8LOW);
		for(Local_u8RowIter = 0 ; Local_u8RowIter < 4; Local_u8RowIter++ )
		{
			DIO_enuGetPinValue(KPD_u8_PORT ,KPD_Au8RowsPins[Local_u8RowIter], &Local_u8KeyValue);
			if(!Local_u8KeyValue)
			{

				_delay_ms(10);
				DIO_enuGetPinValue(KPD_u8_PORT ,KPD_Au8RowsPins[Local_u8RowIter], &Local_u8KeyValue);
				if(!Local_u8KeyValue)
				{
					while(!Local_u8KeyValue)
					{
						DIO_enuGetPinValue(KPD_u8_PORT ,KPD_Au8RowsPins[Local_u8RowIter], &Local_u8KeyValue);
					}
					const u8 KPD_Au8Keys[4][4] = KPD_KEYS;
					*copy_pu8ReturnedKey = KPD_Au8Keys[Local_u8RowIter][Local_u8ColIter];// return the pressed key to the required variable

					return STD_OK;
				}
			}
		}
		DIO_enuSetPinValue(KPD_u8_PORT ,KPD_Au8ColsPins[Local_u8ColIter],DIO_u8HIGH);
		*copy_pu8ReturnedKey = KPD_u8_KEY_NOT_PRESSED;
	}

	return STD_NOTOK;

}

	/*******************************************************/
	
	ERROR KPD_enuInit(void)
	{
		DIO_enuSetPinDirection(KPD_u8_PORT, KPD_u8_C1_PIN, DIO_u8OUTPUT);
		DIO_enuSetPinDirection(KPD_u8_PORT, KPD_u8_C2_PIN, DIO_u8OUTPUT);
		DIO_enuSetPinDirection(KPD_u8_PORT, KPD_u8_C3_PIN, DIO_u8OUTPUT);
		DIO_enuSetPinDirection(KPD_u8_PORT, KPD_u8_C4_PIN, DIO_u8OUTPUT);

		DIO_enuSetPinValue(KPD_u8_PORT, KPD_u8_C1_PIN, DIO_u8HIGH);
		DIO_enuSetPinValue(KPD_u8_PORT, KPD_u8_C2_PIN, DIO_u8HIGH);
		DIO_enuSetPinValue(KPD_u8_PORT, KPD_u8_C3_PIN, DIO_u8HIGH);
		DIO_enuSetPinValue(KPD_u8_PORT, KPD_u8_C4_PIN, DIO_u8HIGH);

		DIO_enuSetPinDirection(KPD_u8_PORT, KPD_u8_R1_PIN, DIO_u8FLOAT);
		DIO_enuSetPinDirection(KPD_u8_PORT, KPD_u8_R2_PIN, DIO_u8FLOAT);
		DIO_enuSetPinDirection(KPD_u8_PORT, KPD_u8_R3_PIN, DIO_u8FLOAT);
		DIO_enuSetPinDirection(KPD_u8_PORT, KPD_u8_R4_PIN, DIO_u8FLOAT);

		DIO_enuSetPinValue(KPD_u8_PORT, KPD_u8_R1_PIN, DIO_u8HIGH);
		DIO_enuSetPinValue(KPD_u8_PORT, KPD_u8_R2_PIN, DIO_u8HIGH);
		DIO_enuSetPinValue(KPD_u8_PORT, KPD_u8_R3_PIN, DIO_u8HIGH);
		DIO_enuSetPinValue(KPD_u8_PORT, KPD_u8_R4_PIN, DIO_u8HIGH);

		return STD_OK;
	}



