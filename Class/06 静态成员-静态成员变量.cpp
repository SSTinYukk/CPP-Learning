#include<iostream>
using namespace std;

class Person
{
    public:
    static int m_A;
};

void test01(){
    Person p;
    cout<<p.m_A<<endl;
}