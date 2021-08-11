#include<iostream>
using namespace std;

class Person
{
public:
    void showClassName()
    {
        cout<<"this is Person class"<<endl;
    }
    int m_Age;

    void showPersonAge()
    {
        cout<<"age ="<<this->m_Age<<endl;
    }
};

void test01()
{
    Person * p=new Person;
    
    p->showClassName();
    p->showPersonAge();
}

int main()
{
    test01();
    return 0;
}