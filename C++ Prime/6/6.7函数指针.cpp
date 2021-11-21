#include<iostream> 
using namespace std;

bool lenthCompare(const string &,const string &);
bool lenthCompare(const string &s1,const string &s2){
    return s1==s2;
}

typedef bool Func(const string&,const string&);
typedef decltype(lenthCompare) Func2;
typedef bool(*FuncP)(const string&,const string&);
typedef decltype(lenthCompare) *FuncP2;

void useBigger(const string&,const string&,Func);
void useBigger(const string&,const string&,FuncP2);



int main(){
    bool (*pf)(const string &,const string &);
    pf=lenthCompare;
    cout<<pf("111","121");
}