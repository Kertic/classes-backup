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
