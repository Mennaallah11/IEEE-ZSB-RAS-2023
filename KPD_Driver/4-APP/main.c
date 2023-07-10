
#include "../5-LIBRARIES/STD_TYPES.h"
#include "../5-LIBRARIES/ES.h"
#include "../1-MCAL/1-DIO/DIO_interface.h"
#include "../2-HAL/1-LCD/LCD_Interface.h"
#include "../2-HAL/2-KPD/KPD_interface.h"

void delay(void)
{
	for(int x=0;x<500;x++)
		for(int y=0;y<500;y++)
			__asm("NOP");
}

#define the_Password          "4433"
#define PasswordLength         4
#define max_try                3


int main(void)
{
   
    DIO_u8SetPinDirection(DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_OUTPUT);
	DIO_u8SetPinDirection(DIO_u8_PORTA,DIO_u8_PIN1,DIO_u8_OUTPUT);
	DIO_u8SetPinDirection(DIO_u8_PORTA,DIO_u8_PIN2,DIO_u8_OUTPUT);
	DIO_u8SetPinDirection(DIO_u8_PORTA,DIO_u8_PIN3,DIO_u8_OUTPUT); 
	                                              
    DIO_u8SetPinDirection(DIO_u8_PORTA,DIO_u8_PIN4,DIO_u8_INPUT);
	DIO_u8SetPinDirection(DIO_u8_PORTA,DIO_u8_PIN5,DIO_u8_INPUT);
	DIO_u8SetPinDirection(DIO_u8_PORTA,DIO_u8_PIN6,DIO_u8_INPUT);
	DIO_u8SetPinDirection(DIO_u8_PORTA,DIO_u8_PIN7,DIO_u8_INPUT);
	                                                      	
	DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_HIGH);
	DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN1,DIO_u8_HIGH);
	DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN2,DIO_u8_HIGH);
	DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN3,DIO_u8_HIGH);
	DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN4,DIO_u8_HIGH);
	DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN5,DIO_u8_HIGH);
	DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN6,DIO_u8_HIGH);
	DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN7,DIO_u8_HIGH); 
	
     
	
	/*KPD_enuInit();*/
	
	LCD_enuInit();
	u8 ReturnedKey  ;
	
	u8 ThePassword[PasswordLength] = the_Password;
	u8 Password[PasswordLength]={0};
	u8 index ;
	/*u8 flag = 0 ; */
	u8 check = 0 ;
	while(1)
{
	LCD_enuSetAc(1,0);
	LCD_enuSendString("Enter_Password:");
	delay();
	LCD_enuClear();
	
	
     KPD_enuGetKeyState(&ReturnedKey);
	if (ReturnedKey != KPD_u8_KEY_NOT_PRESSED )
	{
	LCD_enuSendChar('*');
	Password[index] = ReturnedKey ;
	index ++ ; 
	}
	if ((index)== PasswordLength)
	{
	for (int i = 0 ; i < PasswordLength ; i ++ )
	{
		if (Password[i]==ThePassword[i])
		{
		LCD_enuClear();
	    LCD_enuSendString("True Password :)");
	    delay();
	    LCD_enuClear();
	    break ;	    
		}
	}}
		else 
		{
		LCD_enuClear();
	    LCD_enuSendString("Wrong Password :)");
	    delay();
	    LCD_enuClear();
	    check ++ ;
	    index = 0 ;
		if (check >= max_try) 
		{
		LCD_enuClear();
	    LCD_enuSendString("Error :( ");
	    delay();
	    LCD_enuClear();
	    check = 0 ;
	    
		
		}
		
		}

}
	return 0 ;
}