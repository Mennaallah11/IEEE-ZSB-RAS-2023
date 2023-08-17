#include "../Lib/STD_TYPES.h"
#include "../Lib/ES.h"


#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/Timer/Timer_interface.h"
#include "../MCAL/GI/GI_interface.h"
#include "../HAL/LCD/LCD_interface.h"
#include "../MCAL/AVR_REG.h"
#define F_CPU 8000000UL
void App_voidTogLed(void);
int main()
{
	
	LCD_enuInit();
        DIO_enuInit();
	GI_enuGIEnable();
	Timers_enuTimer0CTCSetCallBack(&App_voidTogLed);
	Timers_enuTimer0Init();
 
	while(1);
	return 0;
}
void App_voidTogLed(void)
{
	
	static u8 flag = 0 ,count =0  ;
	
	count++;
	LCD_enuSetAc(1,0);
	LCD_enuSendNum(count);

	if(flag==0)
	{
		DIO_enuSetPinValue(DIO_u8PORTB,DIO_u8PIN2, DIO_u8HIGH);
		flag =1 ;
	}
	else 
	{
		DIO_enuSetPinValue(DIO_u8PORTB,DIO_u8PIN2, DIO_u8LOW);
		flag =0 ;
	}

}
