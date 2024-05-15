/*
 * Dio_interface.h
 *
 * Created: 05/12/2022 18:17:20
 *  Author: hala
 */ 


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_
#include "Dio_private.h"
#include "../../Lib/types.h"
/* Description names for some objects*/
#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3

#define PORT_OUTPUT 255
#define PORT_INPUT  0

#define PORT_HIGH 255
#define PORT_LOW  0

#define PIN_HIGH 1
#define PIN_LOW  0

#define PIN_OUTPUT 1
#define PIN_INPUT 0

#define NULL 0

typedef enum Pin_t
{
	PIN0,PIN1,PIN2,PIN3,PIN4,PIN5,PIN6,PIN7
}Pin_t;


/*Functions Prototypes*/

void DIO_SetPortDirection(uint8_t PortNumber, uint8_t PortDirection);

void DIO_SetPinDirection(uint8_t PinNumber,uint8_t PortNumber, uint8_t PinDirection);

void DIO_SetPortValue(uint8_t PortNumber, uint8_t PortValue);

void DIO_SetPinValue(uint8_t PinNumber,uint8_t PortNumber, uint8_t PinValue);

void DIO_ReadPort(uint8_t PortNumber, uint8_t * PortReading);

void DIO_ReadPin(uint8_t PinNumber,uint8_t PortNumber, uint8_t * PortReading);

void DIO_TogglePin(uint8_t PinNumber,uint8_t PortNumber);

#endif /* DIO_INTERFACE_H_ */