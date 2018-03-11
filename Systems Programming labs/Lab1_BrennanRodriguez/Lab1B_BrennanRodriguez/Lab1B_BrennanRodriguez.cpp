// Lab1B_BrennanRodriguez.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{

	cout << "Please enter your innitals: ";
	char firstI;
	char secondI;
	cin >> firstI;
	cin >> secondI;
	cin.ignore(INT_MAX, '\n');

	cout << "\nPlease enter your age: ";
	int age;
	while (true)
	{
		if (cin >> age)
		{
			break;
		}
		else
		{
			cin.clear(); //This one clears flags
			cin.ignore(INT_MAX, '\n');  //This one ignores the following text until the \n is reached
			cout << "\nPlease enter a valid number: ";
		}

	}
	cout << "Dear " << firstI << secondI << ",\nYou are very old.";
	cout << "\nIn fact, you are " << age * 365 << " Days old.";
	cout << "\n";
	system("pause");
    return 0;
}

