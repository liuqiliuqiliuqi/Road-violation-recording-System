#ifndef __NODE_H
#define __NODE_H
#include<iostream>

using namespace std;

class Node
{
private:
	Node *_next;
	string  _name;
	string _id;
	string _data;
	string _event;
	string _limit;

	

public:
	Node()
	{
		_next = NULL;
	}
	Node(Node &src)
	{
		//_next = new Node;
		_next = src._next;
		_name = src._name;
		_id = src._id;
		_data = src._data;
		_event = src._event;
		_limit = src._limit;
	}

	Node operator=(Node &src)
	{
		if (this == &src)
		{
			return *this;
		}
		//_next = new Node;
		_next = src._next;
		_name = src._name;
		_id = src._id;
		_data = src._data;
		_event = src._event;
		_limit = src._limit;
		return *this;
	}
	friend class List;
};

#endif
