/*
 * Interrupt_program.c
 *
 * Created: 05/12/2022 19:03:50
 *  Author: hala
 */ 

#include <stdbool.h>
#include "../../Lib/types.h"
#include "../../Lib/bit.h"
#include "../Dio Driver/Dio_interface.h"
#include "Interrupt_interface.h"

// Global Pointer
void (*Glob_ExternalInterrupt_ISR_Ptr)(void)= NULL;


void ExternalInterrupt0_Init()
{
	#if ExternalInterrupt_SENSE_CONTROL_STATE==ExternalInterrupt_LOW_LEVEL

	CLR_BIT(MCUCR,0);
	CLR_BIT(MCUCR,1);
	#elif ExternalInterrupt_SENSE_CONTROL_STATE==ExternalInterrupt_ANY_LOGICAL_CHANGE
	SET_BIT(MCUCR,0);
	CLR_BIT(MCUCR,1);

	#elif ExternalInterrupt_SENSE_CONTROL_STATE==ExternalInterrupt_RISING_EDGE
	SET_BIT(MCUCR,0);
	SET_BIT(MCUCR,1);

	#elif ExternalInterrupt_SENSE_CONTROL_STATE==ExternalInterrupt_FALLING_EDGE
	CLR_BIT(MCUCR,0);
	SET_BIT(MCUCR,1);
	#endif

	/*Enable Interrupt on INT0 ==> PIE of Interrupt zero*/
	SET_BIT(GICR,6);
}


void ExternalInterrupt0_CallBack(void(*Ptr_ExternalInterrupt)(void))
{
	if(Ptr_ExternalInterrupt !=NULL)
	{
		
		Glob_ExternalInterrupt_ISR_Ptr=Ptr_ExternalInterrupt;
	}
}

//EXTI ISR
void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
	if(Glob_ExternalInterrupt_ISR_Ptr!=NULL)
	{
		Glob_ExternalInterrupt_ISR_Ptr();
	}
}