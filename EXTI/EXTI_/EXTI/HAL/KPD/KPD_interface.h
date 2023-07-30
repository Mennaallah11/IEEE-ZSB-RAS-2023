/*****************************************/
/******* Name : menna allah mohamed ******/
/********** Date : 08 / 07 / 2023 ********/
/**************** SWC : KPD**************/
/*************  Version : 1.0 ************/
/*****************************************/




#ifndef KPD_INTERFACE_H
#define KPD_INTERFACE_H

#define KPD_u8_KEY_NOT_PRESSED   0xff

ERROR KPD_enuInit(void) ;
ERROR KPD_enuGetKeyState(u8 *copy_pu8ReturnedKey);




#endif
