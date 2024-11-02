#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#ifndef SIMULATOR
#include "main.h"
#include "app_freertos.h"
#endif
Model::Model() : modelListener(0)
{

}

void Model::tick()
{
#ifndef SIMULATOR
	modelListener->updateVolt(0);
	modelListener->updateTemp(0);
#endif

}
