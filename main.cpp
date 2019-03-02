#include<iostream>
#include<string>
#include"sys.h"

using namespace std;
DataBase *DataBase::_Base = NULL;
int main()
{
    Sys sys;
    while(1)
    {

    cout<<"请选择：1.注册 2.登录 3.退出"<<endl;
   cout<<"请输入命令序号："<<endl;
    char a;
    cin>>a;
    if(a=='1')
    {
       sys.registe();
    }
    else if(a=='2')
    {
       sys.login();
    }
    else if(a=='3')
    {
        cout<<"程序已退出！"<<endl;
        exit(0);
    }

    }
  


    return 0;
}
