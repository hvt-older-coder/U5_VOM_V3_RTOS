/*
 * adc_module.c
 *
 *  Created on: Nov 4, 2024
 *      Author: Admin
 *      This module handles all ADC related function, exclude the BUFFER & QUEUE.
 *      Interrupt will be handle in the isr_module.c
 */
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os2.h"
#include "modules.h"

extern ADC_HandleTypeDef hadc1;

void ADC1_Calibration()
{
	if(HAL_OK != HAL_ADCEx_Calibration_Start(&hadc1, ADC_CALIB_OFFSET, ADC_SINGLE_ENDED))
	{
		Error_Handler();
	}
}

void ADC1_Start_DMA_Conv()
{
		if(HAL_OK != HAL_ADC_Start_DMA(&hadc1, (void*)ADC1_BUFFER, ADC1_MAX_CHANNEL*ADC1_MAX_BUFFER))
		{
			Error_Handler();
		}
}
uint16_t ADC1_Convert_Data_To_V(uint16_t data)
{
	return (uint16_t)__LL_ADC_CALC_DATA_TO_VOLTAGE(ADC1, 3300UL, (uint32_t)data,  LL_ADC_RESOLUTION_14B);
}
