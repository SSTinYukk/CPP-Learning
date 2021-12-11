#include<stdio.h>
#include "list.h"

int max(int *arr,int n){
    int max=0;
    for(int i=0;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    return max;
}

int place(int num){
    int num_place=0;
    while(num){
        num/=10;
        num_place++;
    }
    return num_place;
}

int main(){
    list row;
    listInit(&row);

    int n=10;
    int arr[10]={23,62,40,679,345,26,34,132,231,728};
    for(int i=0;i<n;i++){
        listPushBack(&row,(void*)&arr[i]);
    }

    list base[10];
    for(int i=0;i<10;i++){
        listInit(&base[i]);
    }
    
    int divisor=1;
    int max_num=max(arr,10);
    int place_num=place(max_num);    
    for(int i=0;i<place_num;i++){
        for(int j=0;j<n;j++){
            int temp_num=listPopFront(&row);
            int index_num=(temp_num/divisor)%10;
            printf("pop:%d index:%d\n",temp_num,index_num);
            listPushBack(&base[index_num],(void*)&temp_num);
        }
        for(int j=0;j<10;j++){
            for(int k=0;k<base[j].len;k++){
                int temp_num=listPopFront(&base[j]);
                printf("pop:%d\n",temp_num);
                listPushBack(&row,(void*)&temp_num);
            }
        }
        divisor*=10;
    }
    for(int i=0;i<n;i++){
        printf("%d\n",listPopFront(&row));
    }
}