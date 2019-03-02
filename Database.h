#ifndef __DATABASE_H
#define __DATABASE_H
#include<iostream>
#include"List.h"
using namespace std;



class DataBase
{
public:
	static DataBase* getBase()
	{
		if (NULL == _Base)
		{
			_Base = new DataBase();
			return _Base;
		}
		return _Base;
	}
	DataBase()
	{
	
	}
	DataBase(const DataBase& src)
	{
		List list(src._list);
		_list = list;

	}
	DataBase operator = (DataBase &src)
	{
		if (this == &src)
		{
			return *this;
		}
		List list(src._list);
		_list = list;

	}
	~DataBase()
	{

	}
	
	void Insert(string name, string id, string data, string event, string limit)
	{
		_list.Insert(name, id, data, event, limit);
	}
	void Delete(string id)
	{
		_list.Delete(id);
	}
	void Find(string id)
	{
		_list.Find(id);
	}
	void Modify(string name, string id, string data, string event, string limit)
	{
		_list.Modify(name, id, data, event, limit);
	}
	void Show()
	{
		_list.Show();
	}
	
private:
	
	
	static DataBase *_Base;
	List _list;
	friend class View;
};


#endif
