#include<iostream>
using namespace std;

class Person
{
public:
    Person()
    {
        m_Int = NULL;
        cout << "无参构造函数调用"<<m_Int << endl;
    }
    Person(int a)
    {
        m_Int=new int(0);
        cout << "有参构造函数调用"<<m_Int << endl;
        *m_Int = a;
    }
    ~Person ()
    {
        if (m_Int != NULL)
        {   
            cout << "析构函数调用" << m_Int << endl;
            delete m_Int;
            m_Int = NULL;
        }else{
            cout << "析构函数调用" << m_Int << endl;
            delete m_Int;
            m_Int = NULL;
        }
    }

    Person(const Person &p)
    {
        cout << "拷贝函数调用前" << m_Int << endl;

        m_Int=new int(*p.m_Int);
        cout << "拷贝函数调用后" << m_Int << endl;
    }

    Person & operator=(Person &p)
    {
        if(m_Int!=NULL){
            delete m_Int;
            m_Int=NULL;
        }
        
        m_Int=new int(*p.m_Int);
        *m_Int=*p.m_Int;
        return *this;
    }

    int *m_Int;
};

ostream& operator<<(ostream &cout,Person m)
{
    cout<<*m.m_Int;
    return cout;  
}

ostream& operator<<(Person &m,ostream &cout)
{
    cout<<*m.m_Int;
    return cout;
}

int main()
{
    Person m1(10);
    Person m2(20);
    Person m3(30);
    m1=m2=m3;
    cout<<m1<<endl;
    cout << m2 << endl;
    cout << m3 << endl;
    return 0;

}