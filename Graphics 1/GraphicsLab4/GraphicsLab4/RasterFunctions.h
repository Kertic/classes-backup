#pragma once

#include"Shaders.h"
#include <assert.h>







void ClearBuffer(unsigned int* _pixelArray, unsigned int arraySize);
void SetPixel(unsigned int* _pixelArray, unsigned int _pixelArraySize, unsigned int _pixelIndex, unsigned int _red, unsigned int _blue, unsigned int _green, unsigned int _alpha);
void SetPixel(unsigned int* _pixelArray, unsigned int _pixelArraySize, unsigned int _pixelIndex, unsigned int _color);
unsigned int To1d(unsigned int _dimX, unsigned int _dimY, unsigned int _maxX, unsigned int _maxY);
void Blit(unsigned int sourceRectangleXMin, unsigned int sourceRectangleYMin, unsigned int sourceRectangleXMax, unsigned int sourceRectangleYMax, unsigned int startingDestinationPosX, unsigned int startingDestinationPosY, unsigned int* destinationArray, const unsigned int* sourceArray, unsigned int destinationArrayWidth, unsigned int destinationArrayHeight, unsigned int sourceArrayWidth, unsigned int sourceArrayHeight);
unsigned int Map(unsigned int bottom1, unsigned int top1, unsigned int bottom2, unsigned int top2, unsigned int value);
unsigned int ConvertFormat(unsigned int numberToConvert);
unsigned int Lerp(int bottom, int top, float ratio);
void DrawLineParametric(int _x1, int _x2, int _y1, int _y2, unsigned int* _pixelArray, unsigned int _pixelArraySize, unsigned int _pixelArrayWidth, unsigned int _pixelArrayHeight, unsigned int _red, unsigned int _green, unsigned int _blue, unsigned int _alpha, unsigned int _red2, unsigned int _green2, unsigned int _blue2, unsigned int _alpha2);
void DrawLineBresenham(int _x1, int _x2, int _y1, int _y2, unsigned int* _pixelArray, unsigned int _pixelArraySize, unsigned int _pixelArrayWidth, unsigned int _pixelArrayHeight, unsigned int _red, unsigned int _green, unsigned int _blue, unsigned int _alpha);
void DrawLineMidpoint(int _x1, int _x2, int _y1, int _y2, unsigned int* _pixelArray, unsigned int _pixelArraySize, unsigned int _pixelArrayWidth, unsigned int _pixelArrayHeight, unsigned int _red, unsigned int _green, unsigned int _blue, unsigned int _alpha);
float ImplicitLineEquation(int _x1, int _x2, int _y1, int _y2, float midx, float midy);