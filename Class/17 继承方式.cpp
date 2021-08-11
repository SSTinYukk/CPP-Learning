#include<iostream>
using namespace std;

class Base1
{
public:
    int m_A;
protected:
    int m_B;
private:
    int m_C;
};

class Son1:public Base1
{
public:
    void func()
    {
        m_A=10;//父类中的公共权限成员到子类中依然是公共权限
        m_B=10;//父类中的保护权限成员 到子类中依然是保护权限
    }
};

void test01()
{
    Son1 s1;
    s1.m_A=100;
}

int main()
{
    test01();
}