
#include "Shaders.h"

void setPixelCustom(unsigned int & _pixel)
{
	_pixel = customColor;
}

void setCustomColor(unsigned int _red, unsigned int _green, unsigned int _blue, unsigned int _alpha)
{


	unsigned int pixel = 0x00000000;
	pixel = pixel | (_alpha << 24);
	pixel = pixel | (_red << 16);
	pixel = pixel | (_green << 8);
	pixel = pixel | (_blue);

	customColor = pixel;

}

void setCustomColor(unsigned int color)
{
	customColor = color;
}
