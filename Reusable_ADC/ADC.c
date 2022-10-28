/*
 * ADC.c
 *
 * Created: 04/09/2022 08:57:42 م
 *  Author: user
 */ 
#include "../../Utilities/std_types.h"
#include "../../Utilities/bit_math.h"
#include "../../Utilities/register.h"
#include "ADC.h"

ADC_StructConfig structConfig;

void ADC_init()
{
	switch(structConfig.referenceSelection)
	{
		case ADC_AREFSelection :
		     /*Nothing to do.*/
		break;
		case ADC_AVCCSelection:
		     ADMUX |= (1 << REFS0); /*AVCC Mode.*/
		break;
		case ADC_InternalVoltSelection :
		     ADMUX |= (1 << REFS0) | (1 << REFS1); /*Internal 2.56 volt.*/
		break;
		default:
		break;   
	}
	switch(structConfig.controlEnable)
	{
		case ADC_Enable:
		     ADCSRA |= (1 << ADEN);
		break;
		case ADC_Disable : 
		     /*Nothing to do.*/
		break;
		default:
		break;
	}	
	switch(structConfig.controlPrescaler)
	{
		case ADC_divisionFactor_2 :
		     /*Nothing to do.*/
		break;
		case ADC_divisionFactor_4 :
		     ADCSRA |= (1 << ADPS1);
		break;
		case ADC_divisionFactor_8 :
		     ADCSRA |= (1 << ADPS0)| (1 << ADPS1);
		break;
		case ADC_divisionFactor_16 :
		     ADCSRA |= (1 << ADPS2);
		break;
		case ADC_divisionFactor_32 :
		     ADCSRA |= (1 << ADPS0)| (1 << ADPS2);
		break;
		case ADC_divisionFactor_64 :
		     ADCSRA |= (1 << ADPS1)| (1 << ADPS2);
		break;
		case ADC_divisionFactor_128 :
		     ADCSRA |= (1 << ADPS0)| (1 << ADPS1) | (1 << ADPS2);
		break;
		default:
		break;
	}
	switch(structConfig.adjustResult)
	{
		case ADC_LeftAdjustResult :
		     ADMUX |= (1 << ADLAR); 
		break;
		case ADC_RightAdjustResult :
		     /*Nothing to do.*/
		break;
		default:
		break;
	}
	switch(structConfig.controlInterrupt)
	{
		case ADC_InterruptEnable :
		     ADCSRA |= (1 << ADIE);
		break;
		case ADC_InterruptDisable :
		     /*Nothing to do.*/
		break;
		default:
		break;
	}
	switch(structConfig.autoTriggerControl)
	{
		case ADC_AutoTriggerEnable :
		     ADCSRA |= (1 << ADATE);
		break;
		case ADC_AutoTriggerDisable :
		     /*Nothing to do.*/
		break;
		default:
		break; 
	}
}
uint16_t ADC_read(uint8_t channelNumber)
{
	uint16_t ADC = 0;
	ADMUX |= channelNumber; /*Select channel.*/ 
	ADCSRA |= (1 << ADSC); /*Start conversion.*/
	while(READ_BIT(ADCSRA , ADIF) == 0); /*Conversion continue.*/
    if(structConfig.adjustResult == ADC_LeftAdjustResult)
	{
		ADC = (ADCL >> 6);
		ADC |= (((uint16_t)ADCH) << 2);
	}
	else if(structConfig.adjustResult == ADC_RightAdjustResult)
	{
		ADC |= ADCH;
		ADC <<= 8;
		ADC |= ADCL;	
	}
	ADCSRA |= (1 << ADIF); /*Clear the ADIF bit.*/
	return ADC; /*Return the read value.*/
}