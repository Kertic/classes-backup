
#include "GraphicsFunctions.h"
#include "RasterSurface.h"
#include <math.h>
#include <random>
#include <time.h>
#include <windows.h>


#define SCREEN_PIXEL_SIZE 302500
#define STAR_COUNT 2500




void main() {
	unsigned int dimXorY = (unsigned int)sqrt(SCREEN_PIXEL_SIZE);
	RS_Initialize(dimXorY, dimXorY);
	unsigned int* screenArray;
	screenArray = new unsigned int[SCREEN_PIXEL_SIZE];
	

	srand(time(NULL));
	ClearBuffer(screenArray, SCREEN_PIXEL_SIZE);
#pragma region Stars generation

	//Make all the pixels black
	for (unsigned int i = 0; i < SCREEN_PIXEL_SIZE; i++)
	{
		SetPixel(screenArray,SCREEN_PIXEL_SIZE,  i, 0, 0, 0, 255);
	}

#define STARS x

#ifdef STARS

	for (unsigned int i = 0; i < STAR_COUNT; i++)
	{
		int randX = rand() % dimXorY;
		int randY = rand() % dimXorY;
		SetPixel(screenArray, SCREEN_PIXEL_SIZE, To1d(randX, randY, dimXorY, dimXorY), 255, 255, 255, 255);
	}
#endif

#pragma endregion




#pragma region Parametric line generation
	DrawLineParametric(20, 519, 120, 420, screenArray, SCREEN_PIXEL_SIZE, dimXorY, dimXorY, 255, 0, 255, 255, 0, 255, 255, 255);




	
#pragma endregion

#pragma region Bresenham Line Generation
	DrawLineBresenham(0, 499, 100, 400, screenArray, SCREEN_PIXEL_SIZE, dimXorY, dimXorY, 255, 0, 0, 255);

	SetPixel(screenArray, SCREEN_PIXEL_SIZE, To1d(0, 100, dimXorY, dimXorY), 0xffffffff);
	SetPixel(screenArray, SCREEN_PIXEL_SIZE, To1d(499, 400, dimXorY, dimXorY), 0xffffffff);
#pragma endregion


	int x1a = 0;
	int x2a = 499;
	int y1a = 100;
	int y2a = 400;

	int x1b = 0;
	int x2b = 499;
	int y1b = 110;
	int y2b = 410;

	/*int x1b = 538;
	int x2b = 505;
	int y1b = 307;
	int y2b = 354;*/

	int x1c = 0;
	int x2c = 499;
	int y1c = 120;
	int y2c = 420;
	while (RS_Update(screenArray, SCREEN_PIXEL_SIZE)) {
		ClearBuffer(screenArray, SCREEN_PIXEL_SIZE);
		DrawLineParametric(0, 499, 120, 420, screenArray, SCREEN_PIXEL_SIZE, dimXorY, dimXorY, 255, 0, 255, 255, 0, 255, 255, 255);
		DrawLineBresenham(0, 499, 100, 400, screenArray, SCREEN_PIXEL_SIZE, dimXorY, dimXorY, 255, 0, 0, 255);
		DrawLineMidpoint(0, 499, 110, 410, screenArray, SCREEN_PIXEL_SIZE, dimXorY, dimXorY, 255, 255, 0, 255);


		DrawLineBresenham(x1a, x2a, y1a, y2a, screenArray, SCREEN_PIXEL_SIZE, dimXorY, dimXorY, 255, 0, 0, 255);
		DrawLineMidpoint(x1b, x2b, y1b, y2b, screenArray, SCREEN_PIXEL_SIZE, dimXorY, dimXorY, 255, 255, 0, 255);
		DrawLineParametric(x1c, x2c, y1c, y2c, screenArray, SCREEN_PIXEL_SIZE, dimXorY, dimXorY, 255, 0, 255, 255, 0, 255, 255, 255);

		SetPixel(screenArray, SCREEN_PIXEL_SIZE, To1d(x1a, y1a, dimXorY, dimXorY), 0xffffff00);
		SetPixel(screenArray, SCREEN_PIXEL_SIZE, To1d(x2a, y2a, dimXorY, dimXorY), 0xff00ff00);

		SetPixel(screenArray, SCREEN_PIXEL_SIZE, To1d(x1b, y1b, dimXorY, dimXorY), 0xffffff00);
		SetPixel(screenArray, SCREEN_PIXEL_SIZE, To1d(x2b, y2b, dimXorY, dimXorY), 0xff00ff00);

		SetPixel(screenArray, SCREEN_PIXEL_SIZE, To1d(x1c, y1c, dimXorY, dimXorY), 0xffffff00);
		SetPixel(screenArray, SCREEN_PIXEL_SIZE, To1d(x2c, y2c, dimXorY, dimXorY), 0xff00ff00);

		if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
			x1a = rand() % dimXorY;
			x2a = rand() % dimXorY;
			y1a = rand() % dimXorY;
			y2a = rand() % dimXorY;

			x1b = rand() % dimXorY;
			x2b = rand() % dimXorY;
			y1b = rand() % dimXorY;
			y2b = rand() % dimXorY;

			x1c = rand() % dimXorY;
			x2c = rand() % dimXorY;
			y1c = rand() % dimXorY;
			y2c = rand() % dimXorY;
		}
	}

	RS_Shutdown();

	delete[] screenArray;


}



