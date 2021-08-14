#include <cstdlib>
#include<iostream>
using namespace std;
#include<vector>
#include<deque>
#include<algorithm>

class Person
{
public:
    Person(string name,int score)
    {
        this->m_Name = name;
        this->m_Score=score;  
    }
    string m_Name;  //姓名
    int m_Score;    //平均分
};

void createPerson(vector<Person>&v)
{
    string nameSeed="ABCDE";
    for(int i=0;i<5;i++){
        
        string name="选手";
        name+=nameSeed[i];

        int score=0;

        Person p(name,score);
        //将创建的Person对象放入容器中
        v.push_back(p);
    }

}

void setScore(vector<Person>&v)
{
    for(vector<Person>::iterator it=v.begin();it!=v.end();it++)
    {
        deque<int>d;
        for(int i=0;i<10;i++)
        {
            deque<int>d;
            for(int i=0;i<10;i++){
                int score=rand()%41+60;
                d.push_back(score);
            }
            sort(d.begin(),d.end());

            d.pop_front();
            d.pop_back();

            int sum=0;
        for(deque<int>::iterator dit=d.begin();dit!=d.end();dit++){
            sum+=*dit;
        }
        int avg=sum/d.size();
        it->m_Score=avg;
        }
    }
}

int main()
{
    //1.创建五名选手
    vector<Person>v;
    createPerson(v);
   
    //2.打分
    setScore(v);
     //测试
    for(vector<Person>::iterator it=v.begin();it!=v.end();it++)
    {
        cout<<"姓名:"<<it->m_Name<<"\t分数:"<<it->m_Score<<endl;
    }
    //3.显示平均分
}