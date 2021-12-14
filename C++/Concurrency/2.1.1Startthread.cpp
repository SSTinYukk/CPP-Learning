#include<iostream>
#include<thread>

void do_some_work();
std::thread my_thread(do_some_work);
void do_something();
void do_something_else();

class background_task
{
public:
    void operator()() const
    {
        do_something();
        do_something_else();
    }
};

int main(){
    background_task f;
    std::thread my_thread{background_task(f)};
    std::thread my_thread1([]{
        do_something();
        do_something_else();
    });
    my_thread1.join();
    my_thread.join();
}