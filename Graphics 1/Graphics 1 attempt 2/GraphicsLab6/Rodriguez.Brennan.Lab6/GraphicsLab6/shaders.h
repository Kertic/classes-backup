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
static Matrix4x4 ShaderViewTranslationMatrix(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);
static Matrix4x4 ShaderViewRotationMatrix(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);
static Matrix4x4 ShaderViewMatrix(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);
static Matrix4x4 ShaderProjectionMatrix(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);

void ResetShaderVertexGlobals() {
	ShaderWorldMatrix = Matrix4x4(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);
	ShaderRotationMatrix = Matrix4x4(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);
	ShaderViewRotationMatrix = Matrix4x4(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);
	ShaderProjectionMatrix = Matrix4x4(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);

}
#pragma endregion

#pragma region Misc functions for use in shaders
unsigned int ConvertColorRGBA(unsigned int _red, unsigned int _green, unsigned int _blue, unsigned int _alpha)
{
	unsigned int returnColor = 0;
	unsigned int alpha = _alpha << 24;
	unsigned int red = _red << 16;
	unsigned int green = _green << 8;
	unsigned int blue = _blue;


	returnColor = (((returnColor | red) | green) | blue) | alpha;

	return returnColor;
}
unsigned int BGRAtoARGB(unsigned int _pixel)
{

	unsigned int incomingRed = ((_pixel >> 8) << 24) >> 8;
	unsigned int incomingGreen = ((_pixel << 8) >> 24) << 8;
	unsigned int incomingBlue = _pixel >> 24;
	unsigned int incomingAlpha = _pixel << 24;

	unsigned int finalColor = (((0 | incomingRed) | incomingBlue) | incomingGreen) | incomingAlpha;
	return finalColor;
}
unsigned int LerpColor(unsigned int _color1, unsigned int _color2, float ratio) {
	unsigned int red1 = (_color1 << 8) >> 24;
	unsigned int green1 = (_color1 << 16) >> 24;
	unsigned int blue1 = (_color1 << 24) >> 24;
	unsigned int alpha1 = _color1 >> 24;

	unsigned int red2 = (_color2 << 8) >> 24;
	unsigned int green2 = (_color2 << 16) >> 24;
	unsigned int blue2 = (_color2 << 24) >> 24;
	unsigned int alpha2 = _color2 >> 24;

	unsigned int finalRed = Lerp((float)red1, (float)red2, ratio);
	unsigned int finalGreen = Lerp((float)green1, (float)green2, ratio);
	unsigned int finalBlue = Lerp((float)blue1, (float)blue2, ratio);
	unsigned int finalAlpha = Lerp((float)alpha1, (float)alpha2, ratio);

	finalRed = (finalRed << 16);
	finalGreen = (finalGreen << 8);
	//FinalBlue = finalBlue << 0;
	finalAlpha = finalAlpha << 24;

	return finalAlpha | finalRed | finalGreen | finalBlue;


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


	ShaderViewMatrix = MatrixTimesMatrix(ShaderViewTranslationMatrix, ShaderViewRotationMatrix);
	ShaderViewMatrix = InvertMatrix(ShaderViewMatrix);

	returnVector = VectorTimesMatrix(ShaderWorldMatrix, inVector);
	returnVector = VectorTimesMatrix(ShaderRotationMatrix, returnVector);
	returnVector = VectorTimesMatrix(ShaderViewMatrix, returnVector);
	returnVector = VectorTimesMatrix(ShaderProjectionMatrix, returnVector);

	if (returnVector.w != 0)
		returnVector = Vector(
			returnVector.x / returnVector.w,
			returnVector.y / returnVector.w,
			returnVector.z / returnVector.w,
			returnVector.w,
			inVector.u, inVector.v);
	else
		returnVector = Vector(0, 0, 0, returnVector.w, inVector.u, inVector.v);

	return returnVector;
}
#pragma endregion
#pragma region Pixel Shaders
void CustomColorPixel(unsigned int &inColor) {
	inColor = ShaderCustomColor;
}
void TexturePixel(unsigned int &inColor) {


	unsigned int Xindex = (unsigned int)(TextureU * (float)TextureWidth );
	unsigned int Yindex = (unsigned int)(TextureV * (float)TextureHeight );
	unsigned int index = From2Dto1D(Xindex, Yindex, 0, 0, TextureWidth, TextureHeight);
	if (index == -10)
		inColor = 0xffffffff;
	else
		inColor = BGRAtoARGB(TextureArray[index]);

}
void BiLinearTexturePixel(unsigned int &inColor) {



	float Xindex = (TextureU * (float)TextureWidth);
	float Yindex = (TextureV * (float)TextureHeight);

	unsigned int TopLeftNeighbor = From2Dto1D((int)Xindex, (int)Yindex, 0, 0, TextureWidth, TextureHeight);
	unsigned int TopRightNeighbor = TopLeftNeighbor + 1;
	unsigned int BottomLeftNeighbor = TopLeftNeighbor + TextureWidth;
	unsigned int BottomRightNeighbor = TopLeftNeighbor + TextureWidth + 1;


	float horizontalRatio = TextureU * (TextureWidth)-(int)(TextureU * TextureWidth);
	float verticalRatio = TextureV * (TextureHeight)-(int)(TextureV * TextureHeight);



	unsigned int TopLeftToTopRightLerp = LerpColor(
		BGRAtoARGB(TextureArray[TopLeftNeighbor]),
		BGRAtoARGB(TextureArray[TopRightNeighbor]),
		horizontalRatio);

	unsigned int BottomLeftToBottomRightLerp = LerpColor(
		BGRAtoARGB(TextureArray[BottomLeftNeighbor]),
		BGRAtoARGB(TextureArray[BottomRightNeighbor]),
		horizontalRatio);


	/*if (TopLeftToTopRightLerp != 0x00000000 && TopLeftToTopRightLerp != 0xff000000)
	int x = 0;*/

	unsigned int TopTwoToBottomTwoLerp = LerpColor(TopLeftToTopRightLerp, BottomLeftToBottomRightLerp, verticalRatio);

	inColor = TopTwoToBottomTwoLerp;

	


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



