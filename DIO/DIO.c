/*
 * DIO.c
 *
 * Created: 28/08/2022 11:24:24 م
 *  Author: user
 */ 
#include "DIO.h"
#include "../EX_INTERRUPT/ex_interrupt.h"
void DIO_init(uint8_t portNumber , uint8_t pinNumber , uint8_t pinDirection)
{
	switch(portNumber)
	{
		case PORT_A :
			if(pinDirection ==	OUTPUT) 
			SET_BIT(DDRA , pinNumber);
			else
			CLR_BIT(DDRA , pinNumber);
		break;
		case PORT_B :
			if(pinDirection == OUTPUT)
			SET_BIT(DDRB , pinNumber);
			else
			CLR_BIT(DDRB , pinNumber);
		break;
		case PORT_C :
			if(pinDirection == OUTPUT)
			SET_BIT(DDRC , pinNumber);
			else
			CLR_BIT(DDRC , pinNumber);
		break;
			case PORT_D :
			if(pinDirection == OUTPUT)
			SET_BIT(DDRD , pinNumber);
			else
			CLR_BIT(DDRD , pinNumber);
		break;  
	}
}
void DIO_write(uint8_t portNumber , uint8_t pinNumber , uint8_t value)
{
	switch(portNumber)
	{
		case PORT_A :
		if(value == HIGH)
		SET_BIT(PORTA , pinNumber);
		else if(value == LOW)
		CLR_BIT(PORTA , pinNumber);
		break;
		case PORT_B :
		if(value == HIGH)
		SET_BIT(PORTB , pinNumber);
		else if(value == LOW)
		CLR_BIT(PORTB , pinNumber);
		break;
		case PORT_C :
		if(value == HIGH)
		SET_BIT(PORTC , pinNumber);
		else if(value == LOW)
		CLR_BIT(PORTC , pinNumber);
		break;
		case PORT_D :
		if(value == HIGH)
		SET_BIT(PORTD , pinNumber);
		else if(value == LOW)
		CLR_BIT(PORTD , pinNumber);
		break;
	}
}
void DIO_toggle(uint8_t portNumber , uint8_t pinNumber)
{
	switch(portNumber)
	{
		case PORT_A :
		TOG_BIT(PORTA , pinNumber);
		break;
		case PORT_B :
		TOG_BIT(PORTB , pinNumber);
		break;
		case PORT_C :
		TOG_BIT(PORTC , pinNumber);
		break;
		case PORT_D :
		TOG_BIT(PORTD , pinNumber);
		break;
	}
}
void DIO_read(uint8_t portNumber , uint8_t pinNumber , uint8_t *value)
{
	switch(portNumber)
	{
		
		case PORT_A :
		*value = READ_BIT(PINA , pinNumber);
		break;
		case PORT_B :
		*value = READ_BIT(PINB , pinNumber);
		break;
		case PORT_C :
		*value = READ_BIT(PINC , pinNumber);
		break;
		case PORT_D :
		*value = READ_BIT(PIND , pinNumber);
		break;
	}
}
ISR(EX_INT_2)
{
	static uint8_t counter = 0;
	counter++;
	DIO_init(PORT_D , PIN2 , INPUT);
	DIO_init(PORT_A , PIN0 , OUTPUT);
	DIO_init(PORT_A , PIN1 , OUTPUT);
	DIO_init(PORT_A , PIN2 , OUTPUT);
	if(counter == 1)
	{
		
		DIO_write(PORT_A , PIN0 , HIGH);
		DIO_write(PORT_A , PIN1 , LOW);
		DIO_write(PORT_A , PIN2 , LOW);
	}
	else if(counter == 2)
	{
		DIO_write(PORT_A , PIN0 , LOW);
		DIO_write(PORT_A , PIN1 , HIGH);
		DIO_write(PORT_A , PIN2 , LOW);
	}
	else if(counter == 3)
	{
		DIO_write(PORT_A , PIN0 , LOW);
		DIO_write(PORT_A , PIN1 , LOW);
		DIO_write(PORT_A , PIN2 , HIGH);
	}
	else if(counter == 4)
	{
		DIO_write(PORT_A , PIN2 , LOW);
	}
	else if(counter == 5)
	{
		DIO_write(PORT_A , PIN0 , HIGH);
		DIO_write(PORT_A , PIN1 , HIGH);
		DIO_write(PORT_A , PIN2 , HIGH);
		counter = 1;
	}
}