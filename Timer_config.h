/*
 * Timer_config.h
 *
 * Created: 05/12/2022 21:54:57
 *  Author: hala
 */ 


#ifndef TIMER_CONFIG_H_
#define TIMER_CONFIG_H_

/* 
Options for TIMER_MODE:
1-TIMER_NORMAL_MODE
2-TIMER_PWM_PHASE_CORRECT_MODE
3-TIMER_CTC_MODE
4-TIMER_FAST_PWM_MODE 
*/

#define TIMER0_MODE TIMER_CTC_MODE


/*
 Options For OC0 Pin:
 1-OC0_PIN_DISCONNECTED
 2-OC0_PIN_TOGGLE
 3-OC0_PIN_CLEARED
 4-OC0_PIN_SET
 */
#define TIMER0_OC0_MODE OC0_PIN_SET

/*
  Options For CLOCK Pin:
 1-NO_CLOCK
 2-SYSTEM_CLOCK
 3-PRESCALAR_OVER_8
 4-PRESCALAR_OVER_64
 5-PRESCALAR_OVER_256
 6-PRESCALAR_OVER_1024
 7-EXTERNAL_CLOCK_FALLING_EDGE
 8-EXTERNAL_CLOCK_RISING_EDGE
 */
#define TIMER0_CLOCK_SOURCE PRESCALAR_OVER_256


/*
  Options For TOV Interrupt:
 1-NORMAL_MODE_INTERRUPT_DISABLED
 2-NORMAL_MODE_INTERRUPT_ENABLED
 */
#define TIMER0_NORMAL_MODE_INTERRUPT_STATE NORMAL_MODE_INTERRUPT_DISABLED

/*
  Options For CTC Interrupt:
 1-CTC_MODE_INTERRUPT_DISABLED
 2-CTC_MODE_INTERRUPT_ENABLED
 */
#define TIMER0_CTC_MODE_INTERRUPT_STATE CTC_MODE_INTERRUPT_ENABLED


/**
  Options For Fast PWM:
 1-FAST_PWM_OC0_DISCONNECTED
 2-FAST_PWM_OC0_NON_INVERTING
 3-FAST_PWM_OC0_INVERTING
 */

#define TIMER0_FAST_PWM_WAVE_MODE FAST_PWM_OC0_DISCONNECTED

/**
  Options For PHASE CORRECT PWM:
 1-PHASE_CORRECT_PWM_OC0_DISCONNECTED
 2-PHASE_CORRECT_PWM_OC0_NON_INVERTING
 3-PHASE_CORRECT_PWM_OC0_INVERTING
 */

#define TIMER0_PHASE_CORRECT_PWM_WAVE_MODE PHASE_CORRECT_PWM_OC0_DISCONNECTED

#endif /* TIMER_CONFIG_H_ */