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

	memset((void*)textAreaTempBuffer, 0, TEXTAREATEMP_SIZE*2);

	Unicode::snprintf(textAreaTempBuffer,TEXTAREATEMP_SIZE, "%d", val);
	if(val > 100)
	{
		textAreaTemp.invalidate();
	}
	textAreaTemp.invalidate();

}
void Screen1View::updateVolt(unsigned int val)
{
	//update ui.
	memset((void*)textAreaVoltBuffer, 0, TEXTAREAVOLT_SIZE*2);
	Unicode::snprintf(textAreaVoltBuffer,TEXTAREAVOLT_SIZE, "%d", val);
	textAreaVolt.invalidate();

}

