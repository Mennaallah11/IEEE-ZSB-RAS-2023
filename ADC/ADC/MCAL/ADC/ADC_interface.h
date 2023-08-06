/*****************************************/
/******* Name : menna allah mohamed ******
/********** Date : 02 / 08 / 2023 ********/
/**************** SWC : ADC **************/
/*************  Version : 1.0 ************/
/*****************************************/

#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H  

#include "../../Lib/STD_TYPES.h"
#include "../../Lib/ES.h"


#define ADC_u8_CHANNEL0                  0
#define ADC_u8_CHANNEL1                  1
#define ADC_u8_CHANNEL2                  2
#define ADC_u8_CHANNEL3                  3
#define ADC_u8_CHANNEL4                  4
#define ADC_u8_CHANNEL5                  5
#define ADC_u8_CHANNEL6                  6
#define ADC_u8_CHANNEL7                  7

ERROR ADC_enuInit(void);
ERROR ADC_eunGetDigitalValueSynchNonBlocking(u8 Copy_u8ChannelNb, u16 * Copy_pu16DigitalValue);
ERROR ADC_enuGetDigitalValueAsynch(u8 Copy_u8ChannelNb,void(*Copy_pfNotification)(u16));


#endif
