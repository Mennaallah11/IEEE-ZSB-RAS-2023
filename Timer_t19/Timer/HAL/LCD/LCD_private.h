/*****************************************/
/******* Name : menna allah mohamed ******/
/********** Date : 4 / 05 / 2023 ********/
/**************** SWC : LCD **************/
/*************  Version : 1.0 ************/
/*****************************************/

#ifndef LCD_PRIVATE_H
#define LCD_PRIVATE_H

#define FUN_SET_8_BIT         0b00111000
#define DISPLAY_ON_OFF_8_BIT  0b00001111
#define DISPLAY_CLEAR_8_BIT   0b00000001
#define ENTRY_MOOD_SET_8_BIT  0b00000110

#define FUN_SET_4_BIT         0x00100010
#define DISPLAY_ON_OFF_4_BIT  0b00001111
#define DISPLAY_CLEAR_4_BIT   0b00000001
#define ENTRY_MOOD_SET_4_BIT  0b00000110

//#define DISPLAY_CLEAR                0x01
#define Cursor_at_home_position      0x80

#define LCD_u8_MODE_8_BIT  0
#define LCD_u8_MODE_4_BIT  1

#define ADDRESS_OF_CGRAM             0x40
#define MAX_CHARACTERS                8


#define POWER_ON                   30
#define WAIT_FOR_MORE_THAN_40us   40
#define WAIT_FOR_MORE_THAN_2ms     2

#define FUN_SET         0b00111000
#define DISPLAY_ON_OFF  0b00001111
#define DISPLAY_CLEAR   0b00000001
#define ENTRY_MOOD_SET  0b00000110


           
#endif
