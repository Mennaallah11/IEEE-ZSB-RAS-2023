/*****************************************/
/******* Name : menna allah mohamed ******/
/********** Date : 29 / 04 / 2023 ********/
/**************** SWC :  Dc Motor **************/
/*************  Version : 1.0 ************/
/*****************************************/

#ifndef DcMotor_INTERFACE_H
#define DcMotor_INTERFACE_H

#define ACW  0
#define CW   1  

ERROR DcMotor_voidInit (void);
ERROR DcMotor_enuStart(u8 DcMoroe_u8Direction);
ERROR  DcMotor_enuStop(void);



#endif