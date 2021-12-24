#include<stdio.h>
#include "list.h"
//#define NDEBUG

//寻找最大值
int max(int *arr,int n){
    int max=0;
    for(int i=0;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    return max;
}

//返回最大值位数 例:1435  返回值为4
int place(int num){
    int num_place=0;
    while(num){
        num/=10;
        num_place++;
    }
    return num_place;
}

int main(){
    //初始化链表
    list row;
    listInit(&row);

    //给定待排元素↓
    int n=10;
    int arr[10]={23,62,40,679,3455,26,34,132,231,728};

    //将待排元素录入链表
    for(int i=0;i<n;i++){
        listPushBack(&row,(void*)&arr[i]);
    }

    //创建并初始化链式桶
    list base[10];
    for(int i=0;i<10;i++){
        listInit(&base[i]);
    }
    
    int divisor=1;
    int max_num=max(arr,10);
    int place_num=place(max_num);    
    for(int i=0;i<place_num;i++){
        for(int j=0;j<n;j++){
            int temp_num=listPopFront(&row,0);
            int index_num=(temp_num/divisor)%10;
            #ifdef NDEBUG
            printf("pop:%d index:%d\n",temp_num,index_num);
            #endif
            listPushBack(&base[index_num],(void*)&temp_num);
        }
        for(int j=0;j<10;j++){
            while(!listIsEmpty(&base[j])){
                int temp_num=listPopFront(&base[j],0);
                #ifdef NDEBUG
                printf("pop:%d\n",temp_num);
                #endif
                listPushBack(&row,(void*)&temp_num);
            }
        }
        divisor*=10;
    }
    for(int i=0;i<n;i++){
        printf("%d\t",listPopFront(&row,0));
    }
    printf("\n");
}