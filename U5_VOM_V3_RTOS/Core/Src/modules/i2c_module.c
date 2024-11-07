/*
 * i2c_module.c
 *
 *  Created on: Nov 4, 2024
 *      Author: Admin
 *      This module handles all I2C related function
 */
#include "lm51772_i2c.h"
#include "main.h"
#include "modules.h"

void I2C_Device_Init()
{
	//check device ready.
	if(LM51722_Device_Ready() == 0)
	{
		//Ready to go.
	}
}

uint16_t I2C_Read_Vout_Target_mV()
{
	return LM51722_Read_Vout_Target_mV();
}

void I2C_ClearFaults()
{
	LM51772_ClearFaults();
}

