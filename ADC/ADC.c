/*
 * ADC.c
 *
 * Created: 04/09/2022 08:57:42 م
 *  Author: user
 */ 
#include "ADC.h"
void ADC_init()
{
	/*ADC0 with AVCC - free running mode.*/
	ADMUX |= (1 << REFS0); /*AVCC Mode.*/
	ADCSRA |= (1 << ADEN) | (1 << ADPS0) | (1 << ADPS1) | (1 << ADPS2); /*Enable ADC - prescaler 128 - Auto trigger Enable.*/	
}
uint16_t ADC_read(uint8_t channel)
{
	uint16_t ADC = 0;
	ADMUX = channel | (1 << REFS0); /*Select channel.*/ 
	ADCSRA = (1 << ADSC); /*Start conversion.*/
	while(READ_BIT(ADCSRA , ADIF) == 0); /*Conversion continue.*/
	ADC = ADCH; /*Add the last two bits.*/
	ADC <<= 8; /*shift to left*/
	ADC |= ADCL;  /*add the first eight bit.*/
//	ADCSRA |= (1 << ADIF);
	return ADC;
}