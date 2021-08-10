#include<iostream>
using namespace std;

class cube
{    
    private:
    int length;
    int high;
    int wide;

public:
    void setL(int t)
    {
        length = t;
    }

    void setH(int t)
    {
        high = t;
    }

    void setW(int t)
    {
        wide = t;
    }
    
    int calcube(){
        return length*high*wide;
    }
};


int main(){
    cube c;

    c.setH(1);
    c.setL(2);
    c.setW(3);

    cout<<c.calcube()<<endl;

    return 0;

}