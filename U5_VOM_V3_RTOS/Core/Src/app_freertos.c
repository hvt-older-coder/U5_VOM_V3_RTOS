/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : app_freertos.c
  * Description        : FreeRTOS applicative file
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "app_freertos.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "main.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
/* Definitions for defaultTask */
osThreadId_t defaultTaskHandle;
const osThreadAttr_t defaultTask_attributes = {
  .name = "defaultTask",
  .priority = (osPriority_t) osPriorityNormal,
  .stack_size = 128 * 4
};
/* Definitions for TouchGFXTask */
osThreadId_t TouchGFXTaskHandle;
const osThreadAttr_t TouchGFXTask_attributes = {
  .name = "TouchGFXTask",
  .priority = (osPriority_t) osPriorityNormal,
  .stack_size = 4096 * 4
};
/* Definitions for mySendAdcTask */
osThreadId_t mySendAdcTaskHandle;
const osThreadAttr_t mySendAdcTask_attributes = {
  .name = "mySendAdcTask",
  .priority = (osPriority_t) osPriorityAboveNormal,
  .stack_size = 128 * 4
};
/* Definitions for myUiDataQueue */
osMessageQueueId_t myUiDataQueueHandle;
const osMessageQueueAttr_t myUiDataQueue_attributes = {
  .name = "myUiDataQueue"
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */
  /* creation of myUiDataQueue */
  myUiDataQueueHandle = osMessageQueueNew (10, sizeof(UiData_t), &myUiDataQueue_attributes);

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */
  /* creation of defaultTask */
  defaultTaskHandle = osThreadNew(StartDefaultTask, NULL, &defaultTask_attributes);

  /* creation of TouchGFXTask */
  TouchGFXTaskHandle = osThreadNew(TouchGFX_Task, NULL, &TouchGFXTask_attributes);

  /* creation of mySendAdcTask */
  mySendAdcTaskHandle = osThreadNew(StartSendAdcTask, NULL, &mySendAdcTask_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

}
/* USER CODE BEGIN Header_StartDefaultTask */
/**
* @brief Function implementing the defaultTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void *argument)
{
  /* USER CODE BEGIN defaultTask */
  /* Infinite loop */
	for(;;)
	{

		osDelay(10);
	}
  /* USER CODE END defaultTask */
}

/* USER CODE BEGIN Header_StartSendAdcTask */
/**
* @brief Function implementing the mySendAdcTask thread.
* @param argument: Not used
* @retval None
*/
unsigned int temp_val = 0xffffffff;
unsigned int temp_volt = 0xffffffff;
/* USER CODE END Header_StartSendAdcTask */
void StartSendAdcTask(void *argument)
{
  /* USER CODE BEGIN mySendAdcTask */
  /* Infinite loop */
  for(;;)
  {

#if 0
	  if(hADCxConvertedData_Temperature_DegreeCelsius != temp_val)
	  {
		  temp_val = hADCxConvertedData_Temperature_DegreeCelsius;
		  if(temp_val > 100)
		  {
			  HAL_Delay(1);
		  }
		  UiData_t newUiData;
		  newUiData.Id = TEMP_VAL_ID;
		  newUiData.Data = temp_val;
		  osMessageQueuePut(myUiDataQueueHandle, &newUiData, 0, 10);
	  }

	  if(uhADCxConvertedData_Voltage_mVolt != temp_volt)
	  {
		  temp_volt = uhADCxConvertedData_Voltage_mVolt;
		  UiData_t newUiData;
		  newUiData.Id = V_VAL_ID;
		  newUiData.Data = temp_volt;
		  osMessageQueuePut(myUiDataQueueHandle, &newUiData, 0, 10);

	  }
#endif
	  osDelay(300);
  }
  /* USER CODE END mySendAdcTask */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

