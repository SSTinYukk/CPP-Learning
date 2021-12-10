#ifndef LIST_H
#define LIST_H
#include <stdlib.h>
typedef struct listNode{
    //保存前驱结点
    struct listNode *prev;
    //保存后继节点
    struct listNode *next;
    //保存值
    void *value;
}listNode;

typedef struct list{
    listNode *head;
    //链表头结点
    listNode *tail;
    //链表尾结点
    unsigned long len;
    //链表长度
}list;

/*初始化链表*/
int listInit(list* plist){
    plist->head=NULL;
    plist->len=0;
    plist->tail=NULL;
    return 0;
}

/*尾插法*/
int listPushBack(list* plist,void* data){
    //创建新结点并初始化
    listNode* ptr_new =(listNode*)malloc(sizeof(listNode));
    ptr_new->next=NULL;
    ptr_new->prev=NULL;
    ptr_new->value=data;
    //插入结点
    if(plist->head==NULL&&plist->tail==NULL){
        plist->head=ptr_new;
        plist->tail=ptr_new;
    }else{
        ptr_new->prev=plist->tail;
        plist->tail->next=ptr_new;
        plist->tail=ptr_new;
    }
    //链表长度加一
    plist->len++;
    return 0;
}

/*头插法*/
int listPushFront(list* plist,void* data){
    //创建新结点并初始化
    listNode* ptr_new =(listNode*)malloc(sizeof(listNode));
    ptr_new->next=NULL;
    ptr_new->prev=NULL;
    ptr_new->value=data;
    //插入结点
    if(plist->head==NULL&&plist->tail==NULL){
        plist->head=ptr_new;
        plist->tail=ptr_new;
    }else{
        ptr_new->next=plist->head;
        plist->head->prev=ptr_new;
        plist->head=ptr_new;
    }
    //链表长度加一
    plist->len++;
    return 0;
}

int listPopFront(list* plist){
    if(plist->len>0){
        listNode* ptr_rem=plist->head;
        plist->head=plist->head->next;
        plist->head->prev=NULL;
        ptr_rem->prev=NULL;
        //链表长度减一
        plist->len--;

        free(ptr_rem);  
        return 0;
    }
}

int listPopBack(list* plist){
    if(plist->len>0){
        listNode* ptr_rem=plist->tail;
        plist->tail=plist->tail->prev;
        plist->tail->next=NULL;
        ptr_rem->prev=NULL;
        //链表长度减一
        plist->len--;

        free(ptr_rem);
        return 0;
    }
}

int listIsEmpty(list* plist){
    return !(plist->len);
}

#endif