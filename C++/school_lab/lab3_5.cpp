#include<iostream>

class Score
{ // Score 类定义
    float computer;
    float english;
    float mathematics;

public:
    Score(float x1, float y1, float z1);
    Score() ;
    void print();
    void modify(float x2, float y2, float z2);
};

class Studen:public Score{
    int id;
    int age;
    std::string name;
public:
    Studen(std::string n,int a,int i){
        this->age=a;
        this->id=i;
        this->name=n;
    }
    ~Studen();
    
};

int main(){

}