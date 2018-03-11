#pragma once
#include "Item.h"
#include "Store.h"
#include "Inventory.h"
#include <conio.h>
#include <Windows.h>


class TransactionManager
{
	struct Transaction
	{
		Item theItem;
		bool bought;//True if bought from the store, false if selling from player

		Transaction() {
			//aint nothing
		}
		Transaction(Item inItem, bool didBuy) {
			theItem = inItem;
			bought = didBuy;
		}
	};

	Store _store;
	Player _player;
	SLList<Transaction> _history;
	//No idea why it wont work here like it does in the lab...
	
public:
	TransactionManager(){

	}


	TransactionManager(Store inStore, Player inPlayer) {
		_store = inStore;
		_player = inPlayer;


	}
	void Buy(Item inItem) {
		int foundIndex = _store.SearchItem(inItem.name);
		SLLIter<Transaction> historyIter(_history);
		if (foundIndex >= 0)
		{
			if (_player.getGold() >= inItem.cost)
			{
				if (_player.getWeight() + inItem.weight <= _player.getMaxWeight())
				{

					_player.setGold(_player.getGold() - inItem.cost);//and buy it and 
					_player.setWeight(_player.getWeight() + inItem.weight);
					_player.AddItem(inItem);
					historyIter.begin(); //add it to the history
					AddToHistory(Transaction(inItem, true));
					_store.RemoveItem(foundIndex);//remove it from the list 
					Display(4);

				}
				else
				{
					Display(2);//Display the "Item too heavy" message
				}


			}
			else
			{
				Display(3);//Display "Item too expensive" message
			}
		}
		else
		{
			Display(1);//Display "Item not found" message
		}

	}
	void Sell(Item inItem) {
		



			if (_player.RemoveItem(inItem))
			{
				system("cls");
				cout << "===============================\n";
				cout << "    Item sold successfully\n";
				cout << "===============================";
				AddToHistory(Transaction(inItem, false));
				_player.setGold(_player.getGold() - inItem.cost / 2);
				_player.setWeight(_player.getWeight() - inItem.weight);
				_store.AddItem(inItem);

			}
			else
			{
				system("cls");
				cout << "===============================\n";
				cout << "        Item not found\n";
				cout << "===============================";

			}
			cout << "\n";
			system("pause");

		

	}
	void Undo() {
		if (_history.size() > 0)
		{
			SLLIter<Transaction> tempIter(_history);
			Item itemInQuestion = tempIter.current().theItem;
			bool wasBought = tempIter.current().bought;
			if (wasBought)
			{
				_player.setGold(_player.getGold() + itemInQuestion.cost);//Refund the cost
				_player.setWeight(_player.getWeight() - itemInQuestion.weight);//Remove the weight
				_player.RemoveItem(itemInQuestion);//Remove the item from his inventory
				_store.AddItem(itemInQuestion);//Add the item back into the store


			}
			if (!wasBought)
			{
				_player.setGold(_player.getGold() - itemInQuestion.cost);//Repay the cost
				_player.setWeight(_player.getWeight() + itemInQuestion.weight);//Re-add the weight
				_player.AddItem(itemInQuestion);
				int indexToRemove = _store.SearchItem(itemInQuestion.name);
				_store.RemoveItem(indexToRemove);
			}
			_history.remove(tempIter);
		}

	}
	void AddToHistory(Transaction inTran) {
		SLLIter<Transaction> historyIter(_history);
		if (_history.size() > 4)//If its size is bigger than 4, we remove the last item
		{
			historyIter.begin();
			for (unsigned int i = 0; i < _store.getStock().size(); i++)
			{
				++historyIter;
			}
			_history.remove(historyIter);
		}


		_history.addHead(inTran);
	}
	void DisplayStore() {
		_store.DisplayStock();
	}
	void DisplayPlayer() {
		cout << "Current weight: " << _player.getWeight() << "     Max Weight: " << _player.getMaxWeight() << "     Gold: " << _player.getGold() << "\n";
		_player.DisplayInventory();
	}
	void Display() {//No args will display the inventory and shop
		DisplayPlayer();
		cout << "\n============================Store==============================\n";
		DisplayStore();
	
	} 
	void Display(int choice) {//An arg will display a collection of messages and such, and wait for a key to be pressed.
		



			switch (choice)
			{
			case 1://Item not found
				system("cls");
				cout << "==================================\n";
				cout << "           Item not found\n";
				cout << "==================================";

				break;

			case 2://Item too heavy
				system("cls");
				cout << "==================================\n";
				cout << "           Item too heavy\n";
				cout << "==================================";

				break;
			case 3:
				system("cls");
				cout << "==================================\n";
				cout << "         Item too expensive\n";
				cout << "==================================";

				break;

			case 4: 

				system("cls");
				cout << "==================================\n";
				cout << "         Item purchased\n";
				cout << "==================================";
			default:
				break;
			}
			cout << "\n";
			system("pause");

		


	}
	int GetHistorySize() {
		return _history.size();
	}
	void SortStore(int choice) {
		_store.SetStock(_store.SortStock(_store.getStock(), choice));
	}

};