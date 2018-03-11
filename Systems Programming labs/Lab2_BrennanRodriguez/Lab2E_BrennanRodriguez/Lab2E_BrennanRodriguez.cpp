// Lab2E_BrennanRodriguez.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <time.h>
using namespace std;

int main()
{

	cout << "Please enter a divisor: ";
	int input = 0;
	cin >> input;
	srand(time(NULL));
	int number1 = (int)rand();
	int number2 = (int)rand();
	int number3 = (int)rand();
	cout << "\n" << number1;
	if (number1 % input == 0)
	{
		cout << " - yes";

	}
	else
	{
		cout << " - no";
	}
	cout << "\n" << number2;
	if (number2 % input == 0)
	{
		cout << " - yes";

	}
	else
	{
		cout << " - no";
	}
	cout << "\n" << number3;
	if (number3 % input == 0)
	{
		cout << " - yes";

	}
	else
	{
		cout << " - no";
	}



	system("pause");

    return 0;
}

