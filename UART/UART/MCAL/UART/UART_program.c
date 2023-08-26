/*****************************************/
/******* Name : menna allah mohamed ******/
/********** Date : 24 / 08 / 2023 ********/
/**************** SWC :  UART **************/
/*************  Version : 1.0 ************/
/*****************************************/

/*LIBRARIES Layer*/
#include "../../Lib/STD_TYPES.h"
#include "../../Lib/BIT_MATH.h"
#include "../../Lib/ES.h"

/*MCAL*/
#include "../../MCAL/DIO/DIO_interface.h"
/*HAL*/
#include "UART_private.h"
#include "UART_config.h"
#include "UART_interface.h"

#include "../AVR_REG.h"

ERROR UART_enuInit(void)
{
	 u8 Local_u8UCSRCValue = UCSRC_VALUE;
	 u16 Local_u16BaudRate = UBRR_VALUE;
	 #if UART_MODE == NORMAL_MODE
	 CLR_BIT(UCSRA,U2X);
	 #elif UART_MODE == DOUBLE_SPEED
	 SET_BIT(UCSRA,U2X);
	 #endif
	 
     /* Disable MPCM */
     CLR_BIT(UCSRA, MPCM);
	 
	 /* Enable Tx,Rx */
	 SET_BIT(UCSRB, TXEN);
	 SET_BIT(UCSRB, RXEN);
	 
	 /*Data bit*/
	 #if DATA_BIT == _5_BITS
	 CLR_BIT(UCSRB,UCSZ2);
	 CLR_BIT(Local_u8UCSRCValue,UCSZ1);
	 CLR_BIT(Local_u8UCSRCValue,UCSZ0);
	 #elif DATA_BIT == _6_BITS
	 CLR_BIT(UCSRB,UCSZ2);
	 CLR_BIT(Local_u8UCSRCValue,UCSZ1);
	 SET_BIT(Local_u8UCSRCValue,UCSZ0);
	 #elif DATA_BIT == _7_BITS
	 CLR_BIT(UCSRB,UCSZ2);
	 SET_BIT(Local_u8UCSRCValue,UCSZ1);
	 CLR_BIT(Local_u8UCSRCValue,UCSZ0);
	 #elif DATA_BIT == _8_BITS
	 CLR_BIT(UCSRB,UCSZ2);
	 SET_BIT(Local_u8UCSRCValue,UCSZ1);
	 SET_BIT(Local_u8UCSRCValue,UCSZ0);
	 #elif DATA_BIT == _9_BITS
	 SET_BIT(UCSRB,UCSZ2);
	 SET_BIT(Local_u8UCSRCValue,UCSZ1);
	 SET_BIT(Local_u8UCSRCValue,UCSZ0);
	 SET_BIT(UCSRB,RXB8);
	 SET_BIT(UCSRB,TXB8);
	 #endif
	 
	 #if OPERATION_MODE == Asynchronous
	 CLR_BIT(Local_u8UCSRCValue, UMSEL);
	 #elif OPERATION_MODE == Synchronous
	 SET_BIT(Local_u8UCSRCValue, UMSEL);
	 #endif
	 
	 /* Select PARITY_MODE  */
	 #if PARITY_MODE == Disabled
	 CLR_BIT(Local_u8UCSRCValue, UPM0);
	 CLR_BIT(Local_u8UCSRCValue, UPM1);
	 #elif PARITY_MODE == Even
	 CLR_BIT(Local_u8UCSRCValue, UPM0);
	 SET_BIT(Local_u8UCSRCValue, UPM1);
	 #elif PARITY_MODE == odd
	 SET_BIT(Local_u8UCSRCValue, UPM0);
	 SET_BIT(Local_u8UCSRCValue, UPM1);
	 #endif
	 
	 /*  Stop Bits Mode */
	 #if Stop_Bit == one_Bit
	 CLR_BIT(Local_u8UCSRCValue, USBS);
	 #elif Stop_Bit == Two_Bits
	 SET_BIT(Local_u8UCSRCValue, USBS);
	 #endif
	 
	 /* Update UCSRC Reg Value  */
	 UCSRC = Local_u8UCSRCValue;
	 
	 /* Baud Rate => 9600 */
	 UBRRL = (u8)Local_u16BaudRate;
	 UBRRH = (u8)(Local_u16BaudRate >> Eight);
	 return STD_OK;
}
/***************************************/
ERROR UART_enuSendDataByte(u8 dataByte )
{
	//wait until the transmit reg is empty (UDRE = 0 )

	while(GET_BIT(UCSRA,UDRE)==0);
	
	// sent data IF (UDRE = 1 )
	UDR=dataByte;
	 return STD_OK;

}
/***************************************/
ERROR UART_enuResiveDataByte(u8 *copy_pu8recive )
{
	if(copy_pu8recive!=NULL)
	{ 
		// wait the data is resived finised
		while(GET_BIT(UCSRA,RXC)==zero);
		//read data from register 
		*copy_pu8recive=UDR;
	}
	else {
		return STD_NOTOK;
	}
	
	return STD_OK;
}
/***************************************/
 ERROR UART_enuSendString(u8 * Copy_pu8String)
 {
	 for(u8 i =zero ; Copy_pu8String[i] != '\0' ; i++ )
	 {
		 //wait until the transmit reg is empty (UDRE = 0 )

		 while(GET_BIT(UCSRA,UDRE)==zero);
		 
		 // sent data IF (UDRE = 1 )
		 UDR=Copy_pu8String[i];
	 }
	 return  STD_OK;
 }
/****************************************/
ERROR UART_enuRecieveString(u8 *Copy_pu8RxString)
{
	u8 Local_u8StartChar,Local_u8Endchar ;
	u8 count = 0 ;
	if(Copy_pu8RxString!=NULL)
	{
		// wait the data is resived finised
	while(GET_BIT(UCSRA,RXC)==zero);
	Local_u8StartChar=UDR;
	// Wait for UDRE flag
	while(GET_BIT(UCSRA,UDRE)==zero);
	UDR = Local_u8StartChar ;
	
	while(1)
	{
		while(GET_BIT(UCSRA,RXC)==zero);
		Local_u8Endchar=UDR;
		// Wait for UDRE flag
		while(GET_BIT(UCSRA,UDRE)==zero);
		UDR = Local_u8Endchar ;
		
		if(Local_u8StartChar==Local_u8Endchar)
		{
			Copy_pu8RxString[count++]=zero;
			break;
		}
		else
		{
			Copy_pu8RxString[count++]=Local_u8Endchar;
		}
		count++;
		
	}
	}
	return STD_OK ;
}


