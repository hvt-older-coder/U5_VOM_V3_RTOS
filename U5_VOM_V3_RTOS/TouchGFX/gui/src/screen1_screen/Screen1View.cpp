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

//	memset((void*)textAreaTempBuffer, 0, TEXTAREATEMP_SIZE*2);
//
//	Unicode::snprintf(textAreaTempBuffer,TEXTAREATEMP_SIZE, "%d", val);
//
//	textAreaTemp.invalidate();
//
//	dynamicGraph2.addDataPoint((float)val);
//	dynamicGraph2.invalidate();
	//dynamicGraph1.clear();

}
int graph_point_count = 0;
void Screen1View::updateVolt(unsigned int val)
{
	//update ui.
	memset((void*)textAreaVoltBuffer, 0, TEXTAREAVOLT_SIZE*2);
	Unicode::snprintf(textAreaVoltBuffer,TEXTAREAVOLT_SIZE, "%d", val);
	textAreaVolt.invalidate();
	//3300 - 100
	//val - x
	float gval = ((float)val)/1000; //in V
	dynamicGraph1.addDataPoint(gval);
	dynamicGraph1.invalidate();

	if(graph_point_count++ == 200)
	{
		graph_point_count = 0;
		dynamicGraph1.clear();
		//dynamicGraph1.setScale(1000, true);, to change the scale of the graphic, to match with the input waveform freq.
		//For example, if the waveform freq = 10Khz, then the scale should be set for 1/(10Khz)/10, then 10 points will be display.

	}
}

