#pragma once

template <typename Type>
class DynArray
{
	Type * _array;
	unsigned int _size, _capacity;

public:
	/////////////////////////////////////////////////////////////////////////////
	// Function :	Constructor
	// Notes : Constructs an empty array (Size 0 Capacity 0)
	/////////////////////////////////////////////////////////////////////////////
	DynArray() {
		_array = nullptr;
		_size = 0;
		_capacity = 0;
	}

		/////////////////////////////////////////////////////////////////////////////
		// Function :	Destructor
		// Notes : cleans up any dynamic memory
		/////////////////////////////////////////////////////////////////////////////
	~DynArray() {
		delete[] _array;
		}

		/////////////////////////////////////////////////////////////////////////////
		// Function :	Copy Constructor
		/////////////////////////////////////////////////////////////////////////////
	DynArray(const DynArray<Type>& that) {
		_array = nullptr;

		*this = that;
		}

		/////////////////////////////////////////////////////////////////////////////
		// Function :	Assignment Operator
		/////////////////////////////////////////////////////////////////////////////
	DynArray<Type>& operator=(const DynArray<Type>& that) {
		if (this != &that)
		{
			delete[] _array;
			_array = new Type[that.capacity()];
		
			for (unsigned int i = 0; i < that.size(); i++)
			{
				_array[i] = that[i];
				
			}
			




			_size = that.size();
			_capacity = that.capacity();
		}
		return *this;

		}

		/////////////////////////////////////////////////////////////////////////////
		// Function : operator[]
		// Parameters : index - the index to access
		// Return : Type & - returns the array element at [index]
		// Notes : performs no error checking. user should ensure index is 
		//		valid with the size() method
		/////////////////////////////////////////////////////////////////////////////
	Type& operator[](const unsigned int index) {
		return _array[index];

		}

		/////////////////////////////////////////////////////////////////////////////
		// Function : operator[]
		// Parameters : index - the index to access
		// Return : const Type & - returns the array element at [index]
		// Notes : performs no error checking. user should ensure index is 
		//		valid with the size() method
		/////////////////////////////////////////////////////////////////////////////
	const Type& operator[](const unsigned int index) const {
		return _array[index];

		}
		/////////////////////////////////////////////////////////////////////////////
		// Function :	size
		// Returns : int - returns the number of items being stored
		// Notes : this function returns the number of items being stored, 
		/////////////////////////////////////////////////////////////////////////////
	unsigned int size() const {
		return _size;

		}
		/////////////////////////////////////////////////////////////////////////////
		// Function : capacity
		// Returns : int - returns the number of items the array can store before 
		//		the next resize
		// Notes : this function returns the number of items the array can store, 
		//		not the number of bytes
		/////////////////////////////////////////////////////////////////////////////
	unsigned int capacity() const {
		return _capacity;
		}

		/////////////////////////////////////////////////////////////////////////////
		// Function :	clear
		// Notes : cleans up any dynamic memory and resets size and capacity to 0
		/////////////////////////////////////////////////////////////////////////////
	void clear() {
		
		delete[] _array;
		_array = nullptr;
		_size = 0;
		_capacity = 0;
		}

		/////////////////////////////////////////////////////////////////////////////
		// Function : append
		// Parameters : item - the item to be appended to the next open spot
		// Notes : this function will append the item to the next open spot. if 
		//		no room exists, the array's capacity will be doubled and then 
		//		the item will be added
		/////////////////////////////////////////////////////////////////////////////
	void append(const Type& item) {
		if (_size < _capacity)//If we have room
		{
			_array[_size] = item;
		}
		else//we aint got none room left
		{
			reserve();
			_array[_size] = item;
		}
		_size++;

		}

		/////////////////////////////////////////////////////////////////////////////
		// Function : reserve
		// Parameters : newCap - the new capacity
		// Notes : 	- default parameter - reserve more space in the array, based on //		the expansion rate (100%, 1 minimum).
		//		- non-default parameter, expand to the specified capacity
		//		- if newCap is LESS than the current capacity, do nothing. 
		//		This function should NOT make the array smaller.
		/////////////////////////////////////////////////////////////////////////////
	void reserve(const unsigned int & newCap = 0) {
		if (newCap < _capacity && newCap != 0)
		{
			return;
		}
		int size = 0;
		if (newCap == 0)
		{

			//make a new array with double its size, with minimum of 1
			if (_capacity == 0)
			{
				size = 1;
			}
			else
			{
				size = _capacity * 2;
			}
			Type * tempArray = nullptr;
			tempArray = new Type[size];

			//copy over the data for _size
			for (unsigned int i = 0; i < _size; i++)
			{
				tempArray[i] = _array[i];
			}
			//delete the old array
			delete[] _array;
			//set _array to the new one
			_array = tempArray;
			
			_capacity = size;//Make the capacity into the size of the array
		}

		if (newCap != 0)
		{
			//Make a new array with size newCap
			Type * tempArray = nullptr;
			tempArray = new Type[newCap];


			//copy over the data for _size
			for (unsigned int i = 0; i < _size; i++)
			{
				tempArray[i] = _array[i];
			}
			//delete the old array
			delete[] _array;
			//set _array to the new one
			_array = tempArray;
			_capacity = newCap;
		}

		
		}

};

