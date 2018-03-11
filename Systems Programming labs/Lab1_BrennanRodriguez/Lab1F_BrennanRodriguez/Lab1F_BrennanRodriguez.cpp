// Lab1F_BrennanRodriguez.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	char name[32];

	
	
	cout << "Please enter your name:";
	cin.getline(name, 32, '\n');
		

	

	cout << "\nHello, " << name << ", did you know that you're special? I would know, I'm a windows console.\n";
	system("pause");
	
    return 0;
}

