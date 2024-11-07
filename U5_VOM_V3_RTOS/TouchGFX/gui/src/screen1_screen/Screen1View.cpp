#include <gui/screen1_screen/Screen1View.hpp>

Screen1View::Screen1View()
{

}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();
}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}

void Screen1View::updateTemp(unsigned int val)
{
	//update ui.

	//memset((void*)textAreaTempBuffer, 0, TEXTAREATEMP_SIZE*2);

	//Unicode::snprintf(textAreaTempBuffer,TEXTAREATEMP_SIZE, "%d", val);

	//textAreaTemp.invalidate();
}
//static int point_count = 0;
void Screen1View::updateVolt(unsigned int val)
{
	//update ui.
	memset((void*)textAreaVoltBuffer, 0, TEXTAREAVOLT_SIZE*2);
	Unicode::snprintf(textAreaVoltBuffer,TEXTAREAVOLT_SIZE, "%d", val);
	textAreaVolt.invalidate();
	//3300 - 100
	//val - x
	if(count_point++ == dynamicGraph1.getMaxCapacity())
	{
		count_point = 0;
		dynamicGraph1.clear();
	}
	float gval = ((float)val)/1000; //in V
	dynamicGraph1.addDataPoint(gval);
	dynamicGraph1.invalidate();


}

