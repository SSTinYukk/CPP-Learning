#include<stdio.h>
#include"haffmantree_array.h"


int main(){
    int num;

    HFMCoding code_table[MAX_SIZE];
    HFMTNode code_tree[MAX_SIZE];
    
    printf("请输入字符个数：\n");
    scanf("%d",&num);
    
    printf("请输入字符（以空格为分隔）:\n");
    for(int i=1;i<=num;i++){
        scanf("%c",&code_table[i].uncoding);
    }
    printf("请输入权重（以空格为分隔）:\n");
    for(int i=1;i<=num;i++){
        scanf("%d",&code_tree[i].weight);
    }
    
}