#pragma once
#include "SLList.h"

using namespace std;
template <typename Type>
class HTable {

	SLList<Type> *_array;
	unsigned int arraySize;
public:
	unsigned int(*_hash)(const Type &v);


	/////////////////////////////////////////////////////////////////////////////
	// Function : Constructor 
	// Parameters : numOfBuckets - the number of buckets
	//              hFunction - pointer to the hash function for this table
	// Notes : constructs an empty hash table
	/////////////////////////////////////////////////////////////////////////////
	HTable(unsigned int numOfBuckets, unsigned int(*hFunction) (const Type &v)) {

		_array = new SLList<Type>[numOfBuckets];
		arraySize = numOfBuckets;
		_hash = hFunction;
		
		



	}

	/////////////////////////////////////////////////////////////////////////////
	// Function : Destructor
	// Notes : destroys a hash table
	/////////////////////////////////////////////////////////////////////////////
	~HTable() {
		clear();
		delete[] _array;

	}

	/////////////////////////////////////////////////////////////////////////////
	// Function : Assignment Operator
	/////////////////////////////////////////////////////////////////////////////
	HTable<Type>& operator=(const HTable<Type>& that) {
		if (this != &that)
		{
			clear();
			delete[] _array;
			
			_array = new SLList<Type>[that.arraySize];
			arraySize = that.arraySize;
			for (unsigned int i = 0; i < that.arraySize; i++)
			{
				_array[i] = that._array[i];
			}
			_hash = that._hash;
		}


		return *this;
	}

	/////////////////////////////////////////////////////////////////////////////
	// Function : Copy Constructor
	/////////////////////////////////////////////////////////////////////////////
	HTable(const HTable<Type>& that) {
		_array = new SLList<Type>[that.arraySize];
		arraySize = that.arraySize;
		for (unsigned int i = 0; i < that.arraySize; i++)
		{
			_array[i] = that._array[i];
		}
		_hash = that._hash;

	}

	/////////////////////////////////////////////////////////////////////////////
	// Function : insert
	// Parameters : v - the item to insert into the hash table
	/////////////////////////////////////////////////////////////////////////////
	void insert(const Type& v) {
		_array[_hash(v)].addHead(v);

	}

	/////////////////////////////////////////////////////////////////////////////
	// Function : findAndRemove
	// Parameters : v - the item to remove(if it is found)
	/////////////////////////////////////////////////////////////////////////////
	bool findAndRemove(const Type& v) {
		int spot = _hash(v);
		SLLIter<Type> iter(_array[spot]);
		for (unsigned int i = 0; i < _array[spot].size(); i++)
		{
			if (iter.current() == v)
			{
				_array[spot].remove(iter);
				return true;
			}
			++iter;
		}

		return false;
	}

	/////////////////////////////////////////////////////////////////////////////
	// Function : clear
	// Notes : clears the hash table
	/////////////////////////////////////////////////////////////////////////////
	void clear() {
		for (unsigned int i = 0; i < arraySize; i++)
		{
			_array[i].clear();
		}

	}

	/////////////////////////////////////////////////////////////////////////////
	// Function : find
	// Parameters : v - the item to look for
	// Return : the bucket we found the item in or -1 if we didn’t find the item.
	/////////////////////////////////////////////////////////////////////////////
	int find(const Type& v) const {
		int spot = _hash(v);
		SLLIter<Type> iter(_array[spot]);
		for (unsigned int i = 0; i < _array[spot].size(); i++)
		{
			if (iter.current() == v)
			{
				
				return spot;
			}
			++iter;
		}




		return -1;
	}
	int GetArraySize() {
		return arraySize;
	}

	// the following variable names are used below, match them to your variable names 
	//	theTable - this is the array of lists
	//	buck - the number of buckets

	
	void HTable<Type>::printSomeStuff(const char* filePath = "hashdata.txt")
	{
		ofstream outFile(filePath);

		if (outFile.is_open())
		{
			unsigned int empty = 0;
			unsigned int totalCount = 0;
			unsigned int loIndex = 0;
			unsigned int hiIndex = 0;

			for (unsigned int i = 0; i < arraySize; ++i)
			{
				totalCount += _array[i].size();
				outFile << i << " : " << _array[i].size() << '\n';
				if (_array[i].size() == 0)
					++empty;

				if (_array[i].size() < _array[loIndex].size())
					loIndex = i;
				else if (_array[i].size() > _array[hiIndex].size())
					hiIndex = i;
			}

			outFile << '\n' << totalCount << " Total items stored in " << arraySize << " arraySizeets\n";
			outFile << '\n' << empty << " arraySizeets are empty\n\n";

			unsigned int Low = _array[loIndex].size();
			unsigned int range = _array[hiIndex].size() - Low + 1;

			outFile << "each arraySizeet contains between " << Low << " and " << Low + range - 1 << " items.\n\n";

			unsigned int* arr = new unsigned int[range];
			for (unsigned int j = 0; j < range; ++j)
				arr[j] = 0;

			for (unsigned int k = 0; k < arraySize; ++k)
				++arr[_array[k].size() - Low];

			for (unsigned int p = 0; p < range; ++p)
				outFile << arr[p] << " arraySizeets have " << p + Low << " items\n";

			delete[] arr;
		}
	}






};