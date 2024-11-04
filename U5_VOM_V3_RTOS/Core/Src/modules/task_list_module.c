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

#define TASK_COUNT_MAX 					(2)

#define TASK_INPUT_STACK_SIZE 	(128*4)
#define TASK_INPUT_INTERVAL 		(1) //ms

#define TASK_GFX_STACK_SIZE 		(4096*4)
//need to feature out how to make it.
//Currently, it's set up by the SYNC TIMER, this define is for reading purpose only.
#define TASK_GFX_INTERVAL 			(40) //ms

void InputTask(void *argument);
extern void TouchGFX_Task(void* argument);

const osThreadAttr_t TaskListAttr[TASK_COUNT_MAX] = {
		{.name = "InputTask", 		.priority = (osPriority_t) osPriorityNormal, 	.stack_size = TASK_INPUT_STACK_SIZE},
		{.name = "TouchGFXTask", 	.priority = (osPriority_t) osPriorityNormal,	.stack_size = TASK_GFX_STACK_SIZE},
};

const osThreadFunc_t TaskFuncList[TASK_COUNT_MAX] = {
		InputTask,
		TouchGFX_Task,
};

osThreadId_t TaskIdList[TASK_COUNT_MAX];

void peripherals_init()
{
	//Low level HAL init will be done in main.c
	//The Application level init will be done here.
	Setup_LCD_TouchGFX();

}
void InputTask(void *argument)
{

  /* Infinite loop */
	for(;;)
	{
		//Here we will process all input data, from ISR.
		ADC1_ReadDataFromDMABuffer();
		osDelay(TASK_INPUT_INTERVAL);
	}
}

void init_tasks()
{

	//Set up all peripherals before handover to RTOS tasks.
	peripherals_init();
	ADC1_Init_DMA();
	initQueues();
	for(int i = 0; i < TASK_COUNT_MAX ; i++)
	{
		TaskIdList[i] = osThreadNew(TaskFuncList[i], NULL, (void *)&TaskListAttr[i]);
		if(TaskIdList[i] == NULL)
		{
			Error_Handler();
		}
	}
}




