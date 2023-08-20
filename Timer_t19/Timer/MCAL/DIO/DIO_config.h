/*****************************************/
/******* Name : menna allah mohamed ******/
/********** Date : 29 / 04 / 2023 ********/
/**************** SWC : DIO **************/
/*************  Version : 1.0 ************/
/*****************************************/


/*Initial Directions For All Pins*/
/*Options: DIO_U8_INITIAL_OUTPUT
           DIO_U8_INITIAL_INPUT*/


#ifndef DIO_CONFIG_H_
#define DIO_CONFIG_H_
/*				Directions are DIO_u8OUTPUT or DIO_u8INPUT		*/
#define DIO_u8PA0_DIR  	   DIO_u8INPUT
#define DIO_u8PA1_DIR	   DIO_u8OUTPUT
#define DIO_u8PA2_DIR	   DIO_u8OUTPUT
#define DIO_u8PA3_DIR	   DIO_u8OUTPUT
#define DIO_u8PA4_DIR	   DIO_u8OUTPUT
#define DIO_u8PA5_DIR	   DIO_u8OUTPUT
#define DIO_u8PA6_DIR      DIO_u8OUTPUT
#define DIO_u8PA7_DIR	   DIO_u8OUTPUT


#define DIO_u8PB0_DIR	DIO_u8OUTPUT
#define DIO_u8PB1_DIR	DIO_u8OUTPUT
#define DIO_u8PB2_DIR	DIO_u8OUTPUT
#define DIO_u8PB3_DIR	DIO_u8OUTPUT
#define DIO_u8PB4_DIR	DIO_u8OUTPUT
#define DIO_u8PB5_DIR	DIO_u8INPUT
#define DIO_u8PB6_DIR	DIO_u8OUTPUT
#define DIO_u8PB7_DIR	DIO_u8INPUT


#define DIO_u8PC0_DIR	DIO_u8OUTPUT
#define DIO_u8PC1_DIR   DIO_u8INPUT
#define DIO_u8PC2_DIR   DIO_u8OUTPUT
#define DIO_u8PC3_DIR   DIO_u8INPUT
#define DIO_u8PC4_DIR   DIO_u8OUTPUT
#define DIO_u8PC5_DIR   DIO_u8INPUT
#define DIO_u8PC6_DIR   DIO_u8INPUT
#define DIO_u8PC7_DIR   DIO_u8OUTPUT


#define DIO_u8PD0_DIR   DIO_u8OUTPUT
#define DIO_u8PD1_DIR   DIO_u8OUTPUT
#define DIO_u8PD2_DIR   DIO_u8OUTPUT
#define DIO_u8PD3_DIR   DIO_u8OUTPUT
#define DIO_u8PD4_DIR   DIO_u8OUTPUT
#define DIO_u8PD5_DIR   DIO_u8OUTPUT
#define DIO_u8PD6_DIR   DIO_u8OUTPUT
#define DIO_u8PD7_DIR   DIO_u8OUTPUT

/*				Values of Pin in output are DIO_u8HIGH or DIO_u8LOW
 * 				Values of Pin in input are DIO_u8PULL_UP or DIO_u8FLOAT	*/
#define DIO_u8PA0_VALUE  DIO_u8FLOAT
#define DIO_u8PA1_VALUE  DIO_u8LOW
#define DIO_u8PA2_VALUE  DIO_u8LOW
#define DIO_u8PA3_VALUE  DIO_u8LOW
#define DIO_u8PA4_VALUE  DIO_u8LOW
#define DIO_u8PA5_VALUE  DIO_u8LOW
#define DIO_u8PA6_VALUE  DIO_u8LOW
#define DIO_u8PA7_VALUE  DIO_u8LOW


#define DIO_u8PB0_VALUE  DIO_u8HIGH
#define DIO_u8PB1_VALUE  DIO_u8LOW
#define DIO_u8PB2_VALUE  DIO_u8LOW
#define DIO_u8PB3_VALUE  DIO_u8LOW
#define DIO_u8PB4_VALUE  DIO_u8HIGH
#define DIO_u8PB5_VALUE  DIO_u8FLOAT
#define DIO_u8PB6_VALUE  DIO_u8HIGH
#define DIO_u8PB7_VALUE  DIO_u8LOW


#define DIO_u8PC0_VALUE  DIO_u8LOW
#define DIO_u8PC1_VALUE  DIO_u8LOW
#define DIO_u8PC2_VALUE  DIO_u8LOW
#define DIO_u8PC3_VALUE  DIO_u8HIGH
#define DIO_u8PC4_VALUE  DIO_u8LOW
#define DIO_u8PC5_VALUE  DIO_u8HIGH
#define DIO_u8PC6_VALUE  DIO_u8HIGH
#define DIO_u8PC7_VALUE  DIO_u8LOW


#define DIO_u8PD0_VALUE  DIO_u8LOW
#define DIO_u8PD1_VALUE  DIO_u8LOW
#define DIO_u8PD2_VALUE  DIO_u8LOW
#define DIO_u8PD3_VALUE  DIO_u8LOW
#define DIO_u8PD4_VALUE  DIO_u8LOW
#define DIO_u8PD5_VALUE  DIO_u8LOW
#define DIO_u8PD6_VALUE  DIO_u8LOW
#define DIO_u8PD7_VALUE  DIO_u8LOW



#endif /* DIO_CONFIG_H_ */