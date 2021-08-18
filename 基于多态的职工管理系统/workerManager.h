#include<iostream>
#include "worker.h"
using namespace std;

class WorkerManager
{
public:
    WorkerManager();
    ~WorkerManager();
    void Show_Menu();
    void sys_exit();

    int m_EmpNum;//记录职工人数
    Worker ** m_EmpArray;
    void Add_Emp();
};