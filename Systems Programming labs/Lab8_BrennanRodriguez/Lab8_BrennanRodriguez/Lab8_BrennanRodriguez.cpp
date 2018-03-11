// Lab8_BrennanRodriguez.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <bitset>


using namespace std;
int main()
{
	unsigned char bits = 0;
	bitset<8> memory(bits);
	int selIndex = 0;
	while (true)
	{
		Console::Lock(true);
		Console::Clear();

		if (GetAsyncKeyState(VK_ESCAPE))
			break;

		if (GetAsyncKeyState(VK_F1)) {
			memory[selIndex] = 1;
		}


		if (GetAsyncKeyState(VK_F2)) {
			memory[selIndex] = ~memory[selIndex];
		}


		if (GetAsyncKeyState(VK_F3)) {
			memory[selIndex] = 0;
		}


		if (GetAsyncKeyState(VK_F4)) {
			for (int i = 0; i < memory.size(); i++)
			{
				memory[i] = ~memory[i];
			}
		}


		if (GetAsyncKeyState(VK_LEFT)) {
			selIndex = (selIndex + 1) % 8;
		}


		if (GetAsyncKeyState(VK_RIGHT)) {
			selIndex--;
			if (selIndex < 0)
			{
				selIndex = 7;
			}
		}
		if (GetAsyncKeyState(VK_LSHIFT)) {
			memory = memory << 1;
		}
		if (GetAsyncKeyState(VK_RSHIFT)) {
			memory = memory >> 1;
		}
			


			
		cout << "Bits: \n" << memory;
		
		Console::SetCursorPosition(7-selIndex, 2);
		cout << "^";

		int test;
		test = (int)(memory.to_ulong());
		Console::SetCursorPosition(0, 3);
		cout << "Actual Integer: " << test;
		Console::Lock(false);
		Sleep(10);
	}

    return 0;
}

