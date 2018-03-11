#pragma once

#define SCREEN_WIDTH 500
#define SCREEN_HEIGHT 500
#define SCREEN_ARRAY_SIZE SCREEN_WIDTH * SCREEN_HEIGHT

#define PI 3.14159265


struct Vertex {
public:

	float xyzw[4];

	unsigned int color;


	void SetColor(int _red, int _green, int _blue, int _alpha);
};


struct Triangle {

public:
	
	//float point1x;
	//float point1y;

	//float point2x;
	//float point2y;
	//
	//float point3x;
	//float point3y;

	Vertex vert1;
	Vertex vert2;
	Vertex vert3;
	
	// this is a size of 6, {x1, y1, x2, y2, x3, y3}

	unsigned int* RasterPoints = nullptr;


	Triangle(float _x1, float _y1, float _z1, float _x2, float _y2, float _z2, float _x3, float _y3, float _z3);
	~Triangle();
	unsigned int* ConvertFromNDCtoRaster(int maxWidth, int maxHeight);



	void SetPositions(float _x1, float _y1, float _z1, float _x2, float _y2, float _z2, float _x3, float _y3, float _z3);
};


