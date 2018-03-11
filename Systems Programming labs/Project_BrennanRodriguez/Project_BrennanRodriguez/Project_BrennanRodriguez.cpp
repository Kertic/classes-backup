// Project_BrennanRodriguez.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <Windows.h>

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>




#include <cstring>
#include "Game.h"
#include "Base.h"



using namespace std;
int main()
{
	//	//Also need this for memory leak code stuff
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	_CrtSetBreakAlloc(-1); //Important!



	Console::SetWindowSize(55, 55);
	Console::SetBufferSize(55, 55);

	Game* g = new Game();
	g->start();

	delete g;
    return 0;
}

