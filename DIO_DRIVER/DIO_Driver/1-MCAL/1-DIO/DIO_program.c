/*****************************************/
/******* Name : menna allah mohamed ******/
/********** Date : 29 / 04 / 2023 ********/
/**************** SWC : DIO **************/
/*************  Version : 1.0 ************/
/*****************************************/

/*LIBRARIES Layer*/
#include "../../5-LIBRARIES/STD_TYPES.h"
#include "../../5-LIBRARIES/BIT_MATH.h"

/*MCAL*/
#include "DIO_private.h"
#include "DIO_config.h"
/*void DIO_voidInit (void){
	 DIO_u8_DDRA_REG = Conc(DIO_u8_PA7_INITIAL_DIRECTION,DIO_u8_PA6_INITIAL_DIRECTION,DIO_u8_PA5_INITIAL_DIRECTION,DIO_u8_PA4_INITIAL_DIRECTION,
                           DIO_u8_PA3_INITIAL_DIRECTION,DIO_u8_PA2_INITIAL_DIRECTION,DIO_u8_PA1_INITIAL_DIRECTION,DIO_u8_PA0_INITIAL_DIRECTION);

    DIO_u8_DDRB_REG = Conc(DIO_u8_PB7_INITIAL_DIRECTION,DIO_u8_PB6_INITIAL_DIRECTION,DIO_u8_PB5_INITIAL_DIRECTION,DIO_u8_PB4_INITIAL_DIRECTION,
                           DIO_u8_PB3_INITIAL_DIRECTION,DIO_u8_PB2_INITIAL_DIRECTION,DIO_u8_PB1_INITIAL_DIRECTION,DIO_u8_PB0_INITIAL_DIRECTION);

    DIO_u8_DDRC_REG = Conc(DIO_u8_PC7_INITIAL_DIRECTION,DIO_u8_PC6_INITIAL_DIRECTION,DIO_u8_PC5_INITIAL_DIRECTION,DIO_u8_PC4_INITIAL_DIRECTION,
                           DIO_u8_PC3_INITIAL_DIRECTION,DIO_u8_PC2_INITIAL_DIRECTION,DIO_u8_PC1_INITIAL_DIRECTION,DIO_u8_PC0_INITIAL_DIRECTION);

    DIO_u8_DDRD_REG = Conc(DIO_u8_PD7_INITIAL_DIRECTION,DIO_u8_PD6_INITIAL_DIRECTION,DIO_u8_PD5_INITIAL_DIRECTION,DIO_u8_PD4_INITIAL_DIRECTION,
                           DIO_u8_PD3_INITIAL_DIRECTION,DIO_u8_PD2_INITIAL_DIRECTION,DIO_u8_PD1_INITIAL_DIRECTION,DIO_u8_PD0_INITIAL_DIRECTION);

    DIO_u8_PORTA_REG = Conc(DIO_u8_PA7_INITIAL_VALUE,DIO_u8_PA6_INITIAL_VALUE,DIO_u8_PA5_INITIAL_VALUE,DIO_u8_PA4_INITIAL_VALUE,
                            DIO_u8_PA3_INITIAL_VALUE,DIO_u8_PA2_INITIAL_VALUE,DIO_u8_PA1_INITIAL_VALUE,DIO_u8_PA0_INITIAL_VALUE);

    DIO_u8_PORTB_REG = Conc(DIO_u8_PB7_INITIAL_VALUE,DIO_u8_PB6_INITIAL_VALUE,DIO_u8_PB5_INITIAL_VALUE,DIO_u8_PB4_INITIAL_VALUE,
                            DIO_u8_PB3_INITIAL_VALUE,DIO_u8_PB2_INITIAL_VALUE,DIO_u8_PB1_INITIAL_VALUE,DIO_u8_PB0_INITIAL_VALUE);

    DIO_u8_PORTC_REG = Conc(DIO_u8_PC7_INITIAL_VALUE,DIO_u8_PC6_INITIAL_VALUE,DIO_u8_PC5_INITIAL_VALUE,DIO_u8_PC4_INITIAL_VALUE,
    		DIO_u8_PC3_INITIAL_VALUE,DIO_u8_PC2_INITIAL_VALUE,DIO_u8_PC1_INITIAL_VALUE,DIO_u8_PC0_INITIAL_VALUE);

    DIO_u8_PORTD_REG = Conc(DIO_u8_PD7_INITIAL_VALUE,DIO_u8_PD6_INITIAL_VALUE,DIO_u8_PD5_INITIAL_VALUE,DIO_u8_PD4_INITIAL_VALUE,
                            DIO_u8_PD3_INITIAL_VALUE,DIO_u8_PD2_INITIAL_VALUE,DIO_u8_PD1_INITIAL_VALUE,DIO_u8_PD0_INITIAL_VALUE);

}*/
u8 DIO_u8SetPinDirection (u8 Copy_u8PortId ,u8 Copy_u8PinId , u8 Copy_u8PinDirection ) 
{
		u8 Local_u8_ErrorState = STD_TYPES_OK   ;
        /*check */
if ((Copy_u8PortId <= DIO_u8_PORTD) && (Copy_u8PinId <= DIO_u8_PIN7) && (Copy_u8PinDirection == DIO_u8_OUTPUT) ||( Copy_u8PinDirection == DIO_u8_INPUT))
{
	switch (Copy_u8PortId){
		case DIO_u8_PORTA :
			switch (Copy_u8PinDirection ){
			case DIO_u8_OUTPUT :SET_BIT(DIO_u8_DDRA_REG,Copy_u8PinId);break;
				case DIO_u8_INPUT :CLR_BIT(DIO_u8_DDRA_REG , Copy_u8PinId);break; } break ;

		case DIO_u8_PORTB :
		switch (Copy_u8PinDirection ){
			case DIO_u8_OUTPUT :SET_BIT(DIO_u8_DDRB_REG,Copy_u8PinId);break;
			case DIO_u8_INPUT :CLR_BIT(DIO_u8_DDRB_REG,Copy_u8PinId);break; } break ;

		case DIO_u8_PORTC :
	   switch (Copy_u8PinDirection ){
	   	   case DIO_u8_OUTPUT :SET_BIT(DIO_u8_DDRC_REG,Copy_u8PinId);break;
	   	   case DIO_u8_INPUT :CLR_BIT(DIO_u8_DDRB_REG,Copy_u8PinId);break; } break ;

	   case DIO_u8_PORTD :
		   switch (Copy_u8PinDirection ){
		   	   	  case DIO_u8_OUTPUT :SET_BIT(DIO_u8_DDRD_REG,Copy_u8PinId);break;
		   	   	  case DIO_u8_INPUT :CLR_BIT(DIO_u8_DDRD_REG,Copy_u8PinId);break; } break ;

}

}
else { 
        Local_u8_ErrorState = STD_TYPES_NOTOK   ;
}

        return Local_u8_ErrorState  ;

}
/***************************************************/

u8 DIO_u8SetPinValue (u8 Copy_u8PortId ,u8 Copy_u8PinId , u8 Copy_u8PinValue ) 
{
u8 Local_u8Errorstate = STD_TYPES_OK ;
if (Copy_u8PinId <= DIO_u8_PIN7 ) {
	switch  (Copy_u8PortId )
	{
		case DIO_u8_PORTA:
			switch (Copy_u8PinValue )
			{
				case DIO_u8_HIGH: SET_BIT(DIO_u8_PORTA_REG ,Copy_u8PinId );break ;
				case DIO_u8_LOW: CLR_BIT(DIO_u8_PORTA_REG ,Copy_u8PinId );break ;
				default : Local_u8Errorstate = STD_TYPES_NOTOK;
				}
			break ;

		case DIO_u8_PORTB:
			switch (Copy_u8PinValue )
			{
				case DIO_u8_HIGH: SET_BIT(DIO_u8_PORTB_REG ,Copy_u8PinId );break ;
				case DIO_u8_LOW: CLR_BIT(DIO_u8_PORTB_REG ,Copy_u8PinId );break ;
				default : Local_u8Errorstate = STD_TYPES_NOTOK;
			}
			break ;

		case DIO_u8_PORTC:
			switch (Copy_u8PinValue )
			{
			case DIO_u8_HIGH: SET_BIT(DIO_u8_PORTC_REG ,Copy_u8PinId );break ;
			case DIO_u8_LOW: CLR_BIT(DIO_u8_PORTC_REG ,Copy_u8PinId );break ;
			default : Local_u8Errorstate = STD_TYPES_NOTOK;}
			break ;

		case DIO_u8_PORTD:
			switch (Copy_u8PinValue )
			{
				case DIO_u8_HIGH: SET_BIT(DIO_u8_PORTD_REG ,Copy_u8PinId );break ;
				case DIO_u8_LOW: CLR_BIT(DIO_u8_PORTD_REG ,Copy_u8PinId );break ;
				default : Local_u8Errorstate = STD_TYPES_NOTOK;}
				break ;

		default :
			Local_u8Errorstate = STD_TYPES_NOTOK;
		}
        }
else {Local_u8Errorstate = STD_TYPES_NOTOK;
}
 return Local_u8Errorstate  ;      
   }

/************************************************/

u8 DIO_u8GetPinValue (u8 Copy_u8PortId ,u8 Copy_u8PinId , u8 *Copy_pu8ReturndPinValue ) 
{
u8 Local_u8Errorstate = STD_TYPES_OK ;
u8 Local_u8PinValue;
if ((Copy_u8PortId <= DIO_u8_PORTD) && (Copy_u8PinId <= DIO_u8_PIN7) && ( Copy_pu8ReturndPinValue != NULL))
{
	switch (Copy_u8PortId)
	{
		case DIO_u8_PORTA:Local_u8PinValue = GET_BIT(DIO_u8_PINA_REG, Copy_u8PinId );
			if (Local_u8PinValue == STD_TYPES_NOTOK )
			{
				*Copy_pu8ReturndPinValue = DIO_u8_LOW;}
			else{*Copy_pu8ReturndPinValue = DIO_u8_HIGH;
			}break ;

	    case DIO_u8_PORTB:Local_u8PinValue = GET_BIT(DIO_u8_PINB_REG , Copy_u8PinId);
	    	if (Local_u8PinValue == STD_TYPES_NOTOK )
	    	{
	    		*Copy_pu8ReturndPinValue = DIO_u8_LOW;}
	    	else{*Copy_pu8ReturndPinValue = DIO_u8_HIGH;
	    	}break;

	    case DIO_u8_PORTC:Local_u8PinValue = GET_BIT(DIO_u8_PINC_REG, Copy_u8PinId);
	    	if (Local_u8PinValue == STD_TYPES_NOTOK )
	    	{
	    		*Copy_pu8ReturndPinValue = DIO_u8_LOW;}
	    	else{*Copy_pu8ReturndPinValue = DIO_u8_HIGH;
	    	}break;

	    case DIO_u8_PORTD:Local_u8PinValue = GET_BIT(DIO_u8_PIND_REG, Copy_u8PinId);
	    	if (Local_u8PinValue == STD_TYPES_NOTOK )
	    	{
	    		*Copy_pu8ReturndPinValue = DIO_u8_LOW;}
	    	else{*Copy_pu8ReturndPinValue = DIO_u8_HIGH;
	    	}break;
  }
}
else {
Local_u8Errorstate = STD_TYPES_NOTOK;
}
return Local_u8Errorstate  ;      
}
/******************************************************/ 

u8 DIO_u8SetPortDirection (u8 Copy_u8PortId ,u8 Copy_u8PortDirection )
{
u8 Local_u8Errorstate = STD_TYPES_OK ;
if ((Copy_u8PortDirection == DIO_u8_OUTPUT) ||( Copy_u8PortDirection == DIO_u8_INPUT))
{
	switch (Copy_u8PortId){
		case DIO_u8_PORTA :
			switch (Copy_u8PortDirection) {
				case DIO_u8_OUTPUT :DIO_u8_DDRA_REG = 0xff;break;
				case DIO_u8_INPUT :DIO_u8_DDRA_REG = 0x00;break ;
				}break ;

		case DIO_u8_PORTB :
			switch (Copy_u8PortDirection ){
				case DIO_u8_OUTPUT :DIO_u8_DDRB_REG = 0xff;break;
				case DIO_u8_INPUT :DIO_u8_DDRB_REG = 0x00;break ;
				}break ;

	   case DIO_u8_PORTC :
		   switch (Copy_u8PortDirection ){
		   case DIO_u8_OUTPUT :DIO_u8_DDRC_REG = 0xff;break;
		   case DIO_u8_INPUT :DIO_u8_DDRC_REG = 0x00;break ;
		   }break ;

	  case DIO_u8_PORTD :
		  switch (Copy_u8PortDirection ){
		  case DIO_u8_OUTPUT :DIO_u8_DDRD_REG = 0xff;break;
		  case DIO_u8_INPUT :DIO_u8_DDRD_REG = 0x00;break ;
		  }break ;

     default :Local_u8Errorstate = STD_TYPES_NOTOK;
}
}
else {
Local_u8Errorstate = STD_TYPES_NOTOK;
} 
return Local_u8Errorstate  ;      
}
/********************************************************/


u8 DIO_u8SetPortValue (u8 Copy_u8PortId ,u8 Copy_u8PortValue )
{
	u8 Local_u8Errorstate = STD_TYPES_OK ;
	switch (Copy_u8PortId)
{
	case DIO_u8_PORTA:DIO_u8_PORTA_REG =Copy_u8PortValue ; break ;
	case DIO_u8_PORTB:DIO_u8_PORTB_REG =Copy_u8PortValue ; break ;
	case DIO_u8_PORTC:DIO_u8_PORTC_REG =Copy_u8PortValue ; break ;
	case DIO_u8_PORTD:DIO_u8_PORTD_REG =Copy_u8PortValue ; break ;
	default :Local_u8Errorstate = STD_TYPES_NOTOK;
}
return Local_u8Errorstate  ;
}
/*********************************************/

u8 DIO_u8GetPortValue (u8 Copy_u8PortId ,u8 *Copy_pu8ReturndPortValue )
{
	u8 Local_u8Errorstate = STD_TYPES_OK ;
	if (Copy_pu8ReturndPortValue!= NULL)
{
	switch (Copy_u8PortId)
	{
		case DIO_u8_PORTA:*Copy_pu8ReturndPortValue = DIO_u8_PORTA_REG  ; break ;
		case DIO_u8_PORTB:*Copy_pu8ReturndPortValue = DIO_u8_PORTB_REG  ; break ;
		case DIO_u8_PORTC:*Copy_pu8ReturndPortValue = DIO_u8_PORTC_REG  ; break ;
		case DIO_u8_PORTD:*Copy_pu8ReturndPortValue = DIO_u8_PORTD_REG  ; break ;
		default :Local_u8Errorstate = STD_TYPES_NOTOK;
}
}
else {
Local_u8Errorstate = STD_TYPES_NOTOK;
}
return Local_u8Errorstate  ;
} 
