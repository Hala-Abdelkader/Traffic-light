/*
 * Internal_Interrupt.h
 *
 * Created: 05/12/2022 21:38:57
 *  Author: hala
 */ 


#ifndef INTERNAL_INTERRUPT_H_
#define INTERNAL_INTERRUPT_H_

#define SREG   *((volatile uint8_t*)0x5F)

/*Functions Prototypes*/
void Internal_Interrupt_Enable(void);
void Internal_Interrupt_Disable(void);



#endif /* INTERNAL_INTERRUPT_H_ */