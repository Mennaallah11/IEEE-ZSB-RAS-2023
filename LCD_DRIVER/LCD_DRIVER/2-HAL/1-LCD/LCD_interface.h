/*****************************************/
/******* Name : menna allah mohamed ******
/********** Date : 4 / 05 / 2023 ********/
/**************** SWC : LCD **************/
/*************  Version : 1.0 ************/
/*****************************************/

#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H


ERROR LCD_enuInit(void);
ERROR LCD_enuSendCmnd(u8 Copy_u8Cmdn);
ERROR LCD_enuSendChar(u8 Copy_u8Char);
ERROR LCD_enuSetAc(u8 Copy_u8LineNum,u8 Copy_u8Location);
ERROR LCD_enuSendString(u8 * Copy_pu8String);
ERROR LCD_enuSendNum(u32 Copy_u32Num);
 
#endif
