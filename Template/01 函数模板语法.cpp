#include<iostream>
using namespace std;


template<class T>
void mySwap(T&a,T&b)
{
    T temp = a;
    a = b;
    b = temp;
}

int main()
{
    char c=10;
    int a=10,b=20;
    mySwap(a,b);
    cout<<a<<b<<endl;
}