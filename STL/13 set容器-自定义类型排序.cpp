#include<iostream>
#include <type_traits>
using namespace std;
#include<set>

class Person
{
public:
    Person(string name,int age)
    {
        this->m_Name =name;
        this->m_Age=age;
    }

    string m_Name;
    int m_Age;
};

class comparePerson
{
public:
    bool operator()(const Person&p1,const Person&p2)
    {
        return p1.m_Age>p2.m_Age;
    }
};


void test01()
{
    set<Person,comparePerson>s;
    Person p1("刘备",24);
    Person p2("关羽",28);
    Person p3("张飞",25);
    Person p4("赵云",21);

    s.insert(p1);

}