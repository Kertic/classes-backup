#pragma once
#include "MathFunctions.h"

static void(*PixelShader)(unsigned int) = 0;
static Vector(*VertexShader)(Vector) = 0;



#pragma region Pixel shader globals
static unsigned int customColor = 0;
#pragma endregion
#pragma region Vertex Shader globals
static float ShaderElapsedTime = 0.0f;
static Matrix4x4 ShaderWorldMatrix(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);
static Matrix4x4 ShaderRotationMatrix(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);
static Matrix4x4 ShaderViewMatrix(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);
static Matrix4x4 ShaderProjectionMatrix(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);

void ResetShaderVertexGlobals() {
	ShaderWorldMatrix = Matrix4x4(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);
	ShaderRotationMatrix = Matrix4x4(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);
	ShaderViewMatrix = Matrix4x4(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);
	ShaderProjectionMatrix = Matrix4x4(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);

}
#pragma endregion

Vector RotateVectorAroundZ(Vector inVector)
{

	Vector returnVector;
	returnVector = MatrixTimesVector(ZRotationMatrix(20 * ShaderElapsedTime), inVector);
	return returnVector;
}
Vector RotateVectorAroundX(Vector inVector)
{
	Vector returnVector;
	returnVector = MatrixTimesVector(XRotationMatrix(20 * ShaderElapsedTime), inVector);
	return returnVector;
}
Vector RotateVectorAroundY(Vector inVector)
{
	Vector returnVector;
	returnVector = MatrixTimesVector(YRotationMatrix(20 * ShaderElapsedTime), inVector);
	return returnVector;
}
Vector GeneratePosition(Vector inVector) {
	Vector returnVector;

	returnVector = VectorTimesMatrix(ShaderWorldMatrix, inVector);
	returnVector = VectorTimesMatrix(ShaderRotationMatrix, returnVector);
	returnVector = MatrixTimesVector(ShaderViewMatrix, returnVector);
	returnVector = VectorTimesMatrix(ShaderProjectionMatrix, returnVector);

	returnVector = Vector(returnVector.x / returnVector.w, returnVector.y / returnVector.w, returnVector.z / returnVector.w, 1.0f);

	return returnVector;
}





#ifdef _SHADERDEBUG

Vector GeneratePositionTest(Vector inVector) {
	Vector returnVector;
	returnVector = VectorTimesMatrix(ShaderRotationMatrix, inVector);
	returnVector = VectorTimesMatrix(ShaderWorldMatrix, returnVector);


	return returnVector;
}
#endif 



