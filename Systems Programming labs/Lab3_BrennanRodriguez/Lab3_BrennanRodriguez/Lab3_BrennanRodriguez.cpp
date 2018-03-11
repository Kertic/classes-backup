// Lab3_BrennanRodriguez.cpp : Defines the entry point for the console application.
//
//Yes, you need all this for memory leaks
#include "stdafx.h"
#include <Windows.h>

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>



#include <iostream>
#include <cstring>

using namespace std;

int main()
{
//	//Also need this for memory leak code stuff
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	_CrtSetBreakAlloc(-1); //Important!


	int num = 13;
	int* pNum = &num;
	cout << "The number is: " << num;
	cout << "\nThe memory address is: " << pNum;

	cout << "\nWhat would the new number be?: ";
	cin >> num;
	cout << "\nThe number is: " << num;
	cout << "\nThe memory address is: " << pNum;
	




	cout << "\n";
	system("pause");
    return 0;
}

