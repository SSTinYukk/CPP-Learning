#include<iostream>
using namespace std;

class Building;


class GoodGay
{

public:
    GoodGay();
    void visit();//访问building类中的属性
    Building * building;


};

class Building
{
    public:
    friend class GoodGay;
    Building();
    
    public:
    string m_SittingRoom;//客厅
    ~Building()
    {
        delete(this);
    }

    private:
    string m_BedRoom;//卧室

};

Building::Building()
{
    m_SittingRoom="客厅";
    m_BedRoom="卧室";
}

GoodGay::GoodGay()
{
    //创建建筑物对象
    building=new Building;
}

void GoodGay::visit()
{
    cout<<"好基友类正在访问"<<building->m_SittingRoom<<endl;
    cout << "好基友类正在访问" << building->m_BedRoom << endl;
}

int main()
{
    GoodGay gg;
    gg.visit();
}