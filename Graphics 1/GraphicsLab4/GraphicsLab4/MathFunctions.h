#pragma once
#include "defines.h"
#include <math.h>


//A group of 4 floats
struct Vector
{
public:

	float x, y, z, w;

	Vector(float x, float y, float z, float w);
};

//A group of 16 floats, each representing a spot in the matrix
struct Matrix {

public:

	float index11, index12, index13, index14, index21, index22, index23, index24, index31, index32, index33, index34, index41, index42, index43, index44;

	Matrix(float _index11, float _index12, float  _index13, float _index14,
		float _index21, float _index22, float _index23, float _index24,
		float _index31, float _index32, float _index33, float _index34,
		float _index41, float _index42, float _index43, float  _index44);
};


unsigned int To1d(unsigned int _dimX, unsigned int _dimY, unsigned int _maxX, unsigned int _maxY);
unsigned int Lerp(int ending, int starting, float ratio);
float ImplicitLineEquation(int _x1, int _x2, int _y1, int _y2, float midx, float midy);

//Returns a value from within range 1 (bottom and top 1) as a value in the same spot but in range 2 (bottom and top 2)
unsigned int Map(unsigned int bottom1, unsigned int top1, unsigned int bottom2, unsigned int top2, unsigned int value);


void BarycentricCoords(unsigned int _x1, unsigned int _y1, unsigned int _x2, unsigned int _y2, unsigned int _x3, unsigned int _y3, unsigned int testX, unsigned int testY, float &returnA, float &returnB, float &returnC);

float DegtoRad(float degrees);
Matrix ZRotationMatrix(float degrees);
Vector MultiplyVectorByMatrix(Matrix _matrixToMultBy, Vector _vectorToMult);

unsigned int NDCtoRastor(unsigned int maxWidth, unsigned int maxHeight, float inVar, bool isX);
float RastorToNDC(int maxWidth, int maxHeight, int inVar, bool isX);




