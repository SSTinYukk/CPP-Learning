#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

class Transform
{
public:
    int operator()(int t)
    {
        return t;
    }
};

class Myprint
{
public:
    void operator()(int val){
        cout<<val<<" ";
    }
};

int main()
{
    vector<int>v;
    for(int i;i<10;i++)
    {
        v.push_back(i);
    }
    vector<int>vT;
    // vT.resize(v.size());
    // transform(v.begin(),v.end(),vT.begin(),Transform());
    vT=v;
    for_each(vT.begin(),vT.end(),Myprint());
}