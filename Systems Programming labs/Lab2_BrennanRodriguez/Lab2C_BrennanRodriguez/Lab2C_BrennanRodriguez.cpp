// Lab2C_BrennanRodriguez.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	char ans;
	int correct = 0;
	cout << "Is this the 1st question?: ";
	while (true) {
		cin >> ans;
		if (ans == 't' || ans == 'T')
		{
			cout << "\nYou're correct!";
			++correct;
			break;
		}
		else if (ans == 'f' || ans == 'F')
		{
			cout << "\nYou wrong homie";
			break;
		}
		else
		{
			cout << "\nPlease enter a valid choice: ";
		}

		cin.clear();
		cin.ignore(INT_MAX, '\n');
	}

	cout << "\nIs this the second question?: ";
	while (true) {
		cin >> ans;
		if (ans == 't' || ans == 'T')
		{
			cout << "\nYou're correct!";
			++correct;
			break;
		}
		else if (ans == 'f' || ans == 'F')
		{
			cout << "\nYou wrong homie";
			break;
		}
		else
		{
			cout << "\nPlease enter a valid choice: ";
		}

		cin.clear();
		cin.ignore(INT_MAX, '\n');
	}

	cout << "\nIs this the third question?: ";
	while (true) {
		cin >> ans;
		if (ans == 't' || ans == 'T')
		{
			cout << "\nYou're correct!";
			++correct;
			break;
		}
		else if (ans == 'f' || ans == 'F')
		{
			cout << "\nYou wrong homie";
			break;
		}
		else
		{
			cout << "\nPlease enter a valid choice: ";
		}

		cin.clear();
		cin.ignore(INT_MAX, '\n');
	}

	
	cout << "\nYou got " << correct << " correct!";
	cout << "\n";
	system("pause");


    return 0;
}

