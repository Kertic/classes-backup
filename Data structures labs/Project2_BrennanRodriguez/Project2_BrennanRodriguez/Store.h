#pragma once

#include <iostream>
#include <fstream>
#include "DynArray.h"
#include <string>
#include"Item.h"

using namespace std;
class Store
{
	DynArray<Item> shop;
public:
	Store() {


	}
	~Store() {

	}

	void Load() {
		string dump;

		ifstream filein("items.shp");
		getline(filein, dump);
		//Read in the file
		while (!filein.eof())
		{
			string input;
			getline(filein, input);

			//0-17 is type
			string toType;

			//18-32 is name
			string toName;

			//33-42 is cost
			string s_toCost;
			unsigned int toCost;

			//43 to end is weight
			string s_toWeight;
			unsigned int toWeight;

			toType = input.substr(0, 17);
			toName = input.substr(17, 10);
			s_toCost = input.substr(31, 9);
			s_toWeight = input.substr(39);
			toCost = stoi(s_toCost);
			toWeight = stoi(s_toWeight);
			toType = removeWhiteSpaces(toType);
			toName = removeWhiteSpaces(toName);

			Item temp = Item(toType, toName, toCost, toWeight);
			shop.append(temp);



		}

		filein.close();
	}

	string removeWhiteSpaces(string inString)
	{

		int count = 0;


		for (unsigned int i = 0; i < inString.length(); i++)
		{
			if (inString[i] != ' ')
			{
				inString[count++] = inString[i];
			}
		}

		inString[count] = '\0';
		int x = 0;

		return inString;
	}


	void DisplayStock()
	{
		cout << "Name\t\tType\t\t\tWeight\tCost\n";

		for (unsigned int i = 0; i < shop.size(); i++)
		{
			cout << shop[i].name << "\t";
			cout << shop[i].type << "\t";
			cout << shop[i].weight << "\t";
			cout << shop[i].cost << "\t";
			cout << "\n";

		}

	}

	void DisplayItem(unsigned int index) {
		if (index < shop.size() && index >= 0)
		{
			cout << shop[index].name << "\t";
			cout << shop[index].type << "\t";
			cout << shop[index].weight << "\t";
			cout << shop[index].cost << "\t";
			cout << "\n";
		}
		else
		{
			cout << "Index invalid";
		}
	}

	 int SearchItem(string _name)//Returns what index the item is at if it finds it or -1 otherwise
	{
		for (unsigned int i = 0; i < shop.size(); i++) {

			string itemName = shop[i].name;
			string itemNameLower;
			string nameLower;
			for (int j = 0; itemName[j] != '\0'; j++)
			{
				itemNameLower.append(1, tolower(itemName[j]));
			}
			for (int k = 0; _name[k] != '\0'; k++)
			{
				nameLower.append(1, tolower(_name[k]));
			}


			if (itemNameLower == nameLower) {
				return i;
			}
		}
		return -1;
	}

	 Item SearchItemItem(string _name) {
		 for (unsigned int i = 0; i < shop.size(); i++) {

			 string itemName = shop[i].name;
			 string itemNameLower;
			 string nameLower;
			 for (int j = 0; itemName[j] != '\0'; j++)
			 {
				 itemNameLower.append(1, tolower(itemName[j]));
			 }
			 for (int k = 0; _name[k] != '\0'; k++)
			 {
				 nameLower.append(1, tolower(_name[k]));
			 }


			 if (itemNameLower == nameLower) {
				 return shop[i];
			 }
		 }
		 return Item("Def", "Def", -1, -1);
	 }

	DynArray<Item> SortStock(DynArray<Item> inDyn, int inChoice)
	{
		DynArray<Item> tempDyn = inDyn;
		for (unsigned int i = 1; i < tempDyn.size(); i++)//For every spot in the array
		{
			for (unsigned int j = i; j > 0; j--)//For every spot before it
			{
				if (inChoice == 1)
				{
					if (tempDyn[j - 1].cost > tempDyn[j].cost)//If the spot before it is greater than itself, swap them.
					{
						
						
						Item temp = tempDyn[j];
						tempDyn[j] = tempDyn[j - 1];
						tempDyn[j - 1] = temp;

					}
				}
				if (inChoice == 2)
				{
					if (tempDyn[j].weight > tempDyn[j - 1].weight)
					{
					
						
						Item temp = tempDyn[j];
						tempDyn[j] = tempDyn[j - 1];
						tempDyn[j - 1] = temp;

					}
				}
				if (inChoice == 3)
				{
					if (tempDyn[j].name > tempDyn[j - 1].name)
					{
					
						
						Item temp = tempDyn[j];
						tempDyn[j] = tempDyn[j - 1];
						tempDyn[j - 1] = temp;

					}

				}
				if (inChoice == 4)
				{
					if (tempDyn[j].type > tempDyn[j - 1].type)
					{
						
						
						Item temp = tempDyn[j];
						tempDyn[j] = tempDyn[j - 1];
						tempDyn[j - 1] = temp;

					}
				}

			}
		}

		return tempDyn;
	}
	void SetStock(DynArray<Item> inItem) {
		shop = inItem;
	}


	DynArray<Item> getStock() {
		return shop;
	}

	void RemoveItem(int index) {//Wont remove anything on an invalid index.
		DynArray<Item> temp;
		for (unsigned int i = 0; i < shop.size(); i++)
		{
			if (i != index)
			{
				temp.append(shop[i]);

			}
		}
		shop = temp;
	}

	void AddItem(Item item) {
		shop.append(item);

	}
};


