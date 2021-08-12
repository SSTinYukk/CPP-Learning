#include<iostream>
using namespace std;
#include<fstream>

int main()
{
    ifstream ifs;
    
    ifs.open("./test.txt",ios::in);

    if(!ifs.is_open())
    {
        cout<<"文件打开失败"<<endl;
    }
    char buf[1024]={0};
    // while(ifs>>buf)
    // {
    //     cout<<buf<<endl;
    // }

    // while(ifs.getline(buf,sizeof(buf)))
    // {
    //     cout<<buf<<endl;
    // }

    // string buf1;
    // while(getline(ifs,buf1))
    // {
    //     cout<<buf1<<endl;
    // }
    char c;
    while((c=ifs.get())!=EOF)
    {
        cout<<c;
    }
    ifs.close();


}