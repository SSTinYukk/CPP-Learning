#include<iostream>
using namespace std;
#include<fstream>

class Person
{
public:
    char m_Name[64];
    int m_Age;
};

int main()
{
    ofstream ofs;
    Person p{"張三",18};
    ofs.open("person.txt", ios::out|ios::binary);
    ofs.write((const char *)&p,sizeof(Person)); 

    ofs.close();

}