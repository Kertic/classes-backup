// Lab1G_BrennanRodriguez.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int cTemp;
	int fTemp;
	int cConvertedTemp;
	int fConvertedTemp;
	while (true)
	{
		cout << "Enter a temperature in C: ";
		if (cin >> cTemp)
		{
			cConvertedTemp = (cTemp * 9.0) / 5.0 + 32.0;
			break;
		}
		else
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');

		}


	}
	cout << "\nThe Converted temperature, into F, is: " << cConvertedTemp;
	while (true)
	{
		cout << "\nEnter a temperature in F: ";
		if (cin >> fTemp)
		{
			fConvertedTemp = (fTemp - 32.0) * (5.0 / 9.0);
			break;
		}
		else
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');

		}

	}
	cout << "\nThe Converted temperature, into C, is: " << fConvertedTemp;
	cout << "\n";
	system("pause");

    return 0;
}

