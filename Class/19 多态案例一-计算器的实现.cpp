#include<iostream>
using namespace std;

class Calculator
{
    public:
        int getResult(string oper)
        {
            if(oper=="+")
            {
                return m_Num1+m_Num2;
            }else if(oper =="-"){
                return m_Num1-m_Num2;
            }else if(oper =="*"){
                return m_Num1*m_Num2;
            }
        }
    int m_Num1;
    int m_Num2;
};

void test01()
{

}

int main(){

}