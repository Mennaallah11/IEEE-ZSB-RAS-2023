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
	#elif MODE == PWM_OR_PHASE_COTROL
		SET_BIT(TCCR0, WGM00);
		CLR_BIT(TCCR0, WGM01);
	#elif MODE == CTC_MODE
		CLR_BIT(TCCR0, WGM00);
		SET_BIT(TCCR0, WGM01);
	#elif MODE == FAST_PWM_MODE
		SET_BIT(TCCR0, WGM00);
		SET_BIT(TCCR0, WGM01);
	#endif

	/* Enable Interrupt */
	#if INTERRUPT == INTERRUPT_OVERFLOW
		SET_BIT(TIMSK, TOIE0);
	#elif INTERRUPT == INTERRUPT_CTC
		SET_BIT(TIMSK, OCIE0);
	#endif
	OCR0 = 99 ; 

	/* Set preload value */
	TCNT0 = preload_value;
	
	/* Set prescaler value */
	#if prescaler == No_Clock_source
	   CLR_BIT(TCCR0,CS02);
	   CLR_BIT(TCCR0,CS01);
	   CLR_BIT(TCCR0,CS01);
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



