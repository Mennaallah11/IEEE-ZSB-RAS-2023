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

#define FAST_PWM_INVERTING      0
#define FAST_PWM_NON_INVERTING  1

#define PHASE_CORRECT_PWM_INVERTING      0
#define PHASE_CORRECT_PWM_NON_INVERTING  1

#define No_Clock_source        0
#define CLK_NoPrescling        1
#define CLK_8                  2
#define CLK_64                 3
#define CLK_256                4
#define CLK_1024               5
#define EXTERNAL_FALLING_EDGE  6
#define EXTERNAL_RISING_EDGE   7

/*timer0*/
#define WGM00                6
#define COM01                5
#define COM00                4
#define WGM01                3
#define OCIE0                1
#define TOIE0                0

#define CS00				 0
#define CS01				 1
#define CS02				 2
/*timer1*/
#define WGM10                0
#define WGM11                1
#define WGM12                3
#define WGM13                4
#define COM1A0               6
#define COM1A1               7

#define max_angle            180



#endif
