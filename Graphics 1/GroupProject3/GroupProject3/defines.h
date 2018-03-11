#pragma once

#define SCREEN_WIDTH 250
#define SCREEN_HEIGHT 250
#define SCREEN_ARRAY_SIZE SCREEN_WIDTH * SCREEN_HEIGHT

struct Triangle {
	float point1x;
	float point1y;

	float point2x;
	float point2y;
	
	float point3x;
	float point3y;

	float colorRGBA[4];

	unsigned int* RasterPoints;

public:

	Triangle(float _x1, float _y1, float _x2, float _y2, float _x3, float _y3);
	~Triangle();
	unsigned int* ConvertFromNDCtoRaster(int maxWidth, int maxHeight);
};