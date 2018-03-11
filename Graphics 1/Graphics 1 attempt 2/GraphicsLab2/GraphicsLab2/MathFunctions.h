#pragma once

#include "defines.h"
#include <math.h>


int From2Dto1D(int _x, int _y, int _minX, int _minY, int _maxX, int _maxY);
float Lerp(float min, float max, float ratio);

float ImplicitLineEquation(float _x1, float _y1, float _x2, float _y2, float _xCheck, float _yCheck);