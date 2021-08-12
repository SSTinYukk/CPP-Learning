#include<iostream>
using namespace std;

class AbstractDinking
{
public:
    virtual void Boil()=0;
    virtual void Brew()=0;
    virtual void PourInCup()= 0;
    virtual void PutSomething()=0;

    void makeDrink()
    {
        Boil();
        Brew();
        PourInCup();
        PutSomething();
    }
};

class Coffee:public AbstractDinking
{
    virtual void Boil()
    {
        cout<<"烧开水"<<endl;
    }
    virtual void Brew() 
    {
        cout<<"加入咖啡牛奶"<<endl;
    }
    virtual void PourInCup()
    {
       cout<<"倒入杯子"<<endl;
    }
    virtual void PutSomething()
    {
        cout << "加糖" << endl;
    }
};

class Tea:public AbstractDinking
{
    virtual void Boil()
    {
        cout << "烧开水" << endl;
    }
    virtual void Brew()
    {
        cout << "加入茶叶" << endl;
    }
    virtual void PourInCup()
    {
        cout << "倒入杯子" << endl;
    }
    virtual void PutSomething()
    {
        cout << "加入枸杞" << endl;
    }
};

void doWork(AbstractDinking *abs)
{
    abs->makeDrink();
    delete abs;
}

void tes01()
{
    doWork(new Coffee);
    doWork(new Tea);
}

int main()
{
    tes01();
    return 0;
}

