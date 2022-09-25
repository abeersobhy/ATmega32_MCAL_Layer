/*
 * timer.h
 *
 * Created: 31/08/2022 09:10:59 م
 *  Author: user
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include "../DIO/DIO.h"
/*******************************/
/*Over flow state.*/
/*******************************/
#define FLAG 0
#define INTERRUPT 1
#define NO_PRESCALER 0
void TIMER0_NM_init(uint8_t OverFlowState , uint16_t prescalerValue);
void TIMER0_CTC_init(uint8_t OCR_value);
void TIMER0_FG_init(uint8_t OCR_value);
void TIMER0_getState();
uint16_t TIMER0_CTC_state();
#endif /* TIMER_H_ */