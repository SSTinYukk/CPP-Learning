#include<iostream>
using namespace std;

class Building;
class GoodGay
{
public:
    GoodGay();    
    void visit();//让visit函数可以访问Building私有成员
    void visit2();
    Building * building;
};

class Building
{
public:
    Building();
    friend void GoodGay::visit();
public:
    string m_SettingRoom;
private:
    string m_BedRoom;    
};

Building::Building()
{
    m_SettingRoom="客厅";
    m_BedRoom="卧室";
}

GoodGay::GoodGay()
{
    building = new Building;
}

void GoodGay::visit()
{
    cout<<"visit函数正在访问"<<building->m_SettingRoom;
    cout << "visit函数正在访问" << building->m_BedRoom;
}

void GoodGay::visit2()
{
    cout << "visit函数正在访问" << building->m_SettingRoom;
    //cout << "visit函数正在访问" << building->m_BedRoom;
}

int main()
{
    GoodGay gg;
    gg.visit();
}