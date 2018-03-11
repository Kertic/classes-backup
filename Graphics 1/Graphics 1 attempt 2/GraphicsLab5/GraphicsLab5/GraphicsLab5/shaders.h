#pragma once
#include "MathFunctions.h"

static void(*PixelShader)(unsigned int&) = 0;
static Vector(*VertexShader)(Vector) = 0;



#pragma region Pixel shader globals
static unsigned int ShaderCustomColor = 0;
static const unsigned int* TextureArray = 0;
static unsigned int TextureWidth;
static unsigned int TextureHeight;
static float TextureU;
static float TextureV;
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

#pragma region Misc functions for use in shaders
unsigned int BGRAtoARGB(unsigned int _pixel)
{

	unsigned int incomingRed = ((_pixel >> 8) << 24) >> 8;
	unsigned int incomingGreen = ((_pixel << 8) >> 24) << 8;
	unsigned int incomingBlue = _pixel >> 24;
	unsigned int incomingAlpha = _pixel << 24;

	unsigned int finalColor = (((0 | incomingRed) | incomingBlue) | incomingGreen) | incomingAlpha;
	return finalColor;
}
#pragma endregion
#pragma region Vertex Shaders
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

	returnVector = Vector(returnVector.x / returnVector.w, returnVector.y / returnVector.w, returnVector.z / returnVector.w, 1.0f, inVector.u, inVector.v);

	return returnVector;
}
#pragma endregion
#pragma region Pixel Shaders
void CustomColorPixel(unsigned int &inColor) {
	inColor = ShaderCustomColor;
}
void TexturePixel(unsigned int &inColor) {


	unsigned int Xindex = (unsigned int)(TextureU * (float)TextureWidth);
	unsigned int Yindex = (unsigned int)(TextureV * (float)TextureHeight);
	unsigned int index = From2Dto1D(Xindex, Yindex, 0, 0, TextureWidth, TextureHeight);
	if (index == -10)
		inColor = 0xffffffff;
	else
		inColor = BGRAtoARGB( TextureArray[index]);
		
}
#pragma endregion






#ifdef _SHADERDEBUG

Vector GeneratePositionTest(Vector inVector) {
	Vector returnVector;
	returnVector = VectorTimesMatrix(ShaderRotationMatrix, inVector);
	returnVector = VectorTimesMatrix(ShaderWorldMatrix, returnVector);


	return returnVector;
}
#endif 



