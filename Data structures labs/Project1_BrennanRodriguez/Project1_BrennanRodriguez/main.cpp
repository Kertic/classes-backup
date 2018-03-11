////////////////////////////////////////////////////////////////////////////////////////////////
// File :			main.cpp
// Author :			Rodney Stoeffler
// Created :		03.24.08
// Last Modified :	10.29.09
// Purpose :		The main driver for the memory game
// Notes :			Property of Full Sail University, Data Structures Course.

//Edited by :       Brennan Rodriguez for the purpose of turning it in.
////////////////////////////////////////////////////////////////////////////////////////////////


//Leak detection
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

////////////////////////////////////////////////////////////////////////////////////////////////
// INCLUDES
////////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>				// needed for drawing the screen
#include <conio.h>				// needed for _kbhit and _getch.
#include "MemoryFunctions.h"	// interface for drawing the screen and delay function
#include "DynArray.h"
#include <time.h>
using namespace std;

int CharToInt(char inChar);
char IntToChar(int inInt);
////////////////////////////////////////////////////////////////////////////////////////////////
// Function :	main
// Parameters : argc - the number of command line arguments
//				argv - the array of command line arguments
// return :		int - 0 for success
////////////////////////////////////////////////////////////////////////////////////////////////
int main(int argc, char ** argv)
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	bool toReplay = true;
	while (toReplay)//The loop to enable replaying
	{


		//Splash screen


		while (true)//Splash screen while loop
		{
			system("cls");
			cout << "Welcome to simon!";
			cout << "\nPress 1 to continue";
			delay(100);
			if (_kbhit())
			{
				if (_getch() == 49)
				{
					
					break;
				}
			}
		}
		delay(1000);

		for (int i = 3; i > 0; i--)
		{
			cout << "\n" << i;
			delay(1000);
		}


		//Innizialze game vars
		toReplay = false;
		empty();
		DynArray<int> simonSays;
		bool isLose = false;
		long int timeint = 5;
		time_t time1 = timeint;
		srand(time(&time1));
		int score = 0;

		
		

		while (true)//Game loop
		{
			simonSays.append((rand() % 4) + 1);//Make a new item in the list

			cout << "Simon's turn";
			delay(900);//Display simons moves
			for (unsigned int i = 0; i < simonSays.size(); i++)
			{
				switch (IntToChar(simonSays[i]))
				{
				case 'w':
				{
					delay(150);
					drawUp();
					delay(150);
					empty();
				}
				break;

				case 's':
				{
					delay(150);
					drawDown();
					delay(150);
					empty();
				}
				break;

				case 'a':
				{
					delay(150);
					drawLeft();
					delay(150);
					empty();
				}
				break;

				case 'd':
				{
					delay(150);
					drawRight();
					delay(150);
					empty();
				}
				break;
				default:
					break;
				}

			}//Display the series of moves

			cout << "Your turn";
			
			for (unsigned int i = 0; i < simonSays.size(); i++)//Input loop
			{


				while (true)//The while loop that waits for input before it breaks
				{
					if (_kbhit())
					{
						char ch = _getch();
						switch (tolower(ch))
						{
							// show stuff for each specific move
						case 'w':
						{
							drawUp();
							delay(150);
							empty();
						}
						break;

						case 's':
						{
							drawDown();
							delay(150);
							empty();
						}
						break;

						case 'a':
						{
							drawLeft();
							delay(150);
							empty();
						}
						break;

						case 'd':
						{
							drawRight();
							delay(150);
							empty();
						}
						break;
						}

						// exiting test on the 'q' key
						if (ch == 'q') {
							isLose = true;
							break;
						}
							
						if (CharToInt(ch) != simonSays[i])//the character they're pressing == the character in the array
						{
							isLose = true;
							break;
						}
						//This could be in the else statement, but we break if we enter the above if-statement so it doesnt matter
						
						break;//We break at the end of the if statement, because once they press a key we move on no matter what

					}

				}
				if (isLose)
				{
					break;//We break here cause we don't need to bother testing the rest of the series

				}
				

			}
			if (isLose)
			{	
				break;//Breaks out of the game loop
			}
			score++;//We add to the score if they didnt lose
		}

		while (true)//While loop for getting input regarding replay or not
		{
			system("cls");
			cout << "You lose D:\nYour Score was : " << score;
			cout << "\nPress 1 to continue, or anything else to quit";
			delay(100);
			if (_kbhit())
			{


				if (_getch() == 49)
				{
					toReplay = true;
					break;
				}else 
				{
					toReplay = false;
					break;
				}


			}
		}//Do the replay prompt

		
	}

   // complete.
   return 0;
}

int CharToInt(char inChar)
{
	switch (tolower(inChar))
	{
	case 'w': {
		return 1;

	}
	case 'a': {
		return 2;

	}
	case 's': {
		return 3;

	}
	case 'd': {
		return 4;

	}
	default:
		break;
	}
	return 0;
}

char IntToChar(int inInt)
{
	switch (inInt)
	{
	case 1 : 
		return 'w';
	case 2:
		return 'a';
	case 3: 
		return 's';
	case 4: 
		return 'd';
	default:
		break;
	}
	return 0;
}
