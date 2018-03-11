#include "MathFunctions.h"


Vector::Vector(float x, float y, float z, float w)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

Matrix4x4::Matrix4x4(float a1, float b1, float c1, float d1, float a2, float b2, float c2, float d2, float a3, float b3, float c3, float d3, float a4, float b4, float c4, float d4)
{
	this->a1 = a1;
	this->b1 = b1;
	this->c1 = c1;
	this->d1 = d1;

	this->a2 = a2;
	this->b2 = b2;
	this->c2 = c2;
	this->d2 = d2;

	this->a3 = a3;
	this->b3 = b3;
	this->c3 = c3;
	this->d3 = d3;

	this->a4 = a4;
	this->b4 = b4;
	this->c4 = c4;
	this->d4 = d4;

}

int From2Dto1D(int _x, int _y, int _minX, int _minY, int _maxX, int _maxY)
{
	int value = 0;





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
float DegtoRad(float degrees) {
	return degrees * PI / 180;
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


// x/y1 is A, 2 is B and 3 is C. returnA would be the ratio of point B, returnB would be the ratio of point C, and returnC would be the ratio of point A 
void BarycentricCoords(int _x1, int _y1, int _x2, int _y2, int _x3, int _y3, int testX, int testY, float &returnA, float &returnB, float &returnC) {
	float beta = 0.0;
	float alpha = 0.0;
	float gamma = 0.0;

	float a = 0.0;
	float b = 0.0;
	float y = 0.0;

	beta = ImplicitLineEquation((float)_x1, (float)_y1, (float)_x3, (float)_y3, (float)_x2, (float)_y2);//Line AC, testing B
	gamma = ImplicitLineEquation((float)_x2, (float)_y2, (float)_x1, (float)_y1, (float)_x3, (float)_y3);//Line BA, testing C
	alpha = ImplicitLineEquation((float)_x3, (float)_y3, (float)_x2, (float)_y2, (float)_x1, (float)_y1);//Line CB, testing A

	b = ImplicitLineEquation((float)_x1, (float)_y1, (float)_x3, (float)_y3, (float)testX, (float)testY);//Line AC, testing testPixel
	y = ImplicitLineEquation((float)_x2, (float)_y2, (float)_x1, (float)_y1, (float)testX, (float)testY);//Line CB, testing testPixel
	a = ImplicitLineEquation((float)_x3, (float)_y3, (float)_x2, (float)_y2, (float)testX, (float)testY);//Line CB, testing testPixel

	returnA = b / beta;
	returnB = y / gamma;
	returnC = a / alpha;


}

unsigned int NDCtoRastor(unsigned int maxWidth, unsigned int maxHeight, float inVar, bool isX) {

	if (isX) {
		return (unsigned int)(((inVar + 1.0f) / 2.0f) * (float)maxWidth);
	}
	else
	{
		return (unsigned int)(((inVar - 1.0f) / 2.0f) * (0.0 - (float)maxHeight));
	}

}

float RastorToNDC(int maxWidth, int maxHeight, int inVar, bool isX) {
	if (isX) {
		return	((float)inVar / (float)maxWidth) * 2.0f - 1.0f;
	}
	else
	{

		return ((float)inVar / -(float)maxHeight) * 2.0f + 1.0f;
	}
}

#pragma region Matrix math
Matrix4x4 ZRotationMatrix(float degrees) {
	float Rad = DegtoRad(degrees);

	Matrix4x4 returnMatrix(
		(float)cos(Rad), (float)-sin(Rad), 0, 0,
		(float)sin(Rad), (float)cos(Rad), 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1);

	return returnMatrix;
}

Vector MatrixTimesVector(Matrix4x4 inMatrix, Vector inVector)
{
	float returnIndexX =
		(	inMatrix.a1 * inVector.x +
			inMatrix.a2 * inVector.y +
			inMatrix.a3 * inVector.z +
			inMatrix.a4 * inVector.w);

	float returnIndexY =
		(	inMatrix.b1 * inVector.x +
			inMatrix.b2 * inVector.y +
			inMatrix.b3 * inVector.z +
			inMatrix.b4 * inVector.w);

	float returnIndexZ =
		(	inMatrix.c1 * inVector.x +
			inMatrix.c2 * inVector.y +
			inMatrix.c3 * inVector.z +
			inMatrix.c4 * inVector.w);

	float returnIndexW =
		(	inMatrix.d1 * inVector.x +
			inMatrix.d2 * inVector.y +
			inMatrix.d3 * inVector.z +
			inMatrix.d4 * inVector.w);

	Vector returnVector(returnIndexX, returnIndexY, returnIndexZ, returnIndexW);

		return returnVector;
}

Matrix4x4 MatrixTimesMatrix(Matrix4x4 inMatrix1, Matrix4x4 inMatrix2)
{
//First row
	float a1 = (
		inMatrix1.a1 * inMatrix2.a1 +
		inMatrix1.b1 * inMatrix2.a2 +
		inMatrix1.c1 * inMatrix2.a3 +
		inMatrix1.d1 * inMatrix2.a4);

	float b1 = (
		inMatrix1.a1 * inMatrix2.b1 +
		inMatrix1.b1 * inMatrix2.b2 +
		inMatrix1.c1 * inMatrix2.b3 +
		inMatrix1.d1 * inMatrix2.b4);

	float c1 = (
		inMatrix1.a1 * inMatrix2.c1 +
		inMatrix1.b1 * inMatrix2.c2 +
		inMatrix1.c1 * inMatrix2.c3 +
		inMatrix1.d1 * inMatrix2.c4);

	float d1 = (
		inMatrix1.a1 * inMatrix2.d1 +
		inMatrix1.b1 * inMatrix2.d2 +
		inMatrix1.c1 * inMatrix2.d3 +
		inMatrix1.d1 * inMatrix2.d4);
	//Second row
	float a2 = (
		inMatrix1.a2 * inMatrix2.a1 +
		inMatrix1.b2 * inMatrix2.a2 +
		inMatrix1.c2 * inMatrix2.a3 +
		inMatrix1.d2 * inMatrix2.a4);

	float b2 = (
		inMatrix1.a2 * inMatrix2.b1 +
		inMatrix1.b2 * inMatrix2.b2 +
		inMatrix1.c2 * inMatrix2.b3 +
		inMatrix1.d2 * inMatrix2.b4);

	float c2 = (
		inMatrix1.a2 * inMatrix2.c1 +
		inMatrix1.b2 * inMatrix2.c2 +
		inMatrix1.c2 * inMatrix2.c3 +
		inMatrix1.d2 * inMatrix2.c4);

	float d2 = (
		inMatrix1.a2 * inMatrix2.d1 +
		inMatrix1.b2 * inMatrix2.d2 +
		inMatrix1.c2 * inMatrix2.d3 +
		inMatrix1.d2 * inMatrix2.d4);
	//Third row
	float a3 = (
		inMatrix1.a3 * inMatrix2.a1 +
		inMatrix1.b3 * inMatrix2.a2 +
		inMatrix1.c3 * inMatrix2.a3 +
		inMatrix1.d3 * inMatrix2.a4);

	float b3 = (
		inMatrix1.a3 * inMatrix2.b1 +
		inMatrix1.b3 * inMatrix2.b2 +
		inMatrix1.c3 * inMatrix2.b3 +
		inMatrix1.d3 * inMatrix2.b4);

	float c3 = (
		inMatrix1.a3 * inMatrix2.c1 +
		inMatrix1.b3 * inMatrix2.c2 +
		inMatrix1.c3 * inMatrix2.c3 +
		inMatrix1.d3 * inMatrix2.c4);

	float d3 = (
		inMatrix1.a3 * inMatrix2.d1 +
		inMatrix1.b3 * inMatrix2.d2 +
		inMatrix1.c3 * inMatrix2.d3 +
		inMatrix1.d3 * inMatrix2.d4);
	//Fourth row
	float a4 = (
		inMatrix1.a4 * inMatrix2.a1 +
		inMatrix1.b4 * inMatrix2.a2 +
		inMatrix1.c4 * inMatrix2.a3 +
		inMatrix1.d4 * inMatrix2.a4);

	float b4 = (
		inMatrix1.a4 * inMatrix2.b1 +
		inMatrix1.b4 * inMatrix2.b2 +
		inMatrix1.c4 * inMatrix2.b3 +
		inMatrix1.d4 * inMatrix2.b4);

	float c4 = (
		inMatrix1.a4 * inMatrix2.c1 +
		inMatrix1.b4 * inMatrix2.c2 +
		inMatrix1.c4 * inMatrix2.c3 +
		inMatrix1.d4 * inMatrix2.c4);

	float d4 = (
		inMatrix1.a4 * inMatrix2.d1 +
		inMatrix1.b4 * inMatrix2.d2 +
		inMatrix1.c4 * inMatrix2.d3 +
		inMatrix1.d4 * inMatrix2.d4);

	Matrix4x4 returnMatrix(
		a1, b1, c1, d1,
		a2, b2, c2, d2,
		a3, b3, c3, d3,
		a4, b4, c4, d4);

	return returnMatrix;
}

Matrix4x4 InvertMatrix(Matrix4x4 inMatrix)
{
	Matrix4x4 returnMatrix(
		inMatrix.a1, inMatrix.a2, inMatrix.a3, inMatrix.a4,
		inMatrix.b1, inMatrix.b2, inMatrix.b3, inMatrix.b4,
		inMatrix.c1, inMatrix.c2, inMatrix.c3, inMatrix.c4,
		inMatrix.d1, inMatrix.d2, inMatrix.d3, inMatrix.d4
	);
	return returnMatrix;
}


#pragma endregion


