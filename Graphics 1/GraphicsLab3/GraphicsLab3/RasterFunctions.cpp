#include "RasterFunctions.h"


void ClearBuffer(unsigned int* _pixelArray, unsigned int arraySize) {

	for (unsigned int i = 0; i < arraySize; i++)
	{
		SetPixel(_pixelArray, arraySize, i, 0, 0, 0, 255);
	}
}

void SetPixel(unsigned int* _pixelArray, unsigned int _pixelArraySize, unsigned int _pixelIndex, unsigned int _red, unsigned int _blue, unsigned int _green, unsigned int _alpha) {


	unsigned int pixel = 0x00000000;
	pixel = pixel | (_alpha << 24);
	pixel = pixel | (_red << 16);
	pixel = pixel | (_green << 8);
	pixel = pixel | (_blue);




	SetPixel(_pixelArray, _pixelArraySize, _pixelIndex, pixel);

}

void SetPixel(unsigned int* _pixelArray, unsigned int _pixelArraySize, unsigned int _pixelIndex, unsigned int _color) {
	if (_pixelArraySize < _pixelIndex)
		return;

	unsigned int currentPixel = _pixelArray[_pixelIndex];


	unsigned int currentRed = (currentPixel & 0x00ff0000) >> 16;
	unsigned int currentGreen = (currentPixel & 0x0000ff00) >> 8;
	unsigned int currentBlue = currentPixel & 0x000000ff;



	float alphaRatio = ((_color & 0xff000000) >> 24) / 255.0f;

	unsigned int inputRed = (_color & 0x00ff0000) >> 16;
	unsigned int inputGreen = (_color & 0x0000ff00) >> 8;
	unsigned int inputBlue = _color & 0x000000ff;

	unsigned int finalRed = Lerp(currentRed, inputRed, alphaRatio);
	unsigned int finalGreen = Lerp(currentGreen, inputGreen, alphaRatio);
	unsigned int finalBlue = Lerp(currentBlue, inputBlue, alphaRatio);

	finalRed = finalRed << 16;
	finalGreen = finalGreen << 8;
	//finalBlue = finalBlue << 0;

	unsigned int finalColor = ((finalRed | finalBlue) | finalGreen);

	if (MyPixelShader)
		MyPixelShader(_pixelArray[_pixelIndex]);


	_pixelArray[_pixelIndex] = finalColor;
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
					SetPixel(destinationArray, (destinationArrayWidth * destinationArrayHeight), destinationIndex, ConvertFormat(sourceArray[tileIndex]));
				}
			}
		}
	}
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


void DrawLineParametric(int _x1, int _x2, int _y1, int _y2, unsigned int* _pixelArray, unsigned int _pixelArraySize, unsigned int _pixelArrayWidth, unsigned int _pixelArrayHeight, unsigned int _red, unsigned int _green, unsigned int _blue, unsigned int _alpha, unsigned int _red2, unsigned int _green2, unsigned int _blue2, unsigned int _alpha2) {

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
	unsigned int startPrimary = 0;
	unsigned int endPrimary = 0;

	unsigned int startSecondary = 0;
	unsigned int endSecondary = 0;
	float slope = ((float)_y2 - (float)_y1) / ((float)_x2 - (float)_x1);



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
		for (unsigned int i = startPrimary; i < endPrimary; i++)
		{
			float ratio = ((float)i - (float)startPrimary) / ((float)endPrimary - (float)startPrimary);
			float currX = (float)Lerp(_x2, _x1, ratio);
			float currY = (float)Lerp(_y2, _y1, ratio);
			int red = Lerp(_red, _red2, ratio);
			int green = Lerp(_green, _green2, ratio);
			int blue = Lerp(_blue, _blue2, ratio);
			SetPixel(_pixelArray, _pixelArraySize, To1d((unsigned int)currX, (unsigned int)currY, _pixelArrayWidth, _pixelArrayHeight), red, blue, green, _alpha);
		}
	}
	else
	{
		for (unsigned int i = startPrimary; i > endPrimary; --i)
		{
			float ratio = ((float)startPrimary - (float)i) / ((float)startPrimary - (float)endPrimary);
			float currX = (float)Lerp(_x1, _x2, ratio);
			float currY = (float)Lerp(_y1, _y2, ratio);
			int red = Lerp(_red, _red2, ratio);
			int green = Lerp(_green, _green2, ratio);
			int blue = Lerp(_blue, _blue2, ratio);
			SetPixel(_pixelArray, _pixelArraySize, To1d((unsigned int)currX, (unsigned int)currY, _pixelArrayWidth, _pixelArrayHeight), red, blue, green, _alpha);
		}
	}



	//if (startPrimary < endPrimary) {// If the (var)1 is less than the (var)2

	//	if (slope >= 0) {//If slope is positive
	//		for (int i = startPrimary; i < endPrimary; i++)
	//		{
	//			float ratio = ((float)i - (float)startPrimary) / ((float)endPrimary - (float)startPrimary);
	//			float SecondaryAxisValue = Lerp(startSecondary, endSecondary, ratio);
	//			int red = Lerp(_red, _red2, ratio);
	//			int green = Lerp(_green, _green2, ratio);
	//			int blue = Lerp(_blue, _blue2, ratio);
	//			SetPixel(_pixelArray, _pixelArraySize, To1d(i, (int)(SecondaryAxisValue + 0.5f), _pixelArrayWidth, _pixelArrayHeight), red, blue, green, _alpha);
	//		}
	//	}
	//	else//Slope is negitive
	//	{
	//		for (int i = startPrimary; i < endPrimary; i++)
	//		{
	//			float ratio = ((float)i - (float)startPrimary) / ((float)endPrimary - (float)startPrimary);
	//			float SecondaryAxisValue = Lerp(startSecondary, endSecondary, ratio);
	//			int red = Lerp(_red, _red2, ratio);
	//			int green = Lerp(_green, _green2, ratio);
	//			int blue = Lerp(_blue, _blue2, ratio);
	//			SetPixel(_pixelArray, _pixelArraySize, To1d(i, (int)(SecondaryAxisValue - 0.5f), _pixelArrayWidth, _pixelArrayHeight), red, blue, green, _alpha);
	//		}
	//	}

	//}
	//else// If the (var)1 is greater than (var)2
	//{
	//	if (slope >= 0) {
	//		for (int i = startPrimary; i < endPrimary; i++)
	//		{
	//			float ratio = ((float)i - (float)startPrimary) / ((float)endPrimary - (float)startPrimary);
	//			float SecondaryAxisValue = Lerp(startSecondary, endSecondary, ratio);
	//			int red = Lerp(_red, _red2, ratio);
	//			int green = Lerp(_green, _green2, ratio);
	//			int blue = Lerp(_blue, _blue2, ratio);
	//			SetPixel(_pixelArray, _pixelArraySize, To1d(i, (int)(SecondaryAxisValue + 0.5f), _pixelArrayWidth, _pixelArrayHeight), red, blue, green, _alpha);
	//		}
	//	}
	//	else
	//	{
	//		for (int i = startPrimary; i < endPrimary; i++)
	//		{
	//			float ratio = ((float)i - (float)startPrimary) / ((float)endPrimary - (float)startPrimary);
	//			float SecondaryAxisValue = Lerp(startSecondary, endSecondary, ratio);
	//			int red = Lerp(_red, _red2, ratio);
	//			int green = Lerp(_green, _green2, ratio);
	//			int blue = Lerp(_blue, _blue2, ratio);
	//			SetPixel(_pixelArray, _pixelArraySize, To1d(i, (int)(SecondaryAxisValue + 0.5f), _pixelArrayWidth, _pixelArrayHeight), red, blue, green, _alpha);
	//		}
	//	}
	//}
	//
	//


	//


	///*from the start of the line to the end of the line, using the primary axis as reference
	//ratio is equal to the amount of the line we have covered so far
	//the current Secondary axis is equal to the same portion of its own line, using its start and end and going (the ratio) up the line
	//then, the current secondary axis is added 0.5 in the case where the line is a negitive slope, and subtraced in the case it is positive slope
	//and we plot the pixel on location (primary axis index, secondary axis)
	//
	//
	//
	//
	//*/
}


void DrawLineBresenham(int _x1, int _x2, int _y1, int _y2, unsigned int* _pixelArray, unsigned int _pixelArraySize, unsigned int _pixelArrayWidth, unsigned int _pixelArrayHeight, unsigned int _red, unsigned int _green, unsigned int _blue, unsigned int _alpha) {





	float slope = ((float)_y2 - (float)_y1) / ((float)_x2 - (float)_x1);
	float error = 0.0f;
	//Positive slope
	if (slope > 0) {
		//More horizontal slope
		if (slope < 1) {
			//Moving to the right
			if (_x1 < _x2) {
				int currentSecondary = _y1;
				for (unsigned int i = _x1; i < (unsigned int)_x2; i++)
				{
					SetPixel(_pixelArray, _pixelArraySize, To1d(i, currentSecondary, _pixelArrayWidth, _pixelArrayHeight), _red, _blue, _green, _alpha);
					error += slope;
					if (error > 0.5f) {
						currentSecondary += 1;
						error -= 1;
					}
				}
			}
			//Moving to the left
			else
			{
				int currentSecondary = _y1;
				for (unsigned int i = _x1; i > (unsigned int)_x2; i--)
				{
					SetPixel(_pixelArray, _pixelArraySize, To1d(i, currentSecondary, _pixelArrayWidth, _pixelArrayHeight), _red, _blue, _green, _alpha);
					error += -slope;
					if (error < 0.5f) {
						currentSecondary -= 1;
						error += 1;
					}
				}
			}
		}
		//More Verticle slope
		else
		{
			//Moving to the right
			if (_y1 < _y2) {
				int currentSecondary = _x1;
				for (unsigned int i = _y1; i < (unsigned int)_y2; i++)
				{
					SetPixel(_pixelArray, _pixelArraySize, To1d(currentSecondary, i, _pixelArrayWidth, _pixelArrayHeight), _red, _blue, _green, _alpha);
					error += 1.0f / slope;
					if (error > 0.5f) {
						currentSecondary += 1;
						error -= 1;
					}
				}
			}
			//Moving to the left
			else
			{
				int currentSecondary = _x1;
				for (unsigned int i = _y1; i > (unsigned int)_y2; i--)
				{
					SetPixel(_pixelArray, _pixelArraySize, To1d(currentSecondary, i, _pixelArrayWidth, _pixelArrayHeight), _red, _blue, _green, _alpha);
					error += 1 / slope;
					if (error > 0.5f) {
						currentSecondary -= 1;
						error -= 1;
					}
				}
			}
		}
	}
	//Negitive slope
	else
	{
		//More horizontal slope
		if (slope > -1) {
			//Moving more toward the right
			if (_x1 < _x2) {
				int currentSecondary = _y1;
				for (unsigned int i = _x1; i < (unsigned int)_x2; i++)
				{
					SetPixel(_pixelArray, _pixelArraySize, To1d(i, currentSecondary, _pixelArrayWidth, _pixelArrayHeight), _red, _blue, _green, _alpha);
					error += slope;
					if (error < 0.5f) {
						currentSecondary -= 1;
						error += 1;
					}
				}
			}
			//Moving more toward the left
			else
			{
				int currentSecondary = _y1;
				for (unsigned int i = _x1; i > (unsigned int)_x2; i--)
				{
					SetPixel(_pixelArray, _pixelArraySize, To1d(i, currentSecondary, _pixelArrayWidth, _pixelArrayHeight), _red, _blue, _green, _alpha);
					error += slope;
					if (error < 0.5f) {
						currentSecondary += 1;
						error += 1;
					}
				}
			}
		}
		//More verticle slope
		else
		{
			//More toware the right
			if (_y1 < _y2) {
				int currentSecondary = _x1;
				for (unsigned int i = _y1; i < (unsigned int)_y2; i++)
				{
					SetPixel(_pixelArray, _pixelArraySize, To1d(currentSecondary, i, _pixelArrayWidth, _pixelArrayHeight), _red, _blue, _green, _alpha);
					error += 1 / slope;
					if (error < 0.5f) {
						currentSecondary -= 1;
						error += 1;
					}
				}
			}
			//More toward the left
			else
			{
				int currentSecondary = _x1;
				for (unsigned int i = _y1; i > (unsigned int)_y2; i--)
				{
					SetPixel(_pixelArray, _pixelArraySize, To1d(currentSecondary, i, _pixelArrayWidth, _pixelArrayHeight), _red, _blue, _green, _alpha);
					error += 1 / slope;
					if (error < 0.5f) {
						currentSecondary += 1;
						error += 1;
					}
				}
			}
		}
	}





}


void DrawLineMidpoint(int _x1, int _x2, int _y1, int _y2, unsigned int* _pixelArray, unsigned int _pixelArraySize, unsigned int _pixelArrayWidth, unsigned int _pixelArrayHeight, unsigned int _red, unsigned int _green, unsigned int _blue, unsigned int _alpha) {

	float slope = ((float)_y2 - (float)_y1) / ((float)_x2 - (float)_x1);
	//Its moving mostly horizontal
	if (abs(_x2 - _x1) > abs(_y2 - _y1)) {


		//Moving right
		if (_x1 < _x2) {
			//Positive slope
			if (slope > 0) {
				float currentSecondary = (float)_y1;
				for (unsigned int i = _x1; i < (unsigned int)_x2; i++)
				{
					SetPixel(_pixelArray, _pixelArraySize, To1d(i, (unsigned int)currentSecondary, _pixelArrayWidth, _pixelArrayHeight), _red, _blue, _green, _alpha);
					float midpointX = i + 1.0f;
					float midpointY = currentSecondary + 0.5f;

					if (ImplicitLineEquation(_x1, _x2, _y1, _y2, midpointX, midpointY) < 0) {
						currentSecondary += 1;
					}
				}
			}
			//Negitive slope
			else
			{
				float currentSecondary = (float)_y1;
				for (unsigned int i = _x1; i < (unsigned int)_x2; i++)
				{
					SetPixel(_pixelArray, _pixelArraySize, To1d(i, (unsigned int)currentSecondary, _pixelArrayWidth, _pixelArrayHeight), _red, _blue, _green, _alpha);
					float midpointX = i + 1.0f;
					float midpointY = currentSecondary - 0.5f;

					if (ImplicitLineEquation(_x1, _x2, _y1, _y2, midpointX, midpointY) > 0) {
						currentSecondary -= 1;
					}
				}
			}
		}
		//Moving left
		else
		{
			//Positive slope
			if (slope > 0) {
				float currentSecondary = (float)_y1;
				for (unsigned int i = _x1; i > (unsigned int)_x2; i--)
				{
					SetPixel(_pixelArray, _pixelArraySize, To1d(i, (unsigned int)currentSecondary, _pixelArrayWidth, _pixelArrayHeight), _red, _blue, _green, _alpha);
					float midpointX = i - 1.0f;
					float midpointY = currentSecondary - 0.5f;

					if (ImplicitLineEquation(_x1, _x2, _y1, _y2, midpointX, midpointY) < 0) {
						currentSecondary -= 1.0f;
					}
				}
			}
			//Negitive slope
			else
			{
				float currentSecondary = (float)_y1;
				for (unsigned int i = _x1; i > (unsigned int)_x2; i--)
				{
					SetPixel(_pixelArray, _pixelArraySize, To1d(i, (unsigned int)currentSecondary, _pixelArrayWidth, _pixelArrayHeight), _red, _blue, _green, _alpha);
					float midpointX = i - 1.0f;
					float midpointY = currentSecondary + 0.5f;

					if (ImplicitLineEquation(_x1, _x2, _y1, _y2, midpointX, midpointY) > 0) {
						currentSecondary += 1;
					}
				}

			}
		}
	}
	//Moving mostly vertical
	else
	{

		//Moving down visually
		if (_y1 < _y2)
		{
			//Positive slope
			if (slope > 0) {
				float currentSecondary = (float)_x1;
				for (unsigned int i = _y1; i < (unsigned int)_y2; i++)
				{
					SetPixel(_pixelArray, _pixelArraySize, To1d((unsigned int)currentSecondary, i, _pixelArrayWidth, _pixelArrayHeight), _red, _blue, _green, _alpha);
					float midpointX = currentSecondary + 0.5f;
					float midpointY = i + 1.0f;

					if (ImplicitLineEquation(_x1, _x2, _y1, _y2, midpointX, midpointY) > 0) {
						currentSecondary += 1;
					}
				}
			}
			//Negitive slope
			else
			{
				float currentSecondary = (float)_x1;
				for (unsigned int i = _y1; i < (unsigned int)_y2; i++)
				{
					SetPixel(_pixelArray, _pixelArraySize, To1d((unsigned int)currentSecondary, i, _pixelArrayWidth, _pixelArrayHeight), _red, _blue, _green, _alpha);
					float midpointX = currentSecondary + 0.5f;
					float midpointY = i + 1.0f;

					if (ImplicitLineEquation(_x1, _x2, _y1, _y2, midpointX, midpointY) < 0) {
						currentSecondary -= 1;
					}
				}
			}
		}
		//Moving up visually
		else
		{
			//Positve slope
			if (slope > 0) {
				float currentSecondary = (float)_x1;
				for (unsigned int i = _y1; i > (unsigned int)_y2; i--)
				{
					SetPixel(_pixelArray, _pixelArraySize, To1d((unsigned int)currentSecondary, i, _pixelArrayWidth, _pixelArrayHeight), _red, _blue, _green, _alpha);
					float midpointX = currentSecondary + 0.5f;
					float midpointY = i + 1.0f;

					if (ImplicitLineEquation(_x1, _x2, _y1, _y2, midpointX, midpointY) > 0) {
						currentSecondary -= 1;
					}
				}
			}
			//Negetive slope
			else
			{
				float currentSecondary = (float)_x1;
				for (unsigned int i = _y1; i >(unsigned int)_y2; i--)
				{
					SetPixel(_pixelArray, _pixelArraySize, To1d((unsigned int)currentSecondary, i, _pixelArrayWidth, _pixelArrayHeight), _red, _blue, _green, _alpha);
					float midpointX = currentSecondary - 0.5f;
					float midpointY = i - 1.0f;

					if (ImplicitLineEquation(_x1, _x2, _y1, _y2, midpointX, midpointY) < 0) {
						currentSecondary += 1;
					}
				}
			}
		}
	}

}



