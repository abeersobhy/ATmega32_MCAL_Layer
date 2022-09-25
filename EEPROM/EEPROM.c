/*
 * EEPROM.c
 *
 * Created: 24/09/2022 03:12:42 م
 *  Author: user
 */ 
#include "EEPROM.h"
uint8_t EEPROM_Read(uint16_t address)
{
	while(READ_BIT(EECR , EEWE) == 1); /*Make sure that previous writing is complete.*/
	EEARL = address;
	EEARH = (address >> 8);
	EECR |= (1 << EERE); /*Read Enable.*/
	return EEDR;
}
void EEPROM_Write(uint8_t data , uint16_t address)
{
	while(READ_BIT(EECR , EEWE) == 1); /*Make sure that previous writing is complete.*/
	EEARL = address;
	EEARH = (address >> 8);
	EEDR = data;
	EECR |= (1 << EEMWE); /*Master write Enable.*/
	EECR |= (1 << EEWE); /*Write Enable.*/	
}