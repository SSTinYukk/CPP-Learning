#include<iostream>

class Date
{
    int d, m, y;

public:
    Date(int day,int mon,int year){
        this->d=day;
        this->m=mon;
        this->y=year;
    }
    int day() const { return d; }
    int month() const { return m; }
    int year() ;
    // ...
};
// const 是函数原型的一个组成部分，因此在函数定义部分也要带 const 关键字。
inline int Date::year() 
{
    return y++;
}

int main(){
    Date now(12,3,2022);
    std::cout<<now.month()<<'-'<<now.day()<<'-'<<now.year()<<std::endl;
}