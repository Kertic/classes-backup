#include "RasterFunctions.h"













void ClearScreen(unsigned int* pixelArray, unsigned int arraySize, unsigned int color) {

	for (unsigned int i = 0; i < arraySize; ++i) {
		pixelArray[i] = color;
	}

}

void PaintPixel(unsigned int * pixelArray, unsigned int index, unsigned int color)
{
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
	unsigned int * pixelArray, unsigned int * imageArray,
	unsigned int _maxPixelX, unsigned int _maxPixelY, unsigned int _maxImageX, unsigned int _maxImageY, 
	unsigned int _SourceTopLeftX, unsigned int _SourceTopLeftY, unsigned int _SourceBottomRightX, unsigned int _SourceBottomRightY, 
	unsigned int _DestTopLeftX, unsigned int _DestTopLeftY, unsigned int _DestBottomRightX, unsigned int _DestBottomRightY)
{
	for (unsigned int x = _SourceTopLeftX; x < _SourceBottomRightX; x++)
	{
		if (x > _maxPixelX || x > _maxImageX)
			break;
		for (unsigned int y = _SourceTopLeftY; y < _SourceBottomRightY; y++)
		{
			if (y > _maxPixelY || y > _maxImageY)
				break;

				pixelArray[From2Dto1D(
					x - _SourceTopLeftX + _DestTopLeftX,
					y - _SourceTopLeftY + _DestTopLeftY,
					0, 0, _maxPixelX, _maxPixelY)] 
				= 
				imageArray[From2Dto1D(x, y, 0, 0, _maxImageX, _maxImageY)];
		}
	}

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


