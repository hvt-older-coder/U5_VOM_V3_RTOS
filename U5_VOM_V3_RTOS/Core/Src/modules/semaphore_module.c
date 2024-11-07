/*
 * semaphore_module.c
 *
 *  Created on: Nov 5, 2024
 *      Author: Admin
 */
#include "modules.h"
#include "FreeRTOS.h"
#include "semphr.h"
#include "task.h"
#include "main.h"
#include "cmsis_os2.h"

#define MAX_SEMAPHORE 	(3)

const osSemaphoreAttr_t mySemaphoreAttrList[MAX_SEMAPHORE] = {
		{.name = "ADCHalfCompl"},
		{.name = "ADCComplt"},
		{.name = "UIQueueEmpty"},
} ;

SemaphoreHandle_t mySemaphoreHandleList[MAX_SEMAPHORE];

void InitSemaphore()
{
	for(int i = 0; i < MAX_SEMAPHORE; i++)
	{
		mySemaphoreHandleList[i] = osSemaphoreNew(1, 0, &mySemaphoreAttrList[i]);
	}
}
//typedef enum {
//	ADC_HALF_COMPLETE_SEM = 0,
//	ADC_COMPLETE_SEM = 1,
//	UI_QUEUE_EMPTY = 2,
//
//} MySemaphoreName_t;
//
uint8_t TakeSemaphoreByName(MySemaphoreName_t semName)
{
	return (xSemaphoreTake(mySemaphoreHandleList[semName], 0));
}
uint8_t GiveSemaphoreFromISRByName(MySemaphoreName_t semName)
{
	return(xSemaphoreGiveFromISR(mySemaphoreHandleList[semName], pdFALSE));
}
uint8_t GiveSemaphoreByName(MySemaphoreName_t semName)
{
	return (xSemaphoreGive(mySemaphoreHandleList[semName]));
}
