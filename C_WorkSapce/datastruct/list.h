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
    void *(*free)(void *ptr);
    //释放函数
    unsigned long len;
    //链表长度
}list;

#endif