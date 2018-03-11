
#include <tchar.h>


#include <Windows.h>

#include <cstring>
#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>


#include "DynArray.h"

#include <iostream>
#include <ctime>
#include <string>
#include <conio.h>
#include "BoggleDict.h"



const int numBuckets = 9500;
using namespace std;

unsigned int hashTest(string _input) {//Adds up character values
	unsigned int stringValue = 0;
	for (unsigned int i = 0; i < _input.length(); i++)
	{
		stringValue += _input[i];
	}
	return stringValue;
}

unsigned int hashTest2(const string& _input) {//Changes the factor of each letter from 1000's place to the 1's place up to the 4th character
	unsigned int stringValue = 0;
	for (unsigned int i = 0; i < _input.length(); i++)
	{
		int tempNum = _input[i];
		if (i > 0)//If i > 0
		{
			tempNum *= 10*i;//Take the current index's value
			//Multiply it by 10i

			tempNum -= _input[i - 1];//Subtract the previous value
			tempNum = tempNum % 63709;//Mod it by a large prime number
		}

		stringValue += tempNum;//Add it to stringValue
		


		


	}
	return stringValue % numBuckets;

}

void lock(bool lock)
{
	LockWindowUpdate(lock ? GetConsoleWindow() : nullptr);//Credits to TJ, inspired by code from the console files he gave us last class
}

class DTSTimer
{
	unsigned int startTime;
public:
	DTSTimer()
	{
		reset();
	}

	void reset()
	{
		startTime = clock();
	}

	unsigned int getElapsedTime()
	{
		return (clock() - startTime);
	}

	static void delay(const unsigned int milli)
	{
		unsigned int st = clock();
		while (clock() - st < milli) {}
	}

};


int main(int argc, char ** argv)
{
	//	//Also need this for memory leak code stuff
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	_CrtSetBreakAlloc(-1); //Important!



	
	string userInput;
	DynArray<string> foundStrings;
	BoggleDict<string> boggle(numBuckets, hashTest2);
	cout << "Loading...\n";
	boggle.Populate();
	
	bool isOver = false;
	while (!isOver)
	{
		//Put menu stuff here


		//Testing grid pathing
		boggle.PopulateGrid(true);
		boggle.PrintGrid();
		string test = "slow";
		string test2 = "sloow";
		if (boggle.checkIfStringCanBeMade(test))
		{
			cout << "\nslow worked! Yay!";
		}
		else
		{
			cout << "\nslow failed,boo";
		}

		if (boggle.checkIfStringCanBeMade(test2))
		{
			cout << "\nsloow worked, boo";
		}
		else
		{
			cout << "\nsloow failed, YAAAY";
		}
		system("pause");

		while (true)//Menu while loop
		{


			system("cls");
			cout << "Welcome to Boggleish!";
			cout << "\nType \"1\" to play with a pregenerated grid\nType \"2\" to play with a randomly generated grid\n";
			char menuInput;
			cin >> menuInput;

			if (menuInput == '1')
			{
				boggle.PopulateGrid(true);
				break;
			}
			if (menuInput == '2')
			{
				system("cls");
				cout << "Generating...";
				boggle.PopulateGrid(false);
				break;
			}
		}


		DTSTimer timer;
		while (timer.getElapsedTime() < 15000)
		{
			bool didFind = false;
			string stringFound;
			// 1 - get user input
			if (_kbhit())
			{
				char ch = _getch();

				if (-32 == ch)
					_getch();

				// did the user press a-z?
				else if (isalpha(ch))
				{
					userInput += tolower(ch);
				}
				else if (ch == 13)//13 is the enter key
				{
					if (boggle.searchForString(userInput))//If the boggleDict has the word stored as a word
					{

						bool hasAlreadyBeenFound = false;
						for (unsigned int i = 0; i < foundStrings.size(); i++)
						{
							if (foundStrings[i] == userInput)
							{
								hasAlreadyBeenFound = true;
							}
						}

						if (!hasAlreadyBeenFound)//If we havent already found the word
						{
							unsigned int toAdd = userInput.length();
							for (unsigned int i = userInput.size() - 1; i > 0; i--)
							{
								toAdd *= i;
							}

							foundStrings.append(userInput);
							boggle.SetScore(boggle.GetScore() + toAdd);
						}

					}


					userInput.clear();
				}
				else if (ch == 8)//The backspace key
				{
					userInput.erase(userInput.size() - 1, userInput.size() - 1);
				}
				else if (ch == 27)//The esc key
				{
					break;
				}
			}

			// 2 - act on it


			// 3 - draw the screen
			lock(true);
			system("cls");
			cout << 15 - timer.getElapsedTime() / 1000;
			cout << "\n";
			boggle.PrintGrid();
			cout << '\n' << userInput << '\n';
			cout << "\nScore: " << boggle.GetScore();
			for (unsigned int i = 0; i < foundStrings.size(); i++)
			{
				cout << "\n" << foundStrings[i];
			}
			lock(false);

		}



	}
	return 0;
}