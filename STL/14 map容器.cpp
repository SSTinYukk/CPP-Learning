#include<iostream>
#include <utility>
using namespace std;
#include<map>

void test01()
{
    map<int,int>m;
    m.insert(pair<int,int>(1,10));
    map<int,int>::iterator pos = m.find(1);
    if(pos!=m.end())
    {
        cout<<"找到了"<<endl;
    }else
    {
        cout<<"没找到"<<endl;
    }
}


int main()
{
    test01();
}