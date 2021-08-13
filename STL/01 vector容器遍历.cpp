#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

void MyPrint(int val)
{
    cout<<val<<endl;
}

void test01()
{
    vector<int> v;
    v.push_back((10));
    v.push_back(20);

    vector<int>::iterator pBegin =v.begin();
    vector<int>::iterator pEnd = v.end();

    while(pBegin!=pEnd){
        cout<<*pBegin<<endl;
        pBegin++;
    }

    pBegin = v.begin();

    for(vector<int>::iterator i = pBegin;i!=pEnd;i++){
        cout<<*i<<endl;
    }

    for_each(v.begin(),v.end(),MyPrint);
}

int main()
{
    test01();
    return 0;
}