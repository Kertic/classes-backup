
#include "RasterSurface.h"
#include "GraphicsFunctions.h"
#include <math.h>
#include <assert.h>




#define SCREEN_ARRAY_WIDTH 400
#define SCREEN_ARRAY_HEIGHT 300
#define SCREEN_ARRAY_SIZE SCREEN_ARRAY_WIDTH * SCREEN_ARRAY_HEIGHT

//void DrawLineParametric(int _x1, int _x2, int _y1, int _y2, unsigned int* _pixelArray, unsigned int _pixelArraySize, unsigned int _red, unsigned int _green, unsigned int _blue, unsigned int _alpha);


void main() {

	RS_Initialize(400, 300);

	unsigned int* screenArray;
	screenArray = new unsigned int[SCREEN_ARRAY_SIZE];

	//ClearBuffer(screenArray, SCREEN_ARRAY_SIZE);
	for (unsigned int i = 0; i < SCREEN_ARRAY_SIZE; i++)
	{
		screenArray[i] = 0;
	}


	DrawLineParametric(258, 83, 240, 109, screenArray, SCREEN_ARRAY_SIZE, SCREEN_ARRAY_WIDTH, SCREEN_ARRAY_HEIGHT, 222, 214, 122, 255);

	SetPixel(screenArray, To1d(258, 240, SCREEN_ARRAY_WIDTH, SCREEN_ARRAY_HEIGHT), 0xffffffff);
	SetPixel(screenArray, To1d(83, 109, SCREEN_ARRAY_WIDTH, SCREEN_ARRAY_HEIGHT), 0xffffffff);

	while (RS_Update(screenArray, SCREEN_ARRAY_SIZE)) {


	}

	RS_Shutdown();

	delete[] screenArray;

}


//void DrawLineParametric(int _x1, int _x2, int _y1, int _y2, unsigned int* _pixelArray, unsigned int _pixelArraySize , unsigned int _red, unsigned int _green, unsigned int _blue, unsigned int _alpha) {
//
//	//True would mean x axis, false means y axis
//	bool primAxis = false;
//	bool secAxis = false;
//
//	if (abs(_x2 - _x1) > abs(_y2 - _y1)) {//If the x distance is longer
//		primAxis = true;//X is the primary axis
//	}
//	else {
//		secAxis = true;//X is the secondary axis
//	}
//
//	if (primAxis == secAxis) 
//		assert(false);
//	
//	
//	//int magnitude = (int)sqrt(((_y2 - _y1) * (_y2 - _y1)) + ((_x2 - _x1) * (_x2 - _x1)));
//	int startPrimary = 0;
//	int endPrimary = 0;
//
//	int startSecondary = 0;
//	int endSecondary = 0;
//#pragma region X is the primary axis
//	if (primAxis) {
//		startPrimary = _x1;
//		endPrimary = _x2;
//
//		startSecondary = _y1;
//		endSecondary = _y2;
//	}
//
//#pragma endregion
//
//#pragma region Y is the primary axis
//	if (secAxis) {
//		startPrimary = _y1;
//		endPrimary = _y2;
//
//		startSecondary = _x1;
//		endSecondary = _x2;
//	}
//#pragma endregion
//
//	if (startPrimary < endPrimary) {
//		for (int i = startPrimary; i < endPrimary; i++)
//		{
//			float ratio = ((float)i - (float)startPrimary) / ((float)endPrimary - (float)startPrimary);
//			float currY = Lerp(startSecondary, endSecondary, ratio);
//			SetPixel(_pixelArray, To1d(i, (int)(currY + 0.5f), SCREEN_ARRAY_WIDTH, SCREEN_ARRAY_HEIGHT), _red, _blue, _green, _alpha);
//		}
//	}
//	else {
//
//		for (int i = startPrimary; i > endPrimary; i--)
//		{
//			float ratio = ((float)i - (float)startPrimary) / ((float)endPrimary - (float)startPrimary);
//			float currY = Lerp(endSecondary, startSecondary, ratio);
//			SetPixel(_pixelArray, To1d(i, (int)(currY + 0.5f), SCREEN_ARRAY_WIDTH, SCREEN_ARRAY_HEIGHT), _red, _blue, _green, _alpha);
//		}
//	}
//
//}

