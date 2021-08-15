#include<iostream>
using namespace std;
#include<set>

void printSet(set<int>&s)
{
    for(set<int>::iterator it=s.begin();it!=s.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}   

int main()
{
    set<int>s1;
    s1.insert(1);
    s1.insert(7);
    s1.insert(5);
    s1.insert(3);
    s1.insert(8);
    s1.insert(12);
    printSet(s1); 
}