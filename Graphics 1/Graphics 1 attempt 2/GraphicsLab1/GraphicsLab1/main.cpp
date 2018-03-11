#include "RasterSurface.h"
#include "RasterFunctions.h"
#include "XTime.h"
#include <time.h>
#include <random>
#include "Images\Changed images\tiles_12.h"
#include"Images\Changed images\fire_01.h"



#define TOWNPIXELS tiles_12_pixels
#define FIREPIXELS fire_01_pixels



void main() {
	int x = SCREEN_SIZE;
	unsigned int* screenArray;
	screenArray = new unsigned int[SCREEN_SIZE];
	unsigned int* adjTownPixels;
	adjTownPixels = new unsigned int[tiles_12_height * tiles_12_width];
	unsigned int* adjFirePixels;
	adjFirePixels = new unsigned int[fire_01_height * fire_01_width];
	XTime timer;
	srand((unsigned int)time(NULL));

	for (unsigned int x = 0; x < tiles_12_width; x++)
	{
		for (unsigned int y = 0; y < tiles_12_height; y++)
		{
			adjTownPixels[From2Dto1D(x, y, 0, 0, tiles_12_width, tiles_12_height)] = BGRAtoARGB(TOWNPIXELS[From2Dto1D(x, y, 0, 0, tiles_12_width, tiles_12_height)]);

		}
	}

	for (unsigned int x = 0; x < fire_01_width; x++)
	{
		for (unsigned int y = 0; y < fire_01_height; y++)
		{
			adjFirePixels[From2Dto1D(x, y, 0, 0, fire_01_width, fire_01_height)] = BGRAtoARGB(FIREPIXELS[From2Dto1D(x, y, 0, 0, fire_01_width, fire_01_height)]);

		}
	}


	RS_Initialize(SCREEN_WIDTH, SCREEN_HEIGHT);




	PaintPixel(screenArray,
		From2Dto1D(250, 250, 0, 0, 500, 500),
		ConvertColorRGBA(255, 255, 255, 128));


	ClearScreen(screenArray, SCREEN_SIZE, ConvertColorRGBA(0, 0, 0, 128));
	Blit(screenArray, adjTownPixels, SCREEN_WIDTH, SCREEN_HEIGHT, tiles_12_width, tiles_12_height, 0, 0, tiles_12_width, tiles_12_height, 0, 0, tiles_12_width, tiles_12_height);




#pragma region DrawGrassTiles

	int totalPossibleTileX = SCREEN_WIDTH / (320 - 285);
	int totalPossibleTileY = SCREEN_HEIGHT / (162 - 124);

	for (int x = 0; x < totalPossibleTileX + 1; x++)
	{
		for (int y = 0; y < totalPossibleTileY + 1; y++)
		{
			Blit(screenArray, adjTownPixels, SCREEN_WIDTH, SCREEN_HEIGHT,
				tiles_12_width, tiles_12_height, 285, 124, 320, 162,
				0 + ((320 - 285)* x), 0 + ((162 - 124) * y),
				tiles_12_width + ((320 - 285) * x), tiles_12_height * ((162 - 124)  * y));
		}
	}
#pragma endregion

#pragma region Randomly draw trees
	int positionsX[10];
	int positionsY[10];
	for (unsigned int i = 0; i < 10; i++)
	{
		positionsX[i] = rand() % 500;
		positionsY[i] = rand() % 500;
	}
	for (unsigned int i = 0; i < 10; i++)
	{


		Blit(screenArray, adjTownPixels, SCREEN_WIDTH, SCREEN_HEIGHT, tiles_12_width, tiles_12_height,
			320, 16, 383, 95,
			positionsX[i], positionsY[i], positionsX[i] + (383 - 320), positionsY[i] + (95 - 16));
	}

#pragma endregion


	int framecount = 0;
	double timecount = 0;
	timer.Signal();

	while (RS_Update(screenArray, SCREEN_SIZE)) {

		ClearScreen(screenArray, SCREEN_SIZE, 0x00000000);
#pragma region DrawGrassTiles

		int totalPossibleTileX = SCREEN_WIDTH / (320 - 285);
		int totalPossibleTileY = SCREEN_HEIGHT / (162 - 124);

		for (int x = 0; x < totalPossibleTileX + 1; x++)
		{
			for (int y = 0; y < totalPossibleTileY + 1; y++)
			{
				Blit(screenArray, adjTownPixels, SCREEN_WIDTH, SCREEN_HEIGHT,
					tiles_12_width, tiles_12_height, 285, 124, 320, 162,
					0 + ((320 - 285)* x), 0 + ((162 - 124) * y),
					tiles_12_width + ((320 - 285) * x), tiles_12_height * ((162 - 124)  * y));
			}
		}
#pragma endregion

#pragma region Randomly draw trees
		for (unsigned int i = 0; i < 10; i++)
		{
			Blit(screenArray, adjTownPixels, SCREEN_WIDTH, SCREEN_HEIGHT, tiles_12_width, tiles_12_height,
				320, 16, 383, 95,
				positionsX[i], positionsY[i], positionsX[i] + (383 - 320), positionsY[i] + (95 - 16));
		}
#pragma endregion

#pragma region Draw Fire
		Blit(screenArray, adjFirePixels, SCREEN_WIDTH, SCREEN_HEIGHT, fire_01_width, fire_01_height,
			0 + (128 * (framecount % 8)), 0 + (128 * (framecount / 8)),
			128 + (128 * (framecount % 8)), 128 + (128 * (framecount / 8)),
			250, 250, 378, 378);
#pragma endregion

#pragma region Adjust time and framecount
		timecount += timer.Delta();
		if (timecount >= (1.0 / 30.0)) {

			framecount++;
			timecount = 0.0;
		}


		if (framecount > 63)
			framecount = 0;
#pragma endregion

		timer.Signal();
	}


	RS_Shutdown();
	delete[] screenArray;
	delete[] adjTownPixels;
	delete[] adjFirePixels;

}