/*
 * I2C.c
 *
 * Created: 21/09/2022 05:25:49 م
 *  Author: user
 */ 
#include "I2C.h"

void I2C_Matser_init()
{
	/*Initiate the I2C with 400KHz -
	TWBR = ((16000000 / 400000) - 16 ) / (2 * 4^0)*/
	TWBR = 	12;
}
void I2C_Master_Start()
{
	TWCR |= (1 << TWSTA) | (1 << TWEN) | (1 << TWINT); /*Enable I2C - Start bit - Acknowledge bit - Set flag.*/
	while(READ_BIT(TWCR , TWINT) == 0); /*Current event is not complete.*/
}
void I2C_Master_Addr(uint8_t ID , uint8_t RW)
{
	TWDR = (ID << 1);
	(RW == 1) ? SET_BIT(TWCR , TWWC) : CLR_BIT(TWCR , TWWC);
	TWCR |= (1 << TWEN) | (1 << TWINT);
	while(READ_BIT(TWCR , TWINT) == 0); /*Current event is not complete.*/
}
void I2C_Master_Write(uint8_t data)
{
	TWDR = data;
	TWCR |= (1 << TWEN) | (1 << TWINT); /*Set TW flag - Enable I2C.*/
	while(READ_BIT(TWCR , TWINT) == 0); /*Current event is not complete.*/
}
void I2C_Master_Stop()
{
	TWCR |= (1 << TWSTO) | (1 << TWINT); /*Convert master to slave.*/
}
void I2C_Slave_Init(uint8_t add)
{
	TWAR = (add << 1);
}
uint8_t I2C_Slave_Available()
{
	TWCR |= (1 << TWEA) | (1 << TWEN) | (1 << TWINT);
	while(READ_BIT(TWCR , TWINT) == 0); /*Current event is not complete.*/
	if(TWSR == 0x60)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
uint8_t I2C_Slave_Read()
{
	TWCR |= (1 << TWEA) | (1 << TWEN) | (1 << TWINT);
	while(READ_BIT(TWCR , TWINT) == 0); /*Current event is not complete.*/
	return TWDR;
}
