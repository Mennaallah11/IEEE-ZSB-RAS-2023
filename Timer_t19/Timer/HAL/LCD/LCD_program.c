/*****************************************/
/******* Name : menna allah mohamed ******/
/********** Date : 4 / 05 / 2023 ********/
/**************** SWC : LCD **************/
/*************  Version : 1.0 ************/
/*****************************************/

/*Lib Layer*/
#include "../../Lib/STD_TYPES.h"
#include "../../Lib/ES.h"

/*MCAL*/
#include "../../MCAL/DIO/DIO_interface.h"
/*HAL*/
#include "LCD_private.h"
#include "LCD_config.h"
//#include "LCD_interface.h"

#define F_CPU 8000000UL
#include <util/delay.h>

/************************************************/
 ERROR LCD_enuSendCmnd(u8 Copy_u8Cmdn)
{
#if    (LCD_u8_MODE == LCD_u8_MODE_8_BIT)
	/* RS = 0 */
	DIO_enuSetPinValue (LCD_u8_CONTROL_PORT,LCD_u8_RS_PIN,DIO_u8LOW);

	/* RW = 0 */
    DIO_enuSetPinValue (LCD_u8_CONTROL_PORT,LCD_u8_RW_PIN,DIO_u8LOW);
   
    /*Write Command*/
    DIO_enuSetPortValue(LCD_u8_DATA_PORT,Copy_u8Cmdn);

    /* E = 1 */
    DIO_enuSetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_E_PIN,DIO_u8HIGH);
    _delay_us(1);

    /* E = 0 */
    DIO_enuSetPinValue (LCD_u8_CONTROL_PORT,LCD_u8_E_PIN,DIO_u8LOW);

    return STD_OK;
#elif   (LCD_u8_MODE == LCD_u8_MODE_4_BIT)
    /* code to send a command at 4 bit mode */
	/* RS = 0 */
	DIO_enuSetPinValue (LCD_u8_CONTROL_PORT,LCD_u8_RS_PIN,DIO_u8LOW);

	/* RW = 0 */
    DIO_enuSetPinValue (LCD_u8_CONTROL_PORT,LCD_u8_RW_PIN,DIO_u8LOW);

    /*Write Command*/
    DIO_enuSetPortValue(LCD_u8_DATA_PORT,Copy_u8Cmdn);

    /* E = 1 */
    DIO_enuSetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_E_PIN,DIO_u8HIGH);
    _delay_us(1);

    /* E = 0 */
    DIO_enuSetPinValue (LCD_u8_CONTROL_PORT,LCD_u8_E_PIN,DIO_u8LOW);

    /*Write Command*/
    DIO_enuSetPortValue(LCD_u8_DATA_PORT,Copy_u8Cmdn<<4);

    /* E = 1 */
    DIO_enuSetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_E_PIN,DIO_u8HIGH);
    _delay_us(1);

    /* E = 0 */
    DIO_enuSetPinValue (LCD_u8_CONTROL_PORT,LCD_u8_E_PIN,DIO_u8LOW);

    return STD_OK;

#endif
    return STD_OK;

}
/************************************************/

 /*ERROR LCD_enuInit(void)
 {

	 	DIO_enuSetPinDirection(LCD_u8_RS_PORT, LCD_u8_RS_PIN, DIO_u8OUTPUT);
	 	DIO_enuSetPinDirection(LCD_u8_RW_PORT, LCD_u8_RW_PIN, DIO_u8OUTPUT);
	 	DIO_enuSetPinDirection(LCD_u8_E_PORT, LCD_u8_E_PIN, DIO_u8OUTPUT);
	 	DIO_enuSetPortDirection(LCD_u8_DATA_PORT,DIO_u8OUTPUT);
	 	DIO_enuSetPortValue (LCD_u8_DATA_PORT ,DIO_u8LOW  ) ;

	 	DIO_enuSetPinValue(LCD_u8_RS_PORT,LCD_u8_RS_PIN,DIO_u8LOW);
	 	DIO_enuSetPinValue(LCD_u8_RW_PORT,LCD_u8_RW_PIN,DIO_u8LOW);
	 	DIO_enuSetPinValue(LCD_u8_E_PORT,LCD_u8_E_PIN,DIO_u8LOW);
		 
		 _delay_ms( POWER_ON  );
		 LCD_enuSendCmnd(FUN_SET_8_BIT );
		 _delay_us( WAIT_FOR_MORE_THAN_40us );
		 LCD_enuSendCmnd(DISPLAY_ON_OFF_8_BIT);
		 _delay_us( WAIT_FOR_MORE_THAN_40us );
		 LCD_enuSendCmnd(DISPLAY_CLEAR_8_BIT);
		 _delay_ms(WAIT_FOR_MORE_THAN_2ms);
		 LCD_enuSendCmnd(ENTRY_MOOD_SET_8_BIT);
		 return STD_OK;

/*#if  (LCD_u8_MODE == LCD_u8_MODE_8_BIT)
 	_delay_ms( POWER_ON  );
 	LCD_enuSendCmnd(FUN_SET_8_BIT );
 	_delay_us( WAIT_FOR_MORE_THAN_40us );
 	LCD_enuSendCmnd(DISPLAY_ON_OFF_8_BIT);
 	_delay_us( WAIT_FOR_MORE_THAN_40us );
 	LCD_enuSendCmnd(DISPLAY_CLEAR_8_BIT);
 	_delay_ms(WAIT_FOR_MORE_THAN_2ms);
 	LCD_enuSendCmnd(ENTRY_MOOD_SET_8_BIT);
 	return STD_OK;

#elif  (LCD_u8_MODE == LCD_u8_MODE_4_BIT)
 	_delay_ms( POWER_ON  );
 	LCD_enuSendCmnd(FUN_SET_4_BIT);
 	_delay_us( WAIT_FOR_MORE_THAN_40us );
 	LCD_enuSendCmnd(DISPLAY_ON_OFF_4_BIT);
 	_delay_us( WAIT_FOR_MORE_THAN_40us );
 	LCD_enuSendCmnd(DISPLAY_CLEAR_4_BIT);
 	_delay_ms(WAIT_FOR_MORE_THAN_2ms);
 	LCD_enuSendCmnd(ENTRY_MOOD_SET_4_BIT);
 	return STD_OK;
 	#endif*/
 	 //	return STD_OK;

 // }
 ERROR LCD_enuInit(void)
 {

	 DIO_enuSetPinDirection(LCD_u8_RS_PORT, LCD_u8_RS_PIN, DIO_u8OUTPUT);
	 DIO_enuSetPinDirection(LCD_u8_RW_PORT, LCD_u8_RW_PIN, DIO_u8OUTPUT);
	 DIO_enuSetPinDirection(LCD_u8_E_PORT, LCD_u8_E_PIN, DIO_u8OUTPUT);
	 DIO_enuSetPortDirection(LCD_u8_DATA_PORT,DIO_u8OUTPUT);
	 DIO_enuSetPortValue (LCD_u8_DATA_PORT ,DIO_u8LOW  ) ;

	 DIO_enuSetPinValue(LCD_u8_RS_PORT,LCD_u8_RS_PIN,DIO_u8LOW);
	 DIO_enuSetPinValue(LCD_u8_RW_PORT,LCD_u8_RW_PIN,DIO_u8LOW);
	 DIO_enuSetPinValue(LCD_u8_E_PORT,LCD_u8_E_PIN,DIO_u8LOW);
	 _delay_ms(35);
	 LCD_enuSendCmnd(FUN_SET);
	 _delay_us(40);
	 LCD_enuSendCmnd(DISPLAY_ON_OFF);
	 _delay_us(40);
	 LCD_enuSendCmnd(DISPLAY_CLEAR);
	 _delay_ms(2);
	 LCD_enuSendCmnd(ENTRY_MOOD_SET);
	 return STD_OK;

 }
/************************************************/

 ERROR LCD_enuSendChar(u8 Copy_u8Char)
{
#if    (LCD_u8_MODE == LCD_u8_MODE_8_BIT)
	/* RS = 1 */
       DIO_enuSetPinValue (LCD_u8_CONTROL_PORT,LCD_u8_RS_PIN,DIO_u8HIGH);

    /* RW = 0 */
      DIO_enuSetPinValue (LCD_u8_CONTROL_PORT,LCD_u8_RW_PIN,DIO_u8LOW);

    /* Write char */
      DIO_enuSetPortValue(LCD_u8_DATA_PORT,Copy_u8Char);

    /* E = 1 */
      DIO_enuSetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_E_PIN,DIO_u8HIGH);
      _delay_us(1);

    /* E = 0 */
      DIO_enuSetPinValue (LCD_u8_CONTROL_PORT,LCD_u8_E_PIN,DIO_u8LOW);

    return STD_OK;

#elif  (LCD_u8_MODE == LCD_u8_MODE_4_BIT)
	/* RS = 1 */
       DIO_enuSetPinValue (LCD_u8_CONTROL_PORT,LCD_u8_RS_PIN,DIO_u8HIGH);

    /* RW = 0 */
      DIO_enuSetPinValue (LCD_u8_CONTROL_PORT,LCD_u8_RW_PIN,DIO_u8LOW);
   
    /* Write char */
      DIO_enuSetPortValue(LCD_u8_DATA_PORT,Copy_u8Char);

    /* E = 1 */
      DIO_enuSetPortValue(LCD_u8_CONTROL_PORT,LCD_u8_E_PIN,DIO_u8HIGH);
      _delay_us(1);

    /* E = 0 */
      DIO_enuSetPinValue (LCD_u8_CONTROL_PORT,LCD_u8_E_PIN,DIO_u8LOW);
     /*Write Command*/
      DIO_enuSetPortValue(LCD_u8_DATA_PORT,Copy_u8Char<<4);

     /* E = 1 */
      DIO_enuSetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_E_PIN,DIO_u8HIGH);
      _delay_us(1);

       /* E = 0 */
       DIO_enuSetPinValue (LCD_u8_CONTROL_PORT,LCD_u8_E_PIN,DIO_u8LOW);


    return STD_OK;


#endif
    return STD_OK;

}
/***************************************************/
 ERROR LCD_enuSetAc(u8 Copy_u8LineNum,u8 Copy_u8Location)
 	 {
	 if(Copy_u8Location<=39){
	     switch (Copy_u8LineNum)
	     {
	     case 1 :LCD_enuSendCmnd(0x80 + Copy_u8Location); break;
	     case 2 :LCD_enuSendCmnd(0xC0 + Copy_u8Location); break;
	     default:return STD_NOTOK;break;
	     }
	     }
	     else{
	         return STD_NOTOK;
	     }
	     return STD_OK;
	 }

/*******************************************************/
 ERROR LCD_enuSendString(u8 * Copy_pu8String)
 {
     for(u8 i ; Copy_pu8String[i] != '\0' ; i++ ){
         LCD_enuSendChar(Copy_pu8String[i]);
     }
     return  STD_OK;
 }
 /*******************************************************/

 ERROR LCD_enuClear(void)
 {
	 LCD_enuSendCmnd(DISPLAY_CLEAR);
	 _delay_ms(1);
	 return  STD_OK;

 }
 
 /**********************************************************/

 ERROR LCD_enuCreateCustomChar(u8 Copy_u8Location, u8 *Copy_pu8CharArray)
 {
     if (Copy_pu8CharArray != NULL && Copy_u8Location < MAX_CHARACTERS)
     {
         LCD_enuSendCmnd(ADDRESS_OF_CGRAM + (Copy_u8Location *MAX_CHARACTERS));
         for (u8 Local_u8_Counter = 0; Local_u8_Counter < MAX_CHARACTERS; Local_u8_Counter++)
         {
             LCD_enuSendChar(Copy_pu8CharArray[Local_u8_Counter]);
         }
        LCD_enuSetAc(LCD_u8_LINE1,0);
         return STD_OK;
     }
     else
         {
         return STD_NOTOK;
         }
 }

 /*****************************************************/
ERROR LCD_enuSendNum(u32 Copy_u32Num)
{
	u8 arr[10], i = 0, j = 0;
	if (Copy_u32Num == 0)
	{
		LCD_enuSendChar('0');
	}
	else
	{
		while (Copy_u32Num)
		{
			arr[i] = Copy_u32Num % 10 + '0';
			Copy_u32Num /= 10;
			i++;
		}
		
		for (j = i; j > 0; j--)
		{
			LCD_enuSendChar(arr[j - 1]);
		}
	}
	return STD_OK ;
}
