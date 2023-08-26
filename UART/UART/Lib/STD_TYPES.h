#ifndef STD_TYPES_H
#define STD_TYPES_H

typedef unsigned char       u8;
typedef unsigned short int  u16;
typedef unsigned long int   u32;


typedef signed char         s8;
typedef signed short int    s16;
typedef signed long int     s32;


typedef float               f32;
typedef double              f64;

#define STD_TYPES_OK	    1
#define STD_TYPES_NOK	    0

#define DIO_u8_LOW  	    0
#define DIO_u8_HIGH 	    1

#define DIO_u8PortLow	    0x00
#define DIO_u8PortHigh	    0xff

#define NULL 			((void *)0)
#endif