#include<iostream>
using namespace std;
#include<vector>
#include<map>

class Worker
{
public:
    string m_Name;
    int m_Salary;
};

void createWorker(vector<Worker>&v)
{
    string nameSeed ="ABCDEFGHIJ";
    for(int i =0;i<10;i++)
    {
        Worker worker;
        worker.m_Name = "员工";
        worker.m_Name += nameSeed[i];

        worker.m_Salary = rand() % 10000+10000;
        v.push_back(worker);
    }
}

int main()
{
    vector<Worker>vWorker;
    createWorker(vWorker);

    for(vector<Worker>::iterator it=vWorker.begin();it!=vWorker.end();it++)
    {
        cout<<"姓名:"<<it->m_Name<<"\t工资:"<<it->m_Salary<<endl;
    }
}