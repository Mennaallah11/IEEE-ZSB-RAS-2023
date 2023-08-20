/*****************************************/
/******* Name : menna allah mohamed ******/
/********** Date : 4 / 05 / 2023 ********/
/**************** SWC : LCD **************/
/*************  Version : 1.0 ************/
/*****************************************/

#ifndef LCD_CONFIG_H
#define LCD_CONFIG_H


/*Options for Ports: 1- DIO_u8_PORTA
2-DIO_u8_PORTB
3-DIO_u8_PORTC
4-DIO_u8_PORTD */

            
/*Options For Pins:  1- DIO_u8_PIN0
2-DIO_u8_PIN
3-DIO_u8_PIN2
4-DIO_u8_PIN3
5-DIO_u8_PIN4
6-DIO_u8_PIN5    
7-DIO_u8_PIN6
8-DIO_u8_PIN7*/

#define LCD_u8_LINE1   1
#define LCD_u8_LINE2   2


#define LCD_u8_CONTROL_PORT     DIO_u8PORTA    
#define LCD_u8_RS_PORT          DIO_u8PORTA
#define LCD_u8_RW_PORT          DIO_u8PORTA
#define LCD_u8_E_PORT           DIO_u8PORTA

#define LCD_u8_RS_PIN           DIO_u8PIN4
#define LCD_u8_RW_PIN           DIO_u8PIN5
#define LCD_u8_E_PIN            DIO_u8PIN6


#define LCD_u8_DATA_PORT        DIO_u8PORTB

/* option : 1- LCD_u8_MODE_8_BIT
            2- LCD_u8_MODE_4_BIT */
#define LCD_u8_MODE         LCD_u8_MODE_8_BIT

#endif
