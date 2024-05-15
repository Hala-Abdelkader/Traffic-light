/*
 * App.c
 *
 * Created: 05/12/2022 14:57:09
 *  Author: hala
 */ 
#include "App.h"
#define F_CPU 16000000

uint8_t state=1;
uint8_t static stateCounter =0;
uint8_t static stateCounter_test=0;
uint_16 static CTC_Counter=0;
uint_16 static CTC_Counter_test=750;

uint8_t flag =0;
uint8_t flag_1=1;
uint8_t flag_2=0;

errorState app_init()
{
	/*Direction of pins and ports*/
	
	DIO_SetPortDirection(DIO_PORTA,PORT_OUTPUT);
	
	DIO_SetPortDirection(DIO_PORTB,PORT_OUTPUT);
	
	DIO_SetPinDirection(PIN2,DIO_PORTD,PIN_INPUT);
	
	
	/*initialization of timer and interrupt */
	Timer0_Init();
	Internal_Interrupt_Enable();
	ExternalInterrupt0_Init();
	
	/*Set OC0 of CTC*/
	Timer0_SetCTC(250);
	
	/*set initialization to button*/
	DIO_SetPinValue(PIN2,DIO_PORTD,PIN_HIGH);
	DIO_ReadPin(PIN2,DIO_PORTD,&state);
	if (state ==0)
	{
		return OK;
	}
	return ERROR;
}

errorState Normal_mode()
{
	
	if (flag_1 == 1)
	{
		Led_ON(DIO_PORTA,PIN2);
		Led_ON(DIO_PORTB,PIN0);
	}
	
	if (flag ==1)
	{
		Led_BLINKING(DIO_PORTA,PIN1);
		Led_BLINKING(DIO_PORTB,PIN1);
	}
	
	if ( flag_2==1 && CTC_Counter==1250)
	{
		stateCounter=0;
		flag_2=0;
	}

	if(CTC_Counter==1250 && stateCounter==0)
	{
		flag_1=0;
		Led_OFF(DIO_PORTA,PIN2);
		Led_OFF(DIO_PORTB,PIN0);
		flag=1;
		CTC_Counter=0;
		stateCounter++;

	}
	else if(CTC_Counter==1250 && stateCounter==1)
	{
		flag =0;
		Led_OFF(DIO_PORTA,PIN1);
		Led_OFF(DIO_PORTB,PIN1);
		
		Led_ON(DIO_PORTA,PIN0);
		Led_ON(DIO_PORTB,PIN2);
		
		CTC_Counter=0;
		stateCounter++;	
	}
	else if( CTC_Counter==1250 && stateCounter == 2)
	{
		Led_OFF(DIO_PORTA,PIN0);
		Led_OFF(DIO_PORTB,PIN2);
		flag=1;
		CTC_Counter=0;
		stateCounter++;

	}
	else if(CTC_Counter==1250 && stateCounter==3)
	{
		flag=0;
		Led_OFF(DIO_PORTA,PIN1);
		Led_OFF(DIO_PORTB,PIN1);
		
		Led_ON(DIO_PORTA,PIN2);
		Led_ON(DIO_PORTB,PIN0);
		
		CTC_Counter=0;
		flag_2=1;
	}
	CTC_Counter++;
	if (flag_1 ==1 || stateCounter>3 ||stateCounter<0 )
	{
		return ERROR_WITH_TIMER;
	}
		else 
		{
		return Normal_OK;
        }
	
}


errorState Pedestrian_mode()
{

	if (stateCounter !=3 && flag_1==0)
	{		
		stateCounter=2;
		CTC_Counter=1250;
		Normal_mode();
		return Pedestrian_OK;
	}
	else 
	{
		return ERROR_WITH_BUTTON;
	}
}



void app_start()
{
	Timer0_CTC_CALLBACK(Normal_mode);
	ExternalInterrupt0_CallBack(Pedestrian_mode);
}

  errorState Test_Drivers()
{
	if(CTC_Counter_test==750 && stateCounter_test==0)
	{
		Led_ON(DIO_PORTB,PIN2);
		stateCounter_test++;
		CTC_Counter_test=0;
		
		return OK;	
	}
	else if(CTC_Counter_test==750 && stateCounter_test ==1)
	{
		Led_OFF(DIO_PORTB,PIN2);
		stateCounter_test=0;
		CTC_Counter_test=0;
		
		return OK;
	}
CTC_Counter_test++;	
		
}

errorState Test_ExternalInterrupt()
{
	if (stateCounter_test==1)
	{
		DIO_SetPinValue(PIN2,DIO_PORTB,PIN_LOW);
		return OK;
	}
}
