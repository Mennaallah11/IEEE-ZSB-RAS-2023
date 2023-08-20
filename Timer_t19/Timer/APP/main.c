#include "../Lib/STD_TYPES.h"
#include "../Lib/ES.h"


#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/Timer/Timer_interface.h"
#include "../HAL/servo_motor/servo_interface.h"
#include "../HAL/LCD/LCD_interface.h"
#include "../HAL/KPD_DRIVER/KPD_interface.h"
#include "../HAL/stepper_motor/stepper_interface.h"
#include "../HAL/DC_MOTOR/DcMotor_interface.h"



#include "../MCAL/AVR_REG.h"
#define F_CPU 8000000UL
#include <util/delay.h>


#define the_Password          "4433"
#define PasswordLength         4
#define max_try                3

void stepper_direction();
void DC_direction(void);
void get_angle() ;
void servo_angle();


int main()
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
					LCD_enuSetAc(LCD_u8_LINE1, 0);
					LCD_enuSendString("True Password :)");
					Timers_enudelayms(2000);
					LCD_enuClear();
					LCD_enuSendString("choose_motor");
					Timers_enudelayms(2000);
					LCD_enuClear();
					LCD_enuSetAc(LCD_u8_LINE1, 0);
					LCD_enuSendString("1-DC  2-stepper");
					//LCD_enuSendString("2-stepper");
					LCD_enuSetAc(LCD_u8_LINE2, 0);
					LCD_enuSendString("3-servo  4-EXIT");
				//	LCD_enuSendString("4-EXIT");
			    	Timers_enudelayms(2000);
					
					//		LCD_enuClear();
					while (1) {
						KPD_enuGetKeyState(&option);
						if (option != KPD_u8_KEY_NOT_PRESSED) {
							if (option == '1') {
								DC_direction();
								} 
								else if (option == '2') {
								get_angle();
								stepper_direction();
							}
							else if (option == '3') {
								servo_angle();
							}
							

							else if (option == '4') {
				     		LCD_enuSendString(" thank you ");
							 Timers_enudelayms(1000);
							}
						}
					}

					break;
					} else {
					LCD_enuClear();
					LCD_enuSetAc(1, 0);
					LCD_enuSendString("Wrong Password :)");
					Timers_enudelayms(1000);
					LCD_enuClear();
					check++;
					index = 0;
					if (check >= max_try) {
						LCD_enuSetAc(1, 0);
						LCD_enuSendString("Error :( ");
						Timers_enudelayms(1000);
						LCD_enuClear();
						//	break;
						check = 0;
					}
				}
			}
		}
	}

void stepper_direction() {
		u8 direction;
		u8 angle = 0;

		LCD_enuClear();
		LCD_enuSetAc(LCD_u8_LINE1, 0);
		LCD_enuSendString("1_CW");

		LCD_enuSetAc(LCD_u8_LINE2, 0);
		LCD_enuSendString("2_ACW");
		Timers_enudelayms(2000);
		
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

	LCD_enuSetAc(LCD_u8_LINE2, 0);
	LCD_enuSendString("2_ACW");
	Timers_enudelayms(2000);

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
	u16 angle;

	LCD_enuClear();
	LCD_enuSetAc(LCD_u8_LINE1, 0);
	LCD_enuSendString("1_90  2_180");
	LCD_enuSetAc(LCD_u8_LINE2, 0);
	LCD_enuSendString("3-270");
	Timers_enudelayms(2000);

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

void servo_angle() 
{
	u8 the_angle ;
	DIO_enuSetPinDirection(DIO_u8PORTD ,  DIO_u8PIN5 , DIO_u8OUTPUT);      
	LCD_enuSetAc(LCD_u8_LINE1, 0);
	LCD_enuSendString("1_0   2_45");
	LCD_enuSetAc(LCD_u8_LINE2, 0);
	LCD_enuSendString("3-90   4-180");
	Timers_enudelayms(2000);
	
	while (1) {

		KPD_enuGetKeyState(&the_angle);
		if (the_angle != KPD_u8_KEY_NOT_PRESSED) {
			if (the_angle == '1')
			{
				 servo_enuInit();
                servo_enuServoAngle(0);
				break;
			}
			else if(the_angle == '2')
			{
				 servo_enuInit();
				 servo_enuServoAngle(45);
				 break;
			}
			else if(the_angle == '3')
			{
				servo_enuInit();
				servo_enuServoAngle(90);
				break;
			}
			else if(the_angle == '4')
			{
				servo_enuInit();
				servo_enuServoAngle(180);
				break;
			}
		}		
		}
	
}
