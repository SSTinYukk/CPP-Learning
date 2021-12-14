#include<iostream>
using namespace std;

int main(){
    int i,j;
    double slope = i/j;
    slope =static_cast<double>(j)/i;

    void *p = &slope;
    double *dp=static_cast<double*>(p);

    const char *pc;
    char *pi = const_cast<char*>(pc);

}