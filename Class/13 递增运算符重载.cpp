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

    MyInteger& operator++()
    {
        m_Int++;
        return *this;
    }
    int m_Int;
};

ostream& operator<<(ostream &cout,MyInteger i)
{
    cout<<i.m_Int;
    return cout;
}

ostream &operator<<(MyInteger &i, ostream &cout)
{
    cout << i.m_Int;
    return cout;
}

int main()
{
    MyInteger i(1);
    cout << ((i++)++)<<endl;
    cout<<i<<endl;
}
