#include<iostream>
using namespace std;

//通过全卷函数 打印Person信息

template<class T1,class T2>
class Person
{
public:
    Person(T1 name,T2 age)
    {
        this->m_Name = name;
        this->m_Age =age;
    }
private:
    T1 m_Name;
    T2 m_Age;
};