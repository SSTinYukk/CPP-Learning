#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    string input_string;
    cin>>input_string;
    sort(input_string.begin(),input_string.end());
    cout<<input_string<<endl;
    
}
