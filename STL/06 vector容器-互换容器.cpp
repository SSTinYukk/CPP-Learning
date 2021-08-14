#include<iostream>
using namespace std;
#include<vector>

void printVictor(vector<int>&v)
{
    for(vector<int>::iterator it =v.begin();it!=v.end();it++)
    {
        cout<<*it<<" ";

    }
    cout<<endl;
}

void test01()
{
    vector<int>v1;
    for(int i;i<10;i++)
    {
        v1.push_back(i);
    }
    printVictor(v1);

    vector<int>v2;
    for(int i=9;i>=0;i--)
    {
        v2.push_back(i);
    }
    printVictor(v2);
    v1.swap(v2);
    printVictor(v1);
    printVictor(v2);
}

void test02()
{
    vector<int>v1;
    for(int i=0;i<100000;i++)
    {
        v1.push_back(i);
    }
    cout<<"v1的容量为:"<<v1.capacity()<<endl;
    cout<<"v1的Size为:"<<v1.size()<<endl;
    v1.resize(10);
   
    v1.shrink_to_fit();
    cout<<"v1的容量为:"<<v1.capacity()<<endl;
    cout<<"v1的Size为:"<<v1.size()<<endl;
}

int main()
{
    test02();
    return 0;
}
