#pragma once

#include "defines.h"
#include <math.h>

//We have an NDC x, y, and z
struct Vector {
	float x, y, z, w;

	Vector(float x, float y, float z, float w);
};

struct Matrix4x4 {
	float a1, b1, c1, d1,
		a2, b2, c2, d2,
		a3, b3, c3, d3,
		a4, b4, c4, d4;

	Matrix4x4(float a1, float b1, float c1, float d1,
		float a2, float b2, float c2, float d2,
		float a3, float b3, float c3, float d3,
		float a4, float b4, float c4, float d4);

};

int From2Dto1D(int _x, int _y, int _minX, int _minY, int _maxX, int _maxY);
float Lerp(float min, float max, float ratio);
float DegtoRad(float degrees);
float ImplicitLineEquation(float _x1, float _y1, float _x2, float _y2, float _xCheck, float _yCheck);

// x/y1 is A, 2 is B and 3 is C. returnA would be the ratio of point B, returnB would be the ratio of point C, and returnC would be the ratio of point A 
void BarycentricCoords(int _x1, int _y1, int _x2, int _y2, int _x3, int _y3, int testX, int testY, float &returnA, float &returnB, float &returnC);



unsigned int NDCtoRastor(unsigned int maxWidth, unsigned int maxHeight, float inVar, bool isX);
float RastorToNDC(int maxWidth, int maxHeight, int inVar, bool isX);

#pragma region Matrix math
Matrix4x4 ZRotationMatrix(float degrees);
Vector MatrixTimesVector(Matrix4x4 inMatrix, Vector inVector);
Matrix4x4 MatrixTimesMatrix(Matrix4x4 inMatrix1, Matrix4x4 inMatrix2);
Matrix4x4 InvertMatrix(Matrix4x4 inMatrix);
#pragma endregion
