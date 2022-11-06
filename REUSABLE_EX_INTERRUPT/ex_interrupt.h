#ifndef EX_INTERRUPT_H_
#define EX_INTERRUPT_H_

#define NULL '\0'
#define EX_INT_0 __vector_1
#define EX_INT_1 __vector_2
#define EX_INT_2 __vector_3
#define ISR(INT_VECT)void INT_VECT(void)__attribute__((signal , used));\
        void INT_VECT(void)

typedef enum 
{
	INT_WithRising,
	INT_WithFalling,
	INT_WithLow,
	INT_WithAnyChange,
}INT_Level;
typedef enum
{
	INT0_PIN,
	INT1_PIN,
	INT2_PIN,
}INT_Pin;
typedef struct
{
	INT_Level level;
	INT_Pin pin;	
}INT_StructConfig;

extern INT_StructConfig INT; 		
void EX_INT_Init(); /*Function to initialize the Interrupt*/
void RegisteringFunction(void(*ptrfunc)(void));  /*Function to initialize the pointer to function in the driver with the address of the pointer to func.*/


#endif /* EX_INTERRUPT_H_ */