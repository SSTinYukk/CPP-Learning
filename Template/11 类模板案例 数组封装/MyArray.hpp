#include<iostream>
using namespace std;

template<class T>
class MyArray
{
public:
    MyArray(int capacity)
    {
        cout<<"构造函数调用"<<endl;
        this->m_Capacity=capacity;
        this->m_Size=0;
        this->pAddress=new T[this->m_Capacity];
    }  
    //拷贝构造
    MyArray(const MyArray& arr)
    {
        cout<<"拷贝构造函数调用"<<endl;
        this->m_Capacity=arr.m_Capacity;
        this->m_Size=arr.m_Size;
        //深拷贝
        this->pAddress= new T[arr.m_Capacity];

        for(int i=0;i<this->m_Size;i++){
            this->pAddress[i]=arr.pAddress[i];
        }
    }

    //operator=
    MyArray& operator=(const MyArray& arr)
    {
        //先判断原来对区是否有数据
        if(this->pAddress!=NULL)
        {
            delete [] this->pAddress;
            this->pAddress=NULL;
            this->m_Capacity=arr.m_Capacity;
            this->m_Size=arr.m_Size;
            this->pAddress=new T[arr.m_Capacity];

            for(int i;i<this->m_Size;i++){
                this->pAddress[i]=arr.pAddress[i];
            }
            return *this;
        }
    }
    //析构函数
    ~MyArray()
    {
        cout<<"析构函数调用"<<endl;
        if(this->pAddress!=NULL)
        {
            delete[] this->pAddress;
            this->pAddress=NULL;
        }
    }

    void Push_Back(const T &val)
    {
        if(this->m_Capacity==this->m_Size)
        {
            return;
        }
        this->pAddress[this->m_Size]=val;
        this->m_Size++;
    }

    void Pop_Back()
    {
        if(this->m_Size==0)
        {
            return;
        }
        this->m_Size--;
    }
    T& operator[](int index)
    {
        return this->pAddress[index];
    }



private:
    T *pAddress;    //指针指向对开辟的地址
    int m_Capacity; //数组容量
    int m_Size;     //数组大小
};