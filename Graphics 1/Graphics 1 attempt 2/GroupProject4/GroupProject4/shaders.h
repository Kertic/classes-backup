#pragma once
#include "MathFunctions.h"

static void(*PixelShader)(unsigned int)=0;
static Vector(*MyVertexShader)(Vector)=0;



#pragma region Pixel shader globals
static unsigned int customColor = 0;
#pragma endregion
#pragma region Vertex Shader globals
static float elapsedTime = 0.0f;
#pragma endregion

Vector RotateVector(Vector inVector)
{
	Vector returnVector;
	returnVector = VectorTimesMatrix(ZRotationMatrix(20 * elapsedTime), inVector);
	return returnVector;
}


