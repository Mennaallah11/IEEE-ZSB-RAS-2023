/*****************************************/
/******* Name : menna allah mohamed ******/
/********** Date : 4 / 05 / 2023 ********/
/**************** SWC : LCD **************/
/*************  Version : 1.0 ************/
/*****************************************/

/*Lib Layer*/
#include "../../5-LIBRARIES/STD_TYPES.h"
#include "../../5-LIBRARIES/ES.h"

/*MCAL*/
#include "../../1-MCAL/1-DIO/DIO_interface.h"
/*HAL*/
#include "LCD_private.h"
#include "LCD_config.h"
#include "LCD_interface.h"

#define F_CPU 8000000UL
#include<util/delay.h>

/************************************************/
 ERROR LCD_enuSendCmnd(u8 Copy_u8Cmdn)
{
#if    (LCD_u8_MODE == LCD_u8_MODE_8_BIT)
	/* RS = 0 */
	DIO_u8SetPinValue (LCD_u8_CONTROL_PORT,LCD_u8_RS_PIN,DIO_u8_LOW);

	/* RW = 0 */
    DIO_u8SetPinValue (LCD_u8_CONTROL_PORT,LCD_u8_RW_PIN,DIO_u8_LOW);
   
    /*Write Command*/
    DIO_u8SetPortValue(LCD_u8_DATA_PORT,Copy_u8Cmdn);

    /* E = 1 */
    DIO_u8SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_E_PIN,DIO_u8_HIGH);
    _delay_us(1);

    /* E = 0 */
    DIO_u8SetPinValue (LCD_u8_CONTROL_PORT,LCD_u8_E_PIN,DIO_u8_LOW);

    return STD_OK;
#elif   (LCD_u8_MODE == LCD_u8_MODE_4_BIT)
    /* code to send a command at 4 bit mode */
	/* RS = 0 */
	DIO_u8SetPinValue (LCD_u8_CONTROL_PORT,LCD_u8_RS_PIN,DIO_u8_LOW);

	/* RW = 0 */
    DIO_u8SetPinValue (LCD_u8_CONTROL_PORT,LCD_u8_RW_PIN,DIO_u8_LOW);

    /*Write Command*/
    DIO_u8SetPortValue(LCD_u8_DATA_PORT,Copy_u8Cmdn);

    /* E = 1 */
    DIO_u8SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_E_PIN,DIO_u8_HIGH);
    _delay_us(1);

    /* E = 0 */
    DIO_u8SetPinValue (LCD_u8_CONTROL_PORT,LCD_u8_E_PIN,DIO_u8_LOW);

    /*Write Command*/
    DIO_u8SetPortValue(LCD_u8_DATA_PORT,Copy_u8Cmdn<<4);

    /* E = 1 */
    DIO_u8SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_E_PIN,DIO_u8_HIGH);
    _delay_us(1);

    /* E = 0 */
    DIO_u8SetPinValue (LCD_u8_CONTROL_PORT,LCD_u8_E_PIN,DIO_u8_LOW);

    return STD_OK;

#endif
    return STD_OK;

}
/************************************************/

 ERROR LCD_enuInit(void)
 {
#if  (LCD_u8_MODE == LCD_u8_MODE_8_BIT)
 	_delay_ms(35);
 	LCD_enuSendCmnd(FUN_SET_8_BIT );
 	_delay_us(40);
 	LCD_enuSendCmnd(DISPLAY_ON_OFF_8_BIT);
 	_delay_us(40);
 	LCD_enuSendCmnd(DISPLAY_CLEAR_8_BIT);
 	_delay_ms(2);
 	LCD_enuSendCmnd(ENTRY_MOOD_SET_8_BIT);
 	return STD_OK;

#elif  (LCD_u8_MODE == LCD_u8_MODE_4_BIT)
 	_delay_ms(30);
 	LCD_enuSendCmnd(FUN_SET_4_BIT);
 	_delay_us(40);
 	LCD_enuSendCmnd(DISPLAY_ON_OFF_4_BIT);
 	_delay_us(40);
 	LCD_enuSendCmnd(DISPLAY_CLEAR_4_BIT);
 	_delay_ms(2);
 	LCD_enuSendCmnd(ENTRY_MOOD_SET_4_BIT);
 	return STD_OK;
 	#endif
 	 	return STD_OK;

  }
/************************************************/

 ERROR LCD_enuSendChar(u8 Copy_u8Char)
{
#if    (LCD_u8_MODE == LCD_u8_MODE_8_BIT)
	/* RS = 1 */
       DIO_u8SetPinValue (LCD_u8_CONTROL_PORT,LCD_u8_RS_PIN,DIO_u8_HIGH);

    /* RW = 0 */
      DIO_u8SetPinValue (LCD_u8_CONTROL_PORT,LCD_u8_RW_PIN,DIO_u8_LOW);

    /* Write char */
      DIO_u8SetPortValue(LCD_u8_DATA_PORT,Copy_u8Char);

    /* E = 1 */
      DIO_u8SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_E_PIN,DIO_u8_HIGH);
      _delay_us(1);

    /* E = 0 */
      DIO_u8SetPinValue (LCD_u8_CONTROL_PORT,LCD_u8_E_PIN,DIO_u8_LOW);

    return STD_OK;

#elif  (LCD_u8_MODE == LCD_u8_MODE_4_BIT)
	/* RS = 1 */
       DIO_u8SetPinValue (LCD_u8_CONTROL_PORT,LCD_u8_RS_PIN,DIO_u8_HIGH);

    /* RW = 0 */
      DIO_u8SetPinValue (LCD_u8_CONTROL_PORT,LCD_u8_RW_PIN,DIO_u8_LOW);
   
    /* Write char */
      DIO_u8SetPortValue(LCD_u8_DATA_PORT,Copy_u8Char);

    /* E = 1 */
      DIO_u8SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_E_PIN,DIO_u8_HIGH);
      _delay_us(1);

    /* E = 0 */
      DIO_u8SetPinValue (LCD_u8_CONTROL_PORT,LCD_u8_E_PIN,DIO_u8_LOW);
     /*Write Command*/
      DIO_u8SetPortValue(LCD_u8_DATA_PORT,Copy_u8Char<<4);

     /* E = 1 */
      DIO_u8SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_E_PIN,DIO_u8_HIGH);
      _delay_us(1);

       /* E = 0 */
       DIO_u8SetPinValue (LCD_u8_CONTROL_PORT,LCD_u8_E_PIN,DIO_u8_LOW);


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
 /*ERROR  LCD_enu_SendNum(u32 Copy_u32Num)*/
 ERROR LCD_enuClear(void){
	 LCD_enuSendCmnd(0x01);
	 return  STD_OK;

 }

 ERROR LCD_enuCreateCustomChar(u8 Copy_u8Location, u8 *Copy_pu8CharArray)
 {
     if (Copy_pu8CharArray != NULL && Copy_u8Location < 8)
     {
         LCD_enuSendCmnd(0X40 + (Copy_u8Location *8));
         for (u8 i = 0; i < 8; i++)
         {
             LCD_enuSendChar(Copy_pu8CharArray[i]);
         }
        // LCD_enuSetAc(1,0);
         return STD_OK;
     }
     else
         {
         return STD_NOTOK;
         }
 }

 /*****************************************************/
 ERROR LCD_enuSendCharPos(u8 c, u8 row, u8 column)
 {
     LCD_enuSetAc(row, column);
     LCD_enuSendChar(c);
 }

