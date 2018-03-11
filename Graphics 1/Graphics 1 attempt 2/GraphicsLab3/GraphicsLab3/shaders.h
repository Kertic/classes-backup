#pragma once
#include "MathFunctions.h"

static void(*PixelShader)(unsigned int) = 0;
static Vector(*VertexShader)(Vector) = 0;



#pragma region Pixel shader globals
static unsigned int customColor = 0;
#pragma endregion
#pragma region Vertex Shader globals
static float elapsedTime = 0.0f;
static Matrix4x4 ShaderWorldMatrix(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);
static Matrix4x4 ShaderRotationMatrix(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);
#pragma endregion

Vector RotateVectorAroundZ(Vector inVector)
{

	Vector returnVector;
	returnVector = MatrixTimesVector(ZRotationMatrix(20 * elapsedTime), inVector);
	return returnVector;
}
Vector RotateVectorAroundX(Vector inVector)
{
	Vector returnVector;
	returnVector = MatrixTimesVector(XRotationMatrix(20 * elapsedTime), inVector);
	return returnVector;
}
Vector RotateVectorAroundY(Vector inVector)
{
	Vector returnVector;
	returnVector = MatrixTimesVector(YRotationMatrix(20 * elapsedTime), inVector);
	return returnVector;
}

Vector GeneratePosition(Vector inVector) {
	Vector returnVector;
	returnVector = VectorTimesMatrix(ShaderWorldMatrix, inVector);

	return returnVector;
}


