#include<iostream>
using namespace std;

template<class T>
class Base 
{
    T m;
};

class Son:public Base <int>
{

};

void test01()
{
    Son s1;
}

template<class T1,class T2>
class Son2:public Base<T2>
{
public:
    Son2()
    {
        cout<<"T1的数据类型："<<typeid(T1).name()<<endl;
        cout<<"T2的数据类型："<<typeid(T2).name()<<endl;
    }
    T1 obj;
};

int main()
{
    Son2<int ,char>S1;
}