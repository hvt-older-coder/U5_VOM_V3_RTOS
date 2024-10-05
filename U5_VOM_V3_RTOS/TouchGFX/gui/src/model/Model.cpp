#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include "main.h"
#include "app_freertos.h"
Model::Model() : modelListener(0)
{

}

void Model::tick()
{
	//Get the temp value.
	UiData_t uiData;
	osMessageQueueGet(myUiDataQueueHandle, &uiData, 0, 10);
	if(uiData.Id == TEMP_VAL_ID)
	{

		modelListener->updateTemp(uiData.Data);
	}
	if(uiData.Id == V_VAL_ID)
	{
		modelListener->updateVolt(uiData.Data);
	}
}
