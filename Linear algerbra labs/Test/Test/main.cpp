#include <iostream>
#pragma once
#include "DynArray.h"


using namespace std;



void main() {

	DynArray<int> test;

	for (unsigned int i = 0; i < 10; i++)
	{
		test.append(i);
	}

	test.remove(3);
	system("pause");






}