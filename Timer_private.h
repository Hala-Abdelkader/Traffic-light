/*
 * Timer_private.h
 *
 * Created: 05/12/2022 21:55:43
 *  Author: hala
 */ 


#ifndef TIMER_PRIVATE_H_
#define TIMER_PRIVATE_H_

/* Drivers Registers */
#define TIMSK   *((volatile uint8_t*)0x59)
#define TIFR   *((volatile uint8_t*)0x58)
#define TCNT0   *((volatile uint8_t*)0x52)
#define TCCR0   *((volatile uint8_t*)0x53)
#define OCR0   *((volatile uint8_t*)0x5C)

/*Timer Modes*/
#define TIMER_NORMAL_MODE 				0
#define TIMER_PWM_PHASE_CORRECT_MODE 	1
#define TIMER_CTC_MODE                	2
#define TIMER_FAST_PWM_MODE         	3

/**/
#define OC0_PIN_DISCONNECTED 	0
#define OC0_PIN_TOGGLE			1
#define OC0_PIN_CLEARED			2
#define OC0_PIN_SET				3


/*Options For CLOCK Pin: */
#define NO_CLOCK						0
#define SYSTEM_CLOCK					1
#define PRESCALAR_OVER_8				2
#define PRESCALAR_OVER_64				3
#define PRESCALAR_OVER_256				4
#define PRESCALAR_OVER_1024				5
#define EXTERNAL_CLOCK_FALLING_EDGE		6
#define EXTERNAL_CLOCK_RISING_EDGE		7

#define NORMAL_MODE_INTERRUPT_DISABLED  0
#define NORMAL_MODE_INTERRUPT_ENABLED  	1

#define CTC_MODE_INTERRUPT_DISABLED   0
#define CTC_MODE_INTERRUPT_ENABLED    1

#define FAST_PWM_OC0_DISCONNECTED		0
#define FAST_PWM_OC0_NON_INVERTING		1
#define FAST_PWM_OC0_INVERTING			2		

#define PHASE_CORRECT_PWM_OC0_DISCONNECTED		 0
#define PHASE_CORRECT_PWM_OC0_NON_INVERTING		 1
#define PHASE_CORRECT_PWM_OC0_INVERTING			 2


#endif /* TIMER_PRIVATE_H_ */