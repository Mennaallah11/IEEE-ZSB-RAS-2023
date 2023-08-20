/*****************************************/
/******* Name : menna allah mohamed ******
/********** Date : 28 / 06 / 2023 ********/
/**************** SWC : GI **************/
/*************  Version : 1.0 ************/
/*****************************************/

/*LIBRARIES Layer*/
#include "../../Lib/ib/STD_TYPES.h"
#include "../../Lib/BIT_MATH.h"
#include "../../Lib/ES.h"

/*MCAL*/
#include "GI_private.h"
#include "../AVR_REG.h"



//#include "GI_interface.h"

ERROR  GI_enuGIEnable(void)
{
	SET_BIT(SREG,GI_PIN7);
	return STD_OK;
}

ERROR  GI_enuGIDisable(void)
{
	CLR_BIT(SREG,GI_PIN7);
	return STD_OK;

}

ERROR  GI_enuInit(void)
{
	CLR_BIT(SREG,GI_PIN7);
	return STD_OK;
}


