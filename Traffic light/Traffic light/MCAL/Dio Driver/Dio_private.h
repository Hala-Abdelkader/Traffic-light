/*
 * Dio_private.h
 *
 * Created: 05/12/2022 18:29:01
 *  Author: hala
 */ 


#ifndef MCAL_DIO_DRIVER_DIO_PRIVATE_H_
#define MCAL_DIO_DRIVER_DIO_PRIVATE_H_
//Port A Registers
#define DDRA			*((volatile uint8_t*)0x3A)
#define PORTA			*((volatile uint8_t*)0x3B)
#define PINA			*((volatile uint8_t*)0x39)
//Port B Registers
#define DDRB			*((volatile uint8_t*)0x37)
#define PORTB			*((volatile uint8_t*)0x38)
#define PINB			*((volatile uint8_t*)0x36)
//Port C Registers
#define DDRC			*((volatile uint8_t*)0x34)
#define PORTC			*((volatile uint8_t*)0x35)
#define PINC			*((volatile uint8_t*)0x33)
//Port D Registers
#define DDRD			*((volatile uint8_t*)0x31)
#define PORTD			*((volatile uint8_t*)0x32)
#define PIND			*((volatile uint8_t*)0x30)

#endif /* DIO_PRIVATE_H_ */
