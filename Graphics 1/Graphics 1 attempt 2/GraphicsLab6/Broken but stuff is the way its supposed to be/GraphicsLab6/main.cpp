#include "RasterFunctions.h"
#include "RasterSurface.h"
#include "XTime.h"
#include "Image\greendragon.h"




int main() {
	unsigned int* screenArray;
	screenArray = new unsigned int[SCREEN_SIZE];
	float* zBuffer;
	zBuffer = new float[SCREEN_SIZE];
	ClearExponentialZBuffer(zBuffer, SCREEN_SIZE);
	RS_Initialize(SCREEN_WIDTH, SCREEN_HEIGHT);
	XTime timer;

	timer.Signal();

	Vector testVector1(0.0f, 0.3f, 0.0f, 1.0f);
	Vector testVector2(0.0f, 0.2f, 0.0f, 1.0f);

	Matrix4x4 testM(
		1, 5, 4, 2,
		-2, 3, 6, 4,
		5, 1, 0, -1,
		2, 3, -4, 0);
	Matrix4x4 solM = InvertMatrix(testM);
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
	cubePoints[0] = Vector(-0.25f, -0.25f, 0.25f, 1.0f, 0.0f, 0.0f);//Front Bottom Left corner
	cubePoints[1] = Vector(-0.25f, 0.25f, 0.25f, 1.0f, 0.0f, 0.0f);//Front Top Left corner
	cubePoints[2] = Vector(0.25f, 0.25f, 0.25f, 1.0f, 0.0f, 0.0f);//Front Top Right corner
	cubePoints[3] = Vector(0.25f, -0.25f, 0.25f, 1.0f, 0.0f, 0.0f);//Front Bottom Right corner
	cubePoints[4] = Vector(-0.25f, -0.25f, -0.25f, 1.0f, 0.0f, 0.0f);//Back Bottom Left corner
	cubePoints[5] = Vector(-0.25f, 0.25f, -0.25f, 1.0f, 0.0f, 0.0f);//Back Top Left corner
	cubePoints[6] = Vector(0.25f, 0.25f, -0.25f, 1.0f, 0.0f, 0.0f);//Back Top Right corner
	cubePoints[7] = Vector(0.25f, -0.25f, -0.25f, 1.0f, 0.0f, 0.0f);//Back Bottom Right corner



	Vector uvCubePoints[24];

#pragma region Front face
	uvCubePoints[0] = Vector(-0.25f, -0.25f, 0.25f, 1.0f, 0.0f, 1.0f);//Bottom left corner
	uvCubePoints[1] = Vector(-0.25f, 0.25f, 0.25f, 1.0f, 0.0f, 0.0f);//Top left corner
	uvCubePoints[2] = Vector(0.25f, 0.25f, 0.25f, 1.0f, 1.0f, 0.0f);//Top right corner
	uvCubePoints[3] = Vector(0.25f, -0.25f, 0.25f, 1.0f, 1.0f, 1.0f);//Bottom right corner

#pragma endregion

#pragma region Back Face
	uvCubePoints[4] = Vector(-0.25f, -0.25f, -0.25f, 1.0f, 1.0f, 1.0f);// Bottom right
	uvCubePoints[5] = Vector(-0.25f, 0.25f, -0.25f, 1.0f, 1.0f, 0.0f);// Top right corner
	uvCubePoints[6] = Vector(0.25f, 0.25f, -0.25f, 1.0f, 0.0f, 0.0f);// Top Left corner
	uvCubePoints[7] = Vector(0.25f, -0.25f, -0.25f, 1.0f, 0.0f, 1.0f);// bottom left corner
#pragma endregion

#pragma region Top Face
	uvCubePoints[8] = Vector(-0.25f, 0.25f, 0.25f, 1.0f, 0.0f, 1.0f);// Bottom left corner // 8
	uvCubePoints[9] = Vector(0.25f, 0.25f, 0.25f, 1.0f, 1.0f, 1.0f);// Bottom Right corner // 9
	uvCubePoints[10] = Vector(-0.25f, 0.25f, -0.25f, 1.0f, 0.0f, 0.0f); // Top Left corner // 10
	uvCubePoints[11] = Vector(0.25f, 0.25f, -0.25f, 1.0f, 1.0f, 0.0f); // Top Right corner // 11
#pragma endregion

#pragma region Bottom Face
	uvCubePoints[12] = Vector(-0.25f, -0.25f, 0.25f, 1.0f, 0.0f, 1.0f); // Bottom Left // 12
	uvCubePoints[13] = Vector(0.25f, -0.25f, 0.25f, 1.0f, 1.0f, 1.0f); // Bottom Right // 13
	uvCubePoints[14] = Vector(-0.25f, -0.25f, -0.25f, 1.0f, 0.0f, 0.0f); // Top Left // 14
	uvCubePoints[15] = Vector(0.25f, -0.25f, -0.25f, 1.0f, 1.0f, 0.0f); // Top Right // 15
#pragma endregion


#pragma region Left Face
	uvCubePoints[16] = Vector(-0.25f, -0.25f, 0.25f, 1.0f, 1.0f, 1.0f); // Bottom Right // 16
	uvCubePoints[17] = Vector(-0.25f, 0.25f, 0.25f, 1.0f, 1.0f, 0.0f); // Top Right// 17
	uvCubePoints[18] = Vector(-0.25f, -0.25f, -0.25f, 1.0f, 0.0f, 1.0f); // Bottom Left //18
	uvCubePoints[19] = Vector(-0.25f, 0.25f, -0.25f, 1.0f, 0.0f, 0.0f); // Top Left // 19
#pragma endregion

#pragma region Right Face
	uvCubePoints[20] = Vector(0.25f, 0.25f, 0.25f, 1.0f, 0.0f, 0.0f); // Top Left // 20
	uvCubePoints[21] = Vector(0.25f, -0.25f, 0.25f, 1.0f, 0.0f, 1.0f); // Bottom Left // 21
	uvCubePoints[22] = Vector(0.25f, 0.25f, -0.25f, 1.0f, 1.0f, 0.0f);// Top Right // 22 
	uvCubePoints[23] = Vector(0.25f, -0.25f, -0.25f, 1.0f, 1.0f, 1.0f);// Bottom right // 23
#pragma endregion




#pragma endregion
	float cameraTranslationIn = -1.0f;
	float cameraTranslationRight = 0.0f;
	while (RS_Update(screenArray, SCREEN_SIZE)) {
		ClearScreen(screenArray, SCREEN_SIZE, 0x0);
		ClearExponentialZBuffer(zBuffer, SCREEN_SIZE);

		if (GetAsyncKeyState(87))//Key code for W
			cameraTranslationIn += (float)timer.Delta() * 0.2f;
		if (GetAsyncKeyState(83))//Key Code for S
			cameraTranslationIn -= (float)timer.Delta() * 0.2f;

		if (GetAsyncKeyState(68))//Key code for D
			cameraTranslationRight -= (float)timer.Delta() * 0.2f;
		if (GetAsyncKeyState(65))//Key code for A
			cameraTranslationRight += (float)timer.Delta() * 0.2f;

#pragma region Draw Grid
		ResetShaderVertexGlobals();
		ShaderWorldMatrix = IdentityMatrix();
		ShaderWorldMatrix.a4 = 0.05f;
		ShaderViewRotationMatrix = XRotationMatrix(-18);
		ShaderViewTranslationMatrix.c4 = cameraTranslationIn;
		ShaderViewTranslationMatrix.a4 = cameraTranslationRight;
		ShaderProjectionMatrix = ProjectionMatrix(90, ((float)SCREEN_HEIGHT / (float)SCREEN_WIDTH), 0.1f, 10.0f);
		VertexShader = GeneratePosition;
		//Longitude lines
		DrawParametricLine(gridPoints[0], gridPoints[26], screenArray, SCREEN_SIZE, 0xffffffff, zBuffer, SCREEN_SIZE);
		DrawParametricLine(gridPoints[1], gridPoints[27], screenArray, SCREEN_SIZE, 0xffffffff, zBuffer, SCREEN_SIZE);
		DrawParametricLine(gridPoints[2], gridPoints[28], screenArray, SCREEN_SIZE, 0xffffffff, zBuffer, SCREEN_SIZE);
		DrawParametricLine(gridPoints[3], gridPoints[29], screenArray, SCREEN_SIZE, 0xffffffff, zBuffer, SCREEN_SIZE);
		DrawParametricLine(gridPoints[4], gridPoints[30], screenArray, SCREEN_SIZE, 0xffffffff, zBuffer, SCREEN_SIZE);
		DrawParametricLine(gridPoints[5], gridPoints[31], screenArray, SCREEN_SIZE, 0xffffffff, zBuffer, SCREEN_SIZE);
		DrawParametricLine(gridPoints[6], gridPoints[32], screenArray, SCREEN_SIZE, 0xffffffff, zBuffer, SCREEN_SIZE);
		DrawParametricLine(gridPoints[7], gridPoints[33], screenArray, SCREEN_SIZE, 0xffffffff, zBuffer, SCREEN_SIZE);
		DrawParametricLine(gridPoints[8], gridPoints[34], screenArray, SCREEN_SIZE, 0xffffffff, zBuffer, SCREEN_SIZE);
		DrawParametricLine(gridPoints[9], gridPoints[35], screenArray, SCREEN_SIZE, 0xffffffff, zBuffer, SCREEN_SIZE);

		//Latitude lines
		DrawParametricLine(gridPoints[0], gridPoints[9], screenArray, SCREEN_SIZE, 0xffffffff, zBuffer, SCREEN_SIZE);
		DrawParametricLine(gridPoints[10], gridPoints[18], screenArray, SCREEN_SIZE, 0xffffffff, zBuffer, SCREEN_SIZE);
		DrawParametricLine(gridPoints[11], gridPoints[19], screenArray, SCREEN_SIZE, 0xffffffff, zBuffer, SCREEN_SIZE);
		DrawParametricLine(gridPoints[12], gridPoints[20], screenArray, SCREEN_SIZE, 0xffffffff, zBuffer, SCREEN_SIZE);
		DrawParametricLine(gridPoints[13], gridPoints[21], screenArray, SCREEN_SIZE, 0xffffffff, zBuffer, SCREEN_SIZE);
		DrawParametricLine(gridPoints[14], gridPoints[22], screenArray, SCREEN_SIZE, 0xffffffff, zBuffer, SCREEN_SIZE);
		DrawParametricLine(gridPoints[15], gridPoints[23], screenArray, SCREEN_SIZE, 0xffffffff, zBuffer, SCREEN_SIZE);
		DrawParametricLine(gridPoints[16], gridPoints[24], screenArray, SCREEN_SIZE, 0xffffffff, zBuffer, SCREEN_SIZE);
		DrawParametricLine(gridPoints[17], gridPoints[25], screenArray, SCREEN_SIZE, 0xffffffff, zBuffer, SCREEN_SIZE);
		DrawParametricLine(gridPoints[26], gridPoints[35], screenArray, SCREEN_SIZE, 0xffffffff, zBuffer, SCREEN_SIZE);
		

#pragma endregion

#pragma region Draw Cube
		
		ShaderWorldMatrix = Matrix4x4(
			1, 0, 0, 0,
			0, 1, 0, 0,
			0, 0, 1, 0,
			0, 0.25, 0, 1
		);

		ShaderRotationMatrix = YRotationMatrix(ShaderElapsedTime * -20);
	
		PixelShader = BiLinearTexturePixel;
		//PixelShader = TexturePixel;
		TextureArray = &DRAGON_ARRAY[0];
		TextureWidth = greendragon_width;
		TextureHeight = greendragon_height;

#pragma region Back face

		ShaderCustomColor = 0xffff00ff;


		DrawTriangleBetterBrute(uvCubePoints[4], uvCubePoints[5], uvCubePoints[6], 0xffff00ff, screenArray, SCREEN_SIZE, zBuffer, SCREEN_SIZE);
		DrawTriangleBetterBrute(uvCubePoints[4], uvCubePoints[6], uvCubePoints[7], 0xffff00ff, screenArray, SCREEN_SIZE, zBuffer, SCREEN_SIZE);
#pragma endregion
#pragma region Top face
		ShaderCustomColor = 0xffffff00;
		DrawTriangleBetterBrute(uvCubePoints[8], uvCubePoints[9], uvCubePoints[10], 0xffff00ff, screenArray, SCREEN_SIZE, zBuffer, SCREEN_SIZE);
		DrawTriangleBetterBrute(uvCubePoints[10], uvCubePoints[11], uvCubePoints[9], 0xffff00ff, screenArray, SCREEN_SIZE, zBuffer, SCREEN_SIZE);
#pragma endregion
#pragma region Front face

		ShaderCustomColor = 0xff00ffff;

		DrawTriangleBetterBrute(uvCubePoints[0], uvCubePoints[1], uvCubePoints[2], 0xffff00ff, screenArray, SCREEN_SIZE, zBuffer, SCREEN_SIZE);
		DrawTriangleBetterBrute(uvCubePoints[0], uvCubePoints[2], uvCubePoints[3], 0xffff00ff, screenArray, SCREEN_SIZE, zBuffer, SCREEN_SIZE);
#pragma endregion
#pragma region Bottom face
		ShaderCustomColor = 0xff0000ff;
		DrawTriangleBetterBrute(uvCubePoints[12], uvCubePoints[13], uvCubePoints[14], 0xffff00ff, screenArray, SCREEN_SIZE, zBuffer, SCREEN_SIZE);
		DrawTriangleBetterBrute(uvCubePoints[13], uvCubePoints[14], uvCubePoints[15], 0xffff00ff, screenArray, SCREEN_SIZE, zBuffer, SCREEN_SIZE);
#pragma endregion
#pragma region Left face
		ShaderCustomColor = 0xffff0000;
		DrawTriangleBetterBrute(uvCubePoints[16], uvCubePoints[17], uvCubePoints[18], 0xffff00ff, screenArray, SCREEN_SIZE, zBuffer, SCREEN_SIZE);
		DrawTriangleBetterBrute(uvCubePoints[17], uvCubePoints[18], uvCubePoints[19], 0xffff00ff, screenArray, SCREEN_SIZE, zBuffer, SCREEN_SIZE);
#pragma endregion
#pragma region Right face

		ShaderCustomColor = 0xff00ff00;
		DrawTriangleBetterBrute(uvCubePoints[20], uvCubePoints[21], uvCubePoints[22], 0xffff00ff, screenArray, SCREEN_SIZE, zBuffer, SCREEN_SIZE);
		DrawTriangleBetterBrute(uvCubePoints[21], uvCubePoints[22], uvCubePoints[23], 0xffff00ff, screenArray, SCREEN_SIZE, zBuffer, SCREEN_SIZE);
#pragma endregion



		
		PixelShader = 0;
#pragma endregion

		timer.Signal();
		ShaderElapsedTime += (float)timer.Delta();
		//ShaderElapsedTime = 2.25f;
		//ShaderElapsedTime = 0.0f;

	}


	RS_Shutdown();
	delete[] screenArray;
	delete[] zBuffer;


}