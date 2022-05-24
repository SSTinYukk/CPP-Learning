#include<iostream>

class counter
{
    int value;

public:
    counter(int number);
    void increment(); //给原值加 1
    void decrement(); //给原值减 1
    int getvalue();   //取得计数器的值
    void print();     //显示计数器的值
};
counter::counter(int number){
    this->value=number;
}

void counter::increment(){
    this->value++;
}

void counter::decrement(){
    this->value--;
}

int counter::getvalue(){
    return this->value;
}
void counter::print(){
    std::cout<<"The num value: "<<value<<std::endl;
}

int main(){
    counter num=10;
    num.print();
    num.increment();
    num.print();
    num.decrement();
    num.print();
    std::cout<<num.getvalue()<<std::endl;
}
