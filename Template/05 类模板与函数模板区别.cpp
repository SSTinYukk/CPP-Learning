#include<iostream>
using namespace std;
#include<string>

template<class NameType,class AgeType>
class Person
{
public:
    Person(NameType name,AgeType age)
    {
    this->m_Name=name;
    this->m_Age=age;
    }

    void showPerson()
    {
        cout<<"name:"<<this->m_Name;
    }

    NameType m_Name;
    AgeType m_Age;

};

void test01()
{
    
}

int main()
{

}