#include "RasterFunctions.h"
#include "RasterSurface.h"







int main() {
	unsigned int* screenArray;
	screenArray = new unsigned int[SCREEN_SIZE];
	RS_Initialize(SCREEN_WIDTH, SCREEN_HEIGHT);



	Vector points[13][360];


	for (int j = 0; j < 13; j++)
	{
		for (int i = 0; i < 360; i++)
		{
			float ratio = ((360.0f * (float)j) + (float)i) / (13.0f * 360.0f);

			points[j][i] = Vector(
				(float)cos(DegtoRad((float)i)),
				(float)sin(DegtoRad((float)i)),
				Lerp(0.0f, 10.0f, ratio),
				1.0f);
		}



		for (int i = 0; i < 360; i++)
		{
			points[j][i] = Vector(
				points[j][i].x / points[j][i].z,
				points[j][i].y / points[j][i].z,
				points[j][i].z,
				1.0f);
		}
	}




	while (RS_Update(screenArray, SCREEN_SIZE)) {
		ClearScreen(screenArray, SCREEN_SIZE, 0x0);



		for (int j = 0; j < 13; j++)
		{
			for (int i = 1; i < 360; i++)
			{
				float ratio = ((360.0f * (float)j) + (float)i) / (13.0f * 360.0f);
				float red = 189;
				float green = 186;
				float blue = 62;
				float alpha = (255.0f * Lerp(1.0f, 0.0f, ratio));
				DrawParametricLine(points[j][i - 1], points[j][i], screenArray, SCREEN_SIZE, ConvertColorRGBA(red, green, blue, alpha));
			}
		}


	}


	RS_Shutdown();
	delete[] screenArray;


}