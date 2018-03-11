#include "defines.h"

Triangle::Triangle(float _x1, float _y1, float _x2, float _y2, float _x3, float _y3)
{
	point1x = _x1;
	point1y = _y1;

	point2x = _x2;
	point2y = _y2;

	point3x = _x3;
	point3y = _y3;

	RasterPoints = ConvertFromNDCtoRaster(SCREEN_WIDTH, SCREEN_HEIGHT);
}

Triangle::~Triangle()
{
	delete[] RasterPoints;
}

unsigned int* Triangle::ConvertFromNDCtoRaster(int maxWidth, int maxHeight)
{
	unsigned int* pointsArray;
	pointsArray = new unsigned int[6];

	pointsArray[0] = ((point1x + 1) / 2) *  maxWidth;
	pointsArray[1] = ((point1y - 1) / 2) * maxHeight;

	pointsArray[2] = ((point2x + 1) / 2) *  maxWidth;
	pointsArray[3] = ((point2y - 1) / 2) * maxHeight;

	pointsArray[4] = ((point3x + 1) / 2) *  maxWidth;
	pointsArray[5] = ((point3y - 1) / 2) * maxHeight;

	return pointsArray;
}
