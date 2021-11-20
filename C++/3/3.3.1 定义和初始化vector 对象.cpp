#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<vector<int>>v1;
    vector<int> i1{1,2,3,4};
    v1.push_back(i1);
    for(auto i=i1.begin();i!=i1.end();i++)
        cout<<*i<<" ";
}