#include "../Lib/STD_TYPES.h"
#include "../Lib/ES.h"


#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/UART/UART_interface.h"
#include <string.h>


#include "../MCAL/AVR_REG.h"
#define F_CPU 8000000UL
#include <util/delay.h>




int main()
{
	u8 Data ;
	u8 st[100];
	DIO_enuInit();
	UART_enuInit();
	
	while(1)
	{

        UART_enuSendString("Choose a or b or y or s or g");
		UART_enuResiveDataByte(&Data);
        if(Data == 'a')
	{
		DIO_enuSetPinValue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8HIGH);
	}
	else if (Data == 'b')
	{
		DIO_enuSetPinValue(DIO_u8PORTA,DIO_u8PIN1,DIO_u8HIGH);
	 }	
	else if (Data == 'y')
	{
		DIO_enuSetPinValue(DIO_u8PORTA,DIO_u8PIN2,DIO_u8HIGH);
	 }
	
	else if (Data =='g')
	{
		UART_enuSendString("enter the string");
		UART_enuRecieveString(st);
		if(strcmp(st,"abca"))
		{
			 DIO_enuSetPinValue(DIO_u8PORTD,DIO_u8PIN2,DIO_u8HIGH);
		}
		else
		{
                      UART_enuSendString("ERROR");
	    	}
	}
	else if (Data == 's')
	{
		DIO_enuSetPinValue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8LOW);
		DIO_enuSetPinValue(DIO_u8PORTA,DIO_u8PIN1,DIO_u8LOW);
		DIO_enuSetPinValue(DIO_u8PORTA,DIO_u8PIN2,DIO_u8LOW);
		DIO_enuSetPinValue(DIO_u8PORTD,DIO_u8PIN2,DIO_u8LOW);
	}
 

		
	}
	return 0;
	
}

