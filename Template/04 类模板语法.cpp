#include<iostream>
using namespace std;

template<class NameType,class AgeType>
class Person
{
public:
    Person(NameType name,AgeType age)
    {
        this->m_Name =name;
        this->m_Age=age;
    }
    void showPerson()
    {
        cout<<"name:"<<this->m_Name<<"age:"<<this->m_Age<<endl;
    }
    
    NameType m_Name;
    AgeType m_Age;

};

int main()
{
    Person<string,int>P1("孙悟空",999);
    P1.showPerson();
}