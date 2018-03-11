#include <iostream>
#include "RasterSurface.h"
using namespace std;

#define SCREEN_PIXEL_SIZE 250000




void ClearBuffer(unsigned int* _pixelArray);
void SetPixel(unsigned int* _pixelArray, unsigned int _pixelIndex, unsigned int _red, unsigned int _blue, unsigned int _green, unsigned int _alpha);
unsigned int To3d(unsigned int _dimX, unsigned int _dimY, unsigned int _maxX, unsigned int _maxY);



void main() {

	cout << "Hello world";
	



	RS_Initialize(500, 500);

	unsigned int* screenArray;
	screenArray = new unsigned int[SCREEN_PIXEL_SIZE];

	for (unsigned int i = 0; i < SCREEN_PIXEL_SIZE; i++)
	{
		screenArray[i] = 0;
	}
	ClearBuffer(screenArray);
		
	SetPixel(screenArray, To3d(81, 299, 500, 500), 230, 152, 147, 255);
	SetPixel(screenArray, To3d(81, 300, 500, 500), 230, 152, 147, 255);
	SetPixel(screenArray, To3d(81, 301, 500, 500), 230, 152, 147, 255);
	SetPixel(screenArray, To3d(80, 299, 500, 500), 230, 152, 147, 255);
	SetPixel(screenArray, To3d(80, 300, 500, 500), 230, 152, 147, 255);
	SetPixel(screenArray, To3d(80, 301, 500, 500), 230, 152, 147, 255);
	SetPixel(screenArray, To3d(82, 299, 500, 500), 230, 152, 147, 255);
	SetPixel(screenArray, To3d(82, 300, 500, 500), 230, 152, 147, 255);
	SetPixel(screenArray, To3d(82, 301, 500, 500), 230, 152, 147, 255);

	while (RS_Update(screenArray, 250000))
		int x = 0;




	RS_Shutdown();


}




void ClearBuffer(unsigned int* _pixelArray) {

	for (unsigned int i = 0; i < SCREEN_PIXEL_SIZE; i++)
	{
		SetPixel(_pixelArray, i, 255, 255, 255, 0);
	}
}


void SetPixel(unsigned int* _pixelArray, unsigned int _pixelIndex, unsigned int _red, unsigned int _blue, unsigned int _green, unsigned int _alpha) {


	unsigned int pixel = 0x00000000;
	pixel = pixel | (_alpha << 24);
	pixel = pixel | (_red << 16);
	pixel = pixel | (_green << 8);
	pixel = pixel | (_blue);


		_pixelArray[_pixelIndex] = pixel;

}

unsigned int To3d(unsigned int _dimX, unsigned int _dimY, unsigned int _maxX, unsigned int _maxY) {

	unsigned int index = 0;
	index = _dimY *_maxX + _dimX;


	return index;
}