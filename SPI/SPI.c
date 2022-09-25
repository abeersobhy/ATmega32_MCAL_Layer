/*
 * SPI.c
 *
 * Created: 19/09/2022 08:01:32 م
 *  Author: user
 */ 

#include "SPI.h"
void SPI_slave_init()
{
	DDRB |= 1 << PIN6;
	SET_BIT(SPCR , SPE);
}
void SPI_master_init()
{
	DDRB |= (1 << PIN4) | (1 << PIN5) | (1 << PIN7);
	SET_BIT(SPCR , MSTR);
	SET_BIT(SPCR , SPE);
}
void SPI_send_char(uint8_t data)
{
	SPDR = data;
	while(READ_BIT(SPSR,SPIF) == 0);
}

uint8_t SPI_receive_char()
{
	while(READ_BIT(SPSR,SPIF) == 0);
	return SPDR;
}