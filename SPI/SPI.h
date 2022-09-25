/*
 * SPI.h
 *
 * Created: 19/09/2022 08:01:45 م
 *  Author: user
 */ 


#ifndef SPI_H_
#define SPI_H_
#include <util/delay.h>
#include "../../Utilities/bit_math.h"
#include "../../Utilities/register.h"

void SPI_slave_init();
void SPI_master_init();
void SPI_send_char(uint8_t data);
uint8_t SPI_receive_char();

#endif /* SPI_H_ */