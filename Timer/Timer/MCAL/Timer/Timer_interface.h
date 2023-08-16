/*****************************************/
/******* Name : menna allah mohamed ******
/********** Date : 12 / 08 / 2023 ********/
/**************** SWC : Timer **************/
/*************  Version : 1.0 ************/
/*****************************************/
#ifndef Timer_interface_h
#define Timer_interface_h

#include "../../Lib/STD_TYPES.h"
#include "../../Lib/ES.h"

ERROR Timers_enuTimer0Init(void);
ERROR Timers_enuTimer0OVFSetCallBack(void(*Copy_pf)(void));
ERROR Timers_enuTimer0CTCSetCallBack(void(*Copy_pf)(void));

#endif