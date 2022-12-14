/*
 * Interrupt_private.h
 *
 * Created: 05/12/2022 19:03:30
 *  Author: hala
 */ 


#ifndef INTERRUPT_PRIVATE_H_
#define INTERRUPT_PRIVATE_H_

#define ExternalInterrupt_LOW_LEVEL  				0
#define ExternalInterrupt_ANY_LOGICAL_CHANGE		1
#define ExternalInterrupt_RISING_EDGE				2
#define ExternalInterrupt_FALLING_EDGE				3

#define MCUCR   *((volatile uint8_t*)0x55)
#define MCUCSR  *((volatile uint8_t*)0x54)
#define GICR   *((volatile uint8_t*)0x5B)



#endif /* INTERRUPT_PRIVATE_H_ */