/*
 * lm51772_i2c.c
 *
 *  Created on: Nov 1, 2024
 *      Author: Admin
 */
#include "lm51772_i2c.h"
#include "main.h"
extern I2C_HandleTypeDef hi2c1;

void LM51772_Error_Handler(void)
{
  __disable_irq();
	while (1) {
	}
}
void LM51772_ClearFaults()
{
	uint8_t pData;
	//Perform a Read to LM51772_CLEAR_FAULTS to make a Faults Clear.
	if(HAL_OK != HAL_I2C_Mem_Read(&hi2c1, LM51772_I2C_ADDR, LM51772_CLEAR_FAULTS, 1, &pData, 1, 0))
	{
		LM51772_Error_Handler();
	}
}

//Read the Status Byte: Busy bit 7.
//return 0; ready
//return 1; busy
uint8_t LM51722_Device_Ready()
{
		uint8_t pData;
		//Perform a Read to LM51772_CLEAR_FAULTS to make a Faults Clear.
		if(HAL_OK != HAL_I2C_Mem_Read(&hi2c1, LM51772_I2C_ADDR, LM51772_STATUS_BYTE, 1, &pData, 1, 0))
		{
			LM51772_Error_Handler();
		}
		if(pData == LM51722_STATUS_BYTE_BUSY)
		{
			return 1;
		}
		else {
			return 0;
		}
}

uint16_t LM51722_Read_Vout_Target_mV()
{
		uint8_t VoutLSB = 0;
		uint8_t VoutMSB = 0;
		uint16_t Vout = 0;

		if(HAL_OK != HAL_I2C_Mem_Read(&hi2c1, LM51772_I2C_ADDR, LM51772_VOUT_TARGET1_LSB, 1, &VoutLSB, 1, 0))
		{
			LM51772_Error_Handler();
		}
		if(HAL_OK != HAL_I2C_Mem_Read(&hi2c1, LM51772_I2C_ADDR, LM51772_VOUT_TARGET1_MSB, 1, &VoutMSB, 1, 0))
		{
			LM51772_Error_Handler();
		}
		Vout = (VoutLSB + ((VoutMSB & 0x0f) << 8))*LM51722_VOUT_STEP_SIZE; //mV
		return Vout;
}



