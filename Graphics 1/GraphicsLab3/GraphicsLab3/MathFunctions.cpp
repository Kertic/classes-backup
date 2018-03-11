#include "MathFunctions.h"



float ImplicitLineEquation(int _x1, int _x2, int _y1, int _y2, float midx, float midy) {

	float xTerm = (float)(_y1 - _y2) * midx;
	float yTerm = (float)(_x2 - _x1) * midy;
	float cTerm = (_x1 * _y2 - _y1 * _x2);

	float result = xTerm + yTerm + cTerm;
	return result;

}


unsigned int Lerp(int starting, int ending, float ratio) {

	return (unsigned int)((ending - starting) * ratio + starting);
}

float DegtoRad(float degrees) {
	return degrees * PI / 180;
}
unsigned int To1d(unsigned int _dimX, unsigned int _dimY, unsigned int _maxX, unsigned int _maxY) {

	unsigned int index = 0;
	index = _dimY *_maxX + _dimX;


	return index;
}


unsigned int Map(unsigned int bottom1, unsigned int top1, unsigned int bottom2, unsigned int top2, unsigned int value) {
	unsigned int range1 = top1 - bottom1;
	unsigned int range2 = top2 - bottom2;

	float ratio = (float)value / (float)range1;


	return (unsigned int)ratio * range2;
}


// x/y1 is A, 2 is B and 3 is C. returnA would be the ratio of point B, returnB would be the ratio of point C, and returnC would be the ratio of point A 
void BarycentricCoords(unsigned int _x1, unsigned int _y1, unsigned int _x2, unsigned int _y2, unsigned int _x3, unsigned int _y3, unsigned int testX, unsigned int testY, float &returnA, float &returnB, float &returnC) {
	float beta = 0.0;
	float alpha = 0.0;
	float gamma = 0.0;

	float a = 0.0;
	float b = 0.0;
	float y = 0.0;

	beta =	ImplicitLineEquation(_x1, _x3, _y1, _y3, _x2, _y2);//Line AC, testing B
	gamma = ImplicitLineEquation(_x2, _x1, _y2, _y1, _x3, _y3);//Line BA, testing C
	alpha = ImplicitLineEquation(_x3, _x2, _y3, _y2, _x1, _y1);//Line CB, testing A

	b =		ImplicitLineEquation(_x1, _x3, _y1, _y3, testX, testY);//Line AC, testing testPixel
	y =		ImplicitLineEquation(_x2, _x1, _y2, _y1, testX, testY);//Line CB, testing testPixel
	a =		ImplicitLineEquation(_x3, _x2, _y3, _y2, testX, testY);//Line CB, testing testPixel

	returnA = b / beta;
	returnB = y / gamma;
	returnC = a / alpha;


}

Vector::Vector(float x, float y, float z, float w)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

Matrix::Matrix(float _index11, float _index12, float _index13, float _index14, float _index21, float _index22, float _index23, float _index24, float _index31, float _index32, float _index33, float _index34, float _index41, float _index42, float _index43, float _index44)
{
	index11 = _index11;
	index12 = _index12;
	index13 = _index13;
	index14 = _index14;

	index21 = _index21;
	index22 = _index22;
	index23 = _index23;
	index24 = _index24;

	index31 = _index31;
	index32 = _index32;
	index33 = _index33;
	index34 = _index34;

	index41 = _index41;
	index42 = _index42;
	index43 = _index43;
	index44 = _index44;
}


Matrix ZRotationMatrix(float degrees) {
	float Rad = DegtoRad(degrees);

	Matrix returnMatrix(
		cos(Rad),	-sin(Rad),	0,		0, 
		sin(Rad),	cos(Rad),	0,		0,
		0,			0,			1,		0,
		0,			0,			0,		1);

	return returnMatrix;
}

Vector MultiplyVectorByMatrix(Matrix _matrixToMultBy, Vector _vectorToMult) {

	float returnX = (_vectorToMult.x * _matrixToMultBy.index11 + _vectorToMult.y * _matrixToMultBy.index21 + _vectorToMult.z * _matrixToMultBy.index31 + _vectorToMult.w * _matrixToMultBy.index41);
	float returnY = (_vectorToMult.x * _matrixToMultBy.index12 + _vectorToMult.y * _matrixToMultBy.index22 + _vectorToMult.z * _matrixToMultBy.index32 + _vectorToMult.w * _matrixToMultBy.index42);
	float returnZ = (_vectorToMult.x * _matrixToMultBy.index13 + _vectorToMult.y * _matrixToMultBy.index23 + _vectorToMult.z * _matrixToMultBy.index33 + _vectorToMult.w * _matrixToMultBy.index43);
	float returnW = (_vectorToMult.x * _matrixToMultBy.index14 + _vectorToMult.y * _matrixToMultBy.index24 + _vectorToMult.z * _matrixToMultBy.index34 + _vectorToMult.w * _matrixToMultBy.index44);


	Vector ReturnVector(returnX, returnY, returnZ, returnW);

	return ReturnVector;
}


unsigned int NDCtoRastor(unsigned int maxWidth, unsigned int maxHeight, float inVar, bool isX) {

	if (isX) {
		return ((inVar + 1.0f) / 2.0f) * maxWidth;
	}
	else
	{
		return ((inVar - 1.0f) / 2.0f) * (0.0 - maxWidth);
	}

}

float RastorToNDC( int maxWidth,  int maxHeight, int inVar, bool isX) {
	if (isX) {
		return	((float)inVar / (float)maxWidth) * 2.0f - 1.0f;
	}
	else
	{
		
		return ((float)inVar /  -(float)maxHeight) * 2.0f + 1.0f;
	}
}





