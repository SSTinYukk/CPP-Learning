#ifndef LIST_H
#define LIST_H
#include <stdlib.h>
#include<memory.h>
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
    ptr_new->value=(void *)malloc(sizeof(data));
    memcpy(ptr_new->value,data,sizeof(data));
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
    ptr_new->value=(void *)malloc(sizeof(data));
    memcpy(ptr_new->value,data,sizeof(data));
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

int listPopFront(list* plist,void** ptr_data){
    
    if(plist->len>0){
        if(plist->head==plist->tail){
            listNode* ptr_rem=plist->head;
            int ret=*(int*)plist->tail->value;
            
            plist->head=NULL;
            plist->tail=NULL;
            plist->len--;
            if(ptr_data){
                *ptr_data=ptr_rem->value;
            }else{
                free(ptr_rem->value); 
            }
            free(ptr_rem);
            return ret;
        }else{
            int ret=*(int*)plist->head->value;
            listNode* ptr_rem=plist->head;
            plist->head=plist->head->next;
            plist->head->prev=NULL;
            ptr_rem->prev=NULL;
            //链表长度减一
            plist->len--;
            if(ptr_data){
                *ptr_data=ptr_rem->value;
            }else{
                free(ptr_rem->value); 
            }
            free(ptr_rem);  
            return ret;
        }
    }else{
        return -1;          //链表为空无法删除
    }
}

int listPopBack(list* plist,void** ptr_data){
    if(plist->len>0){
        if(plist->head==plist->tail){
            listNode* ptr_rem=plist->head;
            int ret=*(int*)plist->tail->value;
            
            plist->head=NULL;
            plist->tail=NULL;
            plist->len--;
            if(ptr_data){
                *ptr_data=ptr_rem->value;
            }else{
                free(ptr_rem->value); 
            }
            free(ptr_rem);
            return ret;
        }else{
            int ret=*(int*)plist->tail->value;
            listNode* ptr_rem=plist->tail;
            plist->tail=plist->tail->prev;
            plist->tail->next=NULL;
            ptr_rem->prev=NULL;
            //链表长度减一
            plist->len--;
            if(ptr_data){
                *ptr_data=ptr_rem->value;
            }else{
                free(ptr_rem->value); 
            }
            free(ptr_rem);
            return ret;

        }
        
    }else{
        return -1;
    }
}

int listIsEmpty(list* plist){
    return !(plist->len);
}

int listInsertIntSorted(list* plist,int* data){
     //创建新结点并初始化
    listNode* ptr_new =(listNode*)malloc(sizeof(listNode));
    ptr_new->next=NULL;
    ptr_new->prev=NULL;
    ptr_new->value=(void *)malloc(sizeof(data));
    memcpy(ptr_new->value,data,sizeof(data));

    listNode *iterator=plist->head,*last;
    for(;iterator!=NULL;last=iterator,iterator=iterator->next){
        if(*(int*)iterator->value<=*data){
            continue;
        }else{
            if(iterator==plist->head){
                listPushFront(plist,ptr_new->value);
            }else{
                ptr_new->prev=last;
                ptr_new->next=iterator;
                last->next=ptr_new;
                iterator->prev=ptr_new;
            }           
        }
    }
    if(iterator==plist->tail->next){
        listPushBack(plist,ptr_new->value);
        return 0;
    }
    return -1;
}

int listClear(list *plist){
    int ret=0;
    do{
        ret=listPopFront(plist,0);
    }while(ret!=1);
    return 0;
}

#endif