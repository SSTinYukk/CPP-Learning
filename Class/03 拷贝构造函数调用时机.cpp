#include <iostream>
using namespace std;

class Person
{
    public:
    Person(int a){
        cout << "有参构造函数" << endl;
    }
    Person(){
        cout<<"午餐构造函数"<<endl;
    }
    Person(const Person & p){
        age=p.age;
        cout<<"拷贝构造函数"<<endl;
    }
    ~Person(){
        cout << "析构函数调用"<<endl;
    }

    Person(int a,int b): age(a),weight(b){}
    int age;
    int weight;
};

Person dowork()
{
    Person p1;
    cout << (int *)&p1 <<endl;
    return p1;
}

int main(void)
{
    Person p1(20,30);
    Person p2=dowork();

    cout << p1.age<<endl;
    cout << p1.weight<<endl;

    cout <<(int *)&p2<<endl;
    cout << (int*)&p1<<endl;
    return 0;
}