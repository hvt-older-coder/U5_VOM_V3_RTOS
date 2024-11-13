/*
 * task_list.c
 *
 *  Created on: Nov 4, 2024
 *      Author: Admin
 */

#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os2.h"
#include "modules.h"

#define TASK_COUNT_MAX 					(3)

#define TASK_NORMAL_STACK_SIZE 	(128*4)

//The input task will run at 100Hz speed.
//x4 FPS from the LCD.
//100 sample in a second.
#define TASK_INPUT_INTERVAL_10MS 		(10) //ms
#define TASK_I2C_INTERVAL_50MS			(50)

#define TASK_GFX_STACK_SIZE 		(4096*4)
//need to feature out how to make it.
//Currently, it's set up by the SYNC TIMER, this define is for reading purpose only.
#define TASK_GFX_INTERVAL 			(40) //ms

void InputTask(void *argument);
void Peripherals_Init();
void I2CTask(void *argument);

//external
extern void TouchGFX_Task(void* argument);

const osThreadAttr_t TaskListAttr[TASK_COUNT_MAX] = {
		{.name = "InputTask", 		.priority = (osPriority_t) osPriorityNormal, 	.stack_size = TASK_NORMAL_STACK_SIZE},
		{.name = "TouchGFXTask", 	.priority = (osPriority_t) osPriorityAboveNormal,	.stack_size = TASK_GFX_STACK_SIZE},
		{.name = "I2CTask", 		.priority = (osPriority_t) osPriorityNormal, 	.stack_size = TASK_NORMAL_STACK_SIZE},
};

const osThreadFunc_t TaskFuncList[TASK_COUNT_MAX] = {
		InputTask,
		TouchGFX_Task,
		I2CTask,
};

osThreadId_t TaskIdList[TASK_COUNT_MAX];

void Init_Tasks()
{


	InitSemaphore();
	initQueues();
	//Set up all peripherals before handing over to RTOS tasks.
	Peripherals_Init();
	//Create all tasks.
	for(int i = 0; i < TASK_COUNT_MAX ; i++)
	{
		TaskIdList[i] = osThreadNew(TaskFuncList[i], NULL, (void *)&TaskListAttr[i]);
		if(TaskIdList[i] == NULL)
		{
			Error_Handler();
		}
	}
}

void Peripherals_Init()
{
	//Low level HAL init will be done in main.c
	//The Application level init will be done here.
	Setup_LCD_TouchGFX();
	ADC1_Calibration();

	//I2C_Device_Init();
}
void InputTask(void *argument)
{

  /* Infinite loop */
	for(;;)
	{
		//Periodically run : 10MS.
		ADC1_Start_DMA_Conv();

		//This got trigger from ADC_ISR.
		if (TakeSemaphoreByName(ADC_COMPLETE_SEM) == 1){
			FeedDataToQueueFromADC_DMABuffer();
		}

		//#define TASK_INPUT_INTERVAL_10MS 		(10) //ms
		//Sampling speed is 1/10ms = 100Hz = 100 sample/s.
		//ADC buffer is 4 half-word.
		//We will take average of it and display.
		//The FPS is 25 sample/s.
		osDelay(TASK_INPUT_INTERVAL_10MS);
	}
}

void I2CTask(void *argument)
{
  /* Infinite loop */
	for(;;)
	{
#if 0
		I2C_ReadVoutPutToQueue();
#endif
		osDelay(TASK_I2C_INTERVAL_50MS);
	}
}





