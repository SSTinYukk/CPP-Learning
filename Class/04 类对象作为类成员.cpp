#include <iostream>
using namespace std;

//手机类
class Phone
{
public:
    Phone(string pName){
        m_PName =pName;
        cout <<"Phone构造函数"<<endl;
    }
    ~Phone(){
        cout << "Phone析构函数"<<endl;
    }
    string m_PName;
};

class Person
{
public:

    Person(string name,string pName):m_Name(name),m_Phone(pName)
    {
        cout <<"Person构造函数"<<endl;
    }
    ~Person()
    {
        cout<<"Person析构函数"<<endl;
    }

    //姓名
    string m_Name;
    //手机
    Phone m_Phone;
};

int main()  
{
    Person p("张三","苹果12 MAX");
    cout<<p.m_Name<<"拿着"<<p.m_Phone.m_PName<<endl;
    return 0;
}