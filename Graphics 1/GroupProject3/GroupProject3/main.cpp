#include "EngineMath.h"
#include "defines.h"
#include "RasterFunctions.h"
#include "RasterSurface.h"
#include "MathFunctions.h"





void main() {
	RS_Initialize(250, 250);
	unsigned int* screenArray;
	screenArray = new unsigned int[SCREEN_ARRAY_SIZE];
	ClearBuffer(screenArray, SCREEN_ARRAY_SIZE);

	for (unsigned int x = 0; x < SCREEN_WIDTH; x++)
	{
		for (unsigned int y = 0; y < SCREEN_HEIGHT; y++)
		{
			float test1 = 0.0;
			float test2 = 0.0;
			float test3 = 0.0;
			
			BarycentricCoords(84, 245, 34, 207, 237, 172, x, y, test1, test2, test3);

			if ((test1 >= 0.0f  && test1 <= 1.0f) && (test2 >= 0.0f  && test2 <= 1.0f) && (test3 >= 0.0f  && test3 <= 1.0f)) {
				SetPixel(screenArray, SCREEN_ARRAY_SIZE, To1d(x, y, SCREEN_WIDTH, SCREEN_HEIGHT), 166, 87, 22, 255);
			}
		}
	}



	while (RS_Update(screenArray, SCREEN_ARRAY_SIZE)) {
		

		DrawLineBresenham(84, 34, 245, 207, screenArray, SCREEN_ARRAY_SIZE, SCREEN_WIDTH, SCREEN_HEIGHT, 166, 22, 87, 255);//Line AB
		DrawLineBresenham(34, 237, 207, 172, screenArray, SCREEN_ARRAY_SIZE, SCREEN_WIDTH, SCREEN_HEIGHT, 166, 22, 87, 255);//Line BC
		DrawLineBresenham(84, 237, 245, 172, screenArray, SCREEN_ARRAY_SIZE, SCREEN_WIDTH, SCREEN_HEIGHT, 166, 22, 87, 255);//Line AC



	}




	delete[] screenArray;
	RS_Shutdown();

}




