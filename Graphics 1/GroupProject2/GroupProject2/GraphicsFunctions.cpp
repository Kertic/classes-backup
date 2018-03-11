#include "GraphicsFunctions.h"


void ClearBuffer(unsigned int* _pixelArray, unsigned int arraySize) {

	for (unsigned int i = 0; i < arraySize; i++)
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

void Blit(unsigned int sourceRectangleXMin, unsigned int sourceRectangleYMin, unsigned int sourceRectangleXMax, unsigned int sourceRectangleYMax, unsigned int startingDestinationPosX, unsigned int startingDestinationPosY, unsigned int* destinationArray, const unsigned int* sourceArray, unsigned int destinationArrayWidth, unsigned int destinationArrayHeight, unsigned int sourceArrayWidth, unsigned int sourceArrayHeight) {
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


void DrawLineParametric(int _x1, int _x2, int _y1, int _y2, unsigned int* _pixelArray, unsigned int _pixelArraySize, unsigned int _pixelArrayWidth, unsigned int _pixelArrayHeight, unsigned int _red, unsigned int _green, unsigned int _blue, unsigned int _alpha) {

	//True would mean x axis, false means y axis
	bool primAxis = false;
	bool secAxis = false;

	if (abs(_x2 - _x1) > abs(_y2 - _y1)) {//If the x distance is longer
		primAxis = true;//X is the primary axis
	}
	else {
		secAxis = true;//X is the secondary axis
	}

	if (primAxis == secAxis)
		assert(false);


	//int magnitude = (int)sqrt(((_y2 - _y1) * (_y2 - _y1)) + ((_x2 - _x1) * (_x2 - _x1)));
	int startPrimary = 0;
	int endPrimary = 0;

	int startSecondary = 0;
	int endSecondary = 0;
#pragma region X is the primary axis
	if (primAxis) {
		startPrimary = _x1;
		endPrimary = _x2;

		startSecondary = _y1;
		endSecondary = _y2;
	}

#pragma endregion

#pragma region Y is the primary axis
	if (secAxis) {
		startPrimary = _y1;
		endPrimary = _y2;

		startSecondary = _x1;
		endSecondary = _x2;
	}
#pragma endregion

	if (startPrimary < endPrimary) {
		for (int i = startPrimary; i < endPrimary; i++)
		{
			float ratio = ((float)i - (float)startPrimary) / ((float)endPrimary - (float)startPrimary);
			float currY = Lerp(startSecondary, endSecondary, ratio);
			SetPixel(_pixelArray, To1d(i, (int)(currY + 0.5f), _pixelArrayWidth, _pixelArrayHeight), _red, _blue, _green, _alpha);
		}
	}
	else {

		for (int i = startPrimary; i > endPrimary; i--)
		{
			float ratio = ((float)i - (float)startPrimary) / ((float)endPrimary - (float)startPrimary);
			float currY = Lerp(endSecondary, startSecondary, ratio);
			SetPixel(_pixelArray, To1d(i, (int)(currY + 0.5f), _pixelArrayWidth, _pixelArrayHeight), _red, _blue, _green, _alpha);
		}
	}

}