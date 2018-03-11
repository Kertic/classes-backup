#pragma once

#define awful template<typename type>

template<typename type = int>
class DList
{
private:

	struct node
	{
		type data;
		node* prev, *next;
		node(type _data, node* _prev) : data(_data), prev(_prev), next(nullptr) {}
	};

	int count;
	node* first, *last;

public:

	DList() { count = 0; first = last = nullptr; }
	~DList();

	int size() const { return count; }

	void push_back(type _data);

	type& operator[](int _index);
	type const &  operator[](int _index) const;
	void Clear();//This is the first item on the lab
	void Push_Front(type inData);//Second item on lab
	void Erase(int index);//Last item boyz

};

template <typename type> //Need this
void DList<type>::push_back(type _data)
{
	node* n = new node(_data, last);

	/*
	                   L<-newnode->X
		n-><-n-><-n->newnode
		          L
	*/

	if (last)//If last exists
		last->next = n;
	else//If there is no current last (which means there are no items on the list)
		first = n;

	last = n;

	++count;
}

template<typename type>
DList<type>::~DList()
{
	Clear();
}
template<typename type>
type& DList<type>::operator[](int _index)
{
	node* n = first;
	int i = 0;
	for (; i < _index; ++i, n = n->next);

	return n->data;
}

template<typename type>
type const&  DList<type>::operator[](int _index) const
{
	node* n = first;
	int i = 0;
	for (; i < _index; ++i, n = n->next);

	return n->data;
}

template<typename type>
void DList<type>::Clear()
{
	node* temp = first;
	while (temp)
	{
		first = first->next;
		delete temp;
		temp = first;
		
	}
	count = 0;
	first = nullptr;
	last = nullptr;

}

template<typename type>
void DList<type>::Push_Front(type inData)
{
	node* temp = new node(inData, nullptr);//Make a new node
	temp->prev = nullptr;//Set the created nodes previous to nullptr

	
	
	
	
	
	if (first)//If first exists
	{
		first->prev = temp;//Set firsts previous to this
		temp->next = first;//Set the created nodes next to first
	}
	else//If first doesnt exist, again means no items on the list
	{
		last = temp;
	}
	first = temp;//Set "first" to the created node
	++count;
}

template<typename type>
void DList<type>::Erase(int index)
{
	node* temp = first;
	if (size() == 1)//If we only have one item in the list
	{
		Clear();
	}
	else
	{
		for (int i = 0; i < index; i++)
		{
			temp = temp->next;
		}
		//Temp should be pointing at the node we want to erase
		if (temp->next)//If temp has a next, which means all nodes except the last
		{
			temp->next->prev = temp->prev;//Set temp's next's previous to temps previous
		}
		else//If we're on the last
		{
			last = temp->prev;
		}
		if (temp->prev)//If we have a previous, or all nodes except first
		{
			temp->prev->next = temp->next;//Set temp's previous's next to temps next
		}
		else//If we're on the first
		{
			first = temp->next;
		}



		delete temp;//Delete temp
		--count;

	}


}


