/*
 * Timer_program.c
 *
 * Created: 05/12/2022 21:54:39
 *  Author: hala
 */ 

#include "../../Lib/types.h"
#include "../../Lib/bit.h"
#include "../Dio Driver/Dio_interface.h"
#include "Timer_interface.h"
//Two Global Pointers
void (*Glob_OverflowISR_Ptr)(void)=NULL;
void (*Glob_CTC_ISR_Ptr)(void)=NULL;

/*
 * Init:
 * 1-SetMode of Timer
 * 2-Set OC0 Mode
 * 3-Set Interrupt State
 * 4-Set Prescalar
 */

void Timer0_Init()
{
	//SetMode of Timer
#if TIMER0_MODE==TIMER_NORMAL_MODE
	CLR_BIT(TCCR0,3);
	CLR_BIT(TCCR0,6);

	//Set Normal Mode interrupt
	#if TIMER0_NORMAL_MODE_INTERRUPT_STATE==NORMAL_MODE_INTERRUPT_DISABLED
		CLR_BIT(TIMSK,0);
	#elif TIMER0_NORMAL_MODE_INTERRUPT_STATE==NORMAL_MODE_INTERRUPT_ENABLED
		SET_BIT(TIMSK,0);
	#endif

#elif TIMER0_MODE==TIMER_CTC_MODE
	SET_BIT(TCCR0,3);
	CLR_BIT(TCCR0,6);


	//Set OC0 Mode
	#if TIMER0_OC0_MODE==OC0_PIN_DISCONNECTED
		CLR_BIT(TCCR0,4);
		CLR_BIT(TCCR0,5);
	#elif TIMER0_OC0_MODE==OC0_PIN_TOGGLE
		SET_BIT(TCCR0,4);
		CLR_BIT(TCCR0,5);
	#elif TIMER0_OC0_MODE==OC0_PIN_CLEARED
		CLR_BIT(TCCR0,4);
		SET_BIT(TCCR0,5);
	#elif TIMER0_OC0_MODE==OC0_PIN_SET
		SET_BIT(TCCR0,4);
		SET_BIT(TCCR0,5);
	#endif



		//Set CTC Mode interrupt
	#if TIMER0_CTC_MODE_INTERRUPT_STATE==NORMAL_MODE_INTERRUPT_DISABLED
		CLR_BIT(TIMSK,1);
	#elif TIMER0_CTC_MODE_INTERRUPT_STATE==NORMAL_MODE_INTERRUPT_ENABLED
		SET_BIT(TIMSK,1);
	#endif
	
#elif TIMER0_MODE==TIMER_FAST_PWM_MODE
	SET_BIT(TCCR0,3);
	SET_BIT(TCCR0,6);

	//Set PWM Wave on OC0
	#if TIMER0_FAST_PWM_WAVE_MODE==FAST_PWM_OC0_DISCONNECTED
		CLR_BIT(TCCR0,4);
		CLR_BIT(TCCR0,5);
	#elif TIMER0_FAST_PWM_WAVE_MODE==FAST_PWM_OC0_NON_INVERTING
		CLR_BIT(TCCR0,4);
		SET_BIT(TCCR0,5);
	#elif TIMER0_FAST_PWM_WAVE_MODE==FAST_PWM_OC0_INVERTING
		SET_BIT(TCCR0,4);
		SET_BIT(TCCR0,5);
	#endif


#elif TIMER0_MODE==TIMER_PWM_PHASE_CORRECT_MODE
	CLR_BIT(TCCR0,3);
	SET_BIT(TCCR0,6);

	//Set PWM Wave on OC0
	#if TIMER0_PHASE_CORRECT_PWM_WAVE_MODE==PHASE_CORRECT_PWM_OC0_DISCONNECTED
		CLR_BIT(TCCR0,4);
		CLR_BIT(TCCR0,5);
	#elif TIMER0_PHASE_CORRECT_PWM_WAVE_MODE==PHASE_CORRECT_PWM_OC0_NON_INVERTING
		CLR_BIT(TCCR0,4);
		SET_BIT(TCCR0,5);
	#elif TIMER0_PHASE_CORRECT_PWM_WAVE_MODE==PHASE_CORRECT_PWM_OC0_INVERTING
		SET_BIT(TCCR0,4);
		SET_BIT(TCCR0,5);
	#endif

#else
#error "Wrong Mode chosen"
#endif

	//SET PRESCALAR
#if TIMER0_CLOCK_SOURCE==NO_CLOCK
	CLR_BIT(TCCR0,0);
	CLR_BIT(TCCR0,1);
	CLR_BIT(TCCR0,2);

#elif TIMER0_CLOCK_SOURCE==SYSTEM_CLOCK
	SET_BIT(TCCR0,0);
	CLR_BIT(TCCR0,1);
	CLR_BIT(TCCR0,2);

#elif TIMER0_CLOCK_SOURCE==PRESCALAR_OVER_8
	CLR_BIT(TCCR0,0);
	SET_BIT(TCCR0,1);
	CLR_BIT(TCCR0,2);

#elif TIMER0_CLOCK_SOURCE==PRESCALAR_OVER_64
	SET_BIT(TCCR0,0);
	SET_BIT(TCCR0,1);
	CLR_BIT(TCCR0,2);
#elif TIMER0_CLOCK_SOURCE==PRESCALAR_OVER_256
	CLR_BIT(TCCR0,0);
	CLR_BIT(TCCR0,1);
	SET_BIT(TCCR0,2);
#elif TIMER0_CLOCK_SOURCE==PRESCALAR_OVER_1024
	SET_BIT(TCCR0,0);
	CLR_BIT(TCCR0,1);
	SET_BIT(TCCR0,2);
#elif TIMER0_CLOCK_SOURCE==EXTERNAL_CLOCK_FALLING_EDGE
	CLR_BIT(TCCR0,0);
	SET_BIT(TCCR0,1);
	SET_BIT(TCCR0,2);
#elif TIMER0_CLOCK_SOURCE==EXTERNAL_CLOCK_RISING_EDGE
	SET_BIT(TCCR0,0);
	SET_BIT(TCCR0,1);
	SET_BIT(TCCR0,2);
#endif

}

void Timer0_SetPreload(uint8_t Preload) // initial value for overflow counter
{
	TCCR0=Preload;
}

void Timer0_SetCTC(uint8_t OCR)
{
	OCR0=OCR;
}


void Timer0_OVERFLOW_CALLBACK(void(*Ptr_OverflowApp)(void))
{
	if(Ptr_OverflowApp!=NULL)
	{
		if(Glob_OverflowISR_Ptr==NULL)
		{
			Glob_OverflowISR_Ptr=Ptr_OverflowApp;
		}
	}
}


void Timer0_CTC_CALLBACK(void(*Ptr_CTCApp)(void))
{
	if(Ptr_CTCApp !=NULL)
	{
		Glob_CTC_ISR_Ptr=Ptr_CTCApp;
			
	}

}

//CTC ISR
void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{
	if(Glob_CTC_ISR_Ptr!=NULL)
	{
		Glob_CTC_ISR_Ptr();
	}
}

//Overflow ISR
void __vector_11(void) __attribute__((signal));
void __vector_11(void)
{
	if(Glob_OverflowISR_Ptr != NULL)
	{
		Glob_OverflowISR_Ptr();
	}
}
