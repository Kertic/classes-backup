
//Yo i stole this code from TJ, and then you used it, so idk if its stealing... But if it is, credit goes to my main man Rodney	
////////////////////////////////////////////////////////////////////////////////////////////////
// LEAK DETECTION
////////////////////////////////////////////////////////////////////////////////////////////////
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

////////////////////////////////////////////////////////////////////////////////////////////////
// INCLUDES
////////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include <string>
#include "DynArray.h"
using namespace std;
#include "SLList.h"
#include "Inventory.h"
#include "Store.h"
#include "TransactionMgr.h"
#include <Windows.h>



Item BuyPrompt();
Item SellPrompt();
int SortPrompt();
Item SearchPrompt();



int main(int argc, char ** argv)
{
	////////////////////////////////////////////////////////////////////////////////////////////////
	// LEAK DETECTION
	////////////////////////////////////////////////////////////////////////////////////////////////
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);


	////////////////////////////////
	//  INNITIALIZE
	////////////////////////////////
	Store store;
	store.Load();
	Player player;
	TransactionManager manager(store, player);
	while (true)
	{
		system("cls");
		manager.Display();

		cout << "\n(1) Buy an item";
		cout << "\n(2) Sell an item";
		cout << "\n(3) Undo (" << manager.GetHistorySize() << ")";
		cout << "\n(4) Sort";
		cout << "\n(5) Search";
		cout << "\n(6) Exit";
		if (_kbhit())
		{
			char inKey = _getch();
			if (inKey == 49)
			{
				Item temp = BuyPrompt();

				manager.Buy(store.SearchItemItem(temp.name));//Buy already will already display a message that it wasnt found

			}
			else if (inKey == 50)
			{
				Item temp = SellPrompt();

				manager.Sell(store.SearchItemItem(temp.name));
			}
			else if (inKey == 51)
			{
				manager.Undo();
			}
			else if (inKey == 52)
			{
				manager.SortStore(SortPrompt());
			}
			else if (inKey == 53)
			{
				Item temp = store.SearchItemItem(SearchPrompt().name);
				if (temp.name == "Def")
				{
					system("cls");
					cout << "==================";
					cout << "\n  Item not found\n";
					cout << "==================\n";
				}
				else
				{
					system("cls");
					cout << "==================";
					cout << "\n  Item  found\n";
					cout << temp.name << "\t";
					cout << temp.type << "\t";
					cout << temp.weight << "\t";
					cout << temp.cost << "\t";
					cout << "\n";
					cout << "==================\n";
				}
				system("pause");
			}
			else if (inKey == 54)
			{
				break;
			}
		}
		Sleep(900);

	}









	return 0;

}

Item BuyPrompt()
{
	system("cls");
	cout << "What would you like to buy? ";
	string input;
	cin >> input;
	
	return Item("Def", input, 10, 10);
}

Item SellPrompt()
{
	system("cls");
	cout << "What would you like to sell? ";
	string input;
	cin >> input;

	return Item("Def", input, 10, 10);
}

int SortPrompt()
{
	system("cls");
	cout << "How would you like to sort the list? ";
	cout << "\nCost - 1";
	cout << "\nWeight - 2";
	cout << "\nName - 3";
	cout << "\nType - 4\n";
	int input;
	cin >> input;
	return input;
}

Item SearchPrompt()
{
	system("cls");
	cout << "What is the name of the item? ";
	string input;
	cin >> input;
	return Item("Def", input, 10, 10);
}
