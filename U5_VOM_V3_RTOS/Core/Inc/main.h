/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32u5xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "z_displ_ILI9XXX.h"


/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

#define ADC1_USED_CHANNEL 2
extern uint16_t ADC1_VAL[ADC1_USED_CHANNEL];

extern int32_t temp_sense;
extern int32_t in1_diff_voltage;

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */
void Setup_LCD_TouchGFX();
/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define DISPL_LED_Pin GPIO_PIN_0
#define DISPL_LED_GPIO_Port GPIOA
#define DISPL_RST_Pin GPIO_PIN_3
#define DISPL_RST_GPIO_Port GPIOA
#define LED_GREEN_Pin GPIO_PIN_5
#define LED_GREEN_GPIO_Port GPIOA
#define DISPL_DC_Pin GPIO_PIN_8
#define DISPL_DC_GPIO_Port GPIOA
#define LED_INDICATOR_Pin GPIO_PIN_4
#define LED_INDICATOR_GPIO_Port GPIOB
#define DISPL_CS_Pin GPIO_PIN_8
#define DISPL_CS_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */
extern SPI_HandleTypeDef hspi1;
extern DMA_HandleTypeDef handle_GPDMA1_Channel11;
//extern uint8_t spiDmaTransferComplete;
extern TIM_HandleTypeDef htim3;
extern uint8_t update_ui;

#define CS_L() HAL_GPIO_WritePin(DISPL_CS_GPIO_Port, DISPL_CS_Pin, GPIO_PIN_RESET)
#define CS_H() HAL_GPIO_WritePin(DISPL_CS_GPIO_Port, DISPL_CS_Pin, GPIO_PIN_SET)
#define DC_L() HAL_GPIO_WritePin(DISPL_DC_GPIO_Port, DISPL_DC_Pin, GPIO_PIN_RESET)
#define DC_H() HAL_GPIO_WritePin(DISPL_DC_GPIO_Port, DISPL_DC_Pin, GPIO_PIN_SET)
#define RST_L() HAL_GPIO_WritePin(DISPL_RST_GPIO_Port, DISPL_RST_Pin, GPIO_PIN_RESET)
#define RST_H() HAL_GPIO_WritePin(DISPL_RST_GPIO_Port, DISPL_RST_Pin, GPIO_PIN_SET)
#define LED_H() HAL_GPIO_WritePin(DISPL_LED_GPIO_Port, DISPL_LED_Pin, GPIO_PIN_SET)
#define LED_L() HAL_GPIO_WritePin(DISPL_LED_GPIO_Port, DISPL_LED_Pin, GPIO_PIN_RESET)


/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
