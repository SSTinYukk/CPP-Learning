#include<iostream>
using namespace std;

int main(){
    string  in_string,path_name,file_name;
    cin>>in_string;
    int idx=in_string.rfind('\\');
    int idx2=in_string.rfind('/');
    if(idx!=string::npos){
        path_name=in_string.substr(0,idx);
        file_name=in_string.substr(idx+1,in_string.size());
    }else if(idx2!=string::npos){
        path_name=in_string.substr(0,idx2);
        file_name=in_string.substr(idx2+1,in_string.size());
    }
    cout<<path_name<<endl;
    cout<<file_name<<endl;
}