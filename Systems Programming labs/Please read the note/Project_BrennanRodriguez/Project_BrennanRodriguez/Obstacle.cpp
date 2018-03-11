#include "stdafx.h"
#include "Obstacle.h"


Obstacle::Obstacle()
{
	direction = 0;
}

Obstacle::Obstacle(int inX, int inY, char * inChar, System::ConsoleColor inColor, int inDir) : Base(inX, inY, inChar, inColor)
{
	direction = inDir;
}

void Obstacle::Update()
{
	switch (direction)
	{
	case 0:
		if (y < Console::WindowHeight()/2)
		{
			y++;
		}
		else {
			delete this;
		}
		break;
	case 1:

		break;
	case 2:
		
		break;
	case 3:

		break;
	default:

		break;

	}
	
}


Obstacle::~Obstacle()
{
	delete[] symbol;
}
