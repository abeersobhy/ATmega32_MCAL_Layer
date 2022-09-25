/*
 * timer.c
 *
 * Created: 31/08/2022 09:10:46 م
 *  Author: user
 */
#include "timer.h" 
void TIMER0_NM_init(uint8_t OverFlowState , uint16_t prescalerValue)
{
	/*No prescaler - Enable interrupt - frequancy 16MHz.*/
	if(prescalerValue == NO_PRESCALER)
	{
		TCCR0 |= (1 << CS00); // start timer with no prescaler.
	}
	else if(prescalerValue == 8)
	{
		TCCR0 |= (1 << CS01);
	}
	else if(prescalerValue == 64)
	{
		TCCR0 |= (1 << CS00) | (1 << CS01);
	}
	else if(prescalerValue == 256)
	{
		TCCR0 |= (1 << CS02);
	}
	else if(prescalerValue == 1024)
	{
		TCCR0 |= (1 << CS00) | (1 << CS02);
	}
	if(OverFlowState == INTERRUPT) // Enable interrupt
	{
		TIMSK |= (1 << OCIE0); // Enable 
		SREG |= (1 << I); // Enable global interrupt
	}
}
void TIMER0_getState()
{
	static uint16_t count = 0;
	if(READ_BIT(TIFR , PIN0))
	{
		count++;
		SET_BIT(TIFR , PIN0); /*Set the flag bit.*/
	}
	if(count == 62500)
	{
		TOG_BIT(PORTA , PIN0);
	}
}
void TIMER0_CTC_init(uint8_t OCR_value)
{
   /*Prescaler 1024 - Enable interrupt - frequancy 16MHz.*/
   TCCR0 |= (1 << CS00) | (1 << CS02) | (1 << WGM01); // start timer with prescaler 1024 - Choose the CTC Mode.
   OCR0 = OCR_value; // Initial value to OCR0 Register.
   TIMSK |= (1 << OCIE0); // Enable CTC Interrupt.
   SREG |= (1 << I); // Enable global interrupt.
}
uint16_t TIMER0_CTC_state()
{
	static uint16_t count = 0;
	if(READ_BIT(TIFR , PIN1) == 1) /*Dectect overflow.*/
	{
		count++;
		TIFR |= (1 << OCF0); /*Set the flag bit.*/
	}
	return count;
}
void TIMER0_FG_init(uint8_t OCR_value)
{
   /*Prescaler 1024 - frequancy 16MHz - generate frequancy.*/
   DIO_init(PORT_B , PIN3 , OUTPUT); /*OC0 PIN IN MICROCONTROLLER.*/
   TCCR0 |= (1 << CS00) | (1 << WGM01) | (1 << COM00); // start timer with NO prescaler - Choose the CTC Mode - toggle OC0 PIN.
   OCR0 = OCR_value; // Initial value to start.
}
void TIMER0_FPWM_init()
{
	
}
void TIMER0_PWM_PhaseCorrect_init()
{
	
}