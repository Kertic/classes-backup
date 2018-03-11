#pragma once
#include "SLList.h"
#include <iostream>
#include "Item.h"
using namespace std;

class Player {

private:
	SLList<Item> inventory;

	unsigned int gold, weight, maxWeight;


public: 

	Player() {
		gold = 5000;
		weight = 0;
		maxWeight = 50;
	}

	unsigned int getGold() {
		return gold;

	}

	void setGold(int inGold) {
		if (inGold >= 0)
		{
			gold = inGold;
		}
		else
		{
			gold = 0;
		}
	}

	unsigned int getWeight() {
		return weight;
	}

	void setWeight(int inWeight) {
		if (inWeight >= 0)
		{
			weight = inWeight;

		}
		else
		{
			weight = 0;
		}
	}

	unsigned int getMaxWeight() {
		return maxWeight;
	}

	void AddItem(Item inItem) {
		inventory.addHead(inItem);
	}

	bool RemoveItem(Item inItem) {//returns if it removed successfully or not
		bool found = false;

		SLLIter<Item> iter(inventory);
		for (unsigned int i = 0; i < inventory.size() && found == false; i++)
		{
			if (iter.current().name == inItem.name)
			{
				inventory.remove(iter);
				found = true;
			}
		}

		return found;
	}

	void DisplayInventory() {
		SLLIter<Item> iter(inventory);
		cout << "Name\t\tType\t\t\tWeight\tCost\n";
		for (unsigned int i = 0; i < inventory.size(); i++)
		{

			cout << iter.current().name << "\t";
			cout << iter.current().type << "\t";
			cout << iter.current().weight << "\t";
			cout << iter.current().cost << "\t";
			cout << "\n";
			++iter;
		}
	}





};