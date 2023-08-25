/*****************************************/
/******* Name : menna allah mohamed ******/
/********** Date : 24 / 08 / 2023 ********/
/**************** SWC :  UART **************/
/*************  Version : 1.0 ************/
/*****************************************/

#ifndef     UART_interface_H
#define     UART_interface_H

#include "../../Lib/STD_TYPES.h"
#include "../../Lib/ES.h"

ERROR UART_enuInit(void);
ERROR UART_enuSendDataByte(u8 dataByte );
ERROR UART_enuResiveDataByte(u8 *copy_pu8recive );
ERROR UART_enuSendString(u8 *Copy_pu8String);


#endif
