#include <cstdio>
#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>



class Person
{
public:
    Person(string name,int age)
    {
        m_Name=name;
        m_Age=age;
    }

    bool operator==(const Person &p)
    {
        if(this->m_Name==p.m_Name&&this->m_Age==p.m_Age)
        {
            return true;
        }
        return false;
    }
public:
    string m_Name;
    int m_Age;
};


bool mycompare(Person &p1,Person p2)
{
    return p1.m_Age<p2.m_Age;
}

void print(Person &p)
{
    cout<<"姓名："<<p.m_Name<<"\t年龄"<<p.m_Age<<endl;
}

int main()
{
    vector<Person>v;
    Person p1("张飞",25);
    Person p2("赵云",26);
    Person p3("刘备",23);
    
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    int ret=count(v.begin(),v.end(), p1);
    sort(v.begin(),v.end(),mycompare);
    cout<<ret<<endl;
    for_each(v.begin(),v.end(),print);
}