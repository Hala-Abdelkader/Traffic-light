/*
 * LED.h
 *
 * Created: 05/12/2022 15:40:06
 *  Author: hala
 */ 


#ifndef LED_H_
#define LED_H_

#include "../../Lib/types.h"
#include "../../Lib/bit.h"
#include "../../MCAL/Dio Driver/Dio_interface.h"
#include "../../MCAL/Timer Driver/Timer_interface.h"
#include "../../MCAL/Internal Interrrupt Driver/Internal_Interrupt.h"
#include "../../MCAL/External interrupt Driver/Interrupt_interface.h"
#include <stdbool.h>


void Led_ON (uint8_t PortNumber, uint8_t PinNumber);

void Led_BLINKING (uint8_t PortNumber, uint8_t PinNumber);

void Led_OFF (uint8_t PortNumber, uint8_t PinNumber);



#endif /* LED_H_ */