#include<iostream>
using namespace std;

class Person
{
    public:
    static int m_A;
};
int Person::m_A=100;

void test01(){
    Person p;
    cout<<p.m_A<<endl;
    cout<<Person::m_A<<endl;
}

int main(){
    test01();
}