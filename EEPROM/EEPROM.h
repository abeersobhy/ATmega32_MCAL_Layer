/*
 * EEPROM.h
 *
 * Created: 24/09/2022 03:12:23 م
 *  Author: user
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_
#define F_CPU 1000000UL
#include <util/delay.h>
#include "../../Utilities/bit_math.h"
#include "../../Utilities/register.h"

uint8_t EEPROM_Read(uint16_t address);
void EEPROM_Write(uint8_t data , uint16_t address);


#endif /* EEPROM_H_ */