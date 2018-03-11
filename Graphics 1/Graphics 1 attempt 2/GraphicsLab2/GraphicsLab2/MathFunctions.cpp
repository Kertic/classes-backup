#include "MathFunctions.h"

int From2Dto1D(int _x, int _y, int _minX, int _minY, int _maxX, int _maxY)
{
	int value = 0;
	/*int disjointX = _maxX - _minX;
	int disjointY = _maxY - _minY;*/




	value = (_y * (_maxX - _minX)) + _x;

	return value;
}

float Lerp(float start, float end, float ratio)
{
	float diff = (end - start);
	float position = diff * ratio;
	float adjustedPostition = position + start;
	return (end - start) * ratio + start;
}

float ImplicitLineEquation(float _x1, float _y1, float _x2, float _y2, float _xCheck, float _yCheck)
{

	//(Y1 – Y2)x + (X2 – X1)y + X1Y2 – Y1X2 = 0
	float term1 = (_y1 - _y2) * _xCheck;
	float term2 = (_x2 - _x1) * _yCheck;
	float term3 = _x1 * _y2;
	float term4 = _y1 * _x2;
	float result = term1 + term2 + term3 - term4;
	return result;
}
