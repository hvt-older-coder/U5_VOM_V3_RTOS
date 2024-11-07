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

//uint16_t adc1_debug_buffer[32];
//uint16_t adc1_debug_buffer2[32];

#define MAX_QUEUE 	(3)

typedef enum
{
	ADC1_IN15_QUEUE_NAME = 0,
	ADC1_IN16_QUEUE_NAME = 1,
	I2C_VOUT_QUEUE_NAME = 2,
} QueueIndexName_t;

const osMessageQueueAttr_t myQueueAttr[MAX_QUEUE] = {
		{.name = "AdcIN15"},
		{.name = "AdcIN16"},
		{.name = "I2CVOUT"},
};
#define ADC_IN15_QUEUE_SIZE (40)
#define ADC_IN16_QUEUE_SIZE (40)
#define I2C_VOUT_QUEUE_SIZE (10)

const uint16_t myQueueSizes[MAX_QUEUE] = {
		ADC_IN15_QUEUE_SIZE,
		ADC_IN16_QUEUE_SIZE,
		I2C_VOUT_QUEUE_SIZE,
};
osMessageQueueId_t myQueueHandle[MAX_QUEUE];

void initQueues()
{
	for(int i = 0; i < MAX_QUEUE; i++)
	{
		myQueueHandle[i] = osMessageQueueNew (myQueueSizes[i], sizeof(uint16_t), &myQueueAttr[i]);
	}
}

osMessageQueueId_t GetQueueHandleByName(QueueIndexName_t name)
{
	return myQueueHandle[name];
}

int ADC1_IN15_ReadDataFromQueue()
{
	uint16_t pData;
	if(osOK == osMessageQueueGet(GetQueueHandleByName(ADC1_IN15_QUEUE_NAME), (void*)&pData, 0, 0))
	{
		return (int)pData;
	}
	else {
		//Trigger ADC conversion when UI data is empty.
		//GiveSemaphoreByName(UI_QUEUE_EMPTY_SEM);
		return -1;
	}
}

void FeedDataToQueueFromADC_DMABuffer() {
	//ADC1_IN15 DATA will be in the even index: 0, 2, 4, 6
	//ADC1_IN16 DATA will be in the odd index: 1, 3, 5, 7
	//The Semaphore will be given from ADC ISR.
	uint32_t data = 0;
	uint32_t vdata_in15 = 0;
	uint32_t vdata_in16 = 0;

	for (int i = 0; i < (ADC1_MAX_CHANNEL * ADC1_MAX_BUFFER); i++) {
		//need to get first half of data
		data = ADC1_BUFFER[i];
		if (i % 2 == 0) //even index
				{
			//Data for IN15
			vdata_in15 += (data);
		} else //odd index
		{
			//Data for IN16
			vdata_in16 += (data);
		}
	}
	vdata_in15 = ADC1_Convert_Data_To_V(vdata_in15 / 4);
	vdata_in16 = ADC1_Convert_Data_To_V(vdata_in16 / 4);
	osMessageQueuePut(GetQueueHandleByName(ADC1_IN15_QUEUE_NAME), (void*) &vdata_in15, 0, 0);
	osMessageQueuePut(GetQueueHandleByName(ADC1_IN15_QUEUE_NAME), (void*) &vdata_in16, 0, 0);
}

void I2C_ReadVoutPutToQueue()
{
	uint16_t vout = I2C_Read_Vout_Target_mV();
	osMessageQueuePut(GetQueueHandleByName(I2C_VOUT_QUEUE_NAME), (void*) &vout, 0, 0);
}




