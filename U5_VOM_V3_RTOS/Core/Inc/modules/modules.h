/*
 * modules.h
 *
 *  Created on: Nov 4, 2024
 *      Author: Admin
 */

#ifndef INC_MODULES_MODULES_H_
#define INC_MODULES_MODULES_H_
#include "main.h"

//ADC CONFIG
#define ADC1_MAX_CHANNEL 	(2)
#define ADC1_MAX_BUFFER 	(32)

extern uint16_t ADC1_BUFFER[ADC1_MAX_CHANNEL*ADC1_MAX_BUFFER];

void init_tasks();
void ADC1_Init_DMA();
void initQueues();
void ADC1_Queue_ReleaseSemaphore(uint8_t sem_index);
void ADC1_ReadDataFromDMABuffer();
int ADC1_IN15_ReadDataFromQueue();
int UI_GetADC1_IN16_Data();




#endif /* INC_MODULES_MODULES_H_ */
