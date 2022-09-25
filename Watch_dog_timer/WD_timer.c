/*
 * WD.c
 *
 * Created: 04/09/2022 11:48:53 م
 *  Author: user
 */ 
#include "WD_timer.h"
void WD_on()
{
	WDTCR |= (1 << WDE) | (1 << WDP2) | (1 << WDP1); /*Watchdog timer enable for 1 second.*/	
}
void WD_off()
{
	WDTCR |= (1 << WDTOE) | (1 << WDE); /*Turn off watchdog timer and disable it.*/
	WDTCR = 0;
}