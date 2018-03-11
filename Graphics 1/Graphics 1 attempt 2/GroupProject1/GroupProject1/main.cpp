#include "RasterSurface.h"
#include "RasterFunctions.h"

#define SCREEN_WIDTH 500
#define SCREEN_HEIGHT 500
#define SCREEN_SIZE SCREEN_WIDTH * SCREEN_HEIGHT





void main() {
	int x = SCREEN_SIZE;
	unsigned int* screenArray;
	screenArray = new unsigned int[SCREEN_SIZE];

	RS_Initialize(SCREEN_WIDTH, SCREEN_HEIGHT);

	ClearScreen(screenArray, SCREEN_SIZE, ConvertColorRGBA(0, 0, 0, 128));

	
		
	PaintPixel(screenArray,
		From2Dto1D(238, 123, 0, 0, 500, 500),
		ConvertColorRGBA(236, 140, 222, 255));
	PaintPixel(screenArray,
		From2Dto1D(239, 123, 0, 0, 500, 500),
		ConvertColorRGBA(236, 140, 222, 255));
	PaintPixel(screenArray,
		From2Dto1D(237, 123, 0, 0, 500, 500),
		ConvertColorRGBA(236, 140, 222, 255));

	PaintPixel(screenArray,
		From2Dto1D(238, 122, 0, 0, 500, 500),
		ConvertColorRGBA(236, 140, 222, 255));
	PaintPixel(screenArray,
		From2Dto1D(239, 122, 0, 0, 500, 500),
		ConvertColorRGBA(236, 140, 222, 255));
	PaintPixel(screenArray,
		From2Dto1D(237, 122, 0, 0, 500, 500),
		ConvertColorRGBA(236, 140, 222, 255));

	PaintPixel(screenArray,
		From2Dto1D(238, 124, 0, 0, 500, 500),
		ConvertColorRGBA(236, 140, 222, 255));
	PaintPixel(screenArray,
		From2Dto1D(239, 124, 0, 0, 500, 500),
		ConvertColorRGBA(236, 140, 222, 255));
	PaintPixel(screenArray,
		From2Dto1D(237, 124, 0, 0, 500, 500),
		ConvertColorRGBA(236, 140, 222, 255));



	
	while (RS_Update(screenArray, SCREEN_SIZE)) {

	}


	RS_Shutdown();
	delete[] screenArray;

}