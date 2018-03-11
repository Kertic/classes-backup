#pragma once

#include "defines.h"
#include <math.h>


//We have an NDC x, y, and z
struct Vector {
	float x, y, z, w;
	float u, v;

	Vector() {
		x = 0;
		y = 0;
		z = 0;
		w = 0;
	}
	Vector(float x, float y, float z, float w);
	Vector(float x, float y, float z, float w, float u, float v) {
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
		this->u = u;
		this->v = v;
	}

	Vector& Vector::operator=(const Vector &inVector) {
		x = inVector.x;
		y = inVector.y;
		z = inVector.z;
		w = inVector.w;
		u = inVector.u;
		v = inVector.v;


		return *this;
	}
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

Vector::Vector(float x, float y, float z, float w)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
	this->u = 0.0f;
	this->v = 0.0f;
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

//Returns -10 if its out of bounds
int From2Dto1D(int _x, int _y, int _minX, int _minY, int _maxX, int _maxY)
{
	int value = 0;
	//If we're out of bounds
	/*if (_x > _maxX || _x < _minX || _y > _maxY || _y < _minY || _x == _maxX || _x == _minX || _y == _maxY || _y == _minY) {
		return -10;
	}*/

	value = ((_y) *(_maxX - _minX)) + _x;
	

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
void BarycentricCoords(float _x1, float _y1, float _x2, float _y2, float _x3, float _y3, float testX, float testY, float &returnA, float &returnB, float &returnC) {
	float beta = 0.0;
	float alpha = 0.0;
	float gamma = 0.0;

	float a = 0.0;
	float b = 0.0;
	float y = 0.0;

	beta = ImplicitLineEquation((float)_x1, (float)_y1, (float)_x3, (float)_y3, (float)_x2, (float)_y2);//Line AC, testing B
	gamma = ImplicitLineEquation((float)_x2, (float)_y2, (float)_x1, (float)_y1,   (float)_x3, (float)_y3);//Line BA, testing C
	alpha = ImplicitLineEquation((float)_x3, (float)_y3, (float)_x2, (float)_y2,  (float)_x1, (float)_y1);//Line CB, testing A

	b = ImplicitLineEquation((float)_x1, (float)_y1, (float)_x3, (float)_y3, (float)testX, (float)testY);//Line AC, testing testPixel
	y = ImplicitLineEquation((float)_x2, (float)_y2, (float)_x1, (float)_y1, (float)testX, (float)testY);//Line BA, testing testPixel
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
		return (unsigned int)(((1.0f - inVar) / 2.0f) * ((float)maxHeight));
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
float Map(float bottom1, float top1, float bottom2, float top2, float value) {
	float range1 = top1 - bottom1;
	float range2 = top2 - bottom2;

	float ratio = value / range1;


	return ratio * range2;
}

float customAbs(float value) {
	if (value < 0)
		return value + (-value * 2);
	else
		return value;
}
#pragma region Vector Math
float VectorLength(Vector inVector) {
	float value = 0.0f;
	value = sqrtf(inVector.x * inVector.x + inVector.y * inVector.y + inVector.z * inVector.z);
	return value;
}
Vector NormalizeVector(Vector inVector) {
	float length = VectorLength(inVector);

	Vector NormalizedVector(inVector.x / length, inVector.y / length, inVector.z / length, inVector.w, inVector.u, inVector.v);

	return NormalizedVector;
}
float DotProduct(Vector inVec1, Vector inVec2) {
	float term1 = inVec1.x * inVec2.x;
	float term2 = inVec1.y * inVec2.y;
	float term3 = inVec1.z * inVec2.z;

	return term1 + term2 + term3;
}
#pragma endregion
#pragma region Matrix math
float Matrix_Determinant(float _a1, float _b1, float _c1, float _a2, float _b2, float _c2, float _a3, float _b3, float _c3)
{
	float R = _a1 * (_b2 * _c3 - _b3 * _c2) - _b1 * (_a2 * _c3 - _a3 * _c2) + _c1 * (_a2 * _b3 - _a3 * _b2);

	return R;
}
float Matrix_Determinant(Matrix4x4 inMatrix)
{


	float A = inMatrix.d1 * Matrix_Determinant(inMatrix.a2, inMatrix.b2, inMatrix.c2, inMatrix.a3, inMatrix.b3, inMatrix.c3, inMatrix.a4, inMatrix.b4, inMatrix.c4);
	float B = inMatrix.d2 * Matrix_Determinant(inMatrix.a1, inMatrix.b1, inMatrix.c1, inMatrix.a3, inMatrix.b3, inMatrix.c3, inMatrix.a4, inMatrix.b4, inMatrix.c4);
	float C = inMatrix.d3 * Matrix_Determinant(inMatrix.a1, inMatrix.b1, inMatrix.c1, inMatrix.a2, inMatrix.b2, inMatrix.c2, inMatrix.a4, inMatrix.b4, inMatrix.c4);
	float D = inMatrix.d4 * Matrix_Determinant(inMatrix.a1, inMatrix.b1, inMatrix.c1, inMatrix.a2, inMatrix.b2, inMatrix.c2, inMatrix.a3, inMatrix.b3, inMatrix.c3);

	return -A + B - C + D;
}

Matrix4x4 ZRotationMatrix(float degrees) {
	float Rad = DegtoRad(degrees);

	Matrix4x4 returnMatrix(
		(float)cos(Rad), (float)-sin(Rad), 0, 0,
		(float)sin(Rad), (float)cos(Rad), 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1);

	return returnMatrix;
}
Matrix4x4 XRotationMatrix(float degrees) {
	float rad = DegtoRad(degrees);
	Matrix4x4 returnMatrix(
		1, 0, 0, 0,
		0, (float)cos(rad), (float)-sin(rad), 0,
		0, (float)sin(rad), (float)cos(rad), 0,
		0, 0, 0, 1);
	return returnMatrix;
}
Matrix4x4 YRotationMatrix(float degrees) {
	float rad = DegtoRad(degrees);
	Matrix4x4 returnMatrix(
		(float)cos(rad), 0, (float)sin(rad), 0,
		0, 1, 0, 0,
		(float)-sin(rad), 0, (float)cos(rad), 0,
		0, 0, 0, 1
	);

	return returnMatrix;
}
Vector VectorTimesMatrix(Matrix4x4 inMatrix, Vector inVector)
{
	float returnIndexX =
		(inMatrix.a1 * inVector.x +
			inMatrix.a2 * inVector.y +
			inMatrix.a3 * inVector.z +
			inMatrix.a4 * inVector.w);

	float returnIndexY =
		(inMatrix.b1 * inVector.x +
			inMatrix.b2 * inVector.y +
			inMatrix.b3 * inVector.z +
			inMatrix.b4 * inVector.w);

	float returnIndexZ =
		(inMatrix.c1 * inVector.x +
			inMatrix.c2 * inVector.y +
			inMatrix.c3 * inVector.z +
			inMatrix.c4 * inVector.w);

	float returnIndexW =
		(inMatrix.d1 * inVector.x +
			inMatrix.d2 * inVector.y +
			inMatrix.d3 * inVector.z +
			inMatrix.d4 * inVector.w);

	Vector returnVector(returnIndexX, returnIndexY, returnIndexZ, returnIndexW);

	return returnVector;
}
Vector MatrixTimesVector(Matrix4x4 inMatrix, Vector inVector) {
	float returnIndexX = (
		inMatrix.a1 * inVector.x +
		inMatrix.b1 * inVector.y +
		inMatrix.c1 * inVector.z +
		inMatrix.d1 * inVector.w
		);

	float returnIndexY = (
		inMatrix.a2 * inVector.x +
		inMatrix.b2 * inVector.y +
		inMatrix.c2 * inVector.z +
		inMatrix.d2 * inVector.w
		);

	float returnIndexZ = (
		inMatrix.a3 * inVector.x +
		inMatrix.b3 * inVector.y +
		inMatrix.c3 * inVector.z +
		inMatrix.d3 * inVector.w
		);

	float returnIndexW = (
		inMatrix.a4 * inVector.x +
		inMatrix.b4 * inVector.y +
		inMatrix.c4 * inVector.z +
		inMatrix.d4 * inVector.w
		);
	return Vector(returnIndexX, returnIndexY, returnIndexZ, returnIndexW);

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
Matrix4x4 MatrixTranspose(Matrix4x4 inMatrix)
{
	Matrix4x4 returnMatrix(
		inMatrix.a1, inMatrix.a2, inMatrix.a3, inMatrix.a4,
		inMatrix.b1, inMatrix.b2, inMatrix.b3, inMatrix.b4,
		inMatrix.c1, inMatrix.c2, inMatrix.c3, inMatrix.c4,
		inMatrix.d1, inMatrix.d2, inMatrix.d3, inMatrix.d4
	);
	return returnMatrix;
}
Matrix4x4 InvertMatrix(Matrix4x4 inMatrix) {
	float det = Matrix_Determinant(inMatrix);

	if (det == 0)
		return inMatrix;

	float C11 = Matrix_Determinant(inMatrix.b2, inMatrix.c2, inMatrix.d2, inMatrix.b3, inMatrix.c3, inMatrix.d3, inMatrix.b4, inMatrix.c4, inMatrix.d4);
	float C12 = -1 * Matrix_Determinant(inMatrix.a2, inMatrix.c2, inMatrix.d2, inMatrix.a3, inMatrix.c3, inMatrix.d3, inMatrix.a4, inMatrix.c4, inMatrix.d4);
	float C13 = Matrix_Determinant(inMatrix.a2, inMatrix.b2, inMatrix.d2, inMatrix.a3, inMatrix.b3, inMatrix.d3, inMatrix.a4, inMatrix.b4, inMatrix.d4);
	float C14 = -1 * Matrix_Determinant(inMatrix.a2, inMatrix.b2, inMatrix.c2, inMatrix.a3, inMatrix.b3, inMatrix.c3, inMatrix.a4, inMatrix.b4, inMatrix.c4);

	float C21 = -1 * Matrix_Determinant(inMatrix.b1, inMatrix.c1, inMatrix.d1, inMatrix.b3, inMatrix.c3, inMatrix.d3, inMatrix.b4, inMatrix.c4, inMatrix.d4);
	float C22 = Matrix_Determinant(inMatrix.a1, inMatrix.c1, inMatrix.d1, inMatrix.a3, inMatrix.c3, inMatrix.d3, inMatrix.a4, inMatrix.c4, inMatrix.d4);
	float C23 = -1 * Matrix_Determinant(inMatrix.a1, inMatrix.b1, inMatrix.d1, inMatrix.a3, inMatrix.b3, inMatrix.d3, inMatrix.a4, inMatrix.b4, inMatrix.d4);
	float C24 = Matrix_Determinant(inMatrix.a1, inMatrix.b1, inMatrix.c1, inMatrix.a3, inMatrix.b3, inMatrix.c3, inMatrix.a4, inMatrix.b4, inMatrix.c4);

	float C31 = Matrix_Determinant(inMatrix.b1, inMatrix.c1, inMatrix.d1, inMatrix.b2, inMatrix.c2, inMatrix.d2, inMatrix.b4, inMatrix.c4, inMatrix.d4);
	float C32 = -1 * Matrix_Determinant(inMatrix.a1, inMatrix.c1, inMatrix.d1, inMatrix.a2, inMatrix.c2, inMatrix.d2, inMatrix.a4, inMatrix.c4, inMatrix.d4);
	float C33 = Matrix_Determinant(inMatrix.a1, inMatrix.b1, inMatrix.d1, inMatrix.a2, inMatrix.b2, inMatrix.d2, inMatrix.a4, inMatrix.b4, inMatrix.d4);
	float C34 = -1 * Matrix_Determinant(inMatrix.a1, inMatrix.b1, inMatrix.c1, inMatrix.a2, inMatrix.b2, inMatrix.c2, inMatrix.a4, inMatrix.b4, inMatrix.c4);

	float C41 = -1 * Matrix_Determinant(inMatrix.b1, inMatrix.c1, inMatrix.d1, inMatrix.b2, inMatrix.c2, inMatrix.d2, inMatrix.b3, inMatrix.c3, inMatrix.d3);
	float C42 = Matrix_Determinant(inMatrix.a1, inMatrix.c1, inMatrix.d1, inMatrix.a2, inMatrix.c2, inMatrix.d2, inMatrix.a3, inMatrix.c3, inMatrix.d3);
	float C43 = -1 * Matrix_Determinant(inMatrix.a1, inMatrix.b1, inMatrix.d1, inMatrix.a2, inMatrix.b2, inMatrix.d2, inMatrix.a3, inMatrix.b3, inMatrix.d3);
	float C44 = Matrix_Determinant(inMatrix.a1, inMatrix.b1, inMatrix.c1, inMatrix.a2, inMatrix.b2, inMatrix.c2, inMatrix.a3, inMatrix.b3, inMatrix.c3);

	Matrix4x4 R = Matrix4x4(C11 / det, C12 / det, C13 / det, C14 / det, C21 / det, C22 / det, C23 / det, C24 / det, C31 / det, C32 / det, C33 / det, C34 / det, C41 / det, C42 / det, C43 / det, C44 / det);

	return MatrixTranspose(R);
}

Matrix4x4 ScaleMatrix(Matrix4x4 inMatrix, float scaler)
{

	Matrix4x4 returnMatrix(
		inMatrix.a1 * scaler, inMatrix.b1 * scaler, inMatrix.c1 * scaler, inMatrix.d1 * scaler,
		inMatrix.a2 * scaler, inMatrix.b2 * scaler, inMatrix.c2 * scaler, inMatrix.d2 * scaler,
		inMatrix.a3 * scaler, inMatrix.b3 * scaler, inMatrix.c3 * scaler, inMatrix.d3 * scaler,
		inMatrix.a4 * scaler, inMatrix.b4 * scaler, inMatrix.c4 * scaler, inMatrix.d4 * scaler);

	return returnMatrix;
}
Matrix4x4 IdentityMatrix() {
	return Matrix4x4(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);

}
Matrix4x4 ProjectionMatrix(float VerticalFOVDegrees, float aspectRatio, float nearPlane, float farPlane) {
	float fovRad = DegtoRad(VerticalFOVDegrees);

	float Yscale = 1.0f / (float)tan(0.5f * fovRad);
	float Xscale = Yscale * aspectRatio;
	float z1 = farPlane / (farPlane - nearPlane);
	float z2 = -(farPlane * nearPlane) / (farPlane - nearPlane);
	return Matrix4x4(
		Xscale, 0, 0, 0,
		0, Yscale, 0, 0,
		0, 0, z1, 1.0f,
		0, 0, z2, 0);
}



#pragma endregion
