/*****************************************/
/******* Name : menna allah mohamed ******
/********** Date : 12 / 08 / 2023 ********/
/**************** SWC : Timer **************/
/*************  Version : 1.0 ************/
/*****************************************/
/*lib layer*/
#include "../../Lib/STD_TYPES.h"
#include "../../Lib/BIT_Math.h"
/* MCAL */
#include "WDT_config.h"
#include "WDT_private.h"
#include "WDT_interface.h"
#include "../AVR_REG.h"
#include <stddef.h>
/**********************************************************************/
ERROR WDT_enuEnable(void)
{
	/*Enable WDT 2.1s*/
	SET_BIT(WDTCR,WDTP0);
	SET_BIT(WDTCR,WDTP1);
	SET_BIT(WDTCR,WDTP2);
	
	/*Enable WDT*/
	SET_BIT(WDTCR,WDT_Enable_Pin);
	
}
/***********************************************************************/
ERROR WDT_enuDisable(void)
{
	WDTCR = ((one<<WDT_Disable_Pin)|(one<<WDT_Enable_Pin));
	WDTCR = zero ;
	
}