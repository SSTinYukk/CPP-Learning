#include<iostream>
using namespace std;

class Animal
{
public:
    virtual void speak()=0;
    Animal()
    {
        cout<<"Animal构造函数调用"<<endl;
    }
    virtual ~Animal(){
        cout<<"Animal析构函数调用"<<endl;
    }
};

class Cat:public Animal
{
public:
    Cat(string name)
    {
        cout<<"Cat构造函数调用"<<endl;
        m_Name = new string(name);
    }
    ~Cat()
    {
        delete m_Name;
        cout<<"Cat析构函数调用"<<endl;
    }
    virtual void speak()
    {
        cout<<"小猫"<<*m_Name<<"在说话"<<endl;   
    }
    string *m_Name;
};

void test01()
{
    Animal * animal = new Cat("蛋卷");
    animal->speak();
    delete animal;
}

int main()
{
    test01();
    return 0;
}