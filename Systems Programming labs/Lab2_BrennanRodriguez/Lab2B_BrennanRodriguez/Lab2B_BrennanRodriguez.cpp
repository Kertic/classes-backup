// Lab2B_BrennanRodriguez.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	cout << "Enter a time to convert from Pacific into Eastern: ";
	int pTime = 0;
	do//Get reked TJ
	{

		cin >> pTime;
		if (pTime > 0 && pTime < 13)
		{
			break;
		}
		cout << "\nPlease enter a valid time (1-12): ";
		cin.clear();
		cin.ignore(INT_MAX, '\n');
	} while (true);

	cout << "\nThat would be " << (pTime % 12) + 3 << " in EST";




	cout << "\n";
	system("pause");



    return 0;
}

