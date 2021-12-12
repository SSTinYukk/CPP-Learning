#include<iostream>
#include<list>
using namespace std;

int main(){
    int a=10,x=100;
    list<int> s;

    int *p=&x;
    decltype(p) sum=&a;
    auto p2=p;
    cout<<p2<<endl;
}