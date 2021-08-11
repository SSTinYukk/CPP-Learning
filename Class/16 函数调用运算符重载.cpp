#include<iostream>
using namespace std;

class MyPrint
{
public:
    void operator()(string test)
    {
        cout<<test<<endl;
    }
};

void MyPrint02(string test)
{
    cout<<test<<endl;
}

void test01()
{
    MyPrint MyPrint;

    MyPrint("hello world");

    MyPrint02("hello world");
}


int main()
{
    test01();
}