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

	int numRecords = 0;
	struct records
	{
		char name[32];
		int age;
	};

	cout << "How many people would you like?: ";
	cin >> numRecords;
	records** allRecords = nullptr;
	allRecords = new records*[numRecords];

	for (size_t i = 0; i < numRecords; i++)
	{
		allRecords[i] = new records;
		cout << "\nWhat is their name?: ";
		
		cin >> allRecords[i]->name;
		cout << "\nWhat is their age?: ";
		cin >> allRecords[i]->age;
	}
	for (size_t i = 0; i < numRecords; i++)
	{

		cout << allRecords[i]->name;
	}

	for (size_t i = 0; i < numRecords; i++)
	{
		delete[] allRecords[i];
	}

	
	delete[] allRecords;



	cout << "\n";
	system("pause");
	return 0;
}

