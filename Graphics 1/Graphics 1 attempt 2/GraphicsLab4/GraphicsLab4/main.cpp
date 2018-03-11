#include "RasterFunctions.h"
#include "RasterSurface.h"
#include "XTime.h"







int main() {
	unsigned int* screenArray;
	screenArray = new unsigned int[SCREEN_SIZE];
	RS_Initialize(SCREEN_WIDTH, SCREEN_HEIGHT);
	XTime timer;


	timer.Signal();

	Vector testVector1(0.0f, 0.3f, 0.0f, 1.0f);
	Vector testVector2(0.0f, 0.2f, 0.0f, 1.0f);
#pragma region Create Grid


	Vector gridPoints[36];
	int count = 0;
	//Left side
	for (int i = 0; i < 10; i++)//10 dots on the left side
	{
		count++;
		gridPoints[i] = Vector(-0.5f, 0.0f, (-0.5f + 0.1f * i), 1.0f);
	}

	//Top side
	for (int i = 0; i < 8; i++)
	{
		count++;
		gridPoints[i + 10] = Vector((-0.4f + i*0.1f), 0.0f, -0.5f, 1.0f);

	}
	//Bottom side
	for (int i = 0; i < 8; i++)
	{

		count++;
		gridPoints[i + 18] = Vector((-0.4f + i*0.1f), 0.0f, 0.4f, 1.0f);

	}

	//Right side
	for (int i = 0; i < 10; i++)
	{
		count++;
		gridPoints[i + 26] = Vector(0.4f, 0.0f, (-0.5f + 0.1f * i), 1.0f);
	}



#pragma endregion

#pragma region Create Cube
	Vector cubePoints[8];
	cubePoints[0] = Vector(-0.25f, -0.25f, -0.25f, 1.0f);
	cubePoints[1] = Vector(-0.25f, 0.25f, -0.25f, 1.0f);
	cubePoints[2] = Vector(0.25f, 0.25f, -0.25f, 1.0f);
	cubePoints[3] = Vector(0.25f, -0.25f, -0.25f, 1.0f);
	cubePoints[4] = Vector(-0.25f, -0.25f, 0.25f, 1.0f);
	cubePoints[5] = Vector(-0.25f, 0.25f, 0.25f, 1.0f);
	cubePoints[6] = Vector(0.25f, 0.25f, 0.25f, 1.0f);
	cubePoints[7] = Vector(0.25f, -0.25f, 0.25f, 1.0f);





#pragma endregion

	while (RS_Update(screenArray, SCREEN_SIZE)) {
		ClearScreen(screenArray, SCREEN_SIZE, 0x0);
		

#pragma region Draw Grid
		ResetShaderVertexGlobals();
		ShaderWorldMatrix = IdentityMatrix();
		ShaderWorldMatrix.a4 = 0.05;
		ShaderViewMatrix = XRotationMatrix(-18);
		ShaderViewMatrix.c4 = -1;
		ShaderViewMatrix = InvertMatrix(ShaderViewMatrix);
		ShaderProjectionMatrix = ProjectionMatrix(-90, 1, 0.1, 10.0);
		VertexShader = GeneratePosition;
		//Longitude lines
		DrawParametricLine(gridPoints[0], gridPoints[26], screenArray, SCREEN_SIZE, 0xffffffff);
		DrawParametricLine(gridPoints[1], gridPoints[27], screenArray, SCREEN_SIZE, 0xffffffff);
		DrawParametricLine(gridPoints[2], gridPoints[28], screenArray, SCREEN_SIZE, 0xffffffff);
		DrawParametricLine(gridPoints[3], gridPoints[29], screenArray, SCREEN_SIZE, 0xffffffff);
		DrawParametricLine(gridPoints[4], gridPoints[30], screenArray, SCREEN_SIZE, 0xffffffff);
		DrawParametricLine(gridPoints[5], gridPoints[31], screenArray, SCREEN_SIZE, 0xffffffff);
		DrawParametricLine(gridPoints[6], gridPoints[32], screenArray, SCREEN_SIZE, 0xffffffff);
		DrawParametricLine(gridPoints[7], gridPoints[33], screenArray, SCREEN_SIZE, 0xffffffff);
		DrawParametricLine(gridPoints[8], gridPoints[34], screenArray, SCREEN_SIZE, 0xffffffff);
		DrawParametricLine(gridPoints[9], gridPoints[35], screenArray, SCREEN_SIZE, 0xffffffff);

		//Latitude lines
		DrawParametricLine(gridPoints[0], gridPoints[9], screenArray, SCREEN_SIZE, 0xffffffff);
		DrawParametricLine(gridPoints[10], gridPoints[18], screenArray, SCREEN_SIZE, 0xffffffff);
		DrawParametricLine(gridPoints[11], gridPoints[19], screenArray, SCREEN_SIZE, 0xffffffff);
		DrawParametricLine(gridPoints[12], gridPoints[20], screenArray, SCREEN_SIZE, 0xffffffff);
		DrawParametricLine(gridPoints[13], gridPoints[21], screenArray, SCREEN_SIZE, 0xffffffff);
		DrawParametricLine(gridPoints[14], gridPoints[22], screenArray, SCREEN_SIZE, 0xffffffff);
		DrawParametricLine(gridPoints[15], gridPoints[23], screenArray, SCREEN_SIZE, 0xffffffff);
		DrawParametricLine(gridPoints[16], gridPoints[24], screenArray, SCREEN_SIZE, 0xffffffff);
		DrawParametricLine(gridPoints[17], gridPoints[25], screenArray, SCREEN_SIZE, 0xffffffff);
		DrawParametricLine(gridPoints[26], gridPoints[35], screenArray, SCREEN_SIZE, 0xffffffff);
		VertexShader = 0;

#pragma endregion

#pragma region Draw Cube
		ResetShaderVertexGlobals();
		ShaderWorldMatrix = Matrix4x4(
			1, 0, 0, 0,
			0, 1, 0, 0,
			0, 0, 1, 0,
			0, 0.25, 0, 1
		);

		ShaderRotationMatrix = YRotationMatrix(ShaderElapsedTime * 20);
		ShaderViewMatrix = XRotationMatrix(-18);
		ShaderViewMatrix.c4 = -1;
		ShaderViewMatrix = InvertMatrix(ShaderViewMatrix);
		ShaderProjectionMatrix = ProjectionMatrix(-90, 1, 0.1, 10.0);
		VertexShader = GeneratePosition;

		//Back face
		DrawParametricLine(cubePoints[0], cubePoints[1], screenArray, SCREEN_SIZE, 0xff00ff00);
		DrawParametricLine(cubePoints[1], cubePoints[2], screenArray, SCREEN_SIZE, 0xff00ff00);
		DrawParametricLine(cubePoints[2], cubePoints[3], screenArray, SCREEN_SIZE, 0xff00ff00);
		DrawParametricLine(cubePoints[3], cubePoints[0], screenArray, SCREEN_SIZE, 0xff00ff00);

		////Front face
		DrawParametricLine(cubePoints[4], cubePoints[5], screenArray, SCREEN_SIZE, 0xff00ff00);
		DrawParametricLine(cubePoints[5], cubePoints[6], screenArray, SCREEN_SIZE, 0xff00ff00);
		DrawParametricLine(cubePoints[6], cubePoints[7], screenArray, SCREEN_SIZE, 0xff00ff00);
		DrawParametricLine(cubePoints[7], cubePoints[4], screenArray, SCREEN_SIZE, 0xff00ff00);

		////Connecting lines
		DrawParametricLine(cubePoints[4], cubePoints[0], screenArray, SCREEN_SIZE, 0xff00ff00);
		DrawParametricLine(cubePoints[5], cubePoints[1], screenArray, SCREEN_SIZE, 0xff00ff00);
		DrawParametricLine(cubePoints[6], cubePoints[2], screenArray, SCREEN_SIZE, 0xff00ff00);
		DrawParametricLine(cubePoints[7], cubePoints[3], screenArray, SCREEN_SIZE, 0xff00ff00);

		VertexShader = 0;
#pragma endregion

		timer.Signal();
		ShaderElapsedTime += (float)timer.Delta();

	}


	RS_Shutdown();
	delete[] screenArray;


}