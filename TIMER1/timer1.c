/*
 * timer1.c
 *
 * Created: 04/09/2022 04:10:03 م
 *  Author: user
 */ 
#include "timer1.h"
void PWM_OC1A_FM_init()
{
	DIO_init(PORT_D , PIN5 , OUTPUT); /*OCR0 AS OUTPUT.*/
	TCCR1A |= (1 << COM1A1) | (1 << WGM10) | (1 << WGM11);/*Non inverting mood (HIGH IS FIRST).*/
	TCCR1B |= (1 << WGM12) | (1 << CS10);/*start timer1 with no prescelar - 8 bit FAST MODE (1023 for overflow).*/
}
void PWM_OC1A_FM_setDuty(uint8_t dutyCycle)
{
	OCR1AL = dutyCycle*10.23;
	OCR1AH |= (((uint16_t)(dutyCycle*10.23)) >> 8);
}
void PWM_OC1A_phaseCorrect_init()
{
	DIO_init(PORT_D , PIN5 , OUTPUT); /*OCR0 AS OUTPUT.*/
	TCCR1A |= (1 << COM1A1) | (1 << WGM10) | (1 << WGM11);/*Non inverting mood (HIGH IS FIRST).*/
	TCCR1B |= (1 << CS10);/*start timer1 with no prescelar - 10 bit phase correct (1204 for overflow).*/
}
void PWM_OC1A_phaseCorrect_setDuty(uint8_t dutyCycle)
{
	OCR1AL = dutyCycle*10.23;
	OCR1AH |= (((uint16_t)(dutyCycle*10.23)) >> 8);
}