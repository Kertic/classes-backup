#pragma once
#include "defines.h"




unsigned int To1d(unsigned int _dimX, unsigned int _dimY, unsigned int _maxX, unsigned int _maxY);
unsigned int Lerp(int ending, int starting, float ratio);
float ImplicitLineEquation(int _x1, int _x2, int _y1, int _y2, float midx, float midy);

//Returns a value from within range 1 (bottom and top 1) as a value in the same spot but in range 2 (bottom and top 2)
unsigned int Map(unsigned int bottom1, unsigned int top1, unsigned int bottom2, unsigned int top2, unsigned int value);


void BarycentricCoords(unsigned int _x1, unsigned int _y1, unsigned int _x2, unsigned int _y2, unsigned int _x3, unsigned int _y3, unsigned int testX, unsigned int testY, float &returnA, float &returnB, float &returnC);