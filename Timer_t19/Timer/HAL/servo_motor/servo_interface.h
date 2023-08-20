/*****************************************/
/******* Name : menna allah mohamed ******
/********** Date : 17 / 08 / 2023 ********/
/**************** SWC : servo motor **************/
/*************  Version : 1.0 ************/
/*****************************************/
#ifndef servo_interface_h
#define servo_interface_h

#include "../../Lib/STD_TYPES.h"
#include "../../Lib/ES.h"


ERROR servo_enuInit(void);

ERROR servo_enuServoAngle(u8 servoAngle);
#endif