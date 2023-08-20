/*****************************************/
/******* Name : menna allah mohamed ******/
/********** Date : 23 / 07 / 2023 ********/
/**************** SWC : stepper motor **************/
/*************  Version : 1.0 ************/
/*****************************************/


/*Lib Layer*/
#include "../../Lib/STD_TYPES.h"
#include "../../Lib/ES.h"

/*MCAL*/
#include "../../MCAL/DIO/DIO_interface.h"

/*HAL*/
#include "stepper_config.h"
#include "stepper_interface.h"
#include "stepper_private.h"


#define F_CPU 8000000UL
#include <util/delay.h>

ERROR stepper_enuInit(void)
{
	DIO_enuSetPinDirection(stepper_u8_PORT,stepper_u8_BLUE_PIN,DIO_u8OUTPUT);
	DIO_enuSetPinDirection(stepper_u8_PORT,stepper_u8_PINK_PIN,DIO_u8OUTPUT);
	DIO_enuSetPinDirection(stepper_u8_PORT,stepper_u8_YELLOW_PIN,DIO_u8OUTPUT);
	DIO_enuSetPinDirection(stepper_u8_PORT,stepper_u8_ORANGE_PIN,DIO_u8OUTPUT);
	return STD_OK ;
}

/****************************************************************/

ERROR stepper_enuFullStep(u8 stepper_u8Direction , f32 stepper_f32Angle)
{
	/* Control ULN 2003 */
	f32 steps = (stepper_f32Angle * 2048) / 360;			// number of steps of stepper motor
	u16 steps_ForLoop = steps / 4;			   // number of eterations of for loop (divided by four as it is a full step)
	
	if(stepper_u8Direction == ACW){
		for(u16 i = 0; i < steps_ForLoop; i++){
			/* First Step */
			DIO_enuSetPinValue(stepper_u8_PORT,stepper_u8_BLUE_PIN, DIO_u8LOW);
			DIO_enuSetPinValue(stepper_u8_PORT,stepper_u8_PINK_PIN, DIO_u8HIGH);
			DIO_enuSetPinValue(stepper_u8_PORT,stepper_u8_YELLOW_PIN, DIO_u8HIGH);
			DIO_enuSetPinValue(stepper_u8_PORT,stepper_u8_ORANGE_PIN, DIO_u8HIGH);
			_delay_ms(STEPPER_DELAY);
			/* Second Step */
			DIO_enuSetPinValue(stepper_u8_PORT,stepper_u8_BLUE_PIN, DIO_u8HIGH);
			DIO_enuSetPinValue(stepper_u8_PORT,stepper_u8_PINK_PIN, DIO_u8LOW);
			DIO_enuSetPinValue(stepper_u8_PORT,stepper_u8_YELLOW_PIN, DIO_u8HIGH);
			DIO_enuSetPinValue(stepper_u8_PORT,stepper_u8_ORANGE_PIN, DIO_u8HIGH);
			_delay_ms(STEPPER_DELAY);
			/* Third Step */
			DIO_enuSetPinValue(stepper_u8_PORT,stepper_u8_BLUE_PIN, DIO_u8HIGH);
			DIO_enuSetPinValue(stepper_u8_PORT,stepper_u8_PINK_PIN, DIO_u8HIGH);
			DIO_enuSetPinValue(stepper_u8_PORT,stepper_u8_YELLOW_PIN, DIO_u8LOW);
			DIO_enuSetPinValue(stepper_u8_PORT,stepper_u8_ORANGE_PIN, DIO_u8HIGH);
			/* Fourth Step */
		    DIO_enuSetPinValue(stepper_u8_PORT,stepper_u8_BLUE_PIN, DIO_u8HIGH);
		    DIO_enuSetPinValue(stepper_u8_PORT,stepper_u8_PINK_PIN, DIO_u8HIGH);
		    DIO_enuSetPinValue(stepper_u8_PORT,stepper_u8_YELLOW_PIN, DIO_u8HIGH);
			DIO_enuSetPinValue(stepper_u8_PORT,stepper_u8_ORANGE_PIN, DIO_u8LOW);
			_delay_ms(STEPPER_DELAY);
		}
	}
	else if (stepper_u8Direction == CW)
	{
		for(u16 i = 0; i < steps_ForLoop; i++){
			/* First Step */
		    DIO_enuSetPinValue(stepper_u8_PORT,stepper_u8_BLUE_PIN, DIO_u8HIGH);
		    DIO_enuSetPinValue(stepper_u8_PORT,stepper_u8_PINK_PIN, DIO_u8HIGH);
		    DIO_enuSetPinValue(stepper_u8_PORT,stepper_u8_YELLOW_PIN, DIO_u8HIGH);
		    DIO_enuSetPinValue(stepper_u8_PORT,stepper_u8_ORANGE_PIN, DIO_u8LOW);
			_delay_ms(STEPPER_DELAY);
			/* Second Step */
			DIO_enuSetPinValue(stepper_u8_PORT,stepper_u8_BLUE_PIN, DIO_u8HIGH);
			DIO_enuSetPinValue(stepper_u8_PORT,stepper_u8_PINK_PIN, DIO_u8HIGH);
			DIO_enuSetPinValue(stepper_u8_PORT,stepper_u8_YELLOW_PIN, DIO_u8LOW);
			DIO_enuSetPinValue(stepper_u8_PORT,stepper_u8_ORANGE_PIN, DIO_u8HIGH);
			_delay_ms(STEPPER_DELAY);
			
			/* Third Step */
			DIO_enuSetPinValue(stepper_u8_PORT,stepper_u8_BLUE_PIN, DIO_u8HIGH);
			DIO_enuSetPinValue(stepper_u8_PORT,stepper_u8_PINK_PIN, DIO_u8LOW);
			DIO_enuSetPinValue(stepper_u8_PORT,stepper_u8_YELLOW_PIN, DIO_u8HIGH);
			DIO_enuSetPinValue(stepper_u8_PORT,stepper_u8_ORANGE_PIN, DIO_u8HIGH);
			_delay_ms(STEPPER_DELAY);
			/* Fourth Step */
			DIO_enuSetPinValue(stepper_u8_PORT,stepper_u8_BLUE_PIN, DIO_u8LOW);
			DIO_enuSetPinValue(stepper_u8_PORT,stepper_u8_PINK_PIN, DIO_u8HIGH);
			DIO_enuSetPinValue(stepper_u8_PORT,stepper_u8_YELLOW_PIN, DIO_u8HIGH);
			DIO_enuSetPinValue(stepper_u8_PORT,stepper_u8_ORANGE_PIN, DIO_u8HIGH);
			_delay_ms(STEPPER_DELAY);
		}
	}
	return STD_OK ;
}

/************************************************************************************/

/* Half step anti-clockwise rotation */
ERROR stepper_enuHalfStep(u8 stepper_u8Direction , f32 stepper_f32Angle)
{
	/* Control ULN 2003 */
	f32 steps = (stepper_f32Angle * 2048) / 360;			//  number of steps of stepper motor
	u16 steps_ForLoop = steps / 8;			   //  number of eterations of for loop (divided by eight as it is a half step)
	if(stepper_u8Direction == ACW){
		for(u16 i = 0; i < steps_ForLoop; i++){
			/* 1st Step */

            DIO_enuSetPinValue(stepper_u8_PORT,stepper_u8_BLUE_PIN, DIO_u8LOW);
            DIO_enuSetPinValue(stepper_u8_PORT,stepper_u8_PINK_PIN, DIO_u8HIGH);
            DIO_enuSetPinValue(stepper_u8_PORT,stepper_u8_YELLOW_PIN, DIO_u8HIGH);
            DIO_enuSetPinValue(stepper_u8_PORT,stepper_u8_ORANGE_PIN, DIO_u8LOW);
			_delay_ms(STEPPER_DELAY);
			/* 2nd Step */
			DIO_enuSetPinValue(stepper_u8_PORT,stepper_u8_BLUE_PIN, DIO_u8LOW);
			DIO_enuSetPinValue(stepper_u8_PORT,stepper_u8_PINK_PIN, DIO_u8HIGH);
			DIO_enuSetPinValue(stepper_u8_PORT,stepper_u8_YELLOW_PIN, DIO_u8HIGH);
			DIO_enuSetPinValue(stepper_u8_PORT,stepper_u8_ORANGE_PIN, DIO_u8HIGH);
			_delay_ms(STEPPER_DELAY);
			/* 3rd Step */
            DIO_enuSetPinValue(stepper_u8_PORT,stepper_u8_BLUE_PIN, DIO_u8LOW);
            DIO_enuSetPinValue(stepper_u8_PORT,stepper_u8_PINK_PIN, DIO_u8LOW);
            DIO_enuSetPinValue(stepper_u8_PORT,stepper_u8_YELLOW_PIN, DIO_u8HIGH);
            DIO_enuSetPinValue(stepper_u8_PORT,stepper_u8_ORANGE_PIN, DIO_u8HIGH);
			_delay_ms(STEPPER_DELAY);
			/* 4th Step */
            DIO_enuSetPinValue(stepper_u8_PORT,stepper_u8_BLUE_PIN,DIO_u8HIGH );
            DIO_enuSetPinValue(stepper_u8_PORT,stepper_u8_PINK_PIN, DIO_u8LOW);
            DIO_enuSetPinValue(stepper_u8_PORT,stepper_u8_YELLOW_PIN, DIO_u8HIGH);
            DIO_enuSetPinValue(stepper_u8_PORT,stepper_u8_ORANGE_PIN, DIO_u8HIGH);
			_delay_ms(STEPPER_DELAY);
			/* 5th Step */
			DIO_enuSetPinValue(stepper_u8_PORT,stepper_u8_BLUE_PIN,DIO_u8HIGH );
			DIO_enuSetPinValue(stepper_u8_PORT,stepper_u8_PINK_PIN, DIO_u8LOW);
			DIO_enuSetPinValue(stepper_u8_PORT,stepper_u8_YELLOW_PIN, DIO_u8LOW);
			DIO_enuSetPinValue(stepper_u8_PORT,stepper_u8_ORANGE_PIN, DIO_u8HIGH);
			_delay_ms(STEPPER_DELAY);
			/* 6th Step */
			DIO_enuSetPinValue(stepper_u8_PORT,stepper_u8_BLUE_PIN,DIO_u8HIGH );
			DIO_enuSetPinValue(stepper_u8_PORT,stepper_u8_PINK_PIN,DIO_u8HIGH );
			DIO_enuSetPinValue(stepper_u8_PORT,stepper_u8_YELLOW_PIN, DIO_u8LOW);
			DIO_enuSetPinValue(stepper_u8_PORT,stepper_u8_ORANGE_PIN, DIO_u8HIGH);
			_delay_ms(STEPPER_DELAY);
			/* 7th Step */
			DIO_enuSetPinValue(stepper_u8_PORT,stepper_u8_BLUE_PIN,DIO_u8HIGH );
			DIO_enuSetPinValue(stepper_u8_PORT,stepper_u8_PINK_PIN,DIO_u8HIGH );
			DIO_enuSetPinValue(stepper_u8_PORT,stepper_u8_YELLOW_PIN, DIO_u8LOW);
			DIO_enuSetPinValue(stepper_u8_PORT,stepper_u8_ORANGE_PIN, DIO_u8LOW);
			_delay_ms(STEPPER_DELAY);
			/* 8th Step */
			DIO_enuSetPinValue(stepper_u8_PORT,stepper_u8_BLUE_PIN,DIO_u8HIGH );
			DIO_enuSetPinValue(stepper_u8_PORT,stepper_u8_PINK_PIN,DIO_u8HIGH );
			DIO_enuSetPinValue(stepper_u8_PORT,stepper_u8_YELLOW_PIN, DIO_u8HIGH);
			DIO_enuSetPinValue(stepper_u8_PORT,stepper_u8_ORANGE_PIN, DIO_u8LOW);
			_delay_ms(STEPPER_DELAY);
		}
	}
	else if (stepper_u8Direction == CW)
	{
		for(u16 i = 0; i < steps_ForLoop; i++){
			/* 1st Step */
			DIO_enuSetPinValue(stepper_u8_PORT,stepper_u8_BLUE_PIN,DIO_u8HIGH );
			DIO_enuSetPinValue(stepper_u8_PORT,stepper_u8_PINK_PIN,DIO_u8HIGH );
			DIO_enuSetPinValue(stepper_u8_PORT,stepper_u8_YELLOW_PIN, DIO_u8HIGH);
			DIO_enuSetPinValue(stepper_u8_PORT,stepper_u8_ORANGE_PIN, DIO_u8LOW);
			_delay_ms(STEPPER_DELAY);
			/* 2nd Step */
			DIO_enuSetPinValue(stepper_u8_PORT,stepper_u8_BLUE_PIN,DIO_u8HIGH );
			DIO_enuSetPinValue(stepper_u8_PORT,stepper_u8_PINK_PIN,DIO_u8HIGH );
			DIO_enuSetPinValue(stepper_u8_PORT,stepper_u8_YELLOW_PIN, DIO_u8LOW);
			DIO_enuSetPinValue(stepper_u8_PORT,stepper_u8_ORANGE_PIN, DIO_u8LOW);
			_delay_ms(STEPPER_DELAY);
			/* 3rd Step */
			DIO_enuSetPinValue(stepper_u8_PORT,stepper_u8_BLUE_PIN,DIO_u8HIGH );
			DIO_enuSetPinValue(stepper_u8_PORT,stepper_u8_PINK_PIN,DIO_u8HIGH );
			DIO_enuSetPinValue(stepper_u8_PORT,stepper_u8_YELLOW_PIN, DIO_u8LOW);
			DIO_enuSetPinValue(stepper_u8_PORT,stepper_u8_ORANGE_PIN, DIO_u8HIGH);
			_delay_ms(STEPPER_DELAY);
			/* 4th Step */
			DIO_enuSetPinValue(stepper_u8_PORT,stepper_u8_BLUE_PIN,DIO_u8HIGH );
			DIO_enuSetPinValue(stepper_u8_PORT,stepper_u8_PINK_PIN, DIO_u8LOW);
			DIO_enuSetPinValue(stepper_u8_PORT,stepper_u8_YELLOW_PIN, DIO_u8LOW);
			DIO_enuSetPinValue(stepper_u8_PORT,stepper_u8_ORANGE_PIN, DIO_u8HIGH);
			_delay_ms(STEPPER_DELAY);
			/* 5th Step */
            DIO_enuSetPinValue(stepper_u8_PORT,stepper_u8_BLUE_PIN,DIO_u8HIGH );
            DIO_enuSetPinValue(stepper_u8_PORT,stepper_u8_PINK_PIN, DIO_u8LOW);
            DIO_enuSetPinValue(stepper_u8_PORT,stepper_u8_YELLOW_PIN, DIO_u8HIGH);
            DIO_enuSetPinValue(stepper_u8_PORT,stepper_u8_ORANGE_PIN, DIO_u8HIGH);
			_delay_ms(STEPPER_DELAY);
			/* 6th Step */
           DIO_enuSetPinValue(stepper_u8_PORT,stepper_u8_BLUE_PIN, DIO_u8LOW);
           DIO_enuSetPinValue(stepper_u8_PORT,stepper_u8_PINK_PIN, DIO_u8LOW);
           DIO_enuSetPinValue(stepper_u8_PORT,stepper_u8_YELLOW_PIN, DIO_u8HIGH);
           DIO_enuSetPinValue(stepper_u8_PORT,stepper_u8_ORANGE_PIN, DIO_u8HIGH);
			_delay_ms(STEPPER_DELAY);
			/* 7th Step */
			DIO_enuSetPinValue(stepper_u8_PORT,stepper_u8_BLUE_PIN, DIO_u8LOW);
			DIO_enuSetPinValue(stepper_u8_PORT,stepper_u8_PINK_PIN, DIO_u8HIGH);
			DIO_enuSetPinValue(stepper_u8_PORT,stepper_u8_YELLOW_PIN, DIO_u8HIGH);
			DIO_enuSetPinValue(stepper_u8_PORT,stepper_u8_ORANGE_PIN, DIO_u8HIGH);
			_delay_ms(STEPPER_DELAY);
			/* 8th Step */
            DIO_enuSetPinValue(stepper_u8_PORT,stepper_u8_BLUE_PIN, DIO_u8LOW);
            DIO_enuSetPinValue(stepper_u8_PORT,stepper_u8_PINK_PIN, DIO_u8HIGH);
            DIO_enuSetPinValue(stepper_u8_PORT,stepper_u8_YELLOW_PIN, DIO_u8HIGH);
            DIO_enuSetPinValue(stepper_u8_PORT,stepper_u8_ORANGE_PIN, DIO_u8LOW);
			_delay_ms(STEPPER_DELAY);
		}
	}
	return STD_OK ;
}


