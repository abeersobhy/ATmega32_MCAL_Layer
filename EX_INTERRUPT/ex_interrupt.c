/*
 * ex_interrupt.c
 *
 * Created: 03/09/2022 04:25:46 م
 *  Author: user
 */ 

#include "ex_interrupt.h"
void EX_INT0_init()
{
	SREG |= (1 << I); /*Enable global interrupt.*/
	MCUCR |= (1 << ISC00) | (1 << ISC01); /*Interrupt with rising edge.*/
	GICR |= (1 << INT0); /*External interrupt enabled.*/
}
void EX_INT1_init()
{
	SREG |= (1 << I); /*Enable global interrupt.*/
	MCUCR |= (1 << ISC10) | (1 << ISC11); /*Interrupt with rising edge.*/
	GICR |= (1 << INT1); /*External interrupt enabled.*/	
}
void EX_INT2_init()
{
	SREG |= (1 << I); /*Enable global interrupt.*/
	MCUCSR |= (1 <<  ISC2); /*Interrupt with rising edge.*/
	GICR |= (1 << INT2); /*External interrupt enabled.*/
}