#include<iostream>
using namespace std;

class Person
{
public:
    Person(){
        m_Age=10;
    }
    Person operator+(Person &p)
    {
        Person temp;
        temp.m_Age=this->m_Age+p.m_Age;
        return temp;
    }
public:
    Person(int age,string name):m_Name(name),m_Age(age){}
public:
    int m_Age;
    string m_Name;
};

Person operator-(Person &p1,Person &p2)
{
    Person temp;
    temp.m_Age = p1.m_Age - p2.m_Age;
    return temp;
}
Person operator+(Person &p1,int p2)
{
    Person temp;
    temp.m_Age = p1.m_Age + p2;
    return temp;
}

int main()
{
    Person p1;
    Person p2;
    Person p3=p1+50+p2 ;
    cout<<p3.m_Age<<endl;
    return 0;
}