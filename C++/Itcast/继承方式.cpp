#include<iostream>
using namespace std;

class Base{
public:
    int pub_m;
protected:
    int pro_m;
private:
    int pri_m;
};

class Son:public Base{
public:
    void func(){
        this->pro_m=1;
        this->pub_m=2;
        cout<<this->pro_m<<endl;
        cout<<this->pub_m<<endl;
    }
};

class Son2:protected Son{
public:
    void func(){
        this->pro_m=1;
        this->pub_m=2;
        cout<<this->pro_m<<endl;
        cout<<this->pub_m<<endl;
    }    

};

class Son3:private Son2{
    public:
    void func(){
        this->pro_m=1;
        this->pub_m=2;
        cout<<this->pro_m<<endl;
        cout<<this->pub_m<<endl;
    }   
};




void test01(){
    Son2 a;
    a.func();
}

int main(){
    test01();
}

/*
* 1.子类成员可以直接访问到子类中同名成员
* 2.子类对象加作用域可以访问到父类同名成员
* 3.当子类与父类拥有同名的成员函数，子类会隐藏父类中同名成员函数，加作用域可以访问到父类中同名函数
*/