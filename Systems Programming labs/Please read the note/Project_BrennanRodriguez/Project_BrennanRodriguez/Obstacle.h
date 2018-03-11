#pragma once
#include "Base.h"
class Obstacle :
	public Base
{
protected:
	int direction;
public:
	Obstacle();
	Obstacle(int inX, int inY, char* inChar, System::ConsoleColor inColor, int inDir);
	void Update();
	~Obstacle();
};

