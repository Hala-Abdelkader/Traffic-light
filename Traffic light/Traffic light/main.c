/*
 * Traffic light.c
 *
 * Created: 05/12/2022 14:56:22
 * Author : hala
 */ 


#include "App/App.h"


int main(void)
{
    /* Replace with your application code */
	
	/*DIO_SetPortDirection(DIO_PORTB,PORT_OUTPUT);
	DIO_SetPinValue(PIN0,DIO_PORTB,PIN_HIGH);
	DIO_SetPinValue(PIN1,DIO_PORTB,PIN_HIGH);
	DIO_SetPinValue(PIN2,DIO_PORTB,PIN_LOW);*/
	
	
	/*DIO_SetPortDirection(DIO_PORTB,PORT_OUTPUT);
	DIO_SetPinDirection(PIN2,DIO_PORTD,PIN_INPUT);
	DIO_SetPinValue(PIN2,DIO_PORTD,PIN_HIGH);
	
	//initialize timer and interrupt 
	Timer0_Init();
	Internal_Interrupt_Enable();
	ExternalInterrupt0_Init();

	//Setting OC0 of CTC
	Timer0_SetCTC(250);
		
	Timer0_CTC_CALLBACK(Test_Drivers);
	ExternalInterrupt0_CallBack(Test_ExternalInterrupt);*/
	
	
	
	
	app_init();
	app_start(); 
    while (1) 
    {
	//DIO_TogglePin(PIN1,DIO_PORTB);
		
    }
	
	return 0;
}

