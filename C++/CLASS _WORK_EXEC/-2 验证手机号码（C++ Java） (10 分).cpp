#include<iostream>
using namespace std;

bool is_Number(const string s){
    for(auto i=0;i!=s.size();i++){
        if(isdigit(s.at(i))){

        }else{
            return false;
        }
    }
    return true;
}

int main(){
    string phone_number;
    cin>>phone_number;
    int     flag=1;
    if(phone_number.size()!=11){
        flag=0;
    }
    if(flag!=0&&phone_number.at(0)!='1'){
        flag=0;
    }
    if(flag!=0&&is_Number(phone_number)==false){
        flag=0;
    }
    if(flag>0){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
}