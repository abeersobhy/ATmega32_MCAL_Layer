/*
 * DIO.h
 *
 * Created: 28/08/2022 11:24:11 م
 *  Author: user
 */ 


#ifndef DIO_H_
#define DIO_H_
/*PORT*/
#include "../../Utilities/std_types.h"
#include "../../Utilities/bit_math.h"
#include "../../Utilities/register.h"


void DIO_init(uint8_t portNumber , uint8_t pinNumber , uint8_t pinDirection); //Initialize DIO directions.
void DIO_write(uint8_t portNumber , uint8_t pinNumber , uint8_t value); // Write data into pin
void DIO_toggle(uint8_t portNumber , uint8_t pinNumber); // toggle pin
void DIO_read(uint8_t portNumber , uint8_t pinNumber , uint8_t *value); // read data

#endif /* DIO_H_ */