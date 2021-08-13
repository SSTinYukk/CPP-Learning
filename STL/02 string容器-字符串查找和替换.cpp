#include<iostream>
using namespace std;

int main()
{
    string str1 = "abcdefg";

    int pos =str1.find("de");

    if(pos==-1)
    {
        cout<<"没找到"<<endl;
    }else
    {
        cout<<"找到字符串 坐标:"<<pos<<endl;
    }
    return 0;
}