#include<iostream>
using namespace std;

typedef struct record{
    int record;
    char c;
}Record;

Record lookup(int &a){
    cout<<a<<endl;
}

Record lookup(char &c){
    cout<<c<<endl;
}

int main()
{

    int a=1;
    char c='c';
    lookup(a);
    lookup(c);
}