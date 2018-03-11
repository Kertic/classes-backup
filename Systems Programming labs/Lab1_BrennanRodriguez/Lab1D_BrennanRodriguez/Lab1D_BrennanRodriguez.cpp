// Lab1D_BrennanRodriguez.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{

	int num1;
	int num2;
	int num3;
	while (true)
	{
		cout << "Please enter number A: ";
		if (cin >> num1)
		{
			cout << "\n";
			break;
		}
		else
		{
			cout << "\n";
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}

	}

	while (true)
	{
		cout << "Please enter number B: ";
		if (cin >> num2)
		{
			cout << "\n";
			break;
		}
		else
		{
			cout << "\n";
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}

	}

	while (true)
	{
		cout << "Please enter number C: ";
		if (cin >> num3)
		{
			cout << "\n";
			break;
		}
		else
		{
			cout << "\n";
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}

	}
	
	cout << "\na + 1 * b + 2 - c = " << (num1 + 1 * num2 + 2 - num3);
	cout << "\n(a + 1) * (b + 2) - c = " << ((num1 + 1) * (num2 + 2) - num3) << "\n";
	system("pause");


    return 0;
}

