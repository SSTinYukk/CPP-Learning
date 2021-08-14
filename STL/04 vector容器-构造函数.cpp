#include<iostream>
using namespace std;
#include<vector>

void printVector(vector<int>&v)
{
    for(vector<int>::iterator it=v.begin();it!=v.end();it++)
    {
        cout<<*it<<" ";
    }
}

void test01()
{
    vector<int>v1;
    v1.insert(v1.begin(),2233);
    v1.erase(v1.begin());

    vector<int>v2(v1.begin(),v1.end());

    vector<int>v3(10,100);


    for(int i=0;i<10;i++){
        v1.push_back(i);
    }
    string a;
    printVector(v1);
    cout<<endl;
    printVector(v2);
    printVector(v3);
}

int main()
{
    test01();
}