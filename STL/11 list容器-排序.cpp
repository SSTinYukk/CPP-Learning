#include<iostream>
using namespace std;
#include<list>
#include<algorithm>

class Person
{
public:
    Person(string name,int age,int height)
    {
        this->m_Height=height;
        this->m_Age=age;
        this->m_Name=name;
    }

public:
    string m_Name;
    int m_Age;
    int m_Height;

};

bool comparisonRule(Person &p1,Person &p2)
{
    if(p1.m_Age==p2.m_Age){
        return p1.m_Height>p2.m_Height;
    }
    return p1.m_Age<p2.m_Age;
}

int main()
{
    list<Person>p;
    Person p1("YanYan",19,172);
    Person p2("AAAA",12,111);
    Person p3("XXXX",13,122);
    Person p4("SSSS",13,144);
    Person p5("LLLL",11,233);

    p.push_back(p1);
    p.push_back(p2);
    p.push_back(p3);
    p.push_back(p4);
    p.push_back(p5);

    p.sort(comparisonRule);

    for(list<Person>::iterator it=p.begin();it!=p.end();it++){
        cout<<"姓名: "<<it->m_Name<<"\t年龄: "<<it->m_Age<<"\t身高"<<it->m_Height<<endl;
    }

}