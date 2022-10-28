#ifndef ADC_H_
#define ADC_H_

/*Enum to Enable and Disable the ADC.*/
typedef enum
{
	ADC_Enable,
	ADC_Disable,
}ADC_ControlEnable;
/*Enum to AutoTrigger Enable and Disable.*/
typedef enum
{
	ADC_AutoTriggerEnable,
	ADC_AutoTriggerDisable,
}ADC_AutoTriggerControl;
/*Enum to Enable and Disable the ADC Interrupt*/
typedef enum
{
	ADC_InterruptEnable,
	ADC_InterruptDisable,	
}ADC_ControlInterrupt;
/*Enum to select the division factor of thr ADC.*/
typedef enum
{
	ADC_divisionFactor_2,
	ADC_divisionFactor_4,
	ADC_divisionFactor_8,
	ADC_divisionFactor_16,
	ADC_divisionFactor_32,
	ADC_divisionFactor_64,
	ADC_divisionFactor_128,
}ADC_ControlPrescaler;
/*Enum to select the voltage reference to the ADC.*/
typedef enum
{
	ADC_AREFSelection,
	ADC_AVCCSelection,
	ADC_InternalVoltSelection,
}ADC_referenceSelection;
/*Enum to select the Adjust result.*/
typedef enum
{
	ADC_LeftAdjustResult,
	ADC_RightAdjustResult,
}ADC_AdjustResult;

typedef struct
{
	ADC_ControlEnable         controlEnable;
	ADC_AutoTriggerControl    autoTriggerControl;
	ADC_ControlInterrupt      controlInterrupt;
	ADC_ControlPrescaler      controlPrescaler;
	ADC_referenceSelection    referenceSelection; 	 	
    ADC_AdjustResult          adjustResult;
}ADC_StructConfig;

extern ADC_StructConfig structConfig;
/***************************************************
* Function name :  ADC_init
* Purpose :  initialize The ADC using the selected mode
* Parameters :   (void) No parameters
* Return value :  void
***************************************************/
void ADC_init();
/***************************************************
* Function name :  ADC_read
* Purpose :  read the input value on the selected channel number
* Parameters :   (uint8_t) channel_number (to read from)
* Return value : (uint16_t) the input value to the selected channel
***************************************************/
uint16_t ADC_read(uint8_t channel_number);

#endif /* ADC_H_ */