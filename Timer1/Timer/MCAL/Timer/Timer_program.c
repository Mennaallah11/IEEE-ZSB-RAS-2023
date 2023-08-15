/*****************************************/
/******* Name : menna allah mohamed ******
/********** Date : 12 / 08 / 2023 ********/
/**************** SWC : Timer **************/
/*************  Version : 1.0 ************/
/*****************************************/
/*lib layer*/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_Math.h"
/* MCAL */
#include "Timer_config.h"
#include "Timer_private.h"
#include "Timer_interface.h"
#include "../AVR_REG.h"
#include <stddef.h>
/**********************************************************************/
/*Global Pointer To Function of Timer0 ovf*/
static void (*Timer0_pftimer0OVF)(void) = NULL;
static void (*Timer0_pftimer0CTC)(void) = NULL;

/**********************************************************************/

ERROR Timers_enuTimer0Init(void)
{
    /* Select Mode */
	#if MODE == NORMAL_MODE
		CLR_BIT(TCCR0, WGM00);
		CLR_BIT(TCCR0, WGM01);
		/* Set preload value */
		TCNT0 = preload_value;
	#elif MODE == PWM_OR_PHASE_COTROL
		SET_BIT(TCCR0, WGM00);
		CLR_BIT(TCCR0, WGM01);
		/*select HW Action On OC0PIN */
		#if PHASE_COTROL_PWM_MODE == PHASE_CORRECT_PWM_INVERTING
		 SET_BIT(TCCR0,COM01);
		 SET_BIT(TCCR0,COM00);
		#elif PHASE_COTROL_PWM_MODE == PHASE_CORRECT_PWM_NON_INVERTING
		 SET_BIT(TCCR0,COM01);
		 CLR_BIT(TCCR0,COM00);
		#endif
	#elif MODE == CTC_MODE
		CLR_BIT(TCCR0, WGM00);
		SET_BIT(TCCR0, WGM01);
		OCR0 = CompareMatchValue;
	#elif MODE == FAST_PWM_MODE
		SET_BIT(TCCR0, WGM00);
		SET_BIT(TCCR0, WGM01);
		/*select HW Action On OC0PIN */
		#if FAST_PWM == FAST_PWM_INVERTING
		   SET_BIT(TCCR0,COM01);
		   SET_BIT(TCCR0,COM00);
		#elif FAST_PWM == FAST_PWM_NON_INVERTING
		   SET_BIT(TCCR0,COM01);
		   CLR_BIT(TCCR0,COM00); 
		#endif	  
	#endif

	/* Enable Interrupt */
	#if INTERRUPT == INTERRUPT_OVERFLOW
		SET_BIT(TIMSK, TOIE0);
	#elif INTERRUPT == INTERRUPT_CTC
		SET_BIT(TIMSK, OCIE0);
	#endif
	 
	/* Set prescaler value */
	#if prescaler == No_Clock_source
	   CLR_BIT(TCCR0,CS02);
	   CLR_BIT(TCCR0,CS01);
	   CLR_BIT(TCCR0,CS00);
	#elif prescaler == CLK_NoPrescling
		CLR_BIT(TCCR0, CS02);
		CLR_BIT(TCCR0, CS01);
		SET_BIT(TCCR0, CS00);
	#elif prescaler == CLK_8
		CLR_BIT(TCCR0, CS02);
		SET_BIT(TCCR0, CS01);
		CLR_BIT(TCCR0, CS00);
	#elif prescaler == CLK_64
		CLR_BIT(TCCR0, CS02);
		SET_BIT(TCCR0, CS01);
		SET_BIT(TCCR0, CS00);
	#elif prescaler == CLK_256
		SET_BIT(TCCR0, CS02);
		CLR_BIT(TCCR0, CS01);
		CLR_BIT(TCCR0, CS00);
	#elif prescaler == CLK_1024
		SET_BIT(TCCR0, CS02);
		CLR_BIT(TCCR0, CS01);
		SET_BIT(TCCR0, CS00);
	#elif prescaler == EXTERNAL_FALLING_EDGE
	    SET_BIT(TCCR0, CS02);
		SET_BIT(TCCR0, CS01);
		CLR_BIT(TCCR0, CS00);
	#elif prescaler == EXTERNAL_RISING_EDGE
	    SET_BIT(TCCR0, CS02);
	    SET_BIT(TCCR0, CS01);
		SET_BIT(TCCR0, CS00);	    
	#endif
	return STD_OK;
}

/******************************************/
ERROR Timers_enuTimer1Init(void)
{
	/* Select Timer1 Mode => fast PWM (mode 14) */
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
ERROR Timers_enuTimer0OVFSetCallBack(void(*Copy_pf)(void))
{
	if(Copy_pf != NULL)
	{
		Timer0_pftimer0OVF = Copy_pf;
	}
	else 
	{
		return STD_NOTOK ;
	}
	return STD_OK;
}
/******************************************/
ERROR Timers_enuTimer0CTCSetCallBack(void(*Copy_pf)(void))
{
	if(Copy_pf != NULL)
	{
		Timer0_pftimer0CTC = Copy_pf;
	}
	else
	{
		return STD_NOTOK ;
	}
	return STD_OK;
}
/******************************************/
ERROR Timers_enuTimer0SetCompareMatchValue(u8 Copy_u8OCR0Value)
{
	OCR0 = Copy_u8OCR0Value ;
	return STD_OK ; 
}
/******************************************/
ERROR Timers_enuServoAngle(u8 servoAngle)
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
/* Prototype for ISR of Timer0 OVF */
void __vector_11(void)	__attribute__((signal));
void __vector_11(void)
{
	static u16 Local_u16CounterOvf = 0;
	Local_u16CounterOvf++;
	if(Local_u16CounterOvf == overflows)
	{
		/* update preload value */
		TCNT0 = preload_value;
		/* Clear the OVF Counter */
		Local_u16CounterOvf = 0;
		/* Call application function */
		if(Timer0_pftimer0OVF != NULL)
		{
			Timer0_pftimer0OVF();
		}
	}
	
}
/*************************************/
void __vector_10(void)	__attribute__((signal));
void __vector_10(void)
{
	  
	  static u16 Local_u16CounterCTC = 0;
	  Local_u16CounterCTC++;
	  if(Local_u16CounterCTC == CTC)
	  {
		/* Clear the OVF Counter */
		Local_u16CounterCTC = 0;
		/* Call application function */
		if(Timer0_pftimer0CTC != NULL)
		{
			Timer0_pftimer0CTC();
		}
    	}
}



