#include<iostream>
using namespace std;
#include<list>

void printList(const list<int>&L)
{
    for(list<int>::const_iterator it=L.begin();it!=L.end();it++)
    {
        cout<<*it<<"  ";
    }
    cout<<endl;
}

void test01()
{
    list<int>L1;
    L1.push_back(1);
    L1.push_back(2);
    *L1.begin()=111;
    L1.push_back(3);
    L1.push_back(4);
    printList(L1);
    list<int>L2(L1.begin(),L1.end());
    printList(L2);
    list<int>L3(10,100);
    L3=L2;
    L3.assign(L2.begin(),L2.end());
    printList(L3);    
}

int main()
{
    test01();
}
