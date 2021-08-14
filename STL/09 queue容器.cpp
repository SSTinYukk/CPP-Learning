#include<iostream>
using namespace std;
#include<queue>

class Person
{
public:
    Person(string name,int age):m_Name(name),m_Age(age){}

    string m_Name;
    int m_Age;
};


void test02()
{
    queue<int>q;
    q.push(1);
    q.push(2);
    cout<<q.front()<<endl;
    q.pop();
    cout<<q.front()<<endl;
}
int main()
{
    queue<Person>p;
    Person p1("唐僧",100);
    Person p2("孙悟空",200);

    p.push(p1);
    p.push(p2);

    cout<<p.front().m_Age<<"  "<<p.front().m_Name<<" "<<p.size()<<endl;
    p.pop();
    cout<<p.front().m_Age<<"  "<<p.front().m_Name<<endl;
    
   
}