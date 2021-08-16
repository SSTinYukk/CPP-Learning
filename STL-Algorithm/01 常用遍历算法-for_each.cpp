#include <cstdio>
#include<iostream>
using namespace std;

#include<algorithm>
#include<deque>

void printint(int t)
{
    cout<<t<<" ";
}

int main()
{
    deque<int>d;
    d.push_back(1);
    d.push_back(2);
    d.push_back(3);
    d.push_back(4);
    d.push_front(0);

    for_each(d.begin(),d.end(),printint);
}
