#include<iostream> 
using namespace std;

bool lenthCompare(const string &,const string &);
bool lenthCompare(const string &s1,const string &s2){
    return s1==s2;
}


int main(){
    bool (*pf)(const string &,const string &);
    pf=lenthCompare;
    cout<<pf("111","121");
}