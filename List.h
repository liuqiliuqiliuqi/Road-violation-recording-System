#ifndef __LIST_H
#define __LIST_H
#include<iostream>
#include<stdio.h>
#include<assert.h>
#include"Node.h"
#include<string>

using namespace std;

class List
{
private:
	Node* _head;
	int _count;

public:
	List()
	{
		_head = NULL;
		_count = 0;
	}
	List(const List &src)
	{

		_count = src._count;
		int n = src._count;
		Node *src_head = src._head;

		while (n>0)
		{
			Node *s = new Node;
			s->_data = src_head->_data;
			s->_limit = src_head->_limit;
			s->_id = src_head->_id;
			s->_event = src_head->_event;
			s->_name = src_head->_name;
			s->_next = NULL;

			src_head = src_head->_next;
			if (_head == NULL)
			{
				_head = s;
			}
			else
			{
				_head->_next = s;
				_head = s;
			}
			n--;
		}
	}
	List operator=(List &src)
	{
		if (this == &src)
		{
			return *this;
		}
		_count = src._count;
		int n = src._count;
		Node *src_head = src._head;

		while (n>0)
		{
			Node *s = new Node;
			s->_data = src_head->_data;
			s->_limit = src_head->_limit;
			s->_id = src_head->_id;
			s->_event = src_head->_event;
			s->_name = src_head->_name;
			s->_next = NULL;

			src_head = src_head->_next;
			if (_head == NULL)
			{
				_head = s;
			}
			else
			{
				_head->_next = s;
				_head = s;
			}
			n--;
		}
		return *this;

	}
	~List()
	{

	}

	void Insert( string name, string id, string data, string event, string limit)
	{
		Node *s = new Node;
		assert(s != NULL);

		s->_name = name;
		s->_data = data;
		s->_event = event;
		s->_id = id;
		s->_limit = limit;

	    s->_next = _head;
		_head = s;
		
		_count++;
		cout << "插入成功！" << endl;
	}
	void Delete(string id)
	{
		Node *p = _head;
	//	assert(p != NULL);
		if (_count == 0)
		{
			cout << "数据库为空，请重试！" << endl;
			return;
		}
		Node *q = _head->_next;
		while (q!= NULL)
		{
			if (q->_id != id)
			{
				p = p->_next;
				q = q->_next;
			}
			else
			{
				break;
			}
		}
		if (_head->_id == id)
		{
			Node *s = _head;
			_head = _head->_next;
			delete s;
			_count--;
			cout << "删除成功！" << endl;
			return;

		}
		if (q == NULL)
		{
			cout << "ID错误" << endl;
		}
		else
		{
			p->_next = q->_next;
			delete q;
			cout << "删除成功！" << endl;
		}
		_count--;
	}
			
	void Find(string id)
	{
		Node *p = _head;
		//assert(p != NULL);
		if (_count == 0)
		{
			cout << "数据库为空，请重试！" << endl;
			return;
		}
		
		Node *q = _head->_next;
		while (q != NULL)
		{
			if (q->_id != id)
			{
				p = p->_next;
				q = q->_next;
			}
			else
			{
				break;
			}
		}
		if (_head->_id == id)
		{
			cout << "查找成功！" << endl;
			cout << "name:" << _head->_name << "  ";
			cout << "id:" << _head->_id << "  ";
			cout << "data:" << _head->_data << "   ";
			cout << "event:" << _head->_event << "   ";
			cout << "limit:" << _head->_limit << "   ";
			return;

		}
		
		if (q == NULL)
		{
			cout << "ID错误" << endl;
		}
		else
		{ 
			cout << "查找成功！" << endl;
			cout << "name:" << q->_name << "  ";
			cout << "id:" << q->_id << "  " ;
			cout << "data:" << q->_data << "   ";
			cout << "event:" << q->_event <<"   "  ;
			cout << "limit:" << q->_limit << "   ";
			
		}

	}
	void Modify(string name, string id, string data, string event, string limit)
	{
		Node *p = _head;
		//assert(p != NULL);
		if (_count == 0)
		{
			cout << "数据库为空，请重试！" << endl;
			return;
		}
		Node *q = _head->_next;
		while (q != NULL)
		{
			if (q->_id != id)
			{
				p = p->_next;
				q = q->_next;
			}
			else
			{
				break;
			}
		}
		if (_head->_id == id)
		{
			_head->_data = data;
			_head->_event = event;
			_head->_id = id;
			_head->_limit = limit;
			_head->_name = name;
			cout << "修改完成！" << endl;
			return;

		}

		if (q == NULL)
		{
			cout << "ID错误" << endl;
		}
		else
		{
			q->_data = data;
			q->_event = event;
			q->_id = id;
			q->_limit = limit;
			q->_name = name;
			cout << "修改完成！" << endl;

		}




	}
	void Show()
	{
		if (_count == 0)
		{
			cout << "数据库为空，请重试！" << endl;
			return;
		}
		int i = 0;
		Node *s = _head;
		for (; i < _count; i++)
		{
			
			cout << "name:"<<_head->_name << "     "     ;
			cout << "id:" << _head->_id << "    "        ;
			cout << "data:" << _head->_data <<"    "    ;
			cout << "event:" << _head->_event <<"    "    ;
			cout << "limit:" << _head->_limit <<"     "     ;
			
			cout << " "<< endl;
			_head = _head->_next;
		}
		_head = s;
			

		
		
	
	}

	friend class DataBase;
};

#endif
