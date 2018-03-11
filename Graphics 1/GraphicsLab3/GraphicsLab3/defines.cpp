#include "defines.h"

Triangle::Triangle(float _x1, float _y1, float _z1, float _x2, float _y2, float _z2, float _x3, float _y3, float _z3)
{
	vert1.xyzw[0] = _x1;
	vert1.xyzw[1] = _y1;
	vert1.xyzw[2] = _z1;
	vert1.xyzw[3] = 0;

	vert2.xyzw[0] = _x2;
	vert2.xyzw[1] = _y2;
	vert2.xyzw[2] = _z2;
	vert2.xyzw[3] = 0;

	vert3.xyzw[0] = _x3;
	vert3.xyzw[1] = _y3;
	vert3.xyzw[2] = _z3;
	vert3.xyzw[3] = 0;

	RasterPoints = ConvertFromNDCtoRaster(SCREEN_WIDTH, SCREEN_HEIGHT);






}

Triangle::~Triangle()
{
	delete[] RasterPoints;
}

unsigned int* Triangle::ConvertFromNDCtoRaster(int maxWidth, int maxHeight)
{
	if (RasterPoints != nullptr)
		delete[] RasterPoints;


	unsigned int* pointsArray;
	pointsArray = new unsigned int[6];

	pointsArray[0] = ((vert1.xyzw[0] + 1.0f) / 2.0f) *  maxWidth;
	pointsArray[1] = ((vert1.xyzw[1] - 1.0f) / 2.0f) * (0 - maxHeight);

	pointsArray[2] = ((vert2.xyzw[0] + 1.0f) / 2.0f) *  maxWidth;
	pointsArray[3] = ((vert2.xyzw[1] - 1.0f) / 2.0f) * (0 - maxHeight);

	pointsArray[4] = ((vert3.xyzw[0] + 1.0f) / 2.0f) *  maxWidth;
	pointsArray[5] = ((vert3.xyzw[1] - 1.0f) / 2.0f) * (0 - maxHeight);

	return pointsArray;
}



void Triangle::SetPositions(float _x1, float _y1, float _z1, float _x2, float _y2, float _z2, float _x3, float _y3, float _z3)
{
	vert1.xyzw[0] = _x1;
	vert1.xyzw[1] = _y1;
	vert1.xyzw[2] = _z1;
	vert1.xyzw[3] = 0;

	vert2.xyzw[0] = _x2;
	vert2.xyzw[1] = _y2;
	vert2.xyzw[2] = _z2;
	vert2.xyzw[3] = 0;

	vert3.xyzw[0] = _x3;
	vert3.xyzw[1] = _y3;
	vert3.xyzw[2] = _z3;
	vert3.xyzw[3] = 0;

	RasterPoints = ConvertFromNDCtoRaster(SCREEN_WIDTH, SCREEN_HEIGHT);
}

void Vertex::SetColor(int _red, int _green, int _blue, int _alpha)
{

	unsigned int pixel = 0x00000000;
	pixel = pixel | (_alpha << 24);
	pixel = pixel | (_red << 16);
	pixel = pixel | (_green << 8);
	pixel = pixel | (_blue);

	color = pixel;   

}
