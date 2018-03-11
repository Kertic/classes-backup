#include "RasterFunctions.h"
#include "RasterSurface.h"
#include <random>
#include <time.h>
#include <Windows.h>





void main() {
	RS_Initialize(SCREEN_HEIGHT, SCREEN_WIDTH);
	unsigned int* screenArray;
	screenArray = new unsigned int[SCREEN_SIZE];


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
		0, 0.309, 0.951, 0,
		0, -0.951, 0.309, 0,
		0, 0, 0, 1);
	Matrix4x4 testAns5 = MatrixTimesMatrix(testMatrix5, testMatrix5a);
#pragma endregion



	while (RS_Update(screenArray, SCREEN_SIZE)) {
		ClearScreen(screenArray, SCREEN_SIZE, 0x00000000);

		

		DrawTriangleBetterBrute(205, 193, 179, 219, 186, 153, ConvertColorRGBA(217, 162, 21, 255), screenArray, SCREEN_SIZE);

		DrawParametricLine(205, 193, 179, 219, screenArray, SCREEN_SIZE, 0xffffffff);
		DrawParametricLine(179, 219, 186, 153, screenArray, SCREEN_SIZE, 0xffffffff);
		DrawParametricLine(186, 153, 205, 193, screenArray, SCREEN_SIZE, 0xffffffff);
	}

	RS_Shutdown();
	delete[] screenArray;
}