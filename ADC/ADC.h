/*
 * ADC.h
 *
 * Created: 04/09/2022 08:57:31 م
 *  Author: user
 */ 


#ifndef ADC_H_
#define ADC_H_
#include "../../Utilities/std_types.h"
#include "../../Utilities/bit_math.h"
#include "../../Utilities/register.h"

void ADC_init();
uint16_t ADC_read(uint8_t channel);

#endif /* ADC_H_ */