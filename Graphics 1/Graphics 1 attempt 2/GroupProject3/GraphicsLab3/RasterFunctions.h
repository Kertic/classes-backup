#pragma once
#include "shaders.h"


#pragma region Drawing




//Clears the screen by setting all pixels to "color"
void ClearScreen(unsigned int* pixelArray, unsigned int arraySize, unsigned int color);

//Sets the pixel to the color
void PaintPixel(unsigned int* pixelArray, unsigned int index, unsigned int color);

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
void Blit(unsigned int* pixelArray, const unsigned int* imageArray,
	unsigned int _maxPixelX, unsigned int _maxPixelY, unsigned int _maxImageX, unsigned int _maxImageY, 
	unsigned int _SourceTopLeftX, unsigned int _SourceTopLeftY, unsigned int _SourceBottomRightX, unsigned int _SourceBottomRightY, 
	unsigned int _DestTopLeftX, unsigned int _DestTopLeftY, unsigned int _DestBottomRightX, unsigned int _DestBottomRightY);



	#pragma region Lines
void DrawBresenhamLine(int _x1, int _y1, int _x2, int _y2, unsigned int * pixelArray, unsigned int pixelArraySize, unsigned int color);
void DrawMidpointLine(int _x1, int _y1, int _x2, int _y2, unsigned int * pixelArray, unsigned int pixelArraySize, unsigned int color);
void DrawParametricLine(int _x1, int _y1, int _x2, int _y2, unsigned int * pixelArray, unsigned int pixelArraySize, unsigned int color);
void DrawParametricLineGradiantColor(int _x1, int _y1, int _x2, int _y2, unsigned int * pixelArray, unsigned int pixelArraySize, unsigned int _red, unsigned int _green, unsigned int _blue, unsigned int _alpha, unsigned int _red2, unsigned int _green2, unsigned int _blue2, unsigned int _alpha2);
	#pragma endregion
	#pragma region Triangles
void DrawTriangleBetterBrute(int x1, int y1, int x2, int y2, int x3, int y3, unsigned int color, unsigned int * pixelArray, unsigned int arraySize);
	#pragma endregion



#pragma endregion

#pragma region Color alterations
//red, green, blue, and alpha must be between 0-255, and the function will return a single unsigned int representing that color
unsigned int ConvertColorRGBA(unsigned int _red, unsigned int _green, unsigned int _blue, unsigned int _alpha);
unsigned int BGRAtoARGB(unsigned int _pixel);
#pragma endregion


