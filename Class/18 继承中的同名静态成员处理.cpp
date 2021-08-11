#include<iostream>

using namespace std;
class Base
{
public:
    static int m_A;
};
int Base::m_A=100;

class Son:public Base
{
public:
    static int m_A;
};
int Son::m_A = 200;

int main()
{
    Son s1;
    cout<<s1.m_A
}