/*
 * modules.h
 *
 *  Created on: Nov 4, 2024
 *      Author: Admin
 */

#ifndef INC_MODULES_MODULES_H_
#define INC_MODULES_MODULES_H_
#include "main.h"


//Semaphore Section
typedef enum {
	ADC_HALF_COMPLETE_SEM = 0,
	ADC_COMPLETE_SEM = 1,
	UI_QUEUE_EMPTY_SEM = 2,

} MySemaphoreName_t;
void InitSemaphore();
uint8_t TakeSemaphoreByName(MySemaphoreName_t semName);
uint8_t GiveSemaphoreFromISRByName(MySemaphoreName_t semName);
uint8_t GiveSemaphoreByName(MySemaphoreName_t semName);
//End Semaphore Section

//ADC CONFIG SECTION
#define ADC1_MAX_CHANNEL 	(2)
#define ADC1_MAX_BUFFER 	(4)
extern uint16_t ADC1_BUFFER[ADC1_MAX_CHANNEL*ADC1_MAX_BUFFER];
void Init_Tasks();
void ADC1_Start_DMA_Conv();
void ADC1_Calibration();
uint16_t ADC1_Convert_Data_To_V(uint16_t data);
//END ADC CONFIG SECTION

//I2C SECTION
void I2C_Device_Init();
uint16_t I2C_Read_Vout_Target_mV();
void I2C_ClearFaults();
//END I2C SECTION

//ROTARY SWITCH SECTION
uint32_t RS_Read_Counter(void);
void RS_Init();
//END ROTARY SWITCH SECTION

//Queue SECTION
void initQueues();
void FeedDataToQueueFromADC_DMABuffer();
int ADC1_IN15_ReadDataFromQueue();
int ADC1_IN16_ReadDataFromQueue();
void I2C_ReadVoutPutToQueue();
//End Queue SECTION

#endif /* INC_MODULES_MODULES_H_ */
