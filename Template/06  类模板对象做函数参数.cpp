#include<iostream>
using namespace std;

template<class T1 ,class T2>
class Person
{
public:
    Person(T1 name,T2 age)
    {
        this->m_Name = name;
        this->m_Age= age;
    }

    void showPerson()
    {
        cout<<"姓名："<<this->m_Name<<"年龄："<<this->m_Age<<endl;
    }

    T1 m_Name;
    T2 m_Age;

};

void printPerson1()
{
    
}

int main()
{
    Person<string,int>p("孙悟空",100);  
}