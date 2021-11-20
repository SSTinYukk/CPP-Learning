#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<vector<int>>v1;
    vector<int> i1{1,2,3,4};
    vector<int> i2;
    v1.push_back(i1);
    v1.push_back(i2);
    for(auto i=v1.begin();i!=v1.end();i++)
        cout<<i->empty()<<" ";
}  