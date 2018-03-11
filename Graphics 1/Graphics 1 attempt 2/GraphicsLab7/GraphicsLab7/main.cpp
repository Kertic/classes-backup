#include "RasterFunctions.h"
#include "RasterSurface.h"
#include "XTime.h"





int main() {
	unsigned int* screenArray;
	screenArray = new unsigned int[SCREEN_SIZE];
	float* zBuffer;
	zBuffer = new float[SCREEN_SIZE];
	ClearExponentialZBuffer(zBuffer, SCREEN_SIZE);
	RS_Initialize(SCREEN_WIDTH, SCREEN_HEIGHT);
	XTime timer;

	timer.Signal();

	
	while (RS_Update(screenArray, SCREEN_SIZE)) {
		ClearScreen(screenArray, SCREEN_SIZE, 0x0);
		ClearExponentialZBuffer(zBuffer, SCREEN_SIZE);



	}


	RS_Shutdown();
	delete[] screenArray;
	delete[] zBuffer;


}