#include "../5-LIBRARIES/STD_TYPES.h"
#include "../5-LIBRARIES/ES.h"
#include"../1-MCAL/1-DIO/DIO_interface.h"
#include "../2-HAL/1-LCD/LCD_Interface.h"

void delay(void)
{
	for(int x=0;x<500;x++)
		for(int y=0;y<500;y++)
			__asm("NOP");
}
int main(void) {
    DIO_u8SetPinDirection(DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_OUTPUT);
	DIO_u8SetPinDirection(DIO_u8_PORTA,DIO_u8_PIN1,DIO_u8_OUTPUT);
	DIO_u8SetPinDirection(DIO_u8_PORTA,DIO_u8_PIN2,DIO_u8_OUTPUT);
	DIO_u8SetPinValue(DIO_u8_PORTD,DIO_u8_PIN0,DIO_u8_LOW);
	DIO_u8SetPinValue(DIO_u8_PORTD,DIO_u8_PIN1,DIO_u8_LOW);
	DIO_u8SetPinValue(DIO_u8_PORTD,DIO_u8_PIN2,DIO_u8_LOW);
	DIO_u8SetPinValue(DIO_u8_PORTD,DIO_u8_PIN3,DIO_u8_LOW);
	DIO_u8SetPinValue(DIO_u8_PORTD,DIO_u8_PIN4,DIO_u8_LOW);
	DIO_u8SetPinValue(DIO_u8_PORTD,DIO_u8_PIN5,DIO_u8_LOW);
	DIO_u8SetPinValue(DIO_u8_PORTD,DIO_u8_PIN6,DIO_u8_LOW);
	DIO_u8SetPinValue(DIO_u8_PORTD,DIO_u8_PIN7,DIO_u8_LOW);

	LCD_enuInit();

	LCD_enuSetAc(1,0);
	LCD_enuSendString("IEEE_RAS_");
	LCD_enuSendString("2023");
	delay();
	while(1);

    }
