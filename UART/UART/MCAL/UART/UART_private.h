/*****************************************/
/******* Name : menna allah mohamed ******/
/********** Date : 24 / 08 / 2023 ********/
/**************** SWC :  UART **************/
/*************  Version : 1.0 ************/
/*****************************************/

#ifndef     UART_private_H
#define     UART_private_H

#define MPCM        0
#define U2X         1
#define TXEN		3
#define RXEN		4

#define UCSZ2       2
#define UCSZ1       2
#define UCSZ0       1
#define RXB8        1
#define TXB8        0

#define UMSEL       6

#define UPM0        4
#define UPM1        5

#define USBS        3

#define UDRE        5
#define RXC         7


#define NORMAL_MODE             0
#define DOUBLE_SPEED            1

#define _5_BITS                 0
#define _6_BITS                 1
#define _7_BITS                 2
#define _8_BITS                 3
#define _9_BITS                 4

#define Asynchronous            0
#define Synchronous             1

#define Disabled                0
#define Even                    1
#define odd                     2

#define one_Bit                 0
#define Two_Bits                1

#define UCSRC_VALUE            0b10000000
#define UBRR_VALUE              103
#define Eight                   8
#define zero                    0

 
#endif

