#include<thread>
#include<iostream>
#include<mutex>

void hello_thread(){
    std::cout<<"Hello thread"<<std::endl;
}

int main(){
    std::thread t1(hello_thread);
    t1.join();

    std::cout<<"Main here"<<std::endl;
    
    return 0;
}