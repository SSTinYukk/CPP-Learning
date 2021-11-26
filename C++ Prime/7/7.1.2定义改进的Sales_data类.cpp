#ifndef SALES_DATA
#define SALES_DATA
#include<iostream>
using namespace std;
struct Sales_data{
    std::string isbn() const {return this->bookNo;}
    Sales_data&combine(const Sales_data&);
    double avg_price()const;

    std::string bookNo;
    unsigned units_sold=0;
    double revenue = 0.0; 
};
Sales_data add(const Sales_data&,const Sales_data&);
std::ostream &print(std::ostream&,const Sales_data&);
std::istream &read(std::istream&,Sales_data&);

double Sales_data::avg_price()const{
    if (units_sold)
        return revenue/units_sold;
    else
        return 0;
        
}

Sales_data& Sales_data::combine(const Sales_data &rhs)
{
    units_sold += rhs.units_sold;//把rhs的成员加到this对象的成员上
    revenue += rhs.revenue;
    return *this;//返回调用该函数的对象
}

istream &read(istream &is,Sales_data &item)
{
    double price = 0;
    is>>item.bookNo>>item.units_sold>>price;
    item.revenue=price*item.units_sold;
    return is;
}
ostream &print(ostream &os,const Sales_data &item)
{
    os <<item.isbn()<<" "<<item.units_sold<<" "
        <<item.revenue<<" "<<item.avg_price();
        return os;
    
}

Sales_data add(const Sales_data &lhs,const Sales_data &rhs)
{
    Sales_data sum=lhs;
    sum.combine(rhs);
    return sum;
}



#endif
