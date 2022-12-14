/*
 * LED.c
 *
 * Created: 05/12/2022 15:39:55
 *  Author: hala
 */ 

#define  F_CPU 16000000
#include "util/delay.h"
#include "LED.h"


void Led_ON (uint8_t PortNumber, uint8_t PinNumber)
{
	DIO_SetPinValue(PinNumber,PortNumber,PIN_HIGH);
}

void Led_BLINKING (uint8_t PortNumber, uint8_t PinNumber)
{
	DIO_TogglePin(PinNumber,PortNumber);
}

void Led_OFF (uint8_t PortNumber, uint8_t PinNumber)
{
	DIO_SetPinValue(PinNumber,PortNumber,PIN_LOW);
}
