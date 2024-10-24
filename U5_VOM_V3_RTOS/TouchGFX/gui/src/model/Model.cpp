#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#ifndef SIMULATOR
#include "main.h"
#include "app_freertos.h"
#include <cmsis_os2.h>
extern "C" {
extern osMessageQueueId_t myQueueUIHandle;

}

#endif
Model::Model() :
		modelListener(0) {

}
int count_data = 0;
void Model::tick() {
#ifndef SIMULATOR
	int16_t val = 0;
	if (osMessageQueueGet(myQueueUIHandle, (void*) &val, 0, 0) == osOK) // if the message is read successfully
			{

		val = Adc_Convert_To_mV(val);
		modelListener->updateVolt(val);
	}
#endif

}
