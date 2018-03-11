#pragma once
#include "shaders.h"




void ClearScreen(unsigned int* pixelArray, unsigned int arraySize, unsigned int color) {

	for (unsigned int i = 0; i < arraySize; ++i) {
		pixelArray[i] = color;
	}

}
void PaintPixel(unsigned int * pixelArray, unsigned int index, unsigned int color, float zDepth, float* zBuffer, unsigned int zBufferSize)
{

	if (index > SCREEN_SIZE || index < 0)
		return;

	if (zDepth > zBuffer[index])
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

	if (PixelShader)
		PixelShader(finalColor);


	if (finalColor == 0x0)
		int x = 0;

	pixelArray[index] = finalColor;
	zBuffer[index] = zDepth;
}
unsigned int ModulateColor(unsigned int color1, unsigned int color2) {
	unsigned int firstAlpha = (color1 & 0xff000000) >> 24;
	unsigned int firstRed = (color1 & 0x00ff0000) >> 16;
	unsigned int firstGreen = (color1 & 0x0000ff00) >> 8;
	unsigned int firstBlue = (color1 & 0x000000ff);

	unsigned int secondAlpha = (color2 & 0xff000000) >> 24;
	unsigned int secondRed = (color2 & 0x00ff0000) >> 16;
	unsigned int secondGreen = (color2 & 0x0000ff00) >> 8;
	unsigned int secondBlue = (color2 & 0x000000ff);

	float firstAlphaRatio = (float)firstAlpha / 255.0f;
	float firstRedRatio = (float)firstRed / 255.0f;
	float firstGreenRatio = (float)firstGreen / 255.0f;
	float firstBlueRatio = (float)firstBlue / 255.0f;

	float secondAlphaRatio = (float)secondAlpha / 255.0f;
	float secondRedRatio = (float)secondRed / 255.0f;
	float secondGreenRatio = (float)secondGreen / 255.0f;
	float secondBlueRatio = (float)secondBlue / 255.0f;

	float finalAlpha = firstAlphaRatio * secondAlphaRatio;
	float finalRed = firstRedRatio * secondRedRatio;
	float finalGreen = firstGreenRatio * secondGreenRatio;
	float finalBlue = firstBlueRatio * secondBlueRatio;

	unsigned int finalAlphaCh = finalAlpha * 255.0f;
	unsigned int finalRedCh = finalRed * 255.0f;
	unsigned int finalGreenCh = finalGreen * 255.0f;
	unsigned int finalBlueCh = finalBlue * 255.0f;

	finalAlphaCh = finalAlphaCh << 24;
	finalRedCh = finalRedCh << 16;
	finalGreenCh = finalGreenCh << 8;

	return finalAlphaCh | finalRedCh | finalGreenCh | finalBlueCh;

}
unsigned int AddColors(unsigned int color1, unsigned int color2) {
	unsigned int firstAlpha = (color1 & 0xff000000) >> 24;
	unsigned int firstRed = (color1 & 0x00ff0000) >> 16;
	unsigned int firstGreen = (color1 & 0x0000ff00) >> 8;
	unsigned int firstBlue = (color1 & 0x000000ff);

	unsigned int secondAlpha = (color2 & 0xff000000) >> 24;
	unsigned int secondRed = (color2 & 0x00ff0000) >> 16;
	unsigned int secondGreen = (color2 & 0x0000ff00) >> 8;
	unsigned int secondBlue = (color2 & 0x000000ff);

	unsigned int finalAlpha = firstAlpha + secondAlpha;
	unsigned int finalRed = firstRed + secondRed;
	unsigned int finalGreen = firstGreen + secondGreen;
	unsigned int finalBlue = firstBlue + secondBlue;

	if (finalAlpha > 255)
		finalAlpha = 255;
	if (finalRed > 255)
		finalRed = 255;
	if (finalBlue > 255)
		finalBlue = 255;
	if (finalGreen > 255)
		finalGreen = 255;

	if (finalAlpha < 0)
		finalAlpha = 0;
	if (finalRed < 0)
		finalRed = 0;
	if (finalBlue < 0)
		finalBlue = 0;
	if (finalGreen < 0)
		finalGreen = 0;

	finalAlpha = finalAlpha << 24;
	finalRed = finalRed << 16;
	finalGreen = finalGreen << 8;

	return finalAlpha | finalRed | finalGreen | finalBlue;
}


void DrawParametricLine(Vector point1, Vector point2, unsigned int * pixelArray, unsigned int pixelArraySize, unsigned int color, float* zbuffer, unsigned int zbuffersize)
{
	Vector augmentedPoint1 = point1;
	Vector augmentedPoint2 = point2;

	if (VertexShader) {
		augmentedPoint1 = VertexShader(point1);
		augmentedPoint2 = VertexShader(point2);
	}


	//True would mean x axis, false means y axis
	bool primAxis = false;
	bool secAxis = false;

	int _x1 = NDCtoRastor(SCREEN_WIDTH, SCREEN_HEIGHT, augmentedPoint1.x, true);
	int _x2 = NDCtoRastor(SCREEN_WIDTH, SCREEN_HEIGHT, augmentedPoint2.x, true);
	int _y1 = NDCtoRastor(SCREEN_WIDTH, SCREEN_HEIGHT, augmentedPoint1.y, false);
	int _y2 = NDCtoRastor(SCREEN_WIDTH, SCREEN_HEIGHT, augmentedPoint2.y, false);


	if (abs(_x2 - _x1) > abs(_y2 - _y1)) {//If the x distance is longer
		primAxis = true;//X is the primary axis
	}
	else {
		secAxis = true;//X is the secondary axis
	}





	//int magnitude = (int)sqrt(((_y2 - _y1) * (_y2 - _y1)) + ((_x2 - _x1) * (_x2 - _x1)));
	int startPrimary = 0;
	int endPrimary = 0;

	int startSecondary = 0;
	int endSecondary = 0;
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
		for (int i = startPrimary; i < endPrimary; i++)
		{
			float ratio = ((float)i - (float)startPrimary) / ((float)endPrimary - (float)startPrimary);
			float currX = (float)round(Lerp((float)_x2, (float)_x1, ratio));
			float currY = (float)round(Lerp((float)_y2, (float)_y1, ratio));

			float currZ = Lerp(augmentedPoint2.z, augmentedPoint1.z, ratio);
			/*if (augmentedPoint1.z > augmentedPoint2.z)
				currZ = Lerp(augmentedPoint2.z, augmentedPoint1.z, ratio);*/

			PaintPixel(pixelArray, From2Dto1D((int)currX, (int)currY, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT), color, currZ, zbuffer, zbuffersize);
		}
}
	else
	{
		for (int i = startPrimary; i > endPrimary; --i)
		{
			float ratio = ((float)startPrimary - (float)i) / ((float)startPrimary - (float)endPrimary);
			float currX = (float)round(Lerp((float)_x1, (float)_x2, ratio));
			float currY = (float)round(Lerp((float)_y1, (float)_y2, ratio));

			float currZ = Lerp(augmentedPoint1.z, augmentedPoint2.z, ratio);
			//if (augmentedPoint1.z < augmentedPoint2.z)
			//	currZ = Lerp(augmentedPoint2.z, augmentedPoint1.z, ratio);

			PaintPixel(pixelArray, From2Dto1D((int)currX, (int)currY, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT), color, currZ, zbuffer, zbuffersize);
		}
	}

#ifdef _RASTERDEBUG
	PaintPixel(pixelArray, From2Dto1D(_x1, _y1, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT), 0xffffff00);
	PaintPixel(pixelArray, From2Dto1D(_x2, _y2, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT), 0xffffff00);
#endif
}
void DrawTriangleBetterBrute(Vector point1, Vector point2, Vector point3, unsigned int color, unsigned int * pixelArray, unsigned int arraySize, float* zbuffer, unsigned int zbuffersize)
{
	Vector augmentedVector1 = point1;
	Vector augmentedVector2 = point2;
	Vector augmentedVector3 = point3;

	if (VertexShader)
	{
		augmentedVector1 = VertexShader(point1);
		augmentedVector2 = VertexShader(point2);
		augmentedVector3 = VertexShader(point3);
	}

	int x1 = NDCtoRastor(SCREEN_WIDTH, SCREEN_HEIGHT, augmentedVector1.x, true);
	int x2 = NDCtoRastor(SCREEN_WIDTH, SCREEN_HEIGHT, augmentedVector2.x, true);
	int x3 = NDCtoRastor(SCREEN_WIDTH, SCREEN_HEIGHT, augmentedVector3.x, true);

	int y1 = NDCtoRastor(SCREEN_WIDTH, SCREEN_HEIGHT, augmentedVector1.y, false);
	int y2 = NDCtoRastor(SCREEN_WIDTH, SCREEN_HEIGHT, augmentedVector2.y, false);
	int y3 = NDCtoRastor(SCREEN_WIDTH, SCREEN_HEIGHT, augmentedVector3.y, false);


	int minX = _CRT_INT_MAX;
	int maxX = -2147483647;
	int minY = _CRT_INT_MAX;
	int maxY = -2147483647;

#pragma region Determine Minimum X and Y
	int xs[] = { x1,x2,x3 };
	int ys[] = { y1,y2,y3 };

	for (int i = 0; i < 3; i++)
	{
		if (xs[i] < minX)
			minX = xs[i];
		if (ys[i] < minY)
			minY = ys[i];

		if (xs[i] > maxX)
			maxX = xs[i];
		if (ys[i] > maxY)
			maxY = ys[i];
	}



#pragma endregion


	float originalU1 = augmentedVector1.u;
	float originalU2 = augmentedVector2.u;
	float originalU3 = augmentedVector3.v;
	float originalV1 = augmentedVector1.v;
	float originalV2 = augmentedVector2.v;
	float originalV3 = augmentedVector3.v;

	for (int x = minX; x < maxX; x++)
	{
		for (int y = minY; y < maxY; y++)
		{


			float a;
			float b;
			float c;

			BarycentricCoords((float)x1, (float)y1, (float)x2, (float)y2, (float)x3, (float)y3, (float)x, (float)y, a, b, c);

			if (a < 0 || a > 1 || b < 0 || b > 1 || c < 0 || c > 1) {
				//Fail case

			}
			else
			{
				if (!(x < 0 || x > SCREEN_WIDTH || y < 0 || y > SCREEN_HEIGHT)) {
					//Success case


					//c is point 1, a is point 2, and b is point 3

					float redCh = 255 * c;
					float greenCh = 255 * a;
					float blueCh = 255 * b;
					unsigned int FinalColor = ConvertColorRGBA((unsigned int)redCh, (unsigned int)greenCh, (unsigned int)blueCh, 255);

					float RecipLinearZ1 = 1.0f / augmentedVector1.w;
					float RecipLinearZ2 = 1.0f / augmentedVector2.w;
					float RecipLinearZ3 = 1.0f / augmentedVector3.w;

					RecipLinearZ1 *= c;
					RecipLinearZ2 *= a;
					RecipLinearZ3 *= b;

					float PixelsInterpolatedRecipLinearZ = RecipLinearZ1 + RecipLinearZ2 + RecipLinearZ3;


					augmentedVector1.u = originalU1;
					augmentedVector2.u = originalU2;
					augmentedVector3.u = originalU3;

					augmentedVector1.v = originalV1;
					augmentedVector2.v = originalV2;
					augmentedVector3.v = originalV3;


					augmentedVector1.u /= augmentedVector1.w;
					augmentedVector2.u /= augmentedVector2.w;
					augmentedVector3.u /= augmentedVector3.w;

					augmentedVector1.v /= augmentedVector1.w;
					augmentedVector2.v /= augmentedVector2.w;
					augmentedVector3.v /= augmentedVector3.w;

					TextureU = (c * augmentedVector1.u) + (a * augmentedVector2.u) + (b * augmentedVector3.u);
					TextureV = (c * augmentedVector1.v) + (a * augmentedVector2.v) + (b * augmentedVector3.v);

					TextureU /= PixelsInterpolatedRecipLinearZ;
					TextureV /= PixelsInterpolatedRecipLinearZ;





					//c is point 1, a is point 2, and b is point 3
					float currentZ = (c * augmentedVector1.z) + (a * augmentedVector2.z) + (b * augmentedVector3.z);

					/*	if (TextureU < 0)
							TextureU = -TextureU;
						if (TextureU > 1)
							TextureU -= (int)TextureU;


						if (TextureV < 0)
							TextureV = -TextureV;
						if (TextureV > 1)
							TextureV -= (int)TextureV;*/


					if (PixelShader)
						PixelShader(FinalColor);

					PaintPixel(pixelArray, From2Dto1D(x, y, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT), FinalColor, currentZ, zbuffer, zbuffersize);
				}


			}
		}
	}

}


void ClearExponentialZBuffer(float* inZBuffer, unsigned int arraySize) {
	for (unsigned int i = 0; i < arraySize; i++)
	{
		inZBuffer[i] = 1.0f;
	}
}
void ClearLinearZBuffer(float* inWBuffer, unsigned int arraySize, float farPlane) {
	for (unsigned int i = 0; i < arraySize; i++)
	{
		inWBuffer[i] = farPlane;
	}
}


#pragma region Deprecated
//=====Deprecated=====
//pixelArray = destination array
//imageArray = Source array
//MaxPixelX = The Maximum possible value for the Destination array X
//MaxPixelY = The Maximum possible value for the Destination Array y
//MaxImageX = Max possible value for source image x
//MaxImageY = Max possible value for souce image y
//SourceTopLeftX = The X dimension of the top left corner for the image you want to blit
//SourceTopLeftY = The Y dimension of the top left corner of the image you want to blit
//SourceBottomRightX = The X dimension of the bottom right image you want to blit
//SourceBottomRightY = The Y dimension of the bottom right image you want to blit
//DestTopLeftX = The X dimension of the top left corner for the array you want to blit onto
//DestTopLeftY = The Y dimension of the top left corner of the array you want to blit onto
//DestBottomRightX = The X dimension of the bottom right array you want to blit onto
//DestBottomRightY = The Y dimension of the bottom right array you want to blit onto
void Blit(
	unsigned int * pixelArray, const unsigned int * imageArray,
	unsigned int _maxPixelX, unsigned int _maxPixelY, unsigned int _maxImageX, unsigned int _maxImageY,
	unsigned int _SourceTopLeftX, unsigned int _SourceTopLeftY, unsigned int _SourceBottomRightX, unsigned int _SourceBottomRightY,
	unsigned int _DestTopLeftX, unsigned int _DestTopLeftY, unsigned int _DestBottomRightX, unsigned int _DestBottomRightY, float* zbuffer, unsigned int zbufferSize)
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
				imageArray[From2Dto1D(x, y, 0, 0, _maxImageX, _maxImageY)],
				0.0f, zbuffer, zbufferSize);
		}
	}

}

//Deprecated
void DrawBresenhamLine(int _x1, int _y1, int _x2, int _y2, unsigned int * pixelArray, unsigned int pixelArraySize, unsigned int color, float* zbuffer, unsigned int zbuffersize)
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

					PaintPixel(pixelArray, From2Dto1D(i, currentSecondary, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT), color, 0.0f, zbuffer, zbuffersize);
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

					PaintPixel(pixelArray, From2Dto1D(i, currentSecondary, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT), color, 0.0f, zbuffer, zbuffersize);
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

					PaintPixel(pixelArray, From2Dto1D(currentSecondary, i, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT), color, 0.0f, zbuffer, zbuffersize);
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

					PaintPixel(pixelArray, From2Dto1D(currentSecondary, i, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT), color, 0.0f, zbuffer, zbuffersize);
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

					PaintPixel(pixelArray, From2Dto1D(i, currentSecondary, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT), color, 0.0f, zbuffer, zbuffersize);
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

					PaintPixel(pixelArray, From2Dto1D(i, currentSecondary, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT), color, 0.0f, zbuffer, zbuffersize);
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

					PaintPixel(pixelArray, From2Dto1D(currentSecondary, i, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT), color, 0.0f, zbuffer, zbuffersize);
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
					PaintPixel(pixelArray, From2Dto1D(currentSecondary, i, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT), color, 0.0f, zbuffer, zbuffersize);
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
//Deprecated
void DrawMidpointLine(int _x1, int _y1, int _x2, int _y2, unsigned int * pixelArray, unsigned int pixelArraySize, unsigned int color, float* zbuffer, unsigned int zbuffersize)
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

					PaintPixel(pixelArray, From2Dto1D(i, (int)currentSecondary, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT), color, 0.0f, zbuffer, zbuffersize);
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

					PaintPixel(pixelArray, From2Dto1D(i, (int)currentSecondary, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT), color, 0.0f, zbuffer, zbuffersize);
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

					PaintPixel(pixelArray, From2Dto1D(i, (int)currentSecondary, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT), color, 0.0f, zbuffer, zbuffersize);
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

					PaintPixel(pixelArray, From2Dto1D(i, (int)currentSecondary, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT), color, 0.0f, zbuffer, zbuffersize);
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

					PaintPixel(pixelArray, From2Dto1D((int)currentSecondary, i, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT), color, 0.0f, zbuffer, zbuffersize);
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

					PaintPixel(pixelArray, From2Dto1D((int)currentSecondary, i, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT), color, 0.0f, zbuffer, zbuffersize);
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

					PaintPixel(pixelArray, From2Dto1D((int)currentSecondary, i, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT), color, 0.0f, zbuffer, zbuffersize);
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

					PaintPixel(pixelArray, From2Dto1D((int)currentSecondary, i, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT), color, 0.0f, zbuffer, zbuffersize);
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
void DrawParametricLineGradiantColor(int _x1, int _y1, int _x2, int _y2, unsigned int * pixelArray, unsigned int pixelArraySize, unsigned int _red, unsigned int _green, unsigned int _blue, unsigned int _alpha, unsigned int _red2, unsigned int _green2, unsigned int _blue2, unsigned int _alpha2, float* zbuffer, unsigned int zbuffersize)
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
			PaintPixel(pixelArray, From2Dto1D((int)currX, (int)currY, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT), ConvertColorRGBA(red, blue, green, _alpha), 0.0f, zbuffer, zbuffersize);
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
			PaintPixel(pixelArray, From2Dto1D((int)currX, (int)currY, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT), ConvertColorRGBA(red, blue, green, _alpha), 0.0f, zbuffer, zbuffersize);
		}
	}

#ifdef _RASTERDEBUG
	PaintPixel(pixelArray, From2Dto1D(_x1, _y1, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT), 0xffffff00);
	PaintPixel(pixelArray, From2Dto1D(_x2, _y2, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT), 0xffffff00);
#endif
	}


#pragma endregion