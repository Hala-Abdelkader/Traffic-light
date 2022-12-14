/*
 * Interrupt_interface.h
 *
 * Created: 05/12/2022 19:02:54
 *  Author: hala
 */ 


#ifndef INTERRUPT_INTERFACE_H_
#define INTERRUPT_INTERFACE_H_
#include "Interrupt_private.h"
#include "Interrupt_config.h"

/*Function Prototype*/
void ExternalInterrupt0_Init();

void ExternalInterrupt0_CallBack(void(*ptr_ExternalInterruptApp)(void));

#endif /* INTERRUPT_INTERFACE_H_ */