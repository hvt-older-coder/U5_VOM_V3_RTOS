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

void ADC1_Init_DMA()
{
	if(HAL_OK != HAL_ADCEx_Calibration_Start(&hadc1, ADC_CALIB_OFFSET, ADC_SINGLE_ENDED))
	{
		Error_Handler();
	}
	if(HAL_OK != HAL_ADC_Start_DMA(&hadc1, (void*)ADC1_BUFFER, ADC1_MAX_CHANNEL*ADC1_MAX_BUFFER))
	{
		Error_Handler();
	}


}
void HAL_ADC_ConvHalfCpltCallback(ADC_HandleTypeDef *hadc){
	if(hadc->Instance == ADC1)
		{
			ADC1_Queue_ReleaseSemaphore(0);
		}
}
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc)
{
	//We will read Data from ADC, and feed to the Queue.
	//With Mutex to protect data.
	//Keep it short here.
	if(hadc->Instance == ADC1)
	{
		ADC1_Queue_ReleaseSemaphore(1);
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


