#pragma once
#include "MathFunctions.h"


static void(*MyVertexShader) (Vertex&) = nullptr;
static void(*MyPixelShader) (unsigned int&) = nullptr;

static unsigned int customColor = 0;


void setPixelCustom(unsigned int &_pixel);


void setCustomColor(unsigned int _red, unsigned int _green, unsigned int _blue, unsigned int _alpha);
void setCustomColor(unsigned int color);

