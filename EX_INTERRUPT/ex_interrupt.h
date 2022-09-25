/*
 * ex_interrupt.h
 *
 * Created: 03/09/2022 04:26:06 م
 *  Author: user
 */ 


#ifndef EX_INTERRUPT_H_
#define EX_INTERRUPT_H_

#include "../../Utilities/std_types.h"
#include "../../Utilities/bit_math.h"
#include "../../Utilities/register.h"

#define EX_INT_0 __vector_1
#define EX_INT_1 __vector_2
#define EX_INT_2 __vector_3
#define ISR(INT_VECT)void INT_VECT(void)__attribute__((signal , used));\
        void INT_VECT(void)
void EX_INT0_init();
void EX_INT1_init();
void EX_INT2_init();



#endif /* EX_INTERRUPT_H_ */