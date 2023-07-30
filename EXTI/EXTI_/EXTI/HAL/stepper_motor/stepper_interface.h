/*****************************************/
/******* Name : menna allah mohamed ******/
/********** Date : 23 / 07 / 2023 ********/
/**************** SWC : stepper motor **************/
/*************  Version : 1.0 ************/
/*****************************************/

#ifndef STEPPER_INTERFACE_H
#define STEPPER_INTERFACE_H

ERROR stepper_enuFullStep(u8 stepper_u8Direction , f32 stepper_f32Angle);
ERROR stepper_enuHalfStep(u8 stepper_u8Direction , f32 stepper_f32Angle);
ERROR stepper_enuInit(void);


#endif