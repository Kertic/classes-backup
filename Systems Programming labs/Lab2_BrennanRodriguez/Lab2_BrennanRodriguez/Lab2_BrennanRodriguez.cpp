// Lab2_BrennanRodriguez.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	cout << "How old are you? \n";
	int age = 0;


	
		
	cin >> age;
			
			

			
			if (age >= 16)
			{
				cout << "\nCongratz! You can play the game!\n";
				
			}
			else if(age < 16)
			{
				cout << "\nYou aint playing the game you child\n";
				
			}

		

	

	system("pause");
    return 0;
}

