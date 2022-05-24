#include<iostream>

class Rectangle{
    int lenth;
    int width;
public:
    Rectangle(int l,int w){
        this->lenth=l;
        this->width=w;
    }
    int getArea();
};

int Rectangle::getArea(){
    return this->width*this->lenth;
}
int main(){
    Rectangle A(2,3);
    std::cout<<A.getArea()<<std::endl;
}