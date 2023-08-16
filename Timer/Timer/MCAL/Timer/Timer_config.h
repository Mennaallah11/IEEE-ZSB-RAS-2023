/*****************************************/
/******* Name : menna allah mohamed ******
/********** Date : 12 / 08 / 2023 ********/
/**************** SWC : Timer **************/
/*************  Version : 1.0 ************/
/*****************************************/

#ifndef Timer_config_h
#define Timer_config_h
/* Select Mode : 1- NORMAL_MODE
                 2- PWM_OR_PHASE_COTROL
                 3-CTC_MODE
                 4-FAST_PWM_MODE			  	                                                      
*/
#define MODE      CTC_MODE

/* Select Interrupt : 1-INTERRUPT_OVERFLOW
                      2-INTERRUPT_CTC */
#define INTERRUPT   INTERRUPT_CTC

/*	F.CPU = 8MHZ
		Prescaler = 8
		Timer freq. = F.CPU / Prescaler = 1MHZ
		Timer tick time = 1 Micro sec.
		Time of overflow = 2^(resolution) * Tick time = 256 * 1 = 256 Micro sec.
		If desired time = 1 sec
		Number of overflows = Desired time / Time of overflow = 1M / 256 = 3906.25 overflows
		Number of ticks for 0.25 overflow = 025 * 256 = 64 ticks
		Preload_value = 256 - 64 = 192
		So >>> 3907 overflows & preload_value = 192 in the 3907th
*/
#define preload_value  192
#define overflows      3907
#define CTC            10000

/* prescaler : 0-No_Clock_source
              1-CLK_NoPrescling
              2-CLK_8
              3-CLK_64
              4-CLK_256
              5-CLK_1024				
              6- EXTERNAL_FALLING_EDGE
              7- EXTERNAL_RISING_EDGE
*/
#define prescaler  EXTERNAL_RISING_EDGE



#endif
