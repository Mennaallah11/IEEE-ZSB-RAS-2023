/*****************************************/
/******* Name : menna allah mohamed ******/
/********** Date : 08 / 07 / 2023 ********/
/**************** SWC : KPD**************/
/*************  Version : 1.0 ************/
/*****************************************/

/*Lib Layer*/
#include "../../Lib/STD_TYPES.h"
#include "../../Lib/ES.h"

/*MCAL*/
#include "../../MCAL/DIO/DIO_interface.h"

/*HAL*/
#include "KPD_private.h"
#include "KPD_config.h"
#include "KPD_interface.h"

#define F_CPU 8000000UL
#include <util/delay.h>

 
const u8 KPD_Au8Keys[4][4]=  KEYPAD_KEYS;

const u8 KPD_Au8RowsPins[4] = {KPD_u8_R1_PIN,KPD_u8_R2_PIN,KPD_u8_R3_PIN,KPD_u8_R4_PIN};
const u8 KPD_Au8ColsPins[4] = {KPD_u8_c1_PIN,KPD_u8_c2_PIN,KPD_u8_c3_PIN,KPD_u8_c4_PIN};

/****************************************************/
ERROR KPD_enuGetKeyState(u8 *copy_pu8ReturnedKey){


	u8 Local_u8RowsCount;
	u8 Local_u8ColsCount;
	u8 Local_u8KeyValue = 0;
	u8 Local_u8_Flag = 0 ;
    
	if (copy_pu8ReturnedKey != NULL)
	{
		*copy_pu8ReturnedKey = NO_KEY_PRESSED ;
		for(Local_u8RowsCount = 0 ; Local_u8RowsCount < 4 ; Local_u8RowsCount++)
		{
			DIO_enuSetPinValue(KPD_u8_PORT ,KPD_Au8RowsPins[Local_u8RowsCount],DIO_u8LOW);
			 /*Check Which Input Pin Has Zero*/
			for(Local_u8ColsCount = 0 ; Local_u8ColsCount < 4; Local_u8ColsCount++ )
			{
				DIO_enuGetPinValue(KPD_u8_PORT ,KPD_Au8ColsPins[Local_u8ColsCount], &Local_u8KeyValue);
				if(Local_u8KeyValue == DIO_u8LOW)
				{
					_delay_ms(10);
					DIO_enuGetPinValue(KPD_u8_PORT ,KPD_Au8ColsPins[Local_u8ColsCount], &Local_u8KeyValue);
					while(Local_u8KeyValue == DIO_u8LOW)
					{
						DIO_enuGetPinValue(KPD_u8_PORT ,KPD_Au8ColsPins[Local_u8ColsCount], &Local_u8KeyValue);
					}
					*copy_pu8ReturnedKey = KPD_Au8Keys[Local_u8RowsCount][Local_u8ColsCount];// return the pressed key to the required variable
                     Local_u8_Flag = 1 ;
					 break ;
				}
			}
			DIO_enuSetPinValue(KPD_u8_PORT ,KPD_Au8RowsPins[Local_u8RowsCount],DIO_u8HIGH);
			if(Local_u8_Flag == 1)
			{
				break ;
			}
		}
	}
	else 
	{
		return STD_NOTOK ;
	}
	return STD_OK ;
}
			
			


/********************************************************/

	
	ERROR KPD_enuInit(void)
	{
		DIO_enuSetPinDirection(KPD_u8_PORT, KPD_u8_C1_PIN, DIO_u8INPUT);
	DIO_enuSetPinDirection(KPD_u8_PORT, KPD_u8_C2_PIN, DIO_u8INPUT);
	DIO_enuSetPinDirection(KPD_u8_PORT, KPD_u8_C3_PIN, DIO_u8INPUT);
	DIO_enuSetPinDirection(KPD_u8_PORT, KPD_u8_C4_PIN, DIO_u8INPUT);

	DIO_enuSetPinValue(KPD_u8_PORT, KPD_u8_C1_PIN, DIO_u8HIGH);
	DIO_enuSetPinValue(KPD_u8_PORT, KPD_u8_C2_PIN, DIO_u8HIGH);
	DIO_enuSetPinValue(KPD_u8_PORT, KPD_u8_C3_PIN, DIO_u8HIGH);
	DIO_enuSetPinValue(KPD_u8_PORT, KPD_u8_C4_PIN, DIO_u8HIGH);

	DIO_enuSetPinDirection(KPD_u8_PORT, KPD_u8_R1_PIN, DIO_u8OUTPUT);
	DIO_enuSetPinDirection(KPD_u8_PORT, KPD_u8_R2_PIN, DIO_u8OUTPUT);
	DIO_enuSetPinDirection(KPD_u8_PORT, KPD_u8_R3_PIN, DIO_u8OUTPUT);
	DIO_enuSetPinDirection(KPD_u8_PORT, KPD_u8_R4_PIN, DIO_u8OUTPUT);

	DIO_enuSetPinValue(KPD_u8_PORT, KPD_u8_R1_PIN, DIO_u8HIGH);
	DIO_enuSetPinValue(KPD_u8_PORT, KPD_u8_R2_PIN, DIO_u8HIGH);
	DIO_enuSetPinValue(KPD_u8_PORT, KPD_u8_R3_PIN, DIO_u8HIGH);
	DIO_enuSetPinValue(KPD_u8_PORT, KPD_u8_R4_PIN, DIO_u8HIGH);

		return STD_OK;
	}



