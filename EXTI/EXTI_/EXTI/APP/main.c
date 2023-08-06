#include "../Lib/STD_TYPES.h"
#include "../Lib/ES.h"
#include "../Lib/BIT_MATH.h"

#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/EXTI/EXTI_interface.h"
#include "../MCAL//GI/GI_interface.h"

#include "../HAL/LCD/LCD_Interface.h"
#include "../HAL/KPD/KPD_Interface.h"
#include "../HAL/DC_MOTOR/DcMotor_interface.h"
#include "../HAL/STEPPER_MOTOR/STEPPER_interface.h"

#define SREG       *((volatile u8*)0x5F)
#define the_Password          "4433"
#define PasswordLength         4
#define max_try                3


void login(void);

int main()
{
//	DIO_enuInit();
    DIO_enuSetPinDirection(DIO_u8PORTD,DIO_u8PIN2,DIO_u8INPUT);
	GI_enuGIEnable();
	EXTI_enuExtiEnable(EXTI_u8_INT0,EXTI_u8_RISING_EDGE);
	SET_BIT(SREG  ,7);
	EXTI_enuExtiSetCallBack(&login,EXTI_u8_INT0);
	
	while(1);
	return 0;
}

void login(void)
{
	KPD_enuInit();
	LCD_enuInit();
	//DcMotor_voidInit();
	//stepper_enuInit();
	u8 ReturnedKey  ;
	
	u8 ThePassword[PasswordLength] = the_Password;
	u8 Password[PasswordLength]={0};
	u8 index ;
	u8 flag = 0 ;
	u8 check = 0 ;
	u8 option;
    while(1)
{
	LCD_enuSetAc(1,5);
    LCD_enuSendString("Enter_Password:");
	_delay_ms(100);
	LCD_enuClear();

    KPD_enuGetKeyState(&ReturnedKey);
	if (ReturnedKey != KPD_u8_KEY_NOT_PRESSED )
	{
		LCD_enuSendChar('*');
		Password[index] = ReturnedKey ;
		index ++ ; 
		check ++ ;
	}
	if ((index)== PasswordLength)
	{
		for (int i = 0 ; i < PasswordLength ; i ++ )
		{
			if (Password[i]!=ThePassword[i])
			{
				 flag=1;
				 break;	       
			}
		 }
		if(flag)
		{
			LCD_enuClear();
			LCD_enuSendString("Wrong Password");
			 _delay_ms(1);
			LCD_enuClear();
			check++ ;
			index = 0 ;
			flag = 0 ;
			if (check >= max_try) 
			{
				LCD_enuClear();
				LCD_enuSendString("Error :( ");
				_delay_ms(100);
				LCD_enuClear();
				check = 0 ;
		
			}
		}
		else 
		{
			LCD_enuClear();
			LCD_enuSendString("True Password :)");
			  _delay_ms(100);
			LCD_enuClear();
			LCD_enuSendString("choose_motor");
			
			_delay_ms(100);
			LCD_enuClear();
			LCD_enuSetAc(LCD_u8_LINE1,0);
			LCD_enuSendString("1-DC");
		
			LCD_enuSetAc(LCD_u8_LINE1,5);
			LCD_enuSendString("2-stepper");
			
			LCD_enuSetAc(LCD_u8_LINE2,0);
			LCD_enuSendString("3-EXIT");
			KPD_enuGetKeyState(&option);
			if (option != KPD_u8_KEY_NOT_PRESSED )
			{
				if (option == '1')
				{
					DC_direction();
				}
				else if (option =='2')
			    {
					get_angle();
					stepper_direction();		
				}

				else if (option =='3')	
				{
					LCD_enuSendString(" thank you ");
				
				}
			}
			break;
        }
	}
}
}

void stepper_direction()
{
	u8 direction ;
	u8 angle =0 ;
	
	LCD_enuClear();
	LCD_enuSetAc(LCD_u8_LINE1,0);
	LCD_enuSendString("1_CW");

	LCD_enuSetAc(LCD_u8_LINE1,5);
	LCD_enuSendString("2_ACW");
	LCD_enuSendChar('A');
	

	KPD_enuGetKeyState(&direction);
	if (direction != KPD_u8_KEY_NOT_PRESSED )
	{
		if (direction== '1')
		{
			LCD_enuClear();
			stepper_enuInit();
			stepper_enuHalfStep(CW, angle);
			// break;
		}
		else if (direction== '2')
		{
			LCD_enuClear();
			stepper_enuInit();
			stepper_enuHalfStep(ACW, angle);
			// break;
		}
	}
}

void DC_direction(void)
{
	u8 direction ;
	LCD_enuClear();
	LCD_enuSetAc(LCD_u8_LINE1,0);
	LCD_enuSendString("1_CW");
	
	LCD_enuSetAc(LCD_u8_LINE1,5);
	LCD_enuSendString("2_ACW");
	
	
	KPD_enuGetKeyState(&direction);
	if (direction != KPD_u8_KEY_NOT_PRESSED )
	{
		if (direction== '1')
		{
			LCD_enuClear();
			DcMotor_voidInit();
			DcMotor_enuStart(CW);
			//	break;
		}
		else if (direction== '2')
		{
			LCD_enuClear();
			DcMotor_voidInit();
			DcMotor_enuStart(ACW);
			//	break;
		}
	}
}

void get_angle()
{
	u8 degree ;
	u8 angle ;
	
	LCD_enuClear();
	LCD_enuSetAc(LCD_u8_LINE1,0);
	LCD_enuSendString("1_90");
	
	LCD_enuSetAc(LCD_u8_LINE1,5);
	LCD_enuSendString("2_180");
	
	LCD_enuSetAc(LCD_u8_LINE2,0);
	LCD_enuSendString("3-270");
	
	LCD_enuClear();
	
	KPD_enuGetKeyState(&degree);
	if (degree != KPD_u8_KEY_NOT_PRESSED )
	{
		if (degree =='1')
		{
			angle = 90;
			stepper_direction();
			// break ;
			
		}
		else if (degree =='2')
		{
			angle = 180;
			stepper_direction();
			// break ;
			
		}
		else if (degree =='3')
		{
			angle = 270;
			stepper_direction();
			// break ;
		}
		
	}
}