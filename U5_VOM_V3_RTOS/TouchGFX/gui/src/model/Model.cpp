#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#ifndef SIMULATOR
extern "C"
{
	#include "main.h"
	//#include "app_freertos.h"
	#include "modules.h"
}
#endif
Model::Model() : modelListener(0)
{

}

void Model::tick()
{
#ifndef SIMULATOR
	int ret = UI_GetADC1_IN16_Data();
	if(ret != -1)
	{
		modelListener->updateVolt(ret);
	}

	//modelListener->updateTemp(0);
#endif

}
