#include<iostream>
#include<string.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<stdio.h>
#include<stdlib.h>
#include"control.h"
#define NUM 5
using namespace std;

class Sys
{
    public:
int get_acpw(char buff[],char*myargv[])
{
      char *s=strtok(buff,"\r\n");
      int i=0;
      int count=0;
      
      while(s!=NULL)
      {
          myargv[i++]=s;
          s = strtok(NULL,"\r\n");
          count++;
      }
      return count;


}

   void registe()
   {
       /*
       char *account[1024];
       char buffer[1024];

       char buff[1024];
       int fd1=open("account.txt",O_RDWR|O_CREAT,0600);
       read(fd1,buffer,1024);

       if(strcmp(buffer,"\0")!=0)
       {
         int count=get_acpw(buffer,account);
         while(1)
         {
           printf("请设置未被注册的帐号:\n");
           cin>>buff;
           int i=0;
           for(;i<count;i++)
           {
               if(strcmp(buff,account[i])==0)
               {
                   break;
               }
               
           }
           if(strcmp(buff,account[i])!=0)
           {
            lseek(fd1,0,SEEK_END);
            write(fd1,buff,strlen(buff));
            lseek(fd1,0,SEEK_END);
            write(fd1,"\n",1);
           }
           
         }

       }

       close(fd1);
       */


       char buff[1024];
       printf("请设置帐号：\n");
       cin>>buff;
       int fd1 = open("account.txt",O_RDWR|O_CREAT,0600);
       lseek(fd1,0,SEEK_END);
       write(fd1,buff,strlen(buff));
       lseek(fd1,0,SEEK_END);
       write(fd1,"\n",1);
       close(fd1);

      char buff1[1024];
       printf("请设置密码：\n");
      cin>>buff1;
       int fd2 = open("password.txt",O_RDWR|O_CREAT,0600);
        lseek(fd2,0,SEEK_END);
       write(fd2,buff1,strlen(buff1));
       lseek(fd2,0,SEEK_END);
       write(fd2,"\n",1);
       close(fd2);

       cout<<"register complete !"<<endl;  
          
   }

   void login()
   {
        char buff1[1024];
        char buff2[1024];
        char* password[1024];
        char* account[1024];

       int fd1=open("account.txt",O_RDONLY);
       read(fd1,buff1,1024);
       get_acpw(buff1,account);
       close(fd1);

      // memset(&buff,0,strlen(buff));

   // printf("%s ",account[0]);
   // printf("%s ",account[1]);
   // printf("%s ",account[2]);
  //     printf("%s\n",account[3]);
   
    

      
       int fd2=open("password.txt",O_RDONLY);
       read(fd2,buff2,1024);
        int count=get_acpw(buff2,password);
       close(fd2);

     //printf("%s ",password[0]);
  //  printf("%s ",password[1]);
  //  printf("%s ",password[2]);
    //   printf("%s ",password[3]);


    while(1)
    {
       printf("请输入已注册的帐号：\n");
       char buff[1024];
       cin >> buff;
       //fgets(buff,1024,stdin);
       //buff[strlen(buff)-1]=0;
       int i=0;
       int n=0;
       for(;i<count;i++)
       {
           if(strcmp(buff,account[i])==0)
           {
               while(1)
               {
                   if(n>NUM)
                   {
                       break;
                   }
                   cout<<"请输入正确的密码："<<endl;
                   n++;
                   memset(&buff,0,1024);
                  // fgets(buff,1024,stdin);
                  // buff[strlen(buff)-1]=0;
                  cin>>buff;
                   if(strcmp(buff,password[i])==0)
                   {
                       cout<<"登录成功!"<<endl;
                       control c;
                       c.process();
                       exit(0);
                   }

               }

           }
       }
     }
   }

   
   
};



