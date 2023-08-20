/*****************************************/
/******* Name : menna allah mohamed ******
/********** Date : 17 / 08 / 2023 ********/
/**************** SWC : servo motor **************/
/*************  Version : 1.0 ************/
/*****************************************/
/*lib layer*/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_Math.h"
/* HAL */

#include "servo_interface.h"
#include "servo_private.h"


#include "../../MCAL/AVR_REG.h"
#include <stddef.h>
/**********************************************************************/

ERROR servo_enuInit(void)
{
	/* Select Timer1 Mode (ICR1)=> fast PWM (mode 14) */
	CLR_BIT(TCCR1A, WGM10);
	SET_BIT(TCCR1A, WGM11);
	SET_BIT(TCCR1B, WGM12);
	SET_BIT(TCCR1B, WGM13);
	
	/* Select HW Action on OC1A pin => Non Inverting */
	SET_BIT(TCCR1A, COM1A1);
	CLR_BIT(TCCR1A, COM1A0);
	
	/* Set Top Value in ICR1 */
	ICR1 = Top_Value;
	
	/* Set Angle Of Servo Motor */
//	OCR1A = Angle_Of_Servo_Motor;
	
	/* Set Prescaler Value => clk / 8 */
	CLR_BIT(TCCR1B, CS00);
	SET_BIT(TCCR1B, CS01);
	CLR_BIT(TCCR1B, CS02);
}
/******************************************/

ERROR servo_enuServoAngle(u8 servoAngle)
{
	if(servoAngle <= max_angle)
	{
		OCR1A = ((servoAngle*1000UL)/max_angle)+999;
	}
	else
	{
		return STD_NOTOK;
	}
	return STD_OK ;
}
/******************************************/
