#include<iostream>
using namespace std;

int main(){
    int a=10,x=100;
    
    int *p=&x;
    decltype(p) sum=&a;
    auto p2=p;
    cout<<p2<<endl;
}