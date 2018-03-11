#include "RasterFunctions.h"
#include "RasterSurface.h"
#include <random>
#include <time.h>
#include <Windows.h>


#define RANDOMINTSLENGTH 2500

#define STARS

/*
Test Cases:

deltax > deltay ; slope > 0; primary delta is negitive - (200,100) and (100, 50)
deltax > deltay ; slope > 0; primary delta is positive - (100, 50) and (200,100)
deltax > deltay ; slope < 0; primary delta is negitive - (200,100) and (100,150)
deltax > deltay ; slope < 0; primary delta is positive - (100,150) and (200,100)
deltax < deltay ; slope > 0; primary delta is negitive - (100, 200) and (50, 100)
deltax < deltay ; slope > 0; primary delta is positive - (50,100) and (100, 200)
deltax < deltay ; slope < 0; primary delta is negitive - (50,200) and (100, 100)
deltax < deltay ; slope < 0; primary delta is positive - (100, 100) and (50, 200)
*/


void main() {
	RS_Initialize(SCREEN_HEIGHT, SCREEN_WIDTH);
	unsigned int* screenArray;
	screenArray = new unsigned int[SCREEN_SIZE];


	srand((unsigned int)time(NULL));

#pragma region Setting up star positions




	unsigned int randomInts1[RANDOMINTSLENGTH] = {};
	unsigned int randomInts2[RANDOMINTSLENGTH] = {};

	for (unsigned int i = 0; i < RANDOMINTSLENGTH; i++)
		randomInts1[i] = rand() % SCREEN_WIDTH;

	for (unsigned int i = 0; i < RANDOMINTSLENGTH; i++)
		randomInts2[i] = rand() % SCREEN_HEIGHT;
#pragma endregion

#pragma region Setting up random line positions
	//Indexes 0 and 1 are for start and end of the first draw, 2 and 3 for the 2nd draw, 4 and 5 for the third draw

	int randX1[] = { rand() % SCREEN_WIDTH, rand() % SCREEN_WIDTH , rand() % SCREEN_WIDTH, rand() % SCREEN_WIDTH, rand() % SCREEN_WIDTH , rand() % SCREEN_WIDTH };
	int randY1[] = { rand() % SCREEN_WIDTH, rand() % SCREEN_WIDTH , rand() % SCREEN_WIDTH, rand() % SCREEN_WIDTH, rand() % SCREEN_WIDTH , rand() % SCREEN_WIDTH };
	int* randX = &randX1[0];
	int* randY = &randY1[0];

#pragma endregion

	bool pressed = false;
	while (RS_Update(screenArray, SCREEN_SIZE)) {

		ClearScreen(screenArray, SCREEN_SIZE, 0x00000000);


#ifdef STARS

		for (unsigned int i = 0; i < RANDOMINTSLENGTH; i++)
		{
			PaintPixel(screenArray, From2Dto1D(randomInts1[i], randomInts2[i], 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT), 0xffffffff);
		}

#endif // STARS

		//DrawBresenhamLine(200, 100, 100, 50, screenArray, SCREEN_SIZE, ConvertColorRGBA(255, 0, 0, 255));
		//DrawBresenhamLine(100, 50, 200, 100, screenArray, SCREEN_SIZE, ConvertColorRGBA(255, 0, 0, 255));
		//DrawBresenhamLine(200, 100, 100, 150, screenArray, SCREEN_SIZE, ConvertColorRGBA(255, 0, 0, 255));
		//DrawBresenhamLine(100, 150, 200, 100, screenArray, SCREEN_SIZE, ConvertColorRGBA(255, 0, 0, 255)); 
		//DrawBresenhamLine(100, 200, 50, 100, screenArray, SCREEN_SIZE, ConvertColorRGBA(255, 0, 0, 255));
		//DrawBresenhamLine(50, 100, 100, 200, screenArray, SCREEN_SIZE, ConvertColorRGBA(255, 0, 0, 255));
		//DrawBresenhamLine(50, 200, 100, 100, screenArray, SCREEN_SIZE, ConvertColorRGBA(255, 0, 0, 255));
		//DrawBresenhamLine(100, 100, 50, 200, screenArray, SCREEN_SIZE, ConvertColorRGBA(255, 0, 0, 255)); 

		//DrawMidpointLine(200, 100, 100, 50, screenArray, SCREEN_SIZE, ConvertColorRGBA(255, 0, 0, 255));
		//DrawMidpointLine(100, 50, 200, 100, screenArray, SCREEN_SIZE, ConvertColorRGBA(255, 0, 0, 255)); // incorrect
		//DrawMidpointLine(200, 100, 100, 150, screenArray, SCREEN_SIZE, ConvertColorRGBA(255, 0, 0, 255));
		//DrawMidpointLine(100, 150, 200, 100, screenArray, SCREEN_SIZE, ConvertColorRGBA(255, 0, 0, 255)); // incorrect
		//DrawMidpointLine(100, 200, 50, 100, screenArray, SCREEN_SIZE, ConvertColorRGBA(255, 0, 0, 255)); // incorrect
		//DrawMidpointLine(50, 100, 100, 200, screenArray, SCREEN_SIZE, ConvertColorRGBA(255, 0, 0, 255));
		//DrawMidpointLine(50, 200, 100, 100, screenArray, SCREEN_SIZE, ConvertColorRGBA(255, 0, 0, 255)); // incorrect
		//DrawMidpointLine(100, 100, 50, 200, screenArray, SCREEN_SIZE, ConvertColorRGBA(255, 0, 0, 255)); // incorrect

		DrawBresenhamLine(0, 100, 499, 400, screenArray, SCREEN_SIZE, 0xffff0000);
		DrawMidpointLine(0, 90, 499, 390, screenArray, SCREEN_SIZE, 0xff00ff00);
		DrawParametricLineGradiantColor(0, 80, 499, 380, screenArray, SCREEN_SIZE,
			255, 255, 0, 255,
			0, 255, 255, 255);

		DrawBresenhamLine(randX[0], randY[0], randX[1], randY[1], screenArray, SCREEN_SIZE, 0xffff0000);
		DrawMidpointLine(randX[2], randY[2], randX[3], randY[3], screenArray, SCREEN_SIZE, 0xff00ff00);
		DrawParametricLineGradiantColor(randX[4], randY[4], randX[5], randY[5], screenArray, SCREEN_SIZE,
			255, 255, 0, 255,
			0, 255, 255, 255);

		if (pressed == false && GetAsyncKeyState(VK_SPACE)) {
			int randX2[] = { rand() % SCREEN_WIDTH, rand() % SCREEN_WIDTH , rand() % SCREEN_WIDTH, rand() % SCREEN_WIDTH, rand() % SCREEN_WIDTH , rand() % SCREEN_WIDTH };
			int randY2[] = { rand() % SCREEN_WIDTH, rand() % SCREEN_WIDTH , rand() % SCREEN_WIDTH, rand() % SCREEN_WIDTH, rand() % SCREEN_WIDTH , rand() % SCREEN_WIDTH };
			randX = &randX2[0];
			randY = &randY2[0];
			pressed = true;
		}

		if (GetAsyncKeyState(VK_SPACE))
			pressed = true;
		else
			pressed = false;
	

	}

	RS_Shutdown();
	delete[] screenArray;
}