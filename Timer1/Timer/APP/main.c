#include "../Lib/STD_TYPES.h"
#include "../Lib/ES.h"


#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/Timer/Timer_interface.h"
#include "../MCAL/ADC/ADC_interface.h"
#include "../MCAL/AVR_REG.h"
#define F_CPU 8000000UL
#include <util/delay.h>

int main()
{
	u16 digitalValue = 0 ;
	u16 analogValue_led = 0 ;

    ADC_enuInit();
    DIO_enuInit();
	Timers_enuTimer0Init();
	Timers_enuTimer1Init();
 
	while(1)
	{
		ADC_eunGetDigitalValueSynchNonBlocking(ADC_u8_CHANNEL0,&digitalValue);
		analogValue_led = ((digitalValue*256UL) / 1024);
		Timers_enuTimer0SetCompareMatchValue(analogValue_led);
		Timers_enuServoAngle(45);
	}
	
	
	return 0;
}



