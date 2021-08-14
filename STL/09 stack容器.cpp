#include<iostream>
using namespace std;
#include<stack>

void test01()
{
    stack<int>s;
    s.push(1);
    s.push(2);
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
}

int main()
{
    test01();
}