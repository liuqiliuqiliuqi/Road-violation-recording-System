#ifndef __MODEL_H
#define __MODEL_H
#include<assert.h>
#include"view.h"
#include<iostream>
#include<map>

using namespace std;


class Model
{
public:
	Model()
	{
		_map.insert(make_pair(1, new Insert_view()));
		_map.insert(make_pair(2, new Delete_view()));
		_map.insert(make_pair(3, new Modify_view()));
		_map.insert(make_pair(4, new Find_view()));
		_map.insert(make_pair(5, new Show_view()));
	}
	~Model()
	{
		_map.clear();
	}

private:
	map<int, View*>_map;
	friend class control;
};

#endif
