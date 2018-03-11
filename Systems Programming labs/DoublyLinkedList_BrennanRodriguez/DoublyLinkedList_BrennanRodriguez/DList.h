#pragma once

template<typename type = int>
class DList
{
	struct node {
		node* previous;
		node* next;
		type data;
		node(type inData, node* inPrev) {
			data = inData;
			previous = inPrev;
			next = nullptr;
		}


	};
public:
	DList();
	~DList();
};

