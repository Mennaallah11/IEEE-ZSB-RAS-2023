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
u8 Local_u8RowsCounter ,Local_u8ColsCounter , Local_u8PinValue ,Local_u8Flag=DIO_u8_LOW ;
if (copy_pu8ReturnedKey != NULL )
	{
	 *copy_pu8ReturnedKey = KPD_u8_KEY_NOT_PRESSED;
		/*Activate each Row => for loop on the pins of the rows */
		for(Local_u8RowsCounter=0 ; Local_u8RowsCounter <=3 ; Local_u8RowsCounter ++ )
			{
				DIO_u8SetPinValue(KPD_u8_PORT,KPD_Au8RowsPins[Local_u8RowsCounter],DIO_u8_LOW);
				/*Check which input pin has zero */

				for(Local_u8ColsCounter=0 ; Local_u8ColsCounter<=3 ; Local_u8ColsCounter ++ )
					{
						DIO_u8GetPinValue(KPD_u8_PORT,KPD_Au8ColsPins[Local_u8ColsCounter],&Local_u8PinValue);
						if(Local_u8PinValue == DIO_u8_LOW)/*Switch is pressed*/
					{
					/* Debouncing */
				    _delay_ms(20);
				    DIO_u8GetPinValue(KPD_u8_PORT,KPD_Au8ColsPins[Local_u8ColsCounter],&Local_u8PinValue);

				    /*check if the pin is still == low */
				    while(Local_u8PinValue == DIO_u8_LOW)
				    {
				    	DIO_u8GetPinValue(KPD_u8_PORT,KPD_Au8ColsPins[Local_u8ColsCounter],&Local_u8PinValue);
				    }
				    *copy_pu8ReturnedKey = KPD_Au8Keys[Local_u8RowsCounter][Local_u8ColsCounter];
				    Local_u8Flag = DIO_u8_HIGH ;
				    break;

			}

		}
				DIO_u8SetPinValue(KPD_u8_PORT,KPD_Au8RowsPins[Local_u8RowsCounter],DIO_u8_LOW);

				if (Local_u8Flag == DIO_u8_HIGH )
				{
					break ;

                }


			}


    }

	else
	{
		return STD_NOTOK;
	}
return STD_OK;
	}

/*****************************************************/
ERROR KPD_enuInit(void)
{
    DIO_u8SetPinDirection(KPD_u8_PORT, KPD_u8_R1_PIN, DIO_u8_OUTPUT);
    DIO_u8SetPinDirection(KPD_u8_PORT, KPD_u8_R2_PIN, DIO_u8_OUTPUT);
    DIO_u8SetPinDirection(KPD_u8_PORT, KPD_u8_R3_PIN, DIO_u8_OUTPUT);
    DIO_u8SetPinDirection(KPD_u8_PORT, KPD_u8_R4_PIN, DIO_u8_OUTPUT);

    DIO_u8SetPinDirection(KPD_u8_PORT, KPD_u8_C1_PIN, DIO_u8_INPUT);
    DIO_u8SetPinDirection(KPD_u8_PORT, KPD_u8_C2_PIN, DIO_u8_INPUT);
    DIO_u8SetPinDirection(KPD_u8_PORT, KPD_u8_C3_PIN, DIO_u8_INPUT);
    DIO_u8SetPinDirection(KPD_u8_PORT, KPD_u8_C4_PIN, DIO_u8_INPUT);


 	DIO_u8SetPortValue (KPD_u8_PORT ,DIO_u8_HIGH) ;

 	return STD_OK;
}
