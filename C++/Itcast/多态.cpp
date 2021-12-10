#include<iostream>
using namespace std;

class Animal{
public:
    virtual void Speak(){
        cout<<"Animal Speaking"<<endl; 
    }    
};

class Cat:public Animal{
public:
    void Speak(){
        cout<<"Cat Speaking"<<endl;
    }
};

void doSpeak(Animal &animal){
    animal.Speak();
}

void test01(){
    Cat cat;
    doSpeak(cat);
   cout<<sizeof(Animal)<<endl;
}

int main(){
    test01();
}