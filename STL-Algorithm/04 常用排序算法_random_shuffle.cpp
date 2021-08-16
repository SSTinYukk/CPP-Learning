#include <cstdlib>
#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>
#include<ctime>

void myprint(int t)
{
    cout<<t<<" ";
}

int main()
{
    srand(time(NULL));
    vector<int>v;
    for(int i=0;i<10;i++){ 
        v.push_back(i);
    }
    random_shuffle(v.begin(),v.end());
    for_each(v.begin(),v.end(),myprint);
}
