#include<stdio.h>
#include"list.h"

int main(){
    list l1;
    listInit(&l1);
    for(int i=0;i<10;i++){
        listPushBack(&l1,(void*)&i);
    }

    for(int i=0;i<10;i++){
        int *ptr;
        listPopFront(&l1,(void**)&ptr);
        printf("%d\n",*ptr);
        free(ptr);
    }
    return 0;
}