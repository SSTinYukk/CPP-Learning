#include<iostream>
#include<thread>

void f(int i,std::string const&s);
std::thread t(f,3,"hello");

void f(int i,std::string const& s);
void oops(int some_param){
    char buffer[1024];
    sprintf(buffer,"%i",some_param);
    std::thread t(f,3,buffer);  
}


int main(){
    
}