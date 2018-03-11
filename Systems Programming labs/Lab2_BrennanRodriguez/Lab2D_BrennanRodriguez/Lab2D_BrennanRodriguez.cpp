// Lab2D_BrennanRodriguez.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	cout << "Please enter an even number: ";
	int num1 = 0;
	if (cin >> num1)
	{
		if (num1 % 2 == 0)
		{
			cout << "\nYay!";
		}
		else
		{
			cout << "\nBoo";
		}
	}

	cout << "\n";
	system("pause");


    return 0;
}

