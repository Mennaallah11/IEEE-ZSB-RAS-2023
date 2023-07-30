/*****************************************/
/******* Name : menna allah mohamed ******
/********** Date : 27 / 06 / 2023 ********/
/**************** SWC : EXTI **************/
/*************  Version : 1.0 ************/
/*****************************************/
/*LIBRARIES Layer*/
#include "../../Lib/STD_TYPES.h"
#include "../../Lib/BIT_MATH.h"
#include "../../Lib/ES.h"

/*MCAL*/
#include "EXTI_private.h"
#include "EXTI_interface.h"


//Global pointer to function
static void (*EXTI_ApfEXTI[Number_OFISRFUN])(void)={NULL,NULL,NULL};

ERROR  EXTI_enuExtiEnable(u8 Copy_u8EXTIIndex,u8 Copy_u8EdgeIndex)
{
	ERROR Local_u8_errorState = STD_OK ;
	switch(Copy_u8EXTIIndex)
	{
		case EXTI_u8_INT0 :
			switch(Copy_u8EdgeIndex)
			{
				case EXTI_u8_RISING_EDGE :
				SET_BIT(MCUCR  ,EXTI_u8_INT0_ISC01);
				SET_BIT(MCUCR  ,EXTI_u8_INT0_ISC00);
				 /* Enable EXTI0 */
				 SET_BIT(GICR ,EXTI0_u8_PIN6 );
				break;
			    case EXTI_u8_FALLING_EDGE :
				SET_BIT(MCUCR  ,EXTI_u8_INT0_ISC01);
			    CLR_BIT(MCUCR  ,EXTI_u8_INT0_ISC00);
				 /* Enable EXTI0 */
				SET_BIT(GICR ,EXTI0_u8_PIN6 );
				break;
				case EXTI_u8_ANY_LOGICAL_CHANGE :
				CLR_BIT(MCUCR  ,EXTI_u8_INT0_ISC01);
				SET_BIT(MCUCR  ,EXTI_u8_INT0_ISC00);
				 /* Enable EXTI0 */
				SET_BIT(GICR ,EXTI0_u8_PIN6 );
				break;
				case EXTI_u8_LOW_LEVEL :
				CLR_BIT(MCUCR  ,EXTI_u8_INT0_ISC01);
				CLR_BIT(MCUCR  ,EXTI_u8_INT0_ISC00);
				 /* Enable EXTI0 */
				SET_BIT(GICR ,EXTI0_u8_PIN6 );
				break;
				default: Local_u8_errorState = ES_OUT_OF_RANGE ;
			}	
			break;
			case EXTI_u8_INT1 :
			switch(Copy_u8EdgeIndex)
			{
				case EXTI_u8_RISING_EDGE :
				SET_BIT(MCUCR  ,EXTI_u8_INT1_ISC11);
				SET_BIT(MCUCR  ,EXTI_u8_INT1_ISC10);
				/* Enable EXTI1 */
				SET_BIT(GICR ,EXTI1_u8_PIN7 );
				break;
				case EXTI_u8_FALLING_EDGE :
				SET_BIT(MCUCR  ,EXTI_u8_INT1_ISC11);
				CLR_BIT(MCUCR  ,EXTI_u8_INT1_ISC10);
				/* Enable EXTI1 */
				SET_BIT(GICR ,EXTI1_u8_PIN7 );
				break;
				case EXTI_u8_ANY_LOGICAL_CHANGE :
				CLR_BIT(MCUCR  ,EXTI_u8_INT1_ISC11);
				SET_BIT(MCUCR  ,EXTI_u8_INT1_ISC10);
				/* Enable EXTI1 */
				SET_BIT(GICR ,EXTI1_u8_PIN7 );
				break;
				case EXTI_u8_LOW_LEVEL :
				CLR_BIT(MCUCR  ,EXTI_u8_INT1_ISC11);
				CLR_BIT(MCUCR  ,EXTI_u8_INT1_ISC10);
				/* Enable EXTI1 */
				SET_BIT(GICR ,EXTI1_u8_PIN7 );
				break;
				default: Local_u8_errorState = ES_OUT_OF_RANGE ;
			}
			break;
			case EXTI_u8_INT2 :
			switch(Copy_u8EdgeIndex)
			{
				case EXTI_u8_RISING_EDGE :
				SET_BIT(MCUCSR  ,EXTI_u8_INT2_ISC2);
				/* Enable EXTI2 */
				SET_BIT(GICR ,EXTI2_u8_PIN5 );
				break;
				case EXTI_u8_FALLING_EDGE :
				CLR_BIT(MCUCSR  ,EXTI_u8_INT2_ISC2);
				/* Enable EXTI2 */
				SET_BIT(GICR ,EXTI2_u8_PIN5 );
				break;
				default: Local_u8_errorState = ES_OUT_OF_RANGE ;
			}
			break;
			default: Local_u8_errorState = ES_OUT_OF_RANGE ;	
	}
	return Local_u8_errorState ;
}
/*****************************************************************/

ERROR  EXTI_enuExtiSetCallBack(void(*pf_ISR)(void), u8 Copy_u8ISRIndex)
{
	ERROR Local_u8_errorState = STD_OK ;
	if((Copy_u8ISRIndex <= EXTI_u8_INT2) && (pf_ISR != NULL))
	{
		EXTI_ApfEXTI[Copy_u8ISRIndex]=pf_ISR;
	}
	else 
	{
		Local_u8_errorState = STD_NOTOK ; 
	}
	return Local_u8_errorState ;
}
/*****************************************************************/

ERROR  EXTI_enuExtiDisable(u8 Copy_u8EXTIIndex)
{
	ERROR Local_u8_errorState = STD_OK ;
	if((Copy_u8EXTIIndex <= EXTI_u8_INT2))
	{
		switch(Copy_u8EXTIIndex)
		{
			case EXTI_u8_INT0 :
			CLR_BIT(GICR ,EXTI0_u8_PIN6 );
			break;
			case EXTI_u8_INT1 :
			CLR_BIT(GICR ,EXTI1_u8_PIN7 );
			break;
			case EXTI_u8_INT2 :
			CLR_BIT(GICR ,EXTI2_u8_PIN5 );
			break;
			default : Local_u8_errorState = ES_OUT_OF_RANGE ;
		}
	}
	else 
	{
		 Local_u8_errorState = STD_NOTOK ;
	}
	 return  Local_u8_errorState;
}

/****************************************************************/

// ISR EXTI0
void __vector_1(void)  __attribute__((signal));
void __vector_1(void) 
{
	if(EXTI_ApfEXTI[EXTI_u8_INT0] != NULL)
	{
		EXTI_ApfEXTI[EXTI_u8_INT0]();
	}
}

// ISR EXTI1
void __vector_2(void)  __attribute__((signal));
void __vector_2(void)
{
	if(EXTI_ApfEXTI[EXTI_u8_INT1] != NULL)
	{
		EXTI_ApfEXTI[EXTI_u8_INT1]();
	}
}

// ISR EXTI2
void __vector_3(void)  __attribute__((signal));
void __vector_3(void)
{
	if(EXTI_ApfEXTI[EXTI_u8_INT2] != NULL)
	{
		EXTI_ApfEXTI[EXTI_u8_INT2]();
	}
}



