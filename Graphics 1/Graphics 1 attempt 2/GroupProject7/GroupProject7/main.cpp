#include "RasterFunctions.h"
#include "RasterSurface.h"
#include "XTime.h"
#include "Images\1_Helicopter.h"

#define HELI_ARRAY _1_Helicopter_pixels


void main() {

	unsigned int *screenArray;
	screenArray = new unsigned int[SCREEN_SIZE];
	RS_Initialize(SCREEN_WIDTH, SCREEN_HEIGHT);



	Vector *pixelSurfaceNormals;
	pixelSurfaceNormals = new Vector[_1_Helicopter_numpixels];
	//Make surface normals
	for (int i = 0; i < _1_Helicopter_numpixels; i++)
	{
		unsigned int currentColor =BGRAtoARGB( HELI_ARRAY[i]);
		unsigned int currentRed = (currentColor & 0x00ff0000) >> 16;
		unsigned int currentGreen = (currentColor & 0x0000ff00) >> 8;
		unsigned int currentBlue = (currentColor & 0x000000ff);

		float xRatio = (float)currentRed / 255.0f;
		float yRatio = (float)currentGreen / 255.0f;
		float zRatio = (float)currentBlue / 255.0f * -0.1f;
		pixelSurfaceNormals[i] = NormalizeVector(Vector(xRatio, yRatio, zRatio, 1.0f));

	}

	//Make the light ratios
	float LightRatios[_1_Helicopter_numpixels];
	for (int i = 0; i < _1_Helicopter_numpixels; i++)
	{
		LightRatios[i] = DotProduct(Vector(0.333, 0.333, -0.333, 1.0f), pixelSurfaceNormals[i]);
		if (LightRatios[i] < 0)
			LightRatios[i] = 0.0f;
		if (LightRatios[i] > 1)
			LightRatios[i] = 1.0f;
	}

	for (int i = 0; i < SCREEN_SIZE; i++)
	{
		unsigned int ratioChannel = LightRatios[i] * 255.0f;
		unsigned int ratioColor = ConvertColorRGBA(ratioChannel, ratioChannel, ratioChannel, ratioChannel);

		screenArray[i] = ModulateColor(ratioColor, ModulateColor(ConvertColorRGBA(187, 245, 45, 255), ConvertColorRGBA(255, 255, 255, 255)));
	}

	while (RS_Update(screenArray, SCREEN_SIZE)) {
		ClearScreen(screenArray, SCREEN_SIZE, 0x0);
		for (int i = 0; i < SCREEN_SIZE; i++)
		{
			unsigned int ratioChannel = LightRatios[i] * 255.0f;
			unsigned int ratioColor = ConvertColorRGBA(ratioChannel, ratioChannel, ratioChannel, ratioChannel);

			screenArray[i] = ModulateColor(ratioColor, ModulateColor(ConvertColorRGBA(187, 245, 45, 255), ConvertColorRGBA(255, 255, 255, 255)));
		}

	/*	for (int i = 0; i < SCREEN_SIZE; i++)
		{
			screenArray[i] = BGRAtoARGB(HELI_ARRAY[i]);
		}*/

	}

	


	RS_Shutdown();
	delete[] pixelSurfaceNormals;
	delete[] screenArray;




}