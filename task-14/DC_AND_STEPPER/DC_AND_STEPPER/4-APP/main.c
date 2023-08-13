
#include "../5-LIBRARIES/STD_TYPES.h"
#include "../5-LIBRARIES/ES.h"
#include "../1-MCAL/1-DIO/DIO_interface.h"
#include "../2-HAL/1-LCD/LCD_Interface.h"
#include "../2-HAL/2-KPD/KPD_Interface.h"
#include "../2-HAL/4-DC_MOTOR/DcMotor_interface.h"
#include "../2-HAL/3-STEPPER_MOTOR/STEPPER_interface.h"


#define F_CPU 8000000UL
#include <util/delay.h>



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

	while (1)
		{
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
				LCD_enuSendString("choose_motor");
				delay();
				LCD_enuClear();
				LCD_enuSetAc(LCD_u8_LINE1, 0);
				LCD_enuSendString("1-DC ");
				LCD_enuSendString("2-stepper");
				LCD_enuSetAc(LCD_u8_LINE2, 0);
				LCD_enuSendString("3-EXIT");
//				LCD_enuClear();
				while (1) {
					KPD_enuGetKeyState(&option);
					if (option != KPD_u8_KEY_NOT_PRESSED) {
						if (option == '1') {
							DC_direction();
						} else if (option == '2') {
							get_angle();
							stepper_direction();
						}

						else if (option == '3') {
							LCD_enuSendString(" thank you ");

						}
					}
				}

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
					//	break;
					check = 0;
				}
			}
		}
	}
	return 0;
}

void stepper_direction() {
	u8 direction;
	u8 angle = 0;

	LCD_enuClear();
	LCD_enuSetAc(LCD_u8_LINE1, 0);
	LCD_enuSendString("1_CW");

	LCD_enuSetAc(LCD_u8_LINE1, 5);
	LCD_enuSendString("2_ACW");
	delay();
//	LCD_enuClear();

	while (1) {

		KPD_enuGetKeyState(&direction);
		if (direction != KPD_u8_KEY_NOT_PRESSED) {
			if (direction == '1') {
				LCD_enuClear();
				stepper_enuInit();
				stepper_enuHalfStep(CW, angle);
				break;
			} else if (direction == '2') {
				LCD_enuClear();
				stepper_enuInit();
				stepper_enuHalfStep(ACW, angle);
				break;
			}
		}
	}
}

void DC_direction(void) {
	u8 direction;
	LCD_enuClear();
	LCD_enuSetAc(LCD_u8_LINE1, 0);
	LCD_enuSendString("1_CW");

	LCD_enuSetAc(LCD_u8_LINE1, 5);
	LCD_enuSendString("2_ACW");

	delay();
//	LCD_enuClear();
	while (1) {
		KPD_enuGetKeyState(&direction);
		if (direction != 0xff) {
			if (direction == '1') {
//				LCD_enuClear();
				DcMotor_voidInit();
				DcMotor_enuStart(CW);
				break;
			} else if (direction == '2') {
//				LCD_enuClear();
				DcMotor_voidInit();
				DcMotor_enuStart(ACW);
				break;
			}
		}
	}
}




void get_angle() {
	u8 degree;
	u8 angle;

	LCD_enuClear();
	LCD_enuSetAc(LCD_u8_LINE1, 0);
	LCD_enuSendString("1_90");
	LCD_enuSetAc(LCD_u8_LINE1, 5);
	LCD_enuSendString("2_180");
	LCD_enuSetAc(LCD_u8_LINE2, 0);
	LCD_enuSendString("3-270");
	LCD_enuSendChar('7');

//	LCD_enuClear();
	while (1) {

		KPD_enuGetKeyState(&degree);
		if (degree != KPD_u8_KEY_NOT_PRESSED) {
			if (degree == '1') {
				angle = 90;
				stepper_direction();
				break;

			} else if (degree == '2') {
				angle = 180;
				stepper_direction();
				break;

			} else if (degree == '3') {
				angle = 270;
				stepper_direction();
				break;
			}

		}
	}
}	 
		 
		 


	
	
	
	
	
