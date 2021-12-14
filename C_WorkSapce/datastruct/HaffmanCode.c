#include<stdio.h>
#include"haffmantree_array.h"
#define DEBUG

int main(){
    int num;char c;

    HFMCoding code_table[MAX_SIZE];
    HFMTNode code_tree[MAX_SIZE];
    
    printf("请输入字符个数：\n");
    scanf("%d",&num);
    
    printf("请输入字符（以空格为分隔）:\n");
    for(int i=1;i<=num;i++){
        while ((c = getchar()) != EOF && c != '\n');
        scanf("%c",&code_table[i].uncoding);
    }
    printf("请输入权重（以空格为分隔）:\n");
    for(int i=1;i<=num;i++){
        while ((c = getchar()) != EOF && c != '\n');
        scanf("%d",&code_tree[i].weight);
    }

    createHaffmanTree(code_tree,num);
    createHaffmanCodeTable(code_tree,code_table,num);
    #ifndef NODEBUG
    for(int i=1;i<=num;i++){
        printf("%c %s\n ",code_table[i].uncoding,code_table[i].coding);
    }
    for(int i=1;i<=2*num-1;i++){
        printf("[%d]weight:%d\tparent:%d\tleft:%d\tright:%d\n",i,code_tree[i].weight,code_tree[i].parent,code_tree[i].left_child,code_tree[i].right_child);
    }
    #endif
    char str[MAX_SIZE]={0};
    scanf("%s",str);
    Encode(code_tree,code_table,str,num);
    printf("%s\n",str);
    Decode(code_tree,code_table,str,num);
    printf("%s\n",str);
    
}