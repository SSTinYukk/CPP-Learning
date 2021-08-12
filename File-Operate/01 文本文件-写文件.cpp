#include<iostream>
using namespace std;
#include<fstream>


int main()
{
    ofstream ofs;
    
    ofs.open("test.txt",ios::out|ios::app);

    ofs<<"姓名：张三"<<endl;
    ofs<<"性别男"<<endl;
    ofs.close();
}