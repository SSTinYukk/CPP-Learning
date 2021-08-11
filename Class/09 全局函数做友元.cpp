#include<iostream>

using namespace std;

class Room 
{
    friend void Goodgay(Room *room);

public:
    Room()
    {
        m_bedroom="卧室";
        m_building="客厅";
    }

public:

    string m_building;
private:
    string m_bedroom;
};

void Goodgay(Room *room)
{
    cout<<"好基友全局函数正在访问"<<room->m_bedroom<<endl;
}

void test01()
{
    Room room;
    Goodgay(&room);
}

int main()
{
    test01();
}