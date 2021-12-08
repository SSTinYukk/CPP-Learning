#define MAX_SIZE 256
#include<stdio.h>
#include<stdlib.h>
typedef struct Queue{
    int data[MAX_SIZE];
    int size;
    int front;
    int rear;
}Queue;

typedef struct Graph{
    char  vertex[MAX_SIZE];
    int edge[MAX_SIZE][MAX_SIZE];

    int vex_nums;
    //顶点数
    int edge_nums;
    //边数
    Queue* bfs_que;
}Graph;

typedef struct LNode{
    struct LNode * next;
    //指针域
    int data;
    //数据域
}LNode,*List;

typedef struct HNode{
    char vertex;
    List list;
}gNode;

typedef struct ListGraph{
    gNode glist[MAX_SIZE];

    int glist_nums;
    int arc_nums;
}ListGraph;


int push(List pList,int num){
    LNode* pnew=(LNode *)malloc(sizeof(LNode));
    pnew->data=num;
    pnew->next=NULL;
    if(pList->next==NULL){
        pList->next=pnew;
    }else{
        LNode* p;
        for( p=pList;p->next!=NULL;p=p->next){}
        p->next=pnew;
    }
    return 0;
}

int del(List pList,int num){
    if(pList->next==NULL){
        printf("链表为空,无法删除\n");
    }else{
        for(LNode* p=pList->next,*q;p!=NULL;q=p,p=p->next){
            if(p->data==num){
                q->next=p->next;
                free(p);
                return 1;
            }
        }
    }
    return 0;
}

LNode* find(List pList,int num){
     if(pList->next==NULL){
        printf("链表为空\n");
    }else{
        for(LNode* p=pList->next;p!=NULL;p=p->next){
            if(p->data==num){
                return p;
            }else{
                return NULL;
            }
        }
    }
    return 0;
}

int initQueue(Queue *q)
{
    q->front=0;
    q->rear=0;
    q->size=MAX_SIZE;
    return 0;
}

int push_back(Queue *q,int num)
{
    q->data[q->rear++]=num;
    if(q->rear>=q->size)
        q->rear%=q->size;
    return 0;
}

int pop_fornt(Queue *q)
{
    int ret=q->data[q->front];
    q->front++;
    if(q->front>=q->size)
        q->front%=q->size;
    return ret;
}

int visted[MAX_SIZE]={0};
//访问数组

int init_graph(Graph *g)
{   g->bfs_que=(Queue *)malloc(sizeof(Queue));
    initQueue(g->bfs_que);
    printf("请输入顶点数和边数:\n");
    scanf("%d%d",&g->vex_nums,&g->edge_nums);
    for(int i=1;i<=g->vex_nums;i++){
        g->vertex[i]=0;
    }
    for(int i=0;i<=g->edge_nums;i++){
        for(int j=0;j<=g->edge_nums;j++){
            g->edge[i][j]=0;
        }
    }
    return 1;
}

int FindVexIndex(ListGraph* g,char VexName){
    for(int i=1;i<=g->glist_nums;i++){
        if(g->glist[i].vertex==VexName){
            return i;
        }
    }
}

int InitListGraph(ListGraph* g){
    printf("请输入顶点数和边数:\n");
    scanf("%d%d",&g->glist_nums,&g->arc_nums);
    for(int i=1;i<=g->glist_nums;i++){
        char c;
        while ((c = getchar()) != EOF && c != '\n');//不停地使用getchar()获取缓冲中字符，直到获取的c是“\n”或文件结尾符EOF为止  
        printf("请输入顶点%d\n",i);
        scanf("%c",&g->glist[i].vertex);
        g->glist[i].list=(LNode*)malloc(sizeof(LNode));
    }
    for(int i=1;i<=g->arc_nums;i++){
        char c;
        while ((c = getchar()) != EOF && c != '\n');//不停地使用getchar()获取缓冲中字符，直到获取的c是“\n”或文件结尾符EOF为止  
        printf("请输入边%d\n",i);
        char vex_name_a,vex_name_b=0;
        int vex_index_a,vex_index_b=0;
        scanf("%c%c",&vex_name_a,&vex_name_b);
        vex_index_a=FindVexIndex(g,vex_index_a);
        vex_index_b=FindVexIndex(g,vex_name_b);
        push(g->glist[vex_index_a].list,vex_index_b);
        push(g->glist[vex_index_b].list,vex_index_a);
    }
    return 0;
}


int locateVertex(const Graph *g,char c){
    for(int i=1;i<=g->vex_nums;i++){
        if(c==g->vertex[i]){
            return i;
        }
    }
    return 1;
}

int create_graph(Graph *g)
{
    for(int i=1;i<=g->vex_nums;i++){
        char c;
        while ((c = getchar()) != EOF && c != '\n');//不停地使用getchar()获取缓冲中字符，直到获取的c是“\n”或文件结尾符EOF为止  
        printf("请输入顶点%d\n",i);
        scanf("%c",&g->vertex[i]);
    }
    char edgeVertexa,edgeVertexb;
    for(int i=1;i<=g->edge_nums;i++){
        int edge_indexA,edge_indexB;
        char c;
        while ((c = getchar()) != EOF && c != '\n');//不停地使用getchar()获取缓冲中字符，直到获取的c是“\n”或文件结尾符EOF为止  
        printf("请输入边%d\n",i);
        scanf("%c%c",&edgeVertexa,&edgeVertexb);
        edge_indexA=locateVertex(g,edgeVertexa);
        edge_indexB=locateVertex(g,edgeVertexb);
        g->edge[edge_indexA][edge_indexB]=1;
        g->edge[edge_indexB][edge_indexA]=1;
    }
    return 1;
}

int DFS(Graph *g,int vertexIndex)
{
    visted[vertexIndex]=1;
    printf("%c",g->vertex[vertexIndex]);
    //标记访问
    for(int i=1;i<g->vex_nums;i++){
        if(g->edge[vertexIndex][i]!=0&&visted[i]==0){
            DFS(g,i);
        }
    }
    return 1;
}

int BFS(Graph *g,int vertex_index)
{
    if(visted[vertex_index]==0){
        printf("%c",g->vertex[vertex_index]);
        visted[vertex_index]=1;
        for(int i=0;i<g->vex_nums;i++){
            if(g->edge[vertex_index][i]!=0&&visted[i]==0)
                push_back(g->bfs_que,i);
        }
        int next_index=pop_fornt(g->bfs_que);
        BFS(g,next_index);
        return 1;
    }else{
        return -1;
    }
}

int firstStart(Graph *g)
{
    // char first_vex;
    // int first_index;
    // char c;
    // while ((c = getchar()) != EOF && c != '\n');//不停地使用getchar()获取缓冲中字符，直到获取的c是“\n”或文件结尾符EOF为止  
    // scanf("%c",&first_vex);
    // first_index=locateVertex(g,first_vex);
    printf("深度优先遍历序列:");
    for(int i=1;i<=g->vex_nums;i++){
        // int real_index=(i+first_index-1)%g->vex_nums;
        if(visted[i]==0){
            DFS(g,i);
        }
    }
    printf("\n");
    return 1;
}

int BfsFirstStart(Graph *g)
{
    printf("广度优先遍历序列:");
    for(int i=1;i<=g->vex_nums;i++){
        if(visted[i]==0){
            BFS(g,i);
        }
    }
    printf("\n");
    return 0;
}

int FlushVisted(const Graph *g)
{
    for(int i=1;i<=g->vex_nums;i++)
        visted[i]=0;
    return 0;
}

int main()
{
    int choice;
    printf("1.邻接表 or 2.邻接矩阵 Please put in.\n");
    scanf("%d",&choice);
    if(choice==1){
        ListGraph *g=(ListGraph*)malloc(sizeof(ListGraph));
        InitListGraph(g);

    }else{
        Graph *g=(Graph *)malloc(sizeof(Graph));
        init_graph(g);
        //初始化图结构
        create_graph(g);
        //向图读入数据
        firstStart(g);
        //DFS遍历
        FlushVisted(g);
        //刷新访问记录数组
        BfsFirstStart(g);
        //BFS遍历
        
    }
    return 0;
}
