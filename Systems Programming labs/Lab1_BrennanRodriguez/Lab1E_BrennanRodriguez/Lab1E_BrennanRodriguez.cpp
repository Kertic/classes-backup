// Lab1E_BrennanRodriguez.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	cout << "The different data bounds are: ";
	cout << "\nIntegers: " << INT_MIN << " to " << INT_MAX;
	cout << "\nUnsigned integers: " << "0" << " to " << UINT_MAX;
	cout << "\nShort: " << SHRT_MIN << " to " << SHRT_MAX;
	cout << "\nUnsigned Short: " << 0 << " to " << USHRT_MAX;
	cout << "\nLong: " << LLONG_MIN << " to " << LLONG_MAX;
	cout << "\nUnsigned Long: " << 0 << " to " << ULLONG_MAX;
	cout << "\n";
	system("pause");


    return 0;
}

