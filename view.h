#ifndef __VIEH_H
#define __VIEH_H

#include<iostream>
#include"Database.h"
#include<string>

using namespace std;

class View
{
public:
	View(){}
	virtual void process() = 0;
};

class Delete_view :public View
{
public:
	Delete_view()
		:View()
	{}

	~Delete_view(){}

	void process()
	{
		string _id;
		cin >> _id;
		DataBase::getBase()->Delete(_id);
	}
};
class Insert_view :public View
{
public:
	Insert_view() 
	:View(){}

	~Insert_view(){}

	void process()
	{
		string  _name;
		string _id;
		string _data;
		string _event;
		string _limit;
		cin >> _name >> _id >> _data >> _event >> _limit;
		DataBase::getBase()->Insert(_name, _id, _data, _event, _limit);
	}

};
class Modify_view :public View
{
public:
	Modify_view()
	:View()
	{}

	~Modify_view()
	{}

	void process()
	{
		string  _name;
		string _id;
		string _data;
		string _event;
		string _limit;
		cin >> _name >> _id >> _data >> _event >> _limit;
		DataBase::getBase()->Modify(_name, _id, _data, _event, _limit);
	}
};

class Find_view :public View
{
public:
	Find_view()
	:View()
	{}

	~Find_view()
	{}

	void process()
	{
		string _id;
		cin >> _id;
		DataBase::getBase()->Find(_id);
	}
};

class Show_view : public View
{
public:
	Show_view()
		:View()
	{}

	~Show_view(){}

	void process()
	{
		
		DataBase::getBase()->Show();
	}
};

#endif
