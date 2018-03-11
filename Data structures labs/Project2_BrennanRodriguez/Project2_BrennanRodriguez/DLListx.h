#pragma once

template<typename Type> class DLLIter;

template <typename Type>
class DLList
{
	unsigned int _size;

	struct Node {
		Type data;
		Node* next;
		Node* prev;
	};


	Node* head;
	Node* tail;





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
	friend class DLLIter<Type>;
	/////////////////////////////////////////////////////////////////////////////
	// Function : Constructor
	// Notes : constructs an empty list
	/////////////////////////////////////////////////////////////////////////////
	DLList() {
		head = nullptr;
		tail = nullptr;
		_size = 0;

	}

	/////////////////////////////////////////////////////////////////////////////
	// Function : Destructor
	// Notes : Destroys a list
	/////////////////////////////////////////////////////////////////////////////
	~DLList() {
		Node* temp;
		temp = head;
		for (unsigned int i = 0; i > _size; i++)
		{
			temp = head->next;
			delete head;
			head = temp;
		}

	}

	/////////////////////////////////////////////////////////////////////////////
	// Function : Assignment Operator
	/////////////////////////////////////////////////////////////////////////////
	DLList<Type>& operator=(const DLList<Type>& that) {
		if (this != &that)//As long as we arent the same thing
		{
			if (!that.head && !that.tail)//If it has no head and has no tail
			{
				clear();
			}
			else
			{
				clear();
				RecursiveAddHead(that.head);
			}
			

			

		}
		return *this;
	}

	/////////////////////////////////////////////////////////////////////////////
	// Function : Copy Constructor
	/////////////////////////////////////////////////////////////////////////////
	DLList(const DLList<Type>& that) {
		head = nullptr;
		tail = nullptr;
		RecursiveAddHead(that.head);
		_size = that._size;

	}

	/////////////////////////////////////////////////////////////////////////////
	// Function : addHead
	// Parameters : v - the item to add to the head of the list
	/////////////////////////////////////////////////////////////////////////////
	void addHead(const Type& v) {
		Node* temp = new Node;
		temp->data = v;
		temp->next = head;
		temp->prev = nullptr;
		if (head != nullptr)
			head->prev = temp;

		head = temp;
		if (tail == nullptr)
			tail = temp;
		
		_size++;




	}

	/////////////////////////////////////////////////////////////////////////////
	// Function : addTail
	// Parameters : v - the item to add to the tail of the list
	/////////////////////////////////////////////////////////////////////////////
	void addTail(const Type& v) {
		Node* temp = new Node;
		temp->data = v;
		temp->next = nullptr;
		temp->prev = tail;
		if (tail != nullptr)
			tail->next = temp;

		tail = temp;
		if (head == nullptr)
			head = temp;
		_size++;
	}

	/////////////////////////////////////////////////////////////////////////////
	// Function : clear
	// Notes : clears the list, freeing any dynamic memory
	/////////////////////////////////////////////////////////////////////////////
	void clear() {
		Node* temp;
		temp = head;
		for (unsigned int i = 0; i < _size; i++)
		{
			temp = head->next;
			delete head;
			head = temp;
		}
		_size = 0;
		head = nullptr;
		tail = nullptr;

	}

	/////////////////////////////////////////////////////////////////////////////
	// Function : insert
	// Parameters :	index - an iterator to the location to insert at
	//				v - the item to insert
	// Notes : do nothing on a bad iterator
	/////////////////////////////////////////////////////////////////////////////
	void insert(DLLIter<Type>& index, const Type& v) {

		if (index.iter)
		{
			if (index.iter != head)
			{
				Node* temp = new Node;
				temp->data = v;
				temp->next = index.iter;
				temp->prev = index.iter->prev;
				index.iter->prev->next = temp;
				index.iter->prev = temp;
				index.iter = temp;
				_size++;
			}
			else
			{
				addHead(v);
			}
			

		}

	}

	/////////////////////////////////////////////////////////////////////////////
	// Function : remove
	// Parameters :	index - an iterator to the location to remove from
	// Notes : do nothing on a bad iterator
	/////////////////////////////////////////////////////////////////////////////
	void remove(DLLIter<Type>& index) {
		if (index.iter)
		{
			if (index.iter->next == nullptr && index.iter->prev == nullptr)//If there is one item left
			{
				Node* temp = index.iter;
				head = nullptr;
				tail = nullptr;
				delete temp;
				index.iter = head;
				_size--;
			}
			else
			{
				if (index.iter->next)
					index.iter->next->prev = index.iter->prev;
				if (index.iter->prev)
					index.iter->prev->next = index.iter->next;
				Node* temp = index.iter;
				index.iter = index.iter->next;
				delete temp;
				_size--;
			}

		}

	}



};



template <typename Type>
class DLLIter {

public:
	friend class DLList<Type>;
	typename DLList<Type>::Node * iter;
	typename DLList<Type>* watchedList;
	/////////////////////////////////////////////////////////////////////////////
	// Function : Constructor
	// Parameters :	listToIterate - the list to iterate
	/////////////////////////////////////////////////////////////////////////////
	DLLIter(DLList<Type>& listToIterate) {
		watchedList = &listToIterate;
		iter = listToIterate.head;

	}

	/////////////////////////////////////////////////////////////////////////////
	// Function : beginHead
	// Notes : moves the iterator to the head of the list
	/////////////////////////////////////////////////////////////////////////////
	void beginHead() {
		iter = watchedList->head;

	}

	/////////////////////////////////////////////////////////////////////////////
	// Function : beginTail
	// Notes : moves the iterator to the tail of the list
	/////////////////////////////////////////////////////////////////////////////
	void beginTail() {
		iter = watchedList->tail;
	}

	/////////////////////////////////////////////////////////////////////////////
	// Function : end
	// Notes : returns true if we are at the end of the list, false otherwise
	/////////////////////////////////////////////////////////////////////////////
	bool end() const {
		if (!iter)
		{
			return true;
		}
		return false;

	}

	/////////////////////////////////////////////////////////////////////////////
	// Function : operator++
	// Notes : move the iterator forward one node
	/////////////////////////////////////////////////////////////////////////////
	DLLIter<Type>& operator++() {
		if (iter)
		{
			iter = iter->next;
		}

		return *this;
	}

	/////////////////////////////////////////////////////////////////////////////
	// Function : operator--
	// Notes : move the iterator backward one node
	/////////////////////////////////////////////////////////////////////////////
	DLLIter<Type>& operator--() {
		if (iter)
		{
			iter = iter->prev;
		}
		return *this;


	}
	/////////////////////////////////////////////////////////////////////////////
	// Function : current
	// Notes : returns the item at the current iterator location
	////////////////////////////////////////////////////////////////////////////
	Type& current() const {
		return iter->data;
	}



};

