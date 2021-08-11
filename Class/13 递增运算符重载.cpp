#include<iostream>
using namespace std;


class MyInteger
{
 
public:
    MyInteger(int num):m_Int(num){}
    MyInteger operator++(int)
    {
        MyInteger temp=*this;
        m_Int++;
        return  temp;
    }
    int m_Int;
};

