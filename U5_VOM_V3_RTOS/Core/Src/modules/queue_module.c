/*
 * queue_module.c
 *
 *  Created on: Nov 4, 2024
 *      Author: Admin
 *      This module will contain all the queue related function & definition
 */
#include "modules.h"
#include "FreeRTOS.h"
#include "semphr.h"
#include "task.h"
#include "main.h"
#include "cmsis_os2.h"

uint16_t adc1_debug_buffer[32];


#define MAX_QUEUE 	(2)

const osMessageQueueAttr_t myQueueAttr[MAX_QUEUE] = {
		{.name = "myAdcIN15Queue"},
		{.name = "myAdcIN16Queue"},
};
#define ADC_IN15_QUEUE_SIZE (32)
#define ADC_IN16_QUEUE_SIZE (32)

const uint16_t myQueueSizes[MAX_QUEUE] = {
		ADC_IN15_QUEUE_SIZE,
		ADC_IN16_QUEUE_SIZE,
};
osMessageQueueId_t myQueueHandle[MAX_QUEUE];
SemaphoreHandle_t adcQueueBinSem1;
SemaphoreHandle_t adcQueueBinSem2;

const osSemaphoreAttr_t myBinarySem01_attributes = {
  .name = "myBinarySem01"
};
const osSemaphoreAttr_t myBinarySem02_attributes = {
  .name = "myBinarySem02"
};

void initQueues()
{
	adcQueueBinSem1 = osSemaphoreNew(1, 0, &myBinarySem01_attributes);
	adcQueueBinSem2 = osSemaphoreNew(1, 0, &myBinarySem02_attributes);
	for(int i = 0; i < MAX_QUEUE; i++)
	{
		myQueueHandle[i] = osMessageQueueNew (myQueueSizes[i], sizeof(uint16_t), &myQueueAttr[i]);
	}
}

void ADC1_Queue_ReleaseSemaphore(uint8_t sem_index)
{
	//This will allow the ADC1_GetData to run.
	if(sem_index == 0){
		//osSemaphoreRelease(adcQueueBinSem1);
		xSemaphoreGiveFromISR(adcQueueBinSem1, pdFALSE);
	}else
	{
		xSemaphoreGiveFromISR(adcQueueBinSem2, pdFALSE);
	}
}

int ADC1_IN15_ReadDataFromQueue()
{
	uint16_t pData;
	if(osOK == osMessageQueueGet(myQueueHandle[1], (void*)&pData, 0, 0))
	{
		return (int)pData;
	}
	else {
		return -1;
	}
}


void ADC1_ReadDataFromDMABuffer()
{
	 if(xSemaphoreTake(adcQueueBinSem1, 10) == pdTRUE) {
		 //Do the update.
		 for(int i = 0; i < (ADC1_MAX_CHANNEL*ADC1_MAX_BUFFER/2); i++)
		 {
			 //need to get first half of data
			 uint16_t data = ADC1_BUFFER[i];
			 adc1_debug_buffer[i] = data;
			 if(i%2 == 0)
			 {
				 //Data for IN15
				 osMessageQueuePut(myQueueHandle[0], (void*)&data, 0, 0);
			 }
			 else {
				 //Data for IN16
				 osMessageQueuePut(myQueueHandle[1], (void*)&data, 0, 0);
			 }

		 }
	 } else if (xSemaphoreTake(adcQueueBinSem2, 10) == pdTRUE){
		 //return immediately if Sem is taken.
		 //Do the update.
		 		 for(int i = ADC1_MAX_CHANNEL*ADC1_MAX_BUFFER/2; i < (ADC1_MAX_CHANNEL*ADC1_MAX_BUFFER); i++)
		 		 {
		 			 //need to get first half of data
		 			 uint16_t data = ADC1_BUFFER[i];
		 			adc1_debug_buffer[i - ADC1_MAX_CHANNEL*ADC1_MAX_BUFFER/2] = data;
		 			 if(i%2 == 0)
		 			 {
		 				 //Data for IN15
		 				 osMessageQueuePut(myQueueHandle[0], (void*)&data, 0, 0);

		 			 }
		 			 else {
		 				 //Data for IN16
		 				 osMessageQueuePut(myQueueHandle[1], (void*)&data, 0, 0);
		 			 }
		 		 }
	 }

}




