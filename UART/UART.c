/*
 * UART.c
 *
 * Created: 18/09/2022 04:19:58 م
 *  Author: user
 */ 
#include "UART.h"
void UART_Init()
{
      /*Set baud rate to URR Register with freg = 1 Mhz.*/
      /*Double speed mode.*/
      UCSRA |= (1 << U2X);
      /*UBRR = (1000000/(8*9600) - 1) = 12.*/
      UBRRL = 12;
      /*Select UCSRC Register to write.*/
      UCSRC |= (1 << URSEL);
      /*8 bit character.*/
      UCSRC |= (1 << UCSZ0) | (1 << UCSZ1);
      /*Enable receiver and transmitter.*/
       UCSRB |= (1 << RXEN) | (1 << TXEN);
}
/*Send byte to the receiver*/
void UART_SendByte(uint8_t data)
{
     while(READ_BIT(UCSRA , UDRE) == 0); /*Make sure that UDR is empty.*/
     UDR = data;	
}
/*Receive byte from the transmitter.*/
uint8_t UART_ReceiveByte()
{
     while(READ_BIT(UCSRA , RXC) == 0); /*Make sure that the data is received.*/
     return UDR;
}
void UART_transmit_string(uint8_t *data)
{
     uint8_t i = 0;
     while(data[i] != '\0')
     {
	 UART_SendByte(data[i]);
         i++; 	
     }
}
uint8_t* UART_receive_string()
{
	static uint8_t arr_char[6] , i = 0;
	while(i != 6)
	{
		arr_char[i] = UART_ReceiveByt();
		i++;
	}
	return arr_char;
}
