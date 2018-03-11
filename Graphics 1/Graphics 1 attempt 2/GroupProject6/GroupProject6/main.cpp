#include "RasterFunctions.h"
#include "RasterSurface.h"
#include "Images\0_cave_bluelarge.h"

#define CAVE_ARRAY _0_cave_bluelarge_pixels


void main() {

	RS_Initialize(SCREEN_WIDTH, SCREEN_HEIGHT);

	unsigned int* screenArray;
	screenArray = new unsigned int[SCREEN_SIZE];
	float* zbuffer;
	zbuffer = new float[SCREEN_SIZE];

	Vector points[4];
	points[0] = Vector(-1.0f, 1.0f, -0.1f, 1.0f, 1.0f, 0.0f);
	points[1] = Vector(1.0f, 1.0f, -0.1f, 1.0f, 0.0f, 0.0f);
	points[2] = Vector(1.0f, -1.0f, -0.1f, 1.0f, 0.0f, 1.0f);
	points[3] = Vector(-1.0f, -1.0f, -0.1f, 1.0f, 1.0f, 1.0f);
	PixelShader = BiLinearTexturePixel;
	TextureArray = CAVE_ARRAY;
	TextureWidth = _0_cave_bluelarge_width;
	TextureHeight = _0_cave_bluelarge_height;
	while (RS_Update(screenArray, SCREEN_SIZE)) {
		ClearScreen(screenArray, SCREEN_SIZE, 0x0);
		ClearLinearZBuffer(zbuffer, SCREEN_SIZE, 1000.0f);
		DrawTriangleBetterBrute(points[0], points[1], points[2], 0x0, screenArray, SCREEN_SIZE, zbuffer, SCREEN_SIZE);
		DrawTriangleBetterBrute(points[0], points[2], points[3], 0x0, screenArray, SCREEN_SIZE, zbuffer, SCREEN_SIZE);


	}

	RS_Shutdown();
	delete[] screenArray;

}





