/*****************************************/
/******* Name : menna allah mohamed ******
/********** Date : 12 / 08 / 2023 ********/
/**************** SWC : Timer **************/
/*************  Version : 1.0 ************/
/*****************************************/
#ifndef Timer_private_h
#define Timer_private_h

#define NORMAL_MODE          0
#define PWM_OR_PHASE_COTROL  1
#define CTC_MODE             2
#define FAST_PWM_MODE        3

#define INTERRUPT_OVERFLOW   0
#define INTERRUPT_CTC        1

#define No_Clock_source        0
#define CLK_NoPrescling        1
#define CLK_8                  2
#define CLK_64                 3
#define CLK_256                4
#define CLK_1024               5
#define EXTERNAL_FALLING_EDGE  6
#define EXTERNAL_RISING_EDGE   7


#define WGM00                6
#define WGM01                3
#define TOIE0                0
#define OCIE0                1

#define CS00				 0
#define CS01				 1
#define CS02				 2



#endif
