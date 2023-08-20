/*****************************************/
/******* Name : menna allah mohamed ******/
/********** Date : 29 / 04 / 2023 ********/
/**************** SWC : DIO **************/
/*************  Version : 1.0 ************/
/*****************************************/




#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_

/*Options For Referance Voltage : 1-AREF                     
                                  2-AVCC
                                  3-INTERNAL_VOLTAGE_REF
*/
 #define ADC_VREF             AVCC

/*Options For ADC Coversion Mode :  1-START_CONVERSION 
                                    2-FREE_RUNNING_MODE
                                    3-EXTERNAL_INTERRUPT
*/
#define ADC_CONVERSION_MODE   START_CONVERSION 

/*Options For ADC Presentation Mode :1-RIGHT_ADJUST
                                     2-LEFT_ADJUST
*/
#define ADC_ADJUST            RIGHT_ADJUST
/*Options For ADC Clock(Division Factor) :1-DIV_BY_2
                                          2-DIV_BY_4
                                          3-DIV_BY_8
                                          4-DIV_BY_16
                                          5-DIV_BY_32
                                          6-DIV_BY_64
                                          7-DIV_BY_128
*/
                                   
#define DEVISION_FACTOR                   DIV_BY_64
#define ADC_u32_TIME_OUT_MAX_VALUE        50000
                      

#endif