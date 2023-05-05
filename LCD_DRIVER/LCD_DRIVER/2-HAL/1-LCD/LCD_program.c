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
}
/************************************************/

 ERROR LCD_enuInit(void)
 {
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

}
/***************************************************/
 ERROR LCD_enuSetAc(u8 Copy_u8LineNum,u8 Copy_u8Location)
 	 {
	 if(Copy_u8Location<=39){
	     switch (Copy_u8LineNum)
	     {
	     case 1:LCD_enuSendCmnd(0x80 + Copy_u8Location); break;
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

