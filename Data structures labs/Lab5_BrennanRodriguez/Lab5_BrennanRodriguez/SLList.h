#pragma once

template<typename Type> class SLLIter;

template <typename Type>
class SLList
{
	unsigned int _size;

	struct Node {
		Type data;
		Node* next;
	};


	Node* head;





	/////////////////////////////////////////////////////////////////////////////
	// Function : Recursive add-head
	// Disc.    : This function will take in a node pointer, and use add-head in
	//            Reverse order, by calling itself until the node it was given
	//            no longer has a next, resulting in it adding the node as the 
	//            head until it reaches the original node you gave it.
	/////////////////////////////////////////////////////////////////////////////
	void RecursiveAddHead(Node* inNode) {
		if (inNode->next)
		{
			RecursiveAddHead(inNode->next);
		}
		addHead(inNode->data);
	}





public:
	friend class SLLIter<Type>;
	/////////////////////////////////////////////////////////////////////////////
	// Function : Constructor
	// Notes : constructs an empty list
	/////////////////////////////////////////////////////////////////////////////
	SLList() {
		_size = 0;
		head = nullptr;

	}

	/////////////////////////////////////////////////////////////////////////////
	// Function : Destructor
	// Notes : Destroys the list
	/////////////////////////////////////////////////////////////////////////////
	~SLList() {
		Node* temp;
		temp = head;
		for (unsigned int i = 0; i < size(); i++)
		{
			temp = head->next;
			delete head;
			head = temp;
		}

	}

	/////////////////////////////////////////////////////////////////////////////
	// Function : Assignment Operator
	// Disc     : Sets one list to be a copy of another list, but not point to 
	//            same memory addresses
	/////////////////////////////////////////////////////////////////////////////
	SLList<Type>& operator=(const SLList<Type>& that) {

		if (this != &that)//if its not the same thing
		{
			clear();
			if (!(that.head))//If its head is null
			{
				//do nothing
			}
			else
			{

				RecursiveAddHead(that.head);
			}

		}


		return *this;


	}





	/////////////////////////////////////////////////////////////////////////////
	// Function : Copy Constructor
	/////////////////////////////////////////////////////////////////////////////
	SLList(const SLList<Type>& that) {
		head = nullptr;
		RecursiveAddHead(that.head);
		_size = that.size();
	}

	/////////////////////////////////////////////////////////////////////////////
	// Function : addHead
	// Parameters :	v - the item to add to the list
	/////////////////////////////////////////////////////////////////////////////
	void addHead(const Type& v) {
		Node* temp = head;
		head = new Node;
		head->data = v;
		head->next = temp;
		_size++;
	}

	/////////////////////////////////////////////////////////////////////////////
	// Function : clear
	// Notes : clears the list, freeing any dynamic memory
	/////////////////////////////////////////////////////////////////////////////
	void clear() {
		Node* temp;
		temp = head;
		if (head)
		{
			for (unsigned int i = 0; i < size(); i++)
			{
				temp = head->next;
				delete head;
				head = temp;
			}
		}

		_size = 0;
		head = nullptr;
	}
	/////////////////////////////////////////////////////////////////////////////
	// Function : insert
	// Parameters :	index - an iterator to the location to insert at
	//				v - the item to insert
	// Notes : do nothing on a bad iterator
	/////////////////////////////////////////////////////////////////////////////
	void insert(SLLIter<Type>& index, const Type& v) {
		if (index.iter)
		{
			if (index.iter == index.watchedList->head)
			{
				addHead(v);
				index.begin();
			}
			else
			{
				Node* temp = index.iter;

				for (index.begin(); index.iter->next != temp; ++index)
				{

				}
				Node* newNode = new Node;
				newNode->data = v;
				newNode->next = temp;
				index.iter->next = newNode;
				index.iter = newNode;
				_size++;
			}

		}



	}

	/////////////////////////////////////////////////////////////////////////////
	// Function : remove
	// Parameters :	index - an iterator to the location to remove from
	// Notes : do nothing on a bad iterator
	/////////////////////////////////////////////////////////////////////////////
	void remove(SLLIter<Type>& index) {
		if (index.iter)
		{
			if (index.iter == index.watchedList->head)//if its the head
			{
				Node* temp = index.watchedList->head;
				index.watchedList->head = index.watchedList->head->next;
				index.iter = index.watchedList->head;
				delete temp;


			}
			else//if its not the head
			{
				Node* temp = index.iter;

				for (index.begin(); index.iter->next != temp; ++index)
				{

				}
				index.iter->next = temp->next;
				index.iter = index.iter->next;
				delete temp;
				int x = 0;
			}
			_size--;

		}

	}

	/////////////////////////////////////////////////////////////////////////////
	// Function : size
	// Return : the number of items stored in the linked list.
	/////////////////////////////////////////////////////////////////////////////
	inline unsigned int size() const { return _size; };


};



template <typename Type>
class SLLIter {

public:
	friend class SLList<Type>;
	typename SLList<Type>::Node * iter;
	typename SLList<Type>* watchedList;
	/////////////////////////////////////////////////////////////////////////////
	// Function : Constructor
	// Parameters :	listToIterate - the list to iterate
	/////////////////////////////////////////////////////////////////////////////
	SLLIter(SLList<Type>& listToIterate) {
		iter = listToIterate.head;
		watchedList = &listToIterate;

	}

	/////////////////////////////////////////////////////////////////////////////
	// Function : begin
	// Notes : moves the iterator to the head of the list
	/////////////////////////////////////////////////////////////////////////////
	void begin() {
		iter = watchedList->head;
	}

	/////////////////////////////////////////////////////////////////////////////
	// Function : end
	// Notes : returns true if we are at the end of the list, false otherwise
	/////////////////////////////////////////////////////////////////////////////
	bool end() const {
		if (!iter)//if iter exists
		{
			return true;

		}
		else
		{
			return false;
		}

	}

	/////////////////////////////////////////////////////////////////////////////
	// Function : operator++
	// Notes : move the iterator forward one node
	/////////////////////////////////////////////////////////////////////////////
	SLLIter<Type>& operator++() {
		if (iter)
		{
			iter = iter->next;
		}
		return *this;

	}

	/////////////////////////////////////////////////////////////////////////////
	// Function : current
	// Notes : returns the item at the current iterator location
	/////////////////////////////////////////////////////////////////////////////
	Type& current() const {
		return iter->data;
	}


};

