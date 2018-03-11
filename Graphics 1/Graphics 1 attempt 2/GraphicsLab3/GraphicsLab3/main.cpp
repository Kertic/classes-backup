#include "RasterFunctions.h"
#include "RasterSurface.h"
#include <random>
#include <time.h>
#include <Windows.h>
#include "XTime.h"





void main() {
	RS_Initialize(SCREEN_HEIGHT, SCREEN_WIDTH);
	unsigned int* screenArray;
	screenArray = new unsigned int[SCREEN_SIZE];
	XTime timer;
	timer.Signal();
	srand((unsigned int)time(NULL));
#pragma region MatrixGauntlet
	//Test1
	Vector testVector1(1, 2, 3, 1);
	Matrix4x4 testMatrix1(
		1, 2, 3, 0,
		4, 5, 6, 0,
		7, 8, 9, 0,
		0, 0, 0, 1);
	Vector testAns1 = MatrixTimesVector(testMatrix1, testVector1);
	//Test2
	Vector testVector2(1, 2, 3, 4);
	Matrix4x4 testMatrix2(
		1, 2, 3, 4,
		5, 6, 7, 8,
		9, 10, 11, 12,
		13, 14, 15, 16);

	Vector testAns2 = MatrixTimesVector(testMatrix2, testVector2);
	//Test3
	Matrix4x4 testMatrix3(1, 2, 3, 0, 4, 5, 6, 0, 7, 8, 9, 0, 0, 0, 0, 0);
	Matrix4x4 testAns3 = MatrixTimesMatrix(testMatrix3, testMatrix3);
	//Test4
	Matrix4x4 testMatrix4(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	Matrix4x4 testMatrix4a(17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32);

	Matrix4x4 testAns4 = MatrixTimesMatrix(testMatrix4, testMatrix4a);
	//Test5
	Matrix4x4 testMatrix5(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 7, 8, 5, 1);
	Matrix4x4 testMatrix5a(
		1, 0, 0, 0,
		0, 0.309f, 0.951f, 0,
		0, -0.951f, 0.309f, 0,
		0, 0, 0, 1);
	Matrix4x4 testAns5 = MatrixTimesMatrix(testMatrix5, testMatrix5a);
#pragma endregion



	VertexShader = RotateVectorAroundZ;
	float point1Array[] = { ((rand() % 200) - 100.0f) / 100.0f, ((rand() % 200) - 100.0f) / 100.0f };
	float point2Array[] = { ((rand() % 200) - 100.0f) / 100.0f, ((rand() % 200) - 100.0f) / 100.0f };
	float point3Array[] = { ((rand() % 200) - 100.0f) / 100.0f, ((rand() % 200) - 100.0f) / 100.0f };
	Vector point1(point1Array[0], point1Array[1], 0.0f, 0.0f);
	Vector point2(point2Array[0], point2Array[1], 0.0f, 0.0f);
	Vector point3(point3Array[0], point3Array[1], 0.0f, 0.0f);

	bool pressed = false;
	while (RS_Update(screenArray, SCREEN_SIZE)) {
		ClearScreen(screenArray, SCREEN_SIZE, 0x00000000);




		DrawTriangleBetterBrute(point1, point2, point3, 0xffffffff, screenArray, SCREEN_SIZE);
		DrawParametricLine(point1, point2, screenArray, SCREEN_SIZE, 0xffffffff);
		DrawParametricLine(point2, point3, screenArray, SCREEN_SIZE, 0xffffffff);
		DrawParametricLine(point3, point1, screenArray, SCREEN_SIZE, 0xffffffff);

#ifdef _BARRYDEBUG
		PaintPixel(screenArray, From2Dto1D(
			NDCtoRastor(SCREEN_WIDTH, SCREEN_HEIGHT, point1.x, true),
			NDCtoRastor(SCREEN_WIDTH, SCREEN_HEIGHT, point1.y, false),
			0, 0, SCREEN_WIDTH, SCREEN_HEIGHT), 0xffff0000);

		PaintPixel(screenArray, From2Dto1D(
			NDCtoRastor(SCREEN_WIDTH, SCREEN_HEIGHT, point2.x, true),
			NDCtoRastor(SCREEN_WIDTH, SCREEN_HEIGHT, point2.y, false),
			0, 0, SCREEN_WIDTH, SCREEN_HEIGHT), 0xff00ff00);

		PaintPixel(screenArray, From2Dto1D(
			NDCtoRastor(SCREEN_WIDTH, SCREEN_HEIGHT, point3.x, true),
			NDCtoRastor(SCREEN_WIDTH, SCREEN_HEIGHT, point3.y, false),
			0, 0, SCREEN_WIDTH, SCREEN_HEIGHT), 0xff0000ff);
#endif // _BARRYDEBUG

			


			timer.Signal();



		elapsedTime += (float)timer.Delta();

#ifdef _BARRYDEBUG
		elapsedTime = 0.0f;
#endif // _BARRUDEBUG
#pragma region Change triangle points



		if (GetAsyncKeyState(VK_SPACE)) {
			if (!pressed) {
				float point1Array2[] = { ((rand() % 200) - 100.0f) / 100.0f, ((rand() % 200) - 100.0f) / 100.0f };
				float point2Array2[] = { ((rand() % 200) - 100.0f) / 100.0f, ((rand() % 200) - 100.0f) / 100.0f };
				float point3Array2[] = { ((rand() % 200) - 100.0f) / 100.0f, ((rand() % 200) - 100.0f) / 100.0f };
				Vector newVec1(point1Array2[0], point1Array2[1], 0.0f, 0.0f);
				Vector newVec2(point2Array2[0], point2Array2[1], 0.0f, 0.0f);
				Vector newVec3(point3Array2[0], point3Array2[1], 0.0f, 0.0f);
				point1 = newVec1;
				point2 = newVec2;
				point3 = newVec3;
				pressed = true;

			}
			else
			{
				pressed = true;
			}

		}
		else
			pressed = false;


#pragma endregion
	}

	RS_Shutdown();
	delete[] screenArray;
}