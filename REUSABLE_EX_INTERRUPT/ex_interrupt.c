#include "../../Utilities/std_types.h"
#include "../../Utilities/bit_math.h"
#include "../../Utilities/register.h"

#include "ex_interrupt.h"

void (*pfunc)(void) = NULL;
INT_StructConfig INT;

void EX_INT_Init()
{
	SREG |= (1 << I); /*Enable global interrupt.*/
	switch(INT.pin)
	{
		case INT0_PIN:
		{
		     switch(INT.level)
			 {
				 case INT_WithLow:
				      /*Nothing to do.*/
				 break;
				 case INT_WithRising:
				      MCUCR |= (1 << ISC00) | (1 << ISC01); /*Interrupt with rising edge.*/ 
				 break;
				 case INT_WithFalling:
				      MCUCR |= (1 << ISC01); /*Interrupt with falling edge.*/
				 break;
				 case INT_WithAnyChange:
				      MCUCR |= (1 << ISC00); /*Interrupt with rising or falling edge.*/ 
				 break;
				 default:
				 break;
			 }
			 GICR |= (1 << INT0); /*External interrupt on INT0 enabled.*/ 
		}
		break;
		case INT1_PIN:
		{
			 switch(INT.level)
		     {
			     case INT_WithLow:
			     /*Nothing to do.*/
			     break;
			     case INT_WithRising:
			          MCUCR |= (1 << ISC11) | (1 << ISC10); /*Interrupt with rising edge.*/
			     break;
			     case INT_WithFalling:
			          MCUCR |= (1 << ISC11); /*Interrupt with falling edge.*/
			     break;
			     case INT_WithAnyChange:
			          MCUCR |= (1 << ISC10); /*Interrupt with rising or falling edge.*/
			     break;
			     default:
			     break;
		     }
			 GICR |= (1 << INT1); /*External interrupt on INT1 enabled.*/ 
		}
		break;
		case INT2_PIN:
		{
		     switch(INT.level)
		     {
			     case INT_WithRising:
			          MCUCSR |= (1 << ISC2); /*Interrupt with rising edge.*/
			     break;
			     case INT_WithFalling:
			         /*Nothing to do*/
			     break;
			     default:
			     break;
		     }
			 GICR |= (1 << INT2); /*External interrupt on INT2 enabled.*/
		}
		break;
		default:
		break;
   }
}
void RegisteringFunction(void(*CallBackFunction)(void)) /*Function to implement the pointer to function with the address of the call back function.*/
{
	pfunc = CallBackFunction;	
}
ISR(EX_INT_0)
{
	if(pfunc != NULL)
	{
		(*pfunc)();
	}
}
ISR(EX_INT_1)
{
	if(pfunc != NULL)
	{
		(*pfunc)();
	}
}
ISR(EX_INT_2)
{
	if(pfunc != NULL)
	{
		(*pfunc)();
	}
}