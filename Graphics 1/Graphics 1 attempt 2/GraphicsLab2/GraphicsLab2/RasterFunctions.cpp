#include "RasterFunctions.h"













void ClearScreen(unsigned int* pixelArray, unsigned int arraySize, unsigned int color) {

	for (unsigned int i = 0; i < arraySize; ++i) {
		pixelArray[i] = color;
	}

}

void PaintPixel(unsigned int * pixelArray, unsigned int index, unsigned int color)
{
	if (index > SCREEN_SIZE)
		return;

	unsigned int incomingRed = (color << 8) >> 24;
	unsigned int incomingGreen = (color << 16) >> 24;
	unsigned int incomingBlue = (color << 24) >> 24;
	unsigned int incomingAlpha = color >> 24;

	unsigned int currentRed = (pixelArray[index] << 8) >> 24;
	unsigned int currentGreen = (pixelArray[index] << 16) >> 24;
	unsigned int currentBlue = (pixelArray[index] << 24) >> 24;
	unsigned int currentAlpha = pixelArray[index] >> 24;

	unsigned int finalRed = (unsigned int)Lerp((float)currentRed, (float)incomingRed, ((float)incomingAlpha / (float)255)) << 16;
	unsigned int finalGreen = (unsigned int)Lerp((float)currentGreen, (float)incomingGreen, ((float)incomingAlpha / (float)255)) << 8;
	unsigned int finalBlue = (unsigned int)Lerp((float)currentBlue, (float)incomingBlue, ((float)incomingAlpha / (float)255));

	unsigned int finalColor = 0;
	finalColor = (((finalRed | finalColor) | finalGreen) | finalBlue) | (incomingAlpha << 24);

	pixelArray[index] = finalColor;
}

void Blit(
	unsigned int * pixelArray, const unsigned int * imageArray,
	unsigned int _maxPixelX, unsigned int _maxPixelY, unsigned int _maxImageX, unsigned int _maxImageY,
	unsigned int _SourceTopLeftX, unsigned int _SourceTopLeftY, unsigned int _SourceBottomRightX, unsigned int _SourceBottomRightY,
	unsigned int _DestTopLeftX, unsigned int _DestTopLeftY, unsigned int _DestBottomRightX, unsigned int _DestBottomRightY)
{
	for (unsigned int x = _SourceTopLeftX; x < _SourceBottomRightX; x++)
	{
		/*	if (x > _maxPixelX || x > _maxImageX)
				break;*/
		for (unsigned int y = _SourceTopLeftY; y < _SourceBottomRightY; y++)
		{
			/*if (y > _maxPixelY || y > _maxImageY)
				break;*/

			PaintPixel(pixelArray,
				From2Dto1D(
					x - _SourceTopLeftX + _DestTopLeftX,
					y - _SourceTopLeftY + _DestTopLeftY,
					0, 0, _maxPixelX, _maxPixelY),
				imageArray[From2Dto1D(x, y, 0, 0, _maxImageX, _maxImageY)]);
		}
	}

}

void DrawBresenhamLine(int _x1, int _y1, int _x2, int _y2, unsigned int * pixelArray, unsigned int pixelArraySize, unsigned int color)
{
	float slope = ((float)_y2 - (float)_y1) / ((float)_x2 - (float)_x1);
	float error = 0.0f;
	//Positive slope
	if (slope > 0) {
		//More horizontal slope
		if (slope < 1) {
			//Moving to the right
			if (_x1 < _x2) {
				int currentSecondary = _y1;
				for (int i = _x1; i < _x2; i++)
				{

					PaintPixel(pixelArray, From2Dto1D(i, currentSecondary, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT), color);
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
				for (int i = _x1; i > _x2; i--)
				{

					PaintPixel(pixelArray, From2Dto1D(i, currentSecondary, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT), color);
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
				for (int i = _y1; i < _y2; i++)
				{

					PaintPixel(pixelArray, From2Dto1D(currentSecondary, i, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT), color);
					error += 1 / slope;
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
				for (int i = _y1; i > _y2; i--)
				{

					PaintPixel(pixelArray, From2Dto1D(currentSecondary, i, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT), color);
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
				for (int i = _x1; i < _x2; i++)
				{

					PaintPixel(pixelArray, From2Dto1D(i, currentSecondary, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT), color);
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
				for (int i = _x1; i > _x2; i--)
				{

					PaintPixel(pixelArray, From2Dto1D(i, currentSecondary, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT), color);
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
				for (int i = _y1; i < _y2; i++)
				{

					PaintPixel(pixelArray, From2Dto1D(currentSecondary, i, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT), color);
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
				for (int i = _y1; i > _y2; i--)
				{
					PaintPixel(pixelArray, From2Dto1D(currentSecondary, i, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT), color);
					error += 1 / slope;
					if (error < 0.5f) {
						currentSecondary += 1;
						error += 1;
					}
				}
			}
		}
	}
#ifdef _RASTERDEBUG
	PaintPixel(pixelArray, From2Dto1D(_x1, _y1, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT), 0xffffffff);
	PaintPixel(pixelArray, From2Dto1D(_x2, _y2, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT), 0xffffff00);
#endif

}

void DrawMidpointLine(int _x1, int _y1, int _x2, int _y2, unsigned int * pixelArray, unsigned int pixelArraySize, unsigned int color)
{

	float slope = ((float)_y2 - (float)_y1) / ((float)_x2 - (float)_x1);
	//Its moving mostly horizontal
	if (abs(_x2 - _x1) > abs(_y2 - _y1)) {


		//Moving right
		if (_x1 < _x2) {
			//Positive slope
			if (slope > 0) {
				float currentSecondary = (float)_y1;
				for (int i = _x1; i < _x2; i++)
				{

					PaintPixel(pixelArray, From2Dto1D(i, (int)currentSecondary, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT), color);
					float midpointX = i + 1.0f;
					float midpointY = currentSecondary + 0.5f;

					if (ImplicitLineEquation((float)_x1, (float)_y1, (float)_x2, (float)_y2, midpointX, midpointY) < 0) {
						currentSecondary += 1;
					}
				}
			}
			//Negitive slope
			else
			{
				float currentSecondary = (float)_y1;
				for (int i = _x1; i < _x2; i++)
				{

					PaintPixel(pixelArray, From2Dto1D(i, (int)currentSecondary, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT), color);
					float midpointX = i + 1.0f;
					float midpointY = currentSecondary - 0.5f;

					if (ImplicitLineEquation((float)_x1, (float)_y1, (float)_x2, (float)_y2, midpointX, midpointY) > 0) {
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
				for (int i = _x1; i > _x2; i--)
				{

					PaintPixel(pixelArray, From2Dto1D(i, (int)currentSecondary, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT), color);
					float midpointX = i - 1.0f;
					float midpointY = currentSecondary - 0.5f;

					if (ImplicitLineEquation((float)_x1, (float)_y1, (float)_x2, (float)_y2, midpointX, midpointY) < 0) {
						currentSecondary -= 1.0f;
					}
				}
			}
			//Negitive slope
			else
			{
				float currentSecondary = (float)_y1;
				for (int i = _x1; i > _x2; i--)
				{

					PaintPixel(pixelArray, From2Dto1D(i, (int)currentSecondary, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT), color);
					float midpointX = i - 1.0f;
					float midpointY = currentSecondary + 0.5f;

					if (ImplicitLineEquation((float)_x1, (float)_y1, (float)_x2, (float)_y2, midpointX, midpointY) > 0) {
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
				for (int i = _y1; i < _y2; i++)
				{

					PaintPixel(pixelArray, From2Dto1D((int)currentSecondary, i, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT), color);
					float midpointX = currentSecondary + 0.5f;
					float midpointY = i + 1.0f;

					if (ImplicitLineEquation((float)_x1, (float)_y1, (float)_x2, (float)_y2, midpointX, midpointY) > 0) {
						currentSecondary += 1;
					}
				}
			}
			//Negitive slope
			else
			{
				float currentSecondary = (float)_x1;
				for (int i = _y1; i < _y2; i++)
				{

					PaintPixel(pixelArray, From2Dto1D((int)currentSecondary, i, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT), color);
					float midpointX = currentSecondary + 0.5f;
					float midpointY = i + 1.0f;

					if (ImplicitLineEquation((float)_x1, (float)_y1, (float)_x2, (float)_y2, midpointX, midpointY) < 0) {
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
				for (int i = _y1; i > _y2; i--)
				{

					PaintPixel(pixelArray, From2Dto1D((int)currentSecondary, i, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT), color);
					float midpointX = currentSecondary + 0.5f;
					float midpointY = i + 1.0f;

					if (ImplicitLineEquation((float)_x1, (float)_y1, (float)_x2, (float)_y2, midpointX, midpointY) > 0) {
						currentSecondary -= 1;
					}
				}
			}
			//Negetive slope
			else
			{
				float currentSecondary = (float)_x1;
				for (int i = _y1; i > _y2; i--)
				{

					PaintPixel(pixelArray, From2Dto1D((int)currentSecondary, i, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT), color);
					float midpointX = currentSecondary - 0.5f;
					float midpointY = i - 1.0f;

					if (ImplicitLineEquation((float)_x1, (float)_y1, (float)_x2, (float)_y2, midpointX, midpointY) < 0) {
						currentSecondary += 1;
					}
				}
			}
		}
	}

#ifdef _RASTERDEBUG
	PaintPixel(pixelArray, From2Dto1D(_x1, _y1, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT), 0xffffff00);
	PaintPixel(pixelArray, From2Dto1D(_x2, _y2, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT), 0xffffff00);
#endif
}

void DrawParametricLine(int _x1, int _y1, int _x2, int _y2, unsigned int * pixelArray, unsigned int pixelArraySize, unsigned int color)
{
	//True would mean x axis, false means y axis
	bool primAxis = false;
	bool secAxis = false;

	if (abs(_x2 - _x1) > abs(_y2 - _y1)) {//If the x distance is longer
		primAxis = true;//X is the primary axis
	}
	else {
		secAxis = true;//X is the secondary axis
	}





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
			float currX = (float)Lerp((float)_x2, (float)_x1, ratio);
			float currY = (float)Lerp((float)_y2, (float)_y1, ratio);
			PaintPixel(pixelArray, From2Dto1D((int)currX, (int)currY, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT), color);
		}
	}
	else
	{
		for (unsigned int i = startPrimary; i > endPrimary; --i)
		{
			float ratio = ((float)startPrimary - (float)i) / ((float)startPrimary - (float)endPrimary);
			float currX = (float)Lerp((float)_x1, (float)_x2, ratio);
			float currY = (float)Lerp((float)_y1, (float)_y2, ratio);
			PaintPixel(pixelArray, From2Dto1D((int)currX, (int)currY, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT), color);
		}
	}

#ifdef _RASTERDEBUG
	PaintPixel(pixelArray, From2Dto1D(_x1, _y1, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT), 0xffffff00);
	PaintPixel(pixelArray, From2Dto1D(_x2, _y2, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT), 0xffffff00);
#endif
}

void DrawParametricLineGradiantColor(int _x1, int _y1, int _x2, int _y2, unsigned int * pixelArray, unsigned int pixelArraySize, unsigned int _red, unsigned int _green, unsigned int _blue, unsigned int _alpha, unsigned int _red2, unsigned int _green2, unsigned int _blue2, unsigned int _alpha2)
{

	//True would mean x axis, false means y axis
	bool primAxis = false;
	bool secAxis = false;

	if (abs(_x2 - _x1) > abs(_y2 - _y1)) {//If the x distance is longer
		primAxis = true;//X is the primary axis
	}
	else {
		secAxis = true;//X is the secondary axis
	}


		


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
			float currX = (float)Lerp((float)_x2, (float)_x1, ratio);
			float currY = (float)Lerp((float)_y2, (float)_y1, ratio);
			int red = (int)Lerp((float)_red, (float)_red2, ratio);
			int green = (int)Lerp((float)_green, (float)_green2, ratio);
			int blue = (int)Lerp((float)_blue, (float)_blue2, ratio);
			PaintPixel(pixelArray, From2Dto1D((int)currX, (int)currY, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT), ConvertColorRGBA(red, blue, green, _alpha));
		}
	}
	else
	{
		for (unsigned int i = startPrimary; i > endPrimary; --i)
		{
			float ratio = ((float)startPrimary - (float)i) / ((float)startPrimary - (float)endPrimary);
			float currX = (float)Lerp((float)_x1, (float)_x2, ratio);
			float currY = (float)Lerp((float)_y1, (float)_y2, ratio);
			int red = (int)Lerp((float)_red, (float)_red2, ratio);
			int green = (int)Lerp((float)_green, (float)_green2, ratio);
			int blue = (int)Lerp((float)_blue, (float)_blue2, ratio);
			PaintPixel(pixelArray, From2Dto1D((int)currX, (int)currY, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT), ConvertColorRGBA(red, blue, green, _alpha));
		}
	}

#ifdef _RASTERDEBUG
	PaintPixel(pixelArray, From2Dto1D(_x1, _y1, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT), 0xffffff00);
	PaintPixel(pixelArray, From2Dto1D(_x2, _y2, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT), 0xffffff00);
#endif
}

unsigned int ConvertColorRGBA(unsigned int _red, unsigned int _green, unsigned int _blue, unsigned int _alpha)
{
	unsigned int returnColor = 0;
	unsigned int alpha = _alpha << 24;
	unsigned int red = _red << 16;
	unsigned int green = _green << 8;
	unsigned int blue = _blue;


	returnColor = (((returnColor | red) | green) | blue) | alpha;

	return returnColor;
}

unsigned int BGRAtoARGB(unsigned int _pixel)
{

	unsigned int incomingRed = ((_pixel >> 8) << 24) >> 8;
	unsigned int incomingGreen = ((_pixel << 8) >> 24) << 8;
	unsigned int incomingBlue = _pixel >> 24;
	unsigned int incomingAlpha = _pixel << 24;

	unsigned int finalColor = (((0 | incomingRed) | incomingBlue) | incomingGreen) | incomingAlpha;
	return finalColor;
}


