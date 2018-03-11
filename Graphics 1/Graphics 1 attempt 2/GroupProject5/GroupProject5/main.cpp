#include "RasterFunctions.h"
#include "RasterSurface.h"
#include "Images\3_Human.h"
#include "Images\4_Castle.h"




#define HUMAN_PIXELS _3_Human_pixels
#define CASTLE_PIXELS _4_Castle_pixels







void main() {
	unsigned int* screenArray;
	screenArray = new unsigned int[SCREEN_SIZE];
	RS_Initialize(SCREEN_WIDTH, SCREEN_HEIGHT);
	float* zBuffer;
	zBuffer = new float[SCREEN_SIZE];

	for (int i = 0; i < SCREEN_SIZE; i++)
	{
		zBuffer[i] = 1000.0f;
	}

	//for (unsigned int i = 0; i < SCREEN_SIZE; i++)
	//{
	//	screenArray[i] = _3_Human_pixels[i];
	//	screenArray[i] = _4_Castle_pixels[i];
	//}

	while (RS_Update(screenArray, SCREEN_SIZE))
	{
		ClearScreen(screenArray, SCREEN_SIZE, 0x0);

		for (int i = 0; i < SCREEN_SIZE; i++)
		{
			zBuffer[i] = 1000.0f;
		}

		for (unsigned int i = 0; i < SCREEN_SIZE; i++)
		{
			float depth = (float)((HUMAN_PIXELS[i] & 0x0000ff00) >> 8);
			PaintPixel(
				screenArray,
				i,
				ModulateColor(HUMAN_PIXELS[i], ConvertColorRGBA(210, 162, 26, 255)),
				depth,
				zBuffer,
				SCREEN_SIZE);
		}
		for (unsigned int i = 0; i < SCREEN_SIZE; i++)
		{
			float depth = (float)((CASTLE_PIXELS[i] & 0x0000ff00) >> 8);
			PaintPixel(screenArray, i, ModulateColor(CASTLE_PIXELS[i], ConvertColorRGBA(181, 222, 94, 255)), depth, zBuffer, SCREEN_SIZE);
		}
	}




	RS_Shutdown();
	delete[] screenArray;
}