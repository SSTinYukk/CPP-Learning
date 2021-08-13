#include<iostream>
using namespace std;

#include "MyArray.hpp"

void test01()
{
    MyArray <int>arr1(5);
    cout << arr1[0] << endl;
    MyArray<int>arr2(arr1);
    MyArray<int>arr3(100);

}



int main()
{
    test01();
    
}
