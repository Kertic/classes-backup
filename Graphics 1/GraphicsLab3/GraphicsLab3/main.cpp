#include "RasterFunctions.h"
#include "RasterSurface.h"
#include <Windows.h>
#include <random>
#include <time.h>
#include "XTime.h"


#define RANDOM_ON_PRESS 



void main() {
	RS_Initialize(SCREEN_WIDTH, SCREEN_HEIGHT);
	unsigned int* screenArray;
	screenArray = new unsigned int[SCREEN_ARRAY_SIZE];
	ClearBuffer(screenArray, SCREEN_ARRAY_SIZE);


	XTime timer;

#pragma region Matrix Testing
	Matrix testMatrix(1, 2, 3, 4,
		5, 6, 7, 8, 
		9, 10, 11, 12, 
		13, 14, 15, 16);
	Vector testVector(1, 2, 3, 4);

	Vector testFinalVector = MultiplyVectorByMatrix(testMatrix, testVector);
#pragma endregion





	float ax = 0.22f;
	float ay = 0.005f;
	float bx = 0.109f;
	float by = 0.45f;
	float cx = -0.11f;
	float cy = 0.146f;

	Triangle triangleToDraw(ax, ay, 0, bx, by, 0, cx, cy, 0);


	srand((unsigned int)time(NULL));



	bool pressed = false;
	bool wasPressed = false;
	DrawLineBresenham(triangleToDraw.RasterPoints[0], triangleToDraw.RasterPoints[2], triangleToDraw.RasterPoints[1], triangleToDraw.RasterPoints[3], screenArray, SCREEN_ARRAY_SIZE, SCREEN_WIDTH, SCREEN_HEIGHT, 166, 22, 87, 255);//Line AB

	while (RS_Update(screenArray, SCREEN_ARRAY_SIZE)) {

		ClearBuffer(screenArray, SCREEN_ARRAY_SIZE);

#pragma region Draw In Pixels



		for (unsigned int x = 0; x < SCREEN_WIDTH; x++)
		{
			for (unsigned int y = 0; y < SCREEN_HEIGHT; y++)
			{
				float test1 = 0.0;
				float test2 = 0.0;
				float test3 = 0.0;


				BarycentricCoords(triangleToDraw.RasterPoints[0], triangleToDraw.RasterPoints[1], triangleToDraw.RasterPoints[2],
					triangleToDraw.RasterPoints[3], triangleToDraw.RasterPoints[4], triangleToDraw.RasterPoints[5],
					x, y, test1, test2, test3);


				if ((test1 >= 0.0f  && test1 <= 1.0f) && (test2 >= 0.0f  && test2 <= 1.0f) && (test3 >= 0.0f  && test3 <= 1.0f)) {


#pragma region Lerp colors based on pos
					int red = Lerp(0, 255, test1);
					int green = Lerp(0, 255, test2);
					int blue = Lerp(0, 255, test3);
#pragma endregion




					SetPixel(screenArray, SCREEN_ARRAY_SIZE, To1d(x, y, SCREEN_WIDTH, SCREEN_HEIGHT), red, blue, green, 255);
				}
			}
		}

		DrawLineParametric(triangleToDraw.RasterPoints[0], triangleToDraw.RasterPoints[2], triangleToDraw.RasterPoints[1], triangleToDraw.RasterPoints[3], screenArray, SCREEN_ARRAY_SIZE, SCREEN_WIDTH, SCREEN_HEIGHT, 255, 255, 255, 255, 255, 255, 255, 255);
		DrawLineParametric(triangleToDraw.RasterPoints[4], triangleToDraw.RasterPoints[2], triangleToDraw.RasterPoints[5], triangleToDraw.RasterPoints[3], screenArray, SCREEN_ARRAY_SIZE, SCREEN_WIDTH, SCREEN_HEIGHT, 255, 255, 255, 255, 255, 255, 255, 255);
		DrawLineParametric(triangleToDraw.RasterPoints[0], triangleToDraw.RasterPoints[4], triangleToDraw.RasterPoints[1], triangleToDraw.RasterPoints[5], screenArray, SCREEN_ARRAY_SIZE, SCREEN_WIDTH, SCREEN_HEIGHT, 255, 255, 255, 255, 255, 255, 255, 255);
#pragma endregion

#pragma region Rotate
		//These are the current triangle point's vectors




		Vector tempVector1(triangleToDraw.vert1.xyzw[0], triangleToDraw.vert1.xyzw[1], triangleToDraw.vert1.xyzw[2], triangleToDraw.vert1.xyzw[3]);
		Vector tempVector2(triangleToDraw.vert2.xyzw[0], triangleToDraw.vert2.xyzw[1], triangleToDraw.vert2.xyzw[2], triangleToDraw.vert2.xyzw[3]);
		Vector tempVector3(triangleToDraw.vert3.xyzw[0], triangleToDraw.vert3.xyzw[1], triangleToDraw.vert3.xyzw[2], triangleToDraw.vert3.xyzw[3]);

		//These are the vectors after being rotated
		Vector returnVector1 = MultiplyVectorByMatrix(ZRotationMatrix((float)timer.Delta() * 50.0f), tempVector1);
		Vector returnVector2 = MultiplyVectorByMatrix(ZRotationMatrix((float)timer.Delta() * 50.0f), tempVector2);
		Vector returnVector3 = MultiplyVectorByMatrix(ZRotationMatrix((float)timer.Delta() * 50.0f), tempVector3);


		Vector finalVector1(returnVector1.x, returnVector1.y, returnVector1.z, returnVector1.w);
		Vector finalVector2(returnVector2.x, returnVector2.y, returnVector2.z, returnVector2.w);
		Vector finalVector3(returnVector3.x, returnVector3.y, returnVector3.z, returnVector3.w);



		triangleToDraw.SetPositions(finalVector1.x, finalVector1.y, finalVector1.z, finalVector2.x, finalVector2.y, finalVector2.z, finalVector3.x, finalVector3.y, finalVector3.z);

#pragma endregion


#pragma region Randomize Position On Spacebar




		if (GetAsyncKeyState(VK_SPACE)) {
			pressed = true;
		}
		else
		{
			pressed = false;
		}


		if (pressed && wasPressed == false) {

#ifdef RANDOM_ON_PRESS

			ax = ((rand() % 100) - 50) / 100.0f;
			ay = ((rand() % 100) - 50) / 100.0f;
			bx = ((rand() % 100) - 50) / 100.0f;
			by = ((rand() % 100) - 50) / 100.0f;
			cx = ((rand() % 100) - 50) / 100.0f;
			cy = ((rand() % 100) - 50) / 100.0f;

			triangleToDraw.SetPositions(ax, ay, 0, bx, by, 0, cx, cy, 0);
#endif

		}

		if (pressed) {
			wasPressed = true;
		}
		else
		{
			wasPressed = false;
		}

#pragma endregion

		timer.Signal();

	}




	delete[] screenArray;
	RS_Shutdown();

}




