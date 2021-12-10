#include<iostream>
using namespace std;

class BasePage
{
public:
    void header(){
        cout<<"             公共头部栏"<<endl;
    }
    void footer(){
        cout<<"             公共底部 Copyright@"<<endl;
    }
    void left(){
        cout<<"公共侧边栏"<<endl;
    }
    virtual void content(){}
};

class Java:public BasePage
{
public:
    void content(){
       cout<<"              Java"<<endl;
    }
};

  

void test01(){
    Java ja;
    ja.header();
    ja.left();
    ja.content();
    ja.footer();
}
int main(){
    test01();
}