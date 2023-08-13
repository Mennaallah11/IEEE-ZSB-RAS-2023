#include "../5-LIBRARIES/STD_TYPES.h"
#include "../5-LIBRARIES/ES.h"
#include "../1-MCAL/1-DIO/DIO_interface.h"
#include "../2-HAL/1-LCD/LCD_Interface.h"

void delay(void)
{
	for(int x=0;x<300;x++)
		for(int y=0;y<300;y++)
			__asm("NOP");
}
int main(void) {

    /*  switches */
	DIO_u8SetPinDirection(DIO_u8_PORTB,DIO_u8_PIN0,DIO_u8_INPUT);
	DIO_u8SetPinDirection(DIO_u8_PORTB,DIO_u8_PIN1,DIO_u8_INPUT);
	DIO_u8SetPinDirection(DIO_u8_PORTB,DIO_u8_PIN2,DIO_u8_INPUT);

	DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN0,DIO_u8_LOW);
        DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN1,DIO_u8_LOW);
	DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN2,DIO_u8_LOW);
	LCD_enuInit();

	u8 Character1[8] = { 0x04, 0x1F, 0x11, 0x11, 0x1F, 0x1F, 0x1F, 0x1F };
	u8 Character2[8] = { 0x01, 0x03, 0x07, 0x1F, 0x1F, 0x07, 0x03, 0x01 };



	u8 switch1,switch2;
	u8 flag = 0 ;
	u8 column_counter = 0 ,row_counter=1;
	LCD_enuSetAc(0,1);
	LCD_enuSendChar ('h');
	delay();
	LCD_enuClear();

     while (1){
	     DIO_u8GetPinValue(DIO_u8_PORTB,DIO_u8_PIN0,&switch1);
	     DIO_u8GetPinValue(DIO_u8_PORTB,DIO_u8_PIN1,&switch2);

	     if (switch1==DIO_u8_HIGH)
		 {

		     LCD_enuCreateCustomChar(0,Character1);
		     LCD_enuSetAc(row_counter,column_counter);
		     LCD_enuSendChar(0);
		     delay();
		     column_counter++;

	     }
	     else if (switch2 == DIO_u8_HIGH)
		 {

		     LCD_enuCreateCustomChar(1,Character2);
		     LCD_enuSetAc(row_counter,column_counter);
		     LCD_enuSendChar(1);
		     delay();
		     column_counter++;
	     }
           if(column_counter == 15 )
           {
			 row_counter ++ ;
			 column_counter =0 ;
		   }
		   if (column_counter == 15 && row_counter==2)
		   {
		       LCD_enuClear();
			   delay();
			   column_counter =0;
			   row_counter=1;
	                  LCD_enuSetAc(row_counter,column_counter);
		   }
            }
		   }
