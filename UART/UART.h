/*
 * UART.h
 *
 * Created: 18/09/2022 04:19:46 م
 *  Author: user
 */ 


#ifndef UART_H_
#define UART_H_

//#include "../../Utilities/std_types.h"
#include <util/delay.h>
#include "../../Utilities/bit_math.h"
#include "../../Utilities/register.h"

void UART_init();
void UART_transmit(uint8_t data);
uint8_t UART_receive();
void UART_transmit_string(uint8_t *data);
uint8_t* UART_receive_string();

#endif /* UART_H_ */