#ifndef E
#define E
#include<iostream>
using namespace std;
#include"worker.h"


class Employee:public Worker
{
public:
    Employee(int id,string name,int dId);//构造函数

    virtual void showInfo();//显示个人信息
    
    virtual string getDeptName();//获取岗位名称
};

#endif // !E

