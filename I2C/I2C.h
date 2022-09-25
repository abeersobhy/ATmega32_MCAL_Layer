/*
 * I2C.h
 *
 * Created: 21/09/2022 05:26:18 م
 *  Author: user
 */ 


#ifndef I2C_H_
#define I2C_H_

#include <util/delay.h>
#include "../../Utilities/bit_math.h"
#include "../../Utilities/register.h"

void I2C_Matser_init();
void I2C_Master_Start();
void I2C_Master_Addr(uint8_t ID , uint8_t RW);
void I2C_Master_Write(uint8_t data);
void I2C_Master_Stop();
void I2C_Slave_Init(uint8_t add);
uint8_t I2C_Slave_Available();
uint8_t I2C_Slave_Read();


#endif /* I2C_H_ */