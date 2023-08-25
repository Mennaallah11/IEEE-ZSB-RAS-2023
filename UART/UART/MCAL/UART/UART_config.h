/*****************************************/
/******* Name : menna allah mohamed ******/
/********** Date : 24 / 08 / 2023 ********/
/**************** SWC :  UART **************/
/*************  Version : 1.0 ************/
/*****************************************/

#ifndef     UART_congh_H
#define     UART_congh_H

/*Options For Mode :1-NORMAL_MODE 
                    2-DOUBLE_SPEED
                    */
#define UART_MODE   NORMAL_MODE  
/*Options For Data Bits :1- _5_BITS
                         2- _6_BITS
                         3- _7_BITS
                         4- _8_BITS
                         5- _9_BITS */
#define DATA_BIT   _8_BITS

/*/* Select OPERATION_MODE :1-Asynchronous
                            2-Synchronous */


#define OPERATION_MODE		Asynchronous

/* Select PARITY_MODE :1-Disabled					
                       2-Even								
                       3-odd	*/

#define PARITY_MODE		  Disabled		

/* Select Stop_Bit :1-one_Bit
                    2-Two_Bits*/
														
#define Stop_Bit     Two_Bits			
								


#endif

