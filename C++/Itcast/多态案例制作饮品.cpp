#include<iostream>
using namespace std;

class AbstractDrinking
{
public:
    virtual void Boil() = 0;
    
    virtual void Pour()=0;
    
    virtual void Brew()=0;

    virtual void Join()=0;
};

class MakeTea:public AbstractDrinking{
public:
      virtual void Boil(){
          cout<<"[MakingTea]Boiling OK"<<endl;
      }
      virtual void Pour(){
          cout<<"[MakingTea]Pour OK"<<endl;
      }
      virtual void Brew(){
          cout<<"[MakingTea]Brew OK"<<endl;
      }
      virtual void Join(){
          cout<<"[MakingTea]Join OK.Please enjoy it."<<endl;
      }

};
class MakeCoffe:public AbstractDrinking{
public:
      virtual void Boil(){
          cout<<"[MakingCoffe]Boiling OK"<<endl;
      }
      virtual void Pour(){
          cout<<"[MakingCoffe]Pour OK"<<endl;
      }
      virtual void Brew(){
          cout<<"[MakingCoffe]Brew OK"<<endl;
      }
      virtual void Join(){
          cout<<"[MakingCoffe]Join OK.Please enjoy it."<<endl;
      }

};


void test01(){
    MakeTea t;
    MakeCoffe c;
    t.Boil();
    t.Brew();
    t.Pour();
    t.Join();
    c.Boil();
    c.Brew();
    c.Pour();
    c.Join();
}
int main(){
    test01();
}
