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
			toDie = true;;
		}
		break;
	case 1:
		if (x > Console::WindowWidth() / 2)
		{
			x--;
		}
		else {
			toDie = true;;
		}
		break;
	case 2:
		if (y > Console::WindowHeight() / 2)
		{
			y--;
		}
		else {
			toDie = true;;
		}
		break;
	case 3:
		if (x < Console::WindowWidth() / 2)
		{
			x++;
		}
		else {
			toDie = true;
		}
		break;
	default:

		break;

	}
	
}


Obstacle::~Obstacle()
{
	
}
