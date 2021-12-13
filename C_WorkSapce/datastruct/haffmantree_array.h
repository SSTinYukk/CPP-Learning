#ifndef HAFFMAN
#define HAFFMAN
#include<stdlib.h>
#include"list.h"
typedef char ElemType;
#define MAX_SIZE 256
typedef struct HMTNode{
   int weight;
   int parent,left_child,right_child;
}HFMTNode,*HaffmanTree;

typedef struct {
    char uncoding;
    char coding[MAX_SIZE];
}HFMCoding;


int findTwoMin(HFMTNode code_tree[],int* first_min_idx,int* second_min_idx,int n){
   int min=0xfffffff;
   for(int i=1;i<=n;i++){
      if(code_tree[i].weight<min&&code_tree[i].parent==0&&code_tree[i].weight!=0){
         *first_min_idx=i;
         min=code_tree[i].weight;
      }
   }
   min=0xfffffff;
   for(int i=1;i<=n;i++){
      if(code_tree[i].weight<min&&code_tree[i].parent==0&&i!=*first_min_idx&&code_tree[i].weight!=0){
         *second_min_idx=i;
         min=code_tree[i].weight;
      }
   }
}

int createHaffmanTree(HFMTNode code_tree[],int n){
   int first_idx,second_idx;
   for(int i=n+1;i<=2*n-1;i++){
      findTwoMin(code_tree,&first_idx,&second_idx,i-1);
      code_tree[i].weight=code_tree[first_idx].weight+code_tree[second_idx].weight;
      code_tree[i].left_child=first_idx;
      code_tree[i].right_child=second_idx;

      code_tree[first_idx].parent=i;
      code_tree[second_idx].parent=i;
   }
}

int createHaffmanCodeTable(HFMTNode code_tree[],HFMCoding code_table[],int n){

   list stack;
   int root=2*n-1;
   int p=root;
   char str[MAX_SIZE]={0};
   for(int i=1;i<=n;i++){
      while(code_tree[p].left_child!=0&&code_tree[p].right_child!=0){
         listPushBack(&stack,(void*)&p);
         p=code_tree[p].left_child;
      }
      p=listPopBack(&stack,NULL);
      p=code_tree[p].right_child;
   }
}

int Encode(HFMTNode code_tree[],HFMCoding code_table[],char* str,int n){

}

int Decode(){

}

#endif