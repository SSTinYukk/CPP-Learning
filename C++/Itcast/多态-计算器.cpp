#include<iostream>
using namespace std;

class AbstractCalulator
{
public:
    virtual int GetResult(){
        return 0;
    }
};