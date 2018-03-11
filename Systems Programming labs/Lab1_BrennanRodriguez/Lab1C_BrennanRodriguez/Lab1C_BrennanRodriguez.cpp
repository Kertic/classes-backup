// Lab1C_BrennanRodriguez.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	int numbers[5];

	for (int i = 0; i < 5; /*nothing*/)
	{
		cout << "\nPlease enter a number: ";
		if (cin >> numbers[i])
		{
			i++;
			
		}
		else
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			
		}
	}

	cout << "\nThe array is: ";
	for (int i = 0; i < 5; i++)
	{
		cout << "\n";
		cout << numbers[i];
	}
	cout << "\n";
	system("pause");



    return 0;
}

