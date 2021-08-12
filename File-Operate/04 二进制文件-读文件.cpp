#include <iostream>
using namespace std;
#include <fstream>

class Person
{
public:
    char m_Name[64];
    int m_Age;
};

int main()
{
    ifstream ifs;
    ifs.open("person.txt", ios::in | ios::binary);
    if (!ifs.is_open())
    {
        cout << "文件打开失败";
    }
    Person p;
    ifs.read((char *)&p, sizeof(Person));
    cout << "姓名：" << p.m_Name << endl;
    cout << "年龄：" << p.m_Age << endl;
    ifs.close();
}