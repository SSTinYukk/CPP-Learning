#include<iostream>
using namespace std;

template<class T>
void mySwap(T&a,T&b)
{
    T temp=a;
    a=b;
    b=temp;
}

template<class T>
void myPrintf(T arr[],int len)
{
    for(int i=0;i<len;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

template<class T>
void mySort(T arr[],int len)
{
    for(int i=0;i<len;i++){
        int max=i;
        for(int j=i+1;j<len;j++){
          if (arr[max] > arr[j]) {
            max = j;
          }
        }
        if(max !=i){
            mySwap(arr[max], arr[i]);
        }
    }
}
int main()
{
    char s[]="zxcvbgrtw";
    int a[]={1,3,2,5,4,7,6,5};
    mySort(a, sizeof(a)/4);
    mySort(s, sizeof(s));
    // myPrintf(a, sizeof(a)/4);
    myPrintf(s, sizeof(s));
}