#pragma once
#include <iostream>



template <typename Type>
class BST
{

	struct Node
	{
		Type data;
		Node* left;
		Node* right;

		Node() {
			left = nullptr;
			right = nullptr;
		}
		Node(Type v) {
			left = nullptr;
			right = nullptr;
			data = v;
		}

	};

	Node* _root;

public:
	/////////////////////////////////////////////////////////////////////////////
	// Function : Constuctor
	// Notes : constucts an empty BST
	/////////////////////////////////////////////////////////////////////////////
	BST() {
		_root = nullptr;


	}

	/////////////////////////////////////////////////////////////////////////////
	// Function : Destructor
	// Notes : destroys the BST cleaning up any dynamic memory
	/////////////////////////////////////////////////////////////////////////////
	~BST() {
		clear();
		delete _root;

	}

	/////////////////////////////////////////////////////////////////////////////
	// Function : assignment operator
	/////////////////////////////////////////////////////////////////////////////
	BST& operator=(const BST& that) {
		clear();
		if (that._root != nullptr)//If it has a root
		{
			preOrderAdd(that._root);
			return *this;
		}
		_root = nullptr;
		return *this;
	}

	/////////////////////////////////////////////////////////////////////////////
	// Function: copy constructor
	/////////////////////////////////////////////////////////////////////////////
	BST(const BST& that) {
		_root = nullptr;
		if (that._root != nullptr)//If it has a root
		{
			preOrderAdd(that._root);

		}
		else
		{
			_root = nullptr;
		}


	}

	/////////////////////////////////////////////////////////////////////////////
	// Function : insert
	// Parameters :  v - the item to insert 
	/////////////////////////////////////////////////////////////////////////////
	void insert(const Type& v) {
		
		if (_root == nullptr)
		{
			Node* n = new Node(v);
			_root = n;
			return;

		}

		RecursiveInsert(_root, v);



	}


	//Recursive insert
	//Adds the item down the tree from the starting point "n"
	void RecursiveInsert(Node* n, Type v) {

		if (n->data > v)
		{
			if (n->left == nullptr)
			{
				n->left = new Node(v);
				return;
			}
			else
			{
				RecursiveInsert(n->left, v);
			}
		}
		else
		{
			if (n->right == nullptr)
			{
				n->right = new Node(v);
				return;
			}
			else
			{
				RecursiveInsert(n->right, v);
			}
		}
	}

	/////////////////////////////////////////////////////////////////////////////
	// Function : findAndRemove
	// Parameters : v - the item to find (and remove if it is found)
	// Return : bool - true if the item was removed, false otherwise
	/////////////////////////////////////////////////////////////////////////////
	bool findAndRemove(const Type& v) {
		if (find(v))
		{
			//cur is the current node we're checking
			Node* cur = _root;
			Node* parent = nullptr;
			while (true)
			{
				if (cur->data == v)
				{
					if (cur->left == nullptr && cur->right == nullptr)//No children
					{
						if (cur == _root)
						{
							delete _root;
							_root = nullptr;
							return true;
						}
						else
						{
							if (parent->data <= v)//If we're the parents right
							{
								parent->right = nullptr;
								delete cur;
								return true;
							}
							else if (parent->data > v)//If we're on the left
							{
								parent->left = nullptr;
								delete cur;
								return true;
							}
						}
					}
					else if (cur->left != nullptr && cur->right != nullptr)//Both children
					{
						Node* toSwap = findSmallest(cur->right);
						Type temp = cur->data;
						cur->data = toSwap->data;
						toSwap->data = temp;
						Node* toSwapParent = cur->right;
						while ((toSwapParent->left != nullptr && toSwapParent->left->data != v) && (toSwapParent->right != nullptr && toSwapParent->right->data != v))//Move the parent pointer down the chain until either of its sides is v
						{
							if (v < toSwapParent->data)
							{
								toSwapParent = toSwapParent->left;
							}
							else if (v >= toSwapParent->data)
							{
								toSwapParent = toSwapParent->right;
							}
						}



						if (toSwap->left == nullptr && toSwap->right == nullptr)//No children once swapped
						{
							if (toSwap == _root)
							{
								delete _root;
								_root = nullptr;
								return true;
							}
							else
							{
								if (toSwapParent->data <= v)//If we're the toSwapParents right
								{
									toSwapParent->right = nullptr;
									delete toSwap;
									return true;
								}
								else if (toSwapParent->data > v)//If we're on the left
								{
									toSwapParent->left = nullptr;
									delete toSwap;
									return true;
								}
							}
						}
						else if (toSwap->left == nullptr || toSwap->right == nullptr)//One child when swapped
						{
							Node* child;
							if (toSwap->left != nullptr)
							{
								child = toSwap->left;
							}
							else if (toSwap->right != nullptr)
							{
								child = toSwap->right;
							}
							//Sets the child we need to move up depending on if we have a left or right 


							if (toSwapParent->data <= v)//If we're the toSwapParents right
							{
								toSwapParent->right = child;
								delete toSwap;
								return true;
							}
							else if (toSwapParent->data > v)//If we're on the left
							{
								toSwapParent->left = child;
								delete toSwap;
								return true;
							}
						}//We need to do a case 0 or 1 here

					}
					else if (cur->left == nullptr || cur->right == nullptr)//Given we have at least one child, and not both, if we have one or the other
					{
						Node* child;
						if (cur->left != nullptr)
						{
							child = cur->left;
						}
						else if (cur->right != nullptr)
						{
							child = cur->right;
						}
						//Sets the child we need to move up depending on if we have a left or right 

						if (parent != nullptr)
						{
							if (parent->data <= v)//If we're the parents right
							{
								parent->right = child;
								delete cur;
								return true;
							}
							else if (parent->data > v)//If we're on the left
							{
								parent->left = child;
								delete cur;
								return true;
							}
						}
						else//If we have no parent, then we're deleting the root
						{
							if (_root->data <= v)//If our one child is on _roots left
							{
								_root = _root->right;
								delete cur;
								return true;
							}
							else if (_root->data > v)//If its on the right
							{
								_root = _root->left;
								delete cur;
								return true;
							}
						}


					}
				}

				parent = cur;
				if (v < cur->data)
				{
					cur = cur->left;
				}
				else if (v >= cur->data)
				{
					cur = cur->right;
				}



			}

		}


		return false;
	}
	//Find the smallest item below node N
	Node* findSmallest(Node* n) {
		if (n->left == nullptr)
		{
			return n;
		}
		else
		{
			return findSmallest(n->left);
		}

	}


	//Recursive Remove
	//removes the item down the tree from the starting point "n", or returns false if it doesnt.
	bool RecursiveRemove(Node* n, Type v) {
		if (_root != nullptr)
		{
			if (n->left == nullptr && n->right == nullptr)//No children
			{

			}
			else if (n->left != nullptr && n->right != nullptr)//Both children
			{

			}
			else if (n->left == nullptr || n->right == nullptr)//Given we have at least one child, and not both, if we have one or the other
			{

			}

		}
		return false;


	}


	//Just removes the node and shifts everything if needed
	//N is the node to remove, nParent is its parent
	void Remove(Node* n, Node* nParent) {
		if (n->left == nullptr && n->right == nullptr)//No children
		{

		}
		else if (n->left != nullptr && n->right != nullptr)//Both children
		{

		}
		else if (n->left == nullptr || n->right == nullptr)//Given we have at least one child, and not both, if we have one or the other
		{

		}
	}


	/////////////////////////////////////////////////////////////////////////////
	// Function : find
	// Parameters : v - the item to find
	// Return : bool - true if the item was found, false otherwise
	/////////////////////////////////////////////////////////////////////////////
	bool find(const Type& v) const {
		return findRecursive(_root, v);

	}


	//Uses recursion to go through the list and find (or fail to find) an item, assuming its properly sorted
	bool findRecursive(Node* n, const Type& v) const {
		if (n != nullptr)
		{
			if (n->data == v)
			{
				return true;
			}
			else if (n->left != nullptr && v < n->data)
			{
				if (findRecursive(n->left, v))
					return true;
			}
			else if (n->right != nullptr && v >= n->data)
			{
				if (findRecursive(n->right, v))
					return true;
			}
			else
			{
				return false;
			}
		}

		return false;
	}

	//Works exactly as findRecursive, except it returns either nullptr when its not found and returns a pointer to the node if it is found
	Node* nodeFindRecursive(Node* n, const Type& v) const {
		if (n != nullptr)
		{
			if (n->data == v)
			{
				return n;
			}
			else if (n->left != nullptr && v < n->data)
			{
				if (nodeFindRecursive(n->left, v))
					return nodeFindRecursive(n->left, v);
			}
			else if (n->right != nullptr && v >= n->data)
			{
				if (nodeFindRecursive(n->right, v))
					return nodeFindRecursive(n->right, v);
			}
			else
			{
				return nullptr;
			}
		}

		return nullptr;
	}


	/////////////////////////////////////////////////////////////////////////////
	// Function : clear
	// Notes : clears the BST, cleaning up any dynamic memory
	/////////////////////////////////////////////////////////////////////////////
	void clear() {
		RemoveRecursive(_root);
		_root = nullptr;

	}


	/////////////////////////////////////////////////////////////////////////////
	// Function : RemoveRecursive
	// Notes : Removes all nodes below the original one passed in
	/////////////////////////////////////////////////////////////////////////////
	void RemoveRecursive(Node* v) {
		if (v != nullptr)
		{
			RemoveRecursive(v->left);
			RemoveRecursive(v->right);
			delete v;
		}
	}

	/////////////////////////////////////////////////////////////////////////////
	// Function : printInOrder
	// Notes : prints the contents of the BST to the screen, in ascending order
	/////////////////////////////////////////////////////////////////////////////
	void printInOrder() const {
		printInOrder(_root);
		cout << "\n";
	}

	void printInOrder(Node* v) const {
		if (v != nullptr)
		{

			printInOrder(v->left);
			cout << v->data << ' ';
			printInOrder(v->right);
		}
	}



	/////////////////////////////////////////////////////////////////////////////
	// Function : preOrderAdd
	// Notes : uses insert to add items down the chain until it reaches the end of the chain
	/////////////////////////////////////////////////////////////////////////////
	void preOrderAdd(Node* v) {
		if (v != nullptr)
		{
			insert(v->data);
			preOrderAdd(v->left);
			preOrderAdd(v->right);
		}
	}



};

