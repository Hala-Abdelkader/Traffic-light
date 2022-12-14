/*
 * App.h
 *
 * Created: 05/12/2022 14:57:25
 *  Author: hala
 */ 


#ifndef APP_H_
#define APP_H_
#include "../HAL/LED Driver/LED.h"
typedef enum errorState
{
	OK,ERROR, Normal_OK,Pedestrian_OK,ERROR_WITH_TIMER,ERROR_WITH_BUTTON
	}errorState;

errorState app_init();
errorState Normal_mode();
errorState Pedestrian_mode();
void app_start();
errorState Test_Drivers();
errorState Test_ExternalInterrupt();





#endif /* APP_H_ */