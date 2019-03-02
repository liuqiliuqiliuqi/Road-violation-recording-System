#include<iostream>
#include<string.h>
#include"model.h"
using namespace std;


class control
{
public:
	control()
	{

	}
	
	control operator=(const control &src)
	{
		if (this == &src)
		{
			return *this;
		}
		//_model = src._model;
	}

	void process()
	{
		while (1)
		{
			cout << " " << endl;
			 int c;
			cout << "1.插入" << " " << "2.删除" << " " << "3.修改" << " " << "4.查找" << " " << "5.打印"<<" "<<"6.退出"<<endl;
			cout << "请输入命令序号" << endl;
			cin >> c;
			if (c == 1)
			{
				cout << "请插入数据:"<<endl;
			
				_model._map[1]->process();	
			}
			 if (c == 2)
			{
				cout << "请输入关键码id:"<<endl;
				_model._map[2]->process();
			
			}
			 if (c == 3)
			{
				cout << "请输入以id为关键码的新数据:"<<endl;
				_model._map[3]->process();
				
			}
			 if (c == 4)
			{
				cout << "请输入关键码id来查找数据:"<<endl;
				_model._map[4]->process();
				
			}
			 if (c == 5)
			{
				cout << "打印:"<<endl;
				_model._map[5]->process();

			
			}
		    if (c == 6)
			{
				cout << "已退出程序！" << endl;
				return;
			}

		}
	}

private:
	Model _model;
	
};


	

