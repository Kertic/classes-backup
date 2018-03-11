#include <iostream>
#include "RasterSurface.h"
#include "ImageH\tiles_12.h"
#include "ImageH\fire_01.h"
#include "ImageH\teleporter_01.h"
#include <random>
#include <time.h>
#include "XTime.h"
using namespace std;

#define SCREEN_PIXEL_SIZE 250000




void ClearBuffer(unsigned int* _pixelArray);
void SetPixel(unsigned int* _pixelArray, unsigned int _pixelIndex, unsigned int _red, unsigned int _blue, unsigned int _green, unsigned int _alpha);
void SetPixel(unsigned int* _pixelArray, unsigned int _pixelIndex, unsigned int _color);
unsigned int To1d(unsigned int _dimX, unsigned int _dimY, unsigned int _maxX, unsigned int _maxY);
void Blit(const unsigned int* sourceArray, unsigned int*  destinationArray, unsigned int sourceImageWidth, unsigned int sourceImageHeight, unsigned int destinationWidth, unsigned int destinationHeight, unsigned int sourceImageLeftX, unsigned int sourceImageRightX, unsigned int sourceImageTopY, unsigned int sourceImageBottomY, unsigned int destinationImageLeftX, unsigned int destinationImageRightX, unsigned int destinationImageTopY, unsigned int destinationImageBottomY);
void Blit2(unsigned int sourceRectangleXMin, unsigned int sourceRectangleYMin, unsigned int sourceRectangleXMax, unsigned int sourceRectangleYMax, unsigned int startingDestinationPosX, unsigned int startingDestinationPosY, unsigned int* destinationArray, const unsigned int* sourceArray, unsigned int destinationArrayWidth, unsigned int destinationArrayHeight, unsigned int sourceArrayWidth, unsigned int sourceArrayHeight);
unsigned int Map(unsigned int bottom1, unsigned int top1, unsigned int bottom2, unsigned int top2, unsigned int value);
unsigned int ConvertFormat(unsigned int numberToConvert);
unsigned int Lerp(int bottom, int top, float ratio);



void main() {

	




	RS_Initialize(500, 500);

	unsigned int* screenArray;
	screenArray = new unsigned int[SCREEN_PIXEL_SIZE];

	for (unsigned int i = 0; i < SCREEN_PIXEL_SIZE; i++)
	{
		screenArray[i] = 0;
	}
	ClearBuffer(screenArray);

//Draws the little village once
	Blit2(0, 0, 127, 127, 0, 0, screenArray, &tiles_12_pixels[0], 500, 500, tiles_12_width, tiles_12_height);


	//Tiling portion. At 7, it can draw all of the tiles and leave that little bit of border. The Blit functions has been made to check if it would go out of bounds, so now it can run 8 and automatically ignore the overflowing portion.
	for (unsigned int x = 0; x < 8; x++)
	{
		for (unsigned int y = 0; y < 8; y++) {
			Blit2(272, 112, 335, 175, 0 + x * 63, 0 + y * 63, screenArray, &tiles_12_pixels[0], 500, 500, tiles_12_width, tiles_12_height);
		}
	}

	srand(time(NULL));


	int randomNums[10] = { rand(),rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand() };
	int locationX[10] = { rand() % 500,rand() % 500, rand() % 500, rand() % 500, rand() % 500, rand() % 500, rand() % 500, rand() % 500, rand() % 500, rand() % 500, };
	int locationY[10] = { rand() % 500,rand() % 500, rand() % 500, rand() % 500, rand() % 500, rand() % 500, rand() % 500, rand() % 500, rand() % 500, rand() % 500, };
	//Random Blit placement
	for (unsigned int i = 0; i < 10; i++)
	{
		if (randomNums[i] % 2 == 0) {
			Blit2(320, 16, 383, 97, locationX[i] % 500, locationY[i] % 500, screenArray, &tiles_12_pixels[0], 500, 500, tiles_12_width, tiles_12_height);
		}
		else
		{
			Blit2(128, 32, 191, 98, locationX[i] % 500, locationY[i] % 500, screenArray, &tiles_12_pixels[0], 500, 500, tiles_12_width, tiles_12_height);
		}
	}

	XTime timer;
	
	
	double elapsedTime = 0.0;
	int animCounter = 0;
	while (RS_Update(screenArray, 250000)) {
		elapsedTime += timer.Delta();
		
		if (elapsedTime >= (1.0 / 30.0)) {
			int x = (0 + animCounter) % 8;//8 is the maximum x dimension of cells in the fire_01 animation
			int y = animCounter / 8;//This will truncate, so counters below 8 are 0, and any between 8 and 16 will be 8, so on and so forth.
#pragma region Draw Logic
			ClearBuffer(screenArray);

			for (unsigned int x = 0; x < 8; x++)
			{
				for (unsigned int y = 0; y < 8; y++) {
					Blit2(272, 112, 335, 175, 0 + x * 63, 0 + y * 63, screenArray, &tiles_12_pixels[0], 500, 500, tiles_12_width, tiles_12_height);
				}
			}//Tiling background

			 //Random Blit placement
			for (unsigned int i = 0; i < 10; i++)
			{
				if (randomNums[i] % 2 == 0) {
					Blit2(320, 16, 383, 97, locationX[i] % 500, locationY[i] % 500, screenArray, &tiles_12_pixels[0], 500, 500, tiles_12_width, tiles_12_height);
				}
				else
				{
					Blit2(128, 32, 191, 98, locationX[i] % 500, locationY[i] % 500, screenArray, &tiles_12_pixels[0], 500, 500, tiles_12_width, tiles_12_height);
				}
			}

			Blit2(0 + 128 * x, 0 + 128 * y, 128 + 128 * x, 128 + 128 * y, 250, 250, screenArray, &fire_01_pixels[0], 500, 500, fire_01_width, fire_01_height);//Fire animation
#pragma endregion

			

			animCounter++;
			animCounter = animCounter % 64;
			elapsedTime = 0.0;
		}




		timer.Signal();


		
	}
	




	RS_Shutdown();

	delete[] screenArray;
}




void ClearBuffer(unsigned int* _pixelArray) {

	for (unsigned int i = 0; i < SCREEN_PIXEL_SIZE; i++)
	{
		SetPixel(_pixelArray, i, 128, 0, 255, 255);
	}
}


void SetPixel(unsigned int* _pixelArray, unsigned int _pixelIndex, unsigned int _red, unsigned int _blue, unsigned int _green, unsigned int _alpha) {


	unsigned int pixel = 0x00000000;
	pixel = pixel | (_alpha << 24);
	pixel = pixel | (_red << 16);
	pixel = pixel | (_green << 8);
	pixel = pixel | (_blue);




	SetPixel(_pixelArray, _pixelIndex, pixel);

}

void SetPixel(unsigned int* _pixelArray, unsigned int _pixelIndex, unsigned int _color) {

	unsigned int currentPixel = _pixelArray[_pixelIndex];


	unsigned int currentRed = (currentPixel & 0x00ff0000) >> 16;
	unsigned int currentGreen = (currentPixel & 0x0000ff00) >> 8;
	unsigned int currentBlue = currentPixel & 0x000000ff;



	float alphaRatio = ((_color & 0xff000000) >> 24) / 255.0f;

	unsigned int inputRed = (_color & 0x00ff0000) >> 16;
	unsigned int inputGreen = (_color & 0x0000ff00) >> 8;
	unsigned int inputBlue = _color & 0x000000ff;

	unsigned int finalRed = Lerp(inputRed, currentRed, alphaRatio);
	unsigned int finalGreen = Lerp(inputGreen, currentGreen, alphaRatio);
	unsigned int finalBlue = Lerp(inputBlue, currentBlue, alphaRatio);

	finalRed = finalRed << 16;
	finalGreen = finalGreen << 8;
	//finalBlue = finalBlue << 0;

	unsigned int finalColor = ((finalRed | finalBlue) | finalGreen);


	_pixelArray[_pixelIndex] = finalColor;
}

unsigned int To1d(unsigned int _dimX, unsigned int _dimY, unsigned int _maxX, unsigned int _maxY) {

	unsigned int index = 0;
	index = _dimY *_maxX + _dimX;


	return index;
}

//Widths and Heights
void Blit(const unsigned int* sourceArray, unsigned int*  destinationArray, unsigned int sourceImageWidth, unsigned int sourceImageHeight, unsigned int destinationWidth, unsigned int destinationHeight, unsigned int sourceImageLeftX, unsigned int sourceImageRightX, unsigned int sourceImageTopY, unsigned int sourceImageBottomY, unsigned int destinationImageLeftX, unsigned int destinationImageRightX, unsigned int destinationImageTopY, unsigned int destinationImageBottomY) {




	unsigned int tempImageMaxRange = (destinationWidth - 1) * (destinationHeight - 1);
	unsigned int sourceImageMaxRange = (sourceImageWidth - 1) * (sourceImageHeight - 1);

	for (unsigned int i = destinationImageLeftX; i < destinationImageRightX; i++)
	{
		for (unsigned int j = destinationImageTopY; j < destinationImageBottomY; j++)
		{
			int tempImageIndex = To1d(i, j, destinationImageRightX, destinationImageBottomY);
			destinationArray[tempImageIndex] = sourceArray[Map(0, tempImageMaxRange, 0, sourceImageMaxRange, tempImageIndex)];//The index of the current tempImage mapped onto the source image
		}
	}





}

void Blit2(unsigned int sourceRectangleXMin, unsigned int sourceRectangleYMin, unsigned int sourceRectangleXMax, unsigned int sourceRectangleYMax, unsigned int startingDestinationPosX, unsigned int startingDestinationPosY, unsigned int* destinationArray, const unsigned int* sourceArray, unsigned int destinationArrayWidth, unsigned int destinationArrayHeight, unsigned int sourceArrayWidth, unsigned int sourceArrayHeight) {
	for (unsigned int y = sourceRectangleYMin; y < sourceRectangleYMax; y++)
	{
		if (y + startingDestinationPosY - sourceRectangleYMin <= destinationArrayHeight) {
			for (unsigned int x = sourceRectangleXMin; x < sourceRectangleXMax; x++)
			{
				if (x + startingDestinationPosX - sourceRectangleXMin <= destinationArrayWidth)
				{
					int tileIndex = To1d(x, y, sourceArrayWidth, sourceArrayHeight);
					int destinationIndex = To1d(startingDestinationPosX + x - sourceRectangleXMin, startingDestinationPosY + y - sourceRectangleYMin, 500, 500);
					SetPixel(destinationArray, destinationIndex, ConvertFormat(sourceArray[tileIndex]));
				}
			}
		}
	}
}

unsigned int Lerp(int ending, int starting, float ratio) {

	return (unsigned int)((ending - starting) * ratio + starting);
}

//Returns a value from within range 1 (bottom and top 1) as a value in the same spot but in range 2 (bottom and top 2)
unsigned int Map(unsigned int bottom1, unsigned int top1, unsigned int bottom2, unsigned int top2, unsigned int value) {
	unsigned int range1 = top1 - bottom1;
	unsigned int range2 = top2 - bottom2;

	float ratio = value / range1;


	return (unsigned int)ratio * range2;
}



unsigned int ConvertFormat(unsigned int numberToConvert) {
	unsigned int redBit = 0x0000ff00;
	unsigned int greenBit = 0x00ff0000;
	unsigned int blueBit = 0xff000000;
	unsigned int alphaBit = 0x000000ff;

	alphaBit = (alphaBit & numberToConvert);
	redBit = (redBit & numberToConvert) >> 8;
	greenBit = (greenBit & numberToConvert) >> 16;
	blueBit = (blueBit & numberToConvert) >> 24;

	alphaBit = alphaBit << 24;
	redBit = redBit << 16;
	greenBit = greenBit << 8;
	blueBit = blueBit;

	unsigned int testInt = (((alphaBit | redBit) | greenBit) | blueBit);
	return testInt;
}