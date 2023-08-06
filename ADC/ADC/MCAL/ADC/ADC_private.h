/*****************************************/
/******* Name : menna allah mohamed ******
/********** Date : 02 / 08 / 2023 ********/
/**************** SWC : ADC **************/
/*************  Version : 1.0 ************/
/*****************************************/

#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

/* ADCSRA */

#define ADEN                              7
#define ADSC                              6
#define ADATE                             5
#define ADIF                              4
#define ADIE                              3
#define ADPS2                             2
#define ADPS1                             1
#define ADPS0                             0


/* ADMUX */
#define REFS1                             7
#define REFS0                             6
#define ADLAR                             5

/*SFIOR*/
#define ADTS2                             7
#define ADTS1                             6
#define ADTS0                             5



#define AVCC                              1
#define AREF                              0
#define INTERNAL_VOLTAGE_REF              3

#define RIGHT_ADJUST                      0
#define LEFT_ADJUST                       1

#define START_CONVERSION                  1
#define FREE_RUNNING_MODE                 0
#define EXTERNAL_INTERRUPT                2


#define MAX_NUM_OF_CHANNELS               32
#define CLEAR_MUX_BITS                    0b11100000


#define zero                              0


#define DIV_BY_2                          0
#define DIV_BY_4                          1
#define DIV_BY_8                          2
#define DIV_BY_16                         3
#define DIV_BY_32                         4
#define DIV_BY_64                         5
#define DIV_BY_128                        6


void __vector_16(void)  __attribute__((signal));





#endif

