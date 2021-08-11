#include <iostream>

using namespace std;

class Person
{
public:
    Person(int age)
    {
        this->age=age;
    }
    
    Person& PersonAddage(Person &p)
    {
        this->age+=p.age;
        return *this;
    }

    int age;
};

void test02(){
    Person p1(10);
    Person p2(10);

    p2.PersonAddage(p1).PersonAddage(p1).PersonAddage(p1);
    cout<<"和:"<<p2.age<<endl;
}

int main()
{
    test02();
    
}