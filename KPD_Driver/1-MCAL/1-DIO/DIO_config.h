/*****************************************/
/******* Name : menna allah mohamed ******/
/********** Date : 29 / 04 / 2023 ********/
/**************** SWC : DIO **************/
/*************  Version : 1.0 ************/
/*****************************************/
#ifndef DIO_CONFIG_H
#define DIO_CONFIG_H

/*Initial Directions For All Pins*/
/*Options: DIO_U8_INITIAL_OUTPUT
           DIO_U8_INITIAL_INPUT*/


/*PORTA*/
#define DIO_u8_PA0_INTIAL_DIRECTION     DIO_u8_INITIAL_OUTPUT
#define DIO_u8_PA1_INTIAL_DIRECTION     DIO_u8_INITIAL_OUTPUT
#define DIO_u8_PA2_INTIAL_DIRECTION     DIO_u8_INITIAL_OUTPUT
#define DIO_u8_PA3_INTIAL_DIRECTION     DIO_U8_INITIAL_OUTPUT
#define DIO_u8_PA4_INTIAL_DIRECTION     DIO_u8_INITIAL_INPUT
#define DIO_u8_PA5_INTIAL_DIRECTION     DIO_u8_INITIAL_INPUT
#define DIO_u8_PA6_INTIAL_DIRECTION     DIO_u8_INITIAL_INPUT
#define DIO_u8_PA7_INTIAL_DIRECTION     DIO_u8_INITIAL_INPUT

/*PORTB*/
#define DIO_u8_PB0_INTIAL_DIRECTION     DIO_U8_INITIAL_OUTPUT
#define DIO_u8_PB1_INTIAL_DIRECTION     DIO_U8_INITIAL_OUTPUT
#define DIO_u8_PB2_INTIAL_DIRECTION     DIO_U8_INITIAL_OUTPUT
#define DIO_u8_PB3_INTIAL_DIRECTION     DIO_u8_INITIAL_INPUT
#define DIO_u8_PB4_INTIAL_DIRECTION     DIO_u8_INITIAL_INPUT
#define DIO_u8_PB5_INTIAL_DIRECTION     DIO_u8_INITIAL_INPUT
#define DIO_u8_PB6_INTIAL_DIRECTION     DIO_u8_INITIAL_INPUT
#define DIO_u8_PB7_INTIAL_DIRECTION     DIO_u8_INITIAL_INPUT

/*PORTC*/
#define DIO_u8_PC0_INTIAL_DIRECTION     DIO_u8_INITIAL_INPUT
#define DIO_u8_PC1_INTIAL_DIRECTION     DIO_u8_INITIAL_INPUT
#define DIO_u8_PC2_INTIAL_DIRECTION     DIO_u8_INITIAL_INPUT
#define DIO_u8_PC3_INTIAL_DIRECTION     DIO_u8_INITIAL_INPUT
#define DIO_u8_PC4_INTIAL_DIRECTION     DIO_u8_INITIAL_INPUT
#define DIO_u8_PC5_INTIAL_DIRECTION     DIO_u8_INITIAL_INPUT
#define DIO_u8_PC6_INTIAL_DIRECTION     DIO_u8_INITIAL_INPUT
#define DIO_u8_PC7_INTIAL_DIRECTION     DIO_u8_INITIAL_INPUT

/*PORTD*/
#define DIO_u8_PD0_INTIAL_DIRECTION    DIO_u8_INITIAL_OUTPUT
#define DIO_u8_PD1_INTIAL_DIRECTION    DIO_u8_INITIAL_OUTPUT
#define DIO_u8_PD2_INTIAL_DIRECTION    DIO_u8_INITIAL_OUTPUT
#define DIO_u8_PD3_INTIAL_DIRECTION    DIO_u8_INITIAL_OUTPUT
#define DIO_u8_PD4_INTIAL_DIRECTION    DIO_u8_INITIAL_OUTPUT
#define DIO_u8_PD5_INTIAL_DIRECTION    DIO_u8_INITIAL_OUTPUT
#define DIO_u8_PD6_INTIAL_DIRECTION    DIO_u8_INITIAL_OUTPUT
#define DIO_u8_PD7_INTIAL_DIRECTION    DIO_u8_INITIAL_OUTPUT

/*Initial Values For All Pins*/
/*Options: DIO_U8_OUTPUT_HIGH
           DIO_U8_OUTPIT_LOW
           DIO_U8_INPUT_FLOATING
           DIO_U8_INPUT_PULLUP*/

/*PORTA*/
#define DIO_u8_PA0_INTIAL_VALUE     DIO_u8_OUTPUT_HIGH
#define DIO_u8_PA1_INTIAL_VALUE     DIO_u8_OUTPUT_HIGH
#define DIO_u8_PA2_INTIAL_VALUE     DIO_u8_OUTPUT_HIGH
#define DIO_u8_PA3_INTIAL_VALUE     DIO_u8_OUTPUT_HIGH
#define DIO_u8_PA4_INTIAL_VALUE     DIO_u8_INPUT_PULLUP
#define DIO_u8_PA5_INTIAL_VALUE     DIO_u8_INPUT_PULLUP
#define DIO_u8_PA6_INTIAL_VALUE     DIO_u8_INPUT_PULLUP
#define DIO_u8_PA7_INTIAL_VALUE     DIO_u8_INPUT_PULLUP

/*PORTB*/
#define DIO_u8_PB0_INTIAL_VALUE     DIO_U8_OUTPIT_LOW
#define DIO_u8_PB1_INTIAL_VALUE     DIO_U8_OUTPIT_LOW
#define DIO_u8_PB2_INTIAL_VALUE     DIO_U8_OUTPIT_LOW
#define DIO_u8_PB3_INTIAL_VALUE     DIO_U8_OUTPIT_LOW
#define DIO_u8_PB4_INTIAL_VALUE     DIO_u8_INPUT_FLOATING
#define DIO_u8_PB5_INTIAL_VALUE     DIO_u8_INPUT_FLOATING
#define DIO_u8_PB6_INTIAL_VALUE     DIO_u8_INPUT_FLOATING
#define DIO_u8_PB7_INTIAL_VALUE     DIO_u8_INPUT_FLOATING

/*PORTC*/
#define DIO_u8_PC0_INTIAL_VALUE     DIO_u8_INPUT_FLOATING
#define DIO_u8_PC1_INTIAL_VALUE     DIO_u8_INPUT_FLOATING
#define DIO_u8_PC2_INTIAL_VALUE     DIO_u8_INPUT_FLOATING
#define DIO_u8_PC3_INTIAL_VALUE     DIO_u8_INPUT_FLOATING
#define DIO_u8_PC4_INTIAL_VALUE     DIO_u8_INPUT_FLOATING
#define DIO_u8_PC5_INTIAL_VALUE     DIO_u8_INPUT_FLOATING
#define DIO_u8_PC6_INTIAL_VALUE     DIO_u8_INPUT_FLOATING
#define DIO_u8_PC7_INTIAL_VALUE     DIO_u8_INPUT_FLOATING

/*PORTD*/
#define DIO_u8_PD0_INTIAL_VALUE    DIO_u8_OUTPIT_LOW
#define DIO_u8_PD1_INTIAL_VALUE    DIO_u8_OUTPIT_LOW
#define DIO_u8_PD2_INTIAL_VALUE    DIO_u8_OUTPIT_LOW
#define DIO_u8_PD3_INTIAL_VALUE    DIO_u8_OUTPIT_LOW
#define DIO_u8_PD4_INTIAL_VALUE    DIO_u8_OUTPIT_LOW
#define DIO_u8_PD5_INTIAL_VALUE    DIO_u8_OUTPIT_LOW
#define DIO_u8_PD6_INTIAL_VALUE    DIO_u8_OUTPIT_LOW
#define DIO_u8_PD7_INTIAL_VALUE    DIO_u8_OUTPIT_LOW


#endif