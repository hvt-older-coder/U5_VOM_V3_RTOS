/*
 * isr_module.c
 *
 *  Created on: Nov 4, 2024
 *      Author: Admin
 *      This module will contains all ISR callbacks.
 */
#include "main.h"
#include "modules.h"

extern ADC_HandleTypeDef hadc1;

uint16_t ADC1_BUFFER[ADC1_MAX_CHANNEL*ADC1_MAX_BUFFER];

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc)
{
	//We will read Data from ADC, and feed to the Queue.
	//With Mutex to protect data.
	//Keep it short here.
	if(hadc->Instance == ADC1)
	{
		//HAL_ADC_Stop_DMA(hadc);
		//Give the semaphore to the InputTask to run and feed data to Queue.
		GiveSemaphoreFromISRByName(ADC_COMPLETE_SEM);
	}

}
void PWM_ISR_Callback(void *arg)
{
	//We will read Data from PWM, and feed to the Queue.
	//With Mutex to protect data.
	//Keep it short here.
}
void BUTTON_ISR_Callback(void *arg)
{
	//We will read Data from BUTTON, and feed to the Queue.
	//With Mutex to protect data.
	//Keep it short here.

}


