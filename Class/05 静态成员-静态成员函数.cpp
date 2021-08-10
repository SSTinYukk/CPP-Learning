#include <iostream>
using namespace std;
//静态成员函数
//所有对象共享同一个函数
//静态成员函数只能访问静态成员变量

class Person
{
public:
    static void func()
    {
        m_A=100;
        cout <<"static func 调用"<< endl;

    }
    static int m_A;
    int m_B;
    
};

void test01()
{
    Person p;
    p.func();
    Person :: func();
}

int main()
{
    test01();   
}