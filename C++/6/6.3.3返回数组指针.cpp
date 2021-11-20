#include<iostream>
using namespace std;

auto func(int i)->int(*)[10]{
    static int a[10]={0,1,2,3,4,5,6,7,8,9};
    return &a;
}
int main(){
    int arr[10];
    int *p1[10];
    int (*p2)[10]=func(1);
}