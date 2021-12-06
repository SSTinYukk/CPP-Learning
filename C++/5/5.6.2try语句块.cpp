#include<iostream>
using namespace std;

int main(){
    int a =2,b=1;

    try{
         if(a==b){
        
    }else{
        throw runtime_error("Data not refer");
    }
        
    }catch(runtime_error){
        b=a;
        cout<<"问题已解决"<<endl;
    }
}