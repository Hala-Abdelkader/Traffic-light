/*
 * Dio_program.c
 *
 * Created: 05/12/2022 18:27:18
 *  Author: hala
 */ 


#include "../../Lib/types.h"
#include "../../Lib/bit.h"
#include "Dio_interface.h"


void DIO_SetPortDirection(uint8_t PortNumber, uint8_t PortDirection)
{
	if(PortDirection==PORT_OUTPUT)
	{
		/*Valid Port Direction given */
		switch(PortNumber)
		{
			case DIO_PORTA:
			DDRA=PortDirection;
			break;
			case DIO_PORTB:
			DDRB=PortDirection;
			break;
			case DIO_PORTC:
			DDRC=PortDirection;
			break;
			case DIO_PORTD:
			DDRD=PortDirection;
			break;
			default:
			/*Wrong Port Number Passed*/
			break;
		}
	}
	else
	{
		/*Invalid Port Direction given */
	}
}


void DIO_SetPinDirection(uint8_t PinNumber,uint8_t PortNumber, uint8_t PinDirection)
{
	if((PinNumber>=0)&&(PinNumber<8))
	{
		switch(PortNumber)
		{
			case DIO_PORTA:
			if(PinDirection==PIN_OUTPUT)
			{
				SET_BIT(DDRA,PinNumber);
			}
			else if(PinDirection==PIN_INPUT)
			{
				CLR_BIT(DDRA,PinNumber);
			}
			else
			{
				//Invalid Pin Direction
			}
			break;
			case DIO_PORTB:
			if(PinDirection==PIN_OUTPUT)
			{
				SET_BIT(DDRB,PinNumber);
			}
			else if(PinDirection==PIN_INPUT)
			{
				CLR_BIT(DDRB,PinNumber);
			}
			else
			{
				//Invalid Pin Direction
			}
			break;
			case DIO_PORTC:
			if(PinDirection==PIN_OUTPUT)
			{
				SET_BIT(DDRC,PinNumber);
			}
			else if(PinDirection==PIN_INPUT)
			{
				CLR_BIT(DDRC,PinNumber);
			}
			else
			{
				//Invalid Pin Direction
			}
			break;
			case DIO_PORTD:
			if(PinDirection==PIN_OUTPUT)
			{
				SET_BIT(DDRD,PinNumber);
			}
			else if(PinDirection==PIN_INPUT)
			{
				CLR_BIT(DDRD,PinNumber);
			}
			else
			{
				//Invalid Pin Direction
			}
			break;
			default:
			/*Wrong Port Chosen*/
			break;
		}
	}
	else
	{
		/*Wrong Pin Number*/
	}
}


void DIO_SetPortValue(uint8_t PortNumber, uint8_t PortValue)
{
	if((PortValue==PORT_HIGH)||(PortValue==PORT_LOW))
	{
		/*Valid Port Direction given */
		switch(PortNumber)
		{
			case DIO_PORTA:
			PORTA=PortValue;
			break;
			case DIO_PORTB:
			PORTB=PortValue;
			break;
			case DIO_PORTC:
			PORTC=PortValue;
			break;
			case DIO_PORTD:
			PORTD=PortValue;
			break;
			default:
			/*Wrong Port Number Passed*/
			break;
		}
	}
	else
	{
		/*Invalid Port Value given */
	}
}

void DIO_SetPinValue(uint8_t PinNumber,uint8_t PortNumber, uint8_t PinValue)
{
	if((PinNumber>=0)&&(PinNumber<8))
	{
		switch(PortNumber)
		{
			case DIO_PORTA:
			if(PinValue==PIN_HIGH)
			{
				SET_BIT(PORTA,PinNumber);
			}
			else if(PinValue==PIN_LOW)
			{
				CLR_BIT(PORTA,PinNumber);
			}
			else
			{
				//Invalid Pin Value
			}
			break;
			case DIO_PORTB:
			if(PinValue==PIN_HIGH)
			{
				SET_BIT(PORTB,PinNumber);
			}
			else if(PinValue==PIN_INPUT)
			{
				CLR_BIT(PORTB,PinNumber);
			}
			else
			{
				//Invalid Pin Value
			}
			break;
			case DIO_PORTC:
			if(PinValue==PIN_OUTPUT)
			{
				SET_BIT(PORTC,PinNumber);
			}
			else if(PinValue==PIN_INPUT)
			{
				CLR_BIT(PORTC,PinNumber);
			}
			else
			{
				//Invalid Pin Value
			}
			break;
			case DIO_PORTD:
			if(PinValue==PIN_OUTPUT)
			{
				SET_BIT(PORTD,PinNumber);
			}
			else if(PinValue==PIN_INPUT)
			{
				CLR_BIT(PORTD,PinNumber);
			}
			else
			{
				//Invalid Pin Value
			}
			break;
			default:
			/*Wrong Port Chosen*/
			break;
		}
	}
	else
	{
		/*Wrong Pin Number*/
	}
}
void DIO_ReadPort(uint8_t PortNumber, uint8_t * PortReading)
{
	if(PortReading!=NULL)
	{
		switch(PortNumber)
		{
			case DIO_PORTA:
			*PortReading=PINA;
			break;
			case DIO_PORTB:
			*PortReading=PINB;
			break;
			case DIO_PORTC:
			*PortReading=PINC;
			break;
			case DIO_PORTD:
			*PortReading=PIND;
			break;
			default:
			/*Wrong Port Chosen*/
			break;
		}
	}
	else
	{
		//Null Pointer
	}
}


void DIO_ReadPin(uint8_t PinNumber,uint8_t PortNumber, uint8_t *PortReading)
{
	if((PinNumber>=0)&&(PinNumber<8))
	{
		switch(PortNumber)
		{
			case DIO_PORTA:
			*PortReading=GET_BIT(PINA,PinNumber);
			break;
			case DIO_PORTB:
			*PortReading=GET_BIT(PINB,PinNumber);
			break;
			case DIO_PORTC:
			*PortReading=GET_BIT(PINC,PinNumber);
			break;
			case DIO_PORTD:
			*PortReading=GET_BIT(PIND,PinNumber);
			break;
			default:
			/*Wrong Port Chosen*/
			break;
		}
	}
	else
	{
		/*Wrong Pin Number*/
	}
}

void DIO_TogglePin(uint8_t PinNumber,uint8_t PortNumber)
{
	if((PinNumber>=0)&&(PinNumber<8))
	{
		switch(PortNumber)
		{
			case DIO_PORTA:
			TOGGLE_BIT(PORTA,PinNumber);
			break;
			case DIO_PORTB:
			TOGGLE_BIT(PORTB,PinNumber);
			break;
			case DIO_PORTC:
			TOGGLE_BIT(PORTC,PinNumber);
			break;
			case DIO_PORTD:
			TOGGLE_BIT(PORTD,PinNumber);
			break;
			default:
			/*Wrong Port Chosen*/
			break;
		}
	}
	else
	{
		/*Wrong Pin Number*/
	}
}
