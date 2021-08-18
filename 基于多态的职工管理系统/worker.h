#ifndef W
#define W 

#include<iostream>
using namespace std;

class Worker
{
public:
    virtual void showInfo()=0;//显示个人信息
    virtual string getDeptName()=0;//获取岗位

public:
    int m_Id;//职工编号
    string m_Name;//职工姓名
    int m_DeptId;
};

#endif // !WOKER
