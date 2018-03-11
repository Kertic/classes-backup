#pragma once

#include <string>
using namespace std;


struct Item {
	string type;
	string name;
	unsigned int cost;
	unsigned int weight;

	Item(string _type, string _name, unsigned int _cost, unsigned int _weight) {
		type = _type;
		name = _name;
		cost = _cost;
		weight = _weight;
	}

	Item() {
		type = "Default";
		name = "Def_Name";
		cost = -1;
		weight = -1;
	}
};