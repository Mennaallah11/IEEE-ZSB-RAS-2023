/*****************************************/
/******* Name : menna allah mohamed ******
/********** Date : 12 / 08 / 2023 ********/
/**************** SWC : WDT **************/
/*************  Version : 1.0 ************/
/*****************************************/
#ifndef Timer_interface_h
#define Timer_interface_h

#include "../../Lib/STD_TYPES.h"
#include "../../Lib/ES.h"

ERROR Timers_enuTimer0Init(void);
ERROR Timers_enuTimer1Init(void);
ERROR Timers_enuTimer0OVFSetCallBack(void(*Copy_pf)(void));
ERROR Timers_enuTimer0CTCSetCallBack(void(*Copy_pf)(void));
ERROR Timers_enuTimer0SetCompareMatchValue(u8 Copy_u8OCR0Value);
ERROR Timers_enuTimer1SetTimerValue(u8 Copy_u8Value);
ERROR Timers_enuTimer1ReadTimerValue(void);
ERROR Timers_enudelayms(u32 milliseconds);
#endif