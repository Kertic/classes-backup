#include "MathFunctions.h"



float ImplicitLineEquation(int _x1, int _x2, int _y1, int _y2, float midx, float midy) {

	float xTerm = (float)(_y1 - _y2) * midx;
	float yTerm = (float)(_x2 - _x1) * midy;
	float cTerm = (_x1 * _y2 - _y1 * _x2);

	float result = xTerm + yTerm + cTerm;
	return result;

}


unsigned int Lerp(int ending, int starting, float ratio) {

	return (unsigned int)((ending - starting) * ratio + starting);
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


// x/y1 is A, 2 is B and 3 is C
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