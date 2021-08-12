#include<iostream>
using namespace std;

class CPU
{
public:
    virtual void calculate()=0;
};

class GPU
{
public:
    virtual void display() = 0;
};

class Memory
{
public:
    virtual void storage() = 0 ;     
};

class Computer
{
public:
    Computer(CPU *cpu,GPU *gpu, Memory *mem)
    {
        m_cpu=cpu;
        m_gpu=gpu;
        m_mem=mem;
    }
    
    void work()
    {
        m_cpu->calculate();
        m_gpu->display();
        m_mem->storage();
    }
    ~Computer()
    {
        delete(m_cpu);
        delete(m_gpu);
        delete(m_mem);
    }
private:
    CPU *m_cpu;
    GPU *m_gpu;
    Memory *m_mem;
};

class AMDCPU:public CPU
{
public:
    void calculate()
    {
        cout<<"AMDCPU已运行"<<endl;
    }
};

class AMDGPU : public GPU
{
public:
    void display()
    {
        cout << "AMD显卡开始工作" << endl;
    }
};
class ChangJiang : public Memory
{
public:
    void storage()
    {
        cout << "内存已点亮" << endl;
    }
};  

void test01()
{
    {
        CPU *amdCPU = new AMDCPU;
        GPU *amdGPU =new AMDGPU;
        Memory *mem = new ChangJiang;

        Computer * computer1=new Computer(amdCPU,amdGPU,mem);
        computer1->work();
        delete computer1;
    }
}

int main()
{
    test01();
}
