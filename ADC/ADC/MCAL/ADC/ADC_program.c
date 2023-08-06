/*****************************************/
/******* Name : menna allah mohamed ******
/********** Date : 02 / 08 / 2023 ********/
/**************** SWC : ADC **************/
/*************  Version : 1.0 ************/
/*****************************************/

/*LIBRARIES Layer*/
#include "../../Lib/STD_TYPES.h"
#include "../../Lib/BIT_MATH.h"
#include "../../Lib/ES.h"

/*MCAL*/
#include "ADC_interface.h"
#include "../AVR_REG.h"
#include "ADC_private.h"
#include "ADC_config.h"

static u8 ADC_u8BusyFlag = zero;
static void(*ADC_pfNotification)(u16) = NULL;

ERROR ADC_enuInit(void)
{

	/*	1- Select Vref  */
	#if (ADC_VREF == AVCC)
	CLR_BIT(ADMUX,REFS1);
	SET_BIT(ADMUX,REFS0);
	#elif (ADC_VREF == AREF)
	CLR_BIT(ADMUX,REFS1);
	CLR_BIT(ADMUX,REFS0);
	#elif (ADC_VREF == INTERNAL_VOLTAGE_REF )
	SET_BIT(ADMUX,REFS1);
	SET_BIT(ADMUX,REFS0);
	#endif
	
	/* 2- Right or Left Adjust */
	#if (ADC_ADJUST == RIGHT_ADJUST)
	CLR_BIT(ADMUX,ADLAR);
	#elif (ADC_ADJUST == LEFT_ADJUST)
	SET_BIT(ADMUX,ADLAR);
	#endif
	
    /* 3- CONVERSION MODE */
	#if ADC_CONVERSION_MODE == START_CONVERSION
	CLR_BIT(ADCSRA,ADATE);
	#elif ADC_CONVERSION_MODE == FREE_RUNNING_MODE
	SET_BIT(ADCSRA,ADATE);
	CLR_BIT(SFIOR,ADTS2);
	CLR_BIT(SFIOR,ADTS1);
	CLR_BIT(SFIOR,ADTS0);
	#elif ADC_CONVERSION_MODE == EXTERNAL_INTERRUPT
	SET_BIT(ADCSRA,ADATE);
	CLR_BIT(SFIOR,ADTS2);
	SET_BIT(SFIOR,ADTS1);
	CLR_BIT(SFIOR,ADTS0);
	#endif

    /* 4- Select CLK/DIV_FACTOR*/
    #if DEVISION_FACTOR == DIV_BY_2  
    CLR_BIT(ADCSRA, ADPS2);
    CLR_BIT(ADCSRA, ADPS1);
    SET_BIT(ADCSRA, ADPS0);
    #elif DEVISION_FACTOR == DIV_BY_4
    CLR_BIT(ADCSRA, ADPS2);
    SET_BIT(ADCSRA, ADPS1);
    CLR_BIT(ADCSRA, ADPS0);
    #elif DEVISION_FACTOR == DIV_BY_8
    CLR_BIT(ADCSRA, ADPS2);
    SET_BIT(ADCSRA, ADPS1);
    SET_BIT(ADCSRA, ADPS0);
    #elif DEVISION_FACTOR == DIV_BY_16
    SET_BIT(ADCSRA, ADPS2);
    CLR_BIT(ADCSRA, ADPS1);
    CLR_BIT(ADCSRA, ADPS0);
    #elif DEVISION_FACTOR == DIV_BY_32
    SET_BIT(ADCSRA, ADPS2);
    CLR_BIT(ADCSRA, ADPS1);
    SET_BIT(ADCSRA, ADPS0);
    #elif DEVISION_FACTOR == DIV_BY_64
    SET_BIT(ADCSRA, ADPS2);
    SET_BIT(ADCSRA, ADPS1);
    CLR_BIT(ADCSRA, ADPS0);
    #elif DEVISION_FACTOR == DIV_BY_128
    SET_BIT(ADCSRA, ADPS2);
    SET_BIT(ADCSRA, ADPS1);
    SET_BIT(ADCSRA, ADPS0);
    #endif
    /*5- Enable ADC*/
	SET_BIT(ADCSRA,ADEN);
	return STD_OK ;
}

/*********************************************/

ERROR ADC_eunGetDigitalValueSynchNonBlocking(u8 Copy_u8ChannelNb, u16 *Copy_pu16DigitalValue)
{
	u32 Local_u32TimeOutCounter = 0;
	 if((Copy_u8ChannelNb<MAX_NUM_OF_CHANNELS) && (Copy_pu16DigitalValue!= NULL) && (ADC_u8BusyFlag ==0))
	 {
		  /* Set Flag to make ADC is Busy */
		  ADC_u8BusyFlag = 1;
		 //Clear MUX4...0
		 ADMUX &= CLEAR_MUX_BITS;
		 //Select Channel
		 ADMUX |= Copy_u8ChannelNb;
		 //Start Conversion
		 SET_BIT(ADCSRA,ADSC);
		 //Wait -> ADC Flag = 1 
		 while(((GET_BIT(ADCSRA,ADIF))==zero ) && Local_u32TimeOutCounter < ADC_u32_TIME_OUT_MAX_VALUE )
		 {
			 Local_u32TimeOutCounter ++ ; 
		 }
		 if ((GET_BIT(ADCSRA,ADIF))!=zero) // ADC Flag = 1  , Local_u32TimeOutCounter < ADC_u32_TIME_OUT_MAX_VALUE
		 {
			  //clear flag
			  SET_BIT(ADCSRA,ADIF);
			  ADC_u8BusyFlag = 0 ;
			  //Read Digital Value
			  *Copy_pu16DigitalValue = ADC_u16_ADC_REG;
		 }
		 else 
		 {
			 return STD_NOTOK ;
		 }

	  }
	 else
	 {
		 return STD_NOTOK;
	 }
		 
		  return STD_OK;
}

/******************************************************/

ERROR ADC_enuGetDigitalValueAsynch(u8 Copy_u8ChannelNb,void(*Copy_pfNotification)(u16))
{
	 if((Copy_u8ChannelNb<MAX_NUM_OF_CHANNELS) && (Copy_pfNotification!= NULL) && (ADC_u8BusyFlag ==0))
	 {
		     /* Set Flag to make ADC is Busy */
		      ADC_u8BusyFlag = 1;
			 /* update Global Pointer to a function */
			 ADC_pfNotification = Copy_pfNotification;
			 /* Enable ADC Interrupt */
			 SET_BIT(ADCSRA,ADIE);
			 /* Clear MUX4..0 */
			 ADMUX &= CLEAR_MUX_BITS;
			 /* Select Channel */
			 ADMUX |= Copy_u8ChannelNb;
			 /* Start Conversion */
			 SET_BIT(ADCSRA,ADSC);
		 }
		 else
		 {
			  return STD_NOTOK;
		 }
     return STD_OK;

}
/********************************************************/

/* Prototype for ADC ISR */
void __vector_16(void)  __attribute__((signal));
void __vector_16(void)
{
	if(ADC_pfNotification != NULL)
	{
		/* Clear Flag */
		ADC_u8BusyFlag = 0;
		/* Clear PIE of ADC */
		CLR_BIT(ADCSRA,ADIE);
		/* Calling Notification function */
		ADC_pfNotification(ADC_u16_ADC_REG);
	}
}