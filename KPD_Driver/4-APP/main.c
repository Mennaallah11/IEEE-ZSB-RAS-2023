
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
	KPD_enuInit();
	LCD_enuInit();
	u8 var;
	u8 ThePassword[PasswordLength] = the_Password;
	u8 Password[PasswordLength] = { 0 };
	u8 index;
	u8 flag = 0;
	u8 check = 0;
	u8 option;
	LCD_enuSetAc(LCD_u8_LINE1, 0);
	LCD_enuSendString("Password: ");

	while (1) {
		KPD_enuGetKeyState(&var);
		if (var != 0xff) {
			LCD_enuSendChar('*');
			Password[index] = var;
			index++;
		}
		if ((index) == PasswordLength) {
			flag = 1;
			for (int i = 0; i < PasswordLength; i++) {
				if (Password[i] != ThePassword[i]) {
					flag = 0;
				}
			}
			if (flag) {
				LCD_enuClear();
				LCD_enuSendString("True Password :)");
				delay();
				LCD_enuClear();
				break;
			} else {
				LCD_enuClear();
				LCD_enuSetAc(1, 0);
				LCD_enuSendString("Wrong Password :)");
				delay();
				LCD_enuClear();
				check++;
				index = 0;
				if (check >= max_try) {
					LCD_enuSetAc(1, 0);
					LCD_enuSendString("Error :( ");
					delay();
					LCD_enuClear();
					check = 0;
				}
			}
		}
	}
	return 0 ;
}
