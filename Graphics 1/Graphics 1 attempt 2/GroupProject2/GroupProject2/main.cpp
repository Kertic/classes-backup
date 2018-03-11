#include "RasterFunctions.h"
#include "RasterSurface.h"
#include <random>
#include <time.h>









void main() {
	RS_Initialize(SCREEN_HEIGHT, SCREEN_WIDTH);
	unsigned int* screenArray;
	screenArray = new unsigned int[SCREEN_SIZE];











	while (RS_Update(screenArray, SCREEN_SIZE)) {

		ClearScreen(screenArray, SCREEN_SIZE, 0x00000000);





		DrawBresenhamLine(358, 200, 207, 269, screenArray, SCREEN_SIZE, ConvertColorRGBA(145, 79, 55, 255));
	
		


	}

	RS_Shutdown();
	delete[] screenArray;
}