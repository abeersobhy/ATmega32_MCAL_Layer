/*
 * UART.c
 *
 * Created: 18/09/2022 04:19:58 م
 *  Author: user
 */ 
#include "UART.h"
void UART_init()
{
	
	UBRRL = 103; /*Set the value of the UBRR (9600).*/
	UCSRB |= (1 << RXEN) | (1 << TXEN); 
}
void UART_transmit(uint8_t data)
{
	UDR = data;
	while(READ_BIT(UCSRA , TXC) == 0); /*Data is not shifted out yet.*/
}
uint8_t UART_receive()
{
	while(READ_BIT(UCSRA , RXC) == 0); /*Data is not read yet.*/
	return UDR;
}
void UART_transmit_string(uint8_t *data)
{
	uint8_t i = 0;
	while(data[i] != '\0')
	{
		UART_transmit(data[i]);
        i++; 	
	}
}
uint8_t* UART_receive_string()
{
	static uint8_t arr_char[6] , i = 0;
	while(i != 6)
	{
		arr_char[i] = UART_receive();
		i++;
	}
	return arr_char;
}