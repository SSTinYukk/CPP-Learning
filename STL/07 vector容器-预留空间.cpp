#include<iostream>
using namespace std;
#include<vector>

int main()
{
    vector<int>v;
    int num=0;
    int * p=NULL;
    for(int i=0;i<100000;i++)
    {
        v.push_back(i);
        if(p!=&v[0])
        {
            p=&v[0];
            num++;
        }
    }
    cout<<num<<endl;
    cout<<v.capacity()<<endl;
}
