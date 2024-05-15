/*
 * Timer_interface.h
 *
 * Created: 05/12/2022 21:55:18
 *  Author: hala
 */ 


#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

#include "Timer_config.h"
#include "Timer_private.h"


/*Function Prototypes*/
void Timer0_Init();

void Timer0_SetPreload(uint8_t Preload);

void Timer0_SetCTC(uint8_t OCR);

void Timer0_OVERFLOW_CALLBACK(void(*Ptr_OverflowApp)(void));

void Timer0_CTC_CALLBACK(void(*Ptr_CTCApp)(void));

#endif /* TIMER_INTERFACE_H_ */