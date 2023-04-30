/*LIBRARIES Layer */

#include "../5-LIBRARIES/STD_TYPES.h"
#include "../5-LIBRARIES/BIT_MATH.h"
/*MCAL*/
#include "../1-MCAL/1-DIO/DIO_interface.h"

void delay(void)
{
	for(int x=0;x<500;x++)
		for(int y=0;y<500;y++)
			__asm("NOP");
}

int main(void) {
	        DIO_u8SetPinDirection(DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_INPUT);
		    DIO_u8SetPinDirection(DIO_u8_PORTD,DIO_u8_PIN0,DIO_u8_OUTPUT);
		    DIO_u8SetPinDirection(DIO_u8_PORTD,DIO_u8_PIN1,DIO_u8_OUTPUT);
		    DIO_u8SetPinDirection(DIO_u8_PORTD,DIO_u8_PIN2,DIO_u8_OUTPUT);
		    DIO_u8SetPinValue(DIO_u8_PORTD,DIO_u8_PIN0,DIO_u8_LOW);
		    DIO_u8SetPinValue(DIO_u8_PORTD,DIO_u8_PIN1,DIO_u8_LOW);
		    DIO_u8SetPinValue(DIO_u8_PORTD,DIO_u8_PIN2,DIO_u8_LOW);

		    u8 pReturndPinValue1;
		    while (1){
		    	DIO_u8GetPinValue(DIO_u8_PORTA,DIO_u8_PIN0,&pReturndPinValue1);
		    	if (pReturndPinValue1 == DIO_u8_HIGH )
		    	     {
		    	        	DIO_u8SetPinValue(DIO_u8_PORTD,DIO_u8_PIN0,DIO_u8_HIGH);
		    	        	delay();
		    	        	DIO_u8SetPinValue(DIO_u8_PORTD,DIO_u8_PIN0,DIO_u8_LOW);

		    	        	DIO_u8SetPinValue(DIO_u8_PORTD,DIO_u8_PIN1,DIO_u8_HIGH);
		    	            delay ();
		    	            DIO_u8SetPinValue(DIO_u8_PORTD,DIO_u8_PIN1,DIO_u8_LOW);

		    	            DIO_u8SetPinValue(DIO_u8_PORTD,DIO_u8_PIN2,DIO_u8_HIGH);
		    	            delay ();
		    	            DIO_u8SetPinValue(DIO_u8_PORTD,DIO_u8_PIN2,DIO_u8_LOW);

		    	     }
		    	else {
		    		DIO_u8SetPinValue(DIO_u8_PORTD,DIO_u8_PIN0,DIO_u8_LOW);
		    		DIO_u8SetPinValue(DIO_u8_PORTD,DIO_u8_PIN1,DIO_u8_LOW);
		    		DIO_u8SetPinValue(DIO_u8_PORTD,DIO_u8_PIN2,DIO_u8_LOW);

		    	}
		    }
		    return 0;
		    }



