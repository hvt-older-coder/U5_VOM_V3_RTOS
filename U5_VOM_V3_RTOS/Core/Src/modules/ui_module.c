/*
 * ui_module.c
 *
 *  Created on: Nov 4, 2024
 *      Author: Admin
 *      This module contain all the TouchGFX & LCD related function & init code: inlude Sync Timer & SPI.
 */

#include "modules.h"
#include "FreeRTOS.h"
#include "semphr.h"
#include "task.h"
#include "main.h"
#include "cmsis_os2.h"
//
//int UI_GetADC1_IN16_Data()
//{
//	return ADC1_IN15_ReadDataFromQueue();
//}
