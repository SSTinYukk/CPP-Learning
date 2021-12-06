#include<iostream>
#include<vector>

using namespace std;
int main(){
    vector<int> v{1,2,3,4,5,6,7,8};
    auto b =v.begin(),e=v.end();
    
    string a("abcdefghigklmnopqrstuvwxyz");
    auto i1=a.begin(),i2=a.end();
    for(;i1!=i2;i1++){
        cout<<*i1<<endl;
    }
}   