//开发环境 Linux_64位 Gcc
#include<stdio.h>
#include"haffmantree_array.h"


#define DEBUG   //NODEBUG 为非调试模式  DEBUG为调试模式 打印一系列帮助信息

int main(){
    int num;char c;

    HFMCoding code_table[MAX_SIZE];
    HFMTNode code_tree[MAX_SIZE];
    FILE* weight_fd=fopen("/home/Learn/C_WorkSapce/datastruct/weight.txt","r");
    FILE* encode_fd=fopen("/home/Learn/C_WorkSapce/datastruct/EnCode.txt","r+");
    FILE* decode_fd=fopen("/home/Learn/C_WorkSapce/datastruct/DeCode.txt","w+");
    fscanf(weight_fd,"%d",&num);    
    for(int i=1;i<=num;i++){
        fscanf(weight_fd,"%c\n",&code_table[i].uncoding);
    }
    for(int i=1;i<=num;i++){
        fscanf(weight_fd,"%d\n",&code_tree[i].weight);
    }
    createHaffmanTree(code_tree,num);
    createHaffmanCodeTable(code_tree,code_table,num);
    int key;
    printf("                    1.键盘输入\n");
    printf("                    2.文件输入\n");
    scanf("%d",&key);
    if(key==1){

            #ifndef NODEBUG
            for(int i=1;i<=num;i++){
                printf("%c %s\n ",code_table[i].uncoding,code_table[i].coding);
            }
            for(int i=1;i<=2*num-1;i++){
                printf("[%d]weight:%d\tparent:%d\tleft:%d\tright:%d\n",i,code_tree[i].weight,code_tree[i].parent,code_tree[i].left_child,code_tree[i].right_child);
            }
            #endif
            char str[MAX_SIZE]={0};
            printf("请输入要编码的字符串:\n");
            scanf("%s",str);
            Encode(code_tree,code_table,str,num);
            printf("编码字符串:%s\n",str);
            
            Decode(code_tree,code_table,str,num);
            printf("解码字符串:%s\n",str);
    }else if(key==2){

            #ifndef NODEBUG
            for(int i=1;i<=num;i++){
                printf("%c %s\n ",code_table[i].uncoding,code_table[i].coding);
            }
            for(int i=1;i<=2*num-1;i++){
                printf("[%d]weight:%d\tparent:%d\tleft:%d\tright:%d\n",i,code_tree[i].weight,code_tree[i].parent,code_tree[i].left_child,code_tree[i].right_child);
            }
            #endif
            char str[MAX_SIZE]={0};
            printf("请输入要编码的字符串:\n");
            fscanf(encode_fd,"%s",str);
            Encode(code_tree,code_table,str,num);
            printf("编码字符串:%s\n",str);
            fprintf(decode_fd,"%s",str);
            Decode(code_tree,code_table,str,num);
            fclose(decode_fd);
    }
        
    }