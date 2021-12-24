#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXVEX 100
#define INFINITY 65535
int visited[MAXVEX]={0};
typedef struct node
{
	int data;
	struct node * next;
}Qnode;
typedef struct
{
	Qnode * front;
	Qnode * rear;
}Queue;
typedef struct
{
	char vexs[MAXVEX];
	int arc[MAXVEX][MAXVEX];
	int numNodes,numEdges;
}MGraph;
void CreateMGraph(MGraph *g);
void DFS(MGraph g,int i);
void BFS(MGraph g,int i);
int main()
{
	MGraph g;
	int i;
	CreateMGraph(&g);
	printf("\n"); 
	printf("输入i\n");
	scanf("%d",&i);
	printf("深度\n");
	DFS(g,i);
	printf("\n");
	printf("广度Ϊ\n");
	BFS(g,i);
}
void CreateMGraph(MGraph *g)
{
	int i,j,k,w;
	printf("请输入顶点数和边数:\n");
	scanf("%d %d",&g->numNodes,&g->numEdges);
	for(i=1;i<=g->numNodes;i++)
	{
		char c;
		while((c=getchar())!=EOF&&c!='\n');
	    printf("输入第%d个顶点信息",i);
		scanf("%c",&(g->vexs[i]));
	}
	for(i=1;i<=g->numNodes;i++)
	   for(j=1;j<=g->numNodes;j++)
	      g->arc[i][j]=INFINITY;
	for(k=1;k<=g->numEdges;k++)
	{
		printf("请输入边(vi,vj)上的下标i,下标j和权w:\n");
		scanf("%d %d %d",&i,&j,&w);
		g->arc[i][j]=w;
		g->arc[j][i]=g->arc[i][j];
	}
	printf("输出邻接矩阵为：\n");
	for(i=1;i<=g->numNodes;i++)
	{
		for(j=1;j<=g->numNodes;j++)
		{
			printf("%8d",g->arc[i][j]);
		}
		printf("\n");
	} 
}
void DFS(MGraph g,int i)
{
	int j;
	visited[i]=1;
	printf("%d ",i);
	fflush(stdout);
	for(j=1;j<=g.numNodes;j++)
	{
		if((g.arc[i][j]>=1)&& (!visited[j]))
		{
			DFS(g,j);
		}
	}
}

void BFS (MGraph g,int i)
{
	int visited[MAXVEX]={0};
	int que[MAXVEX]={0};
	int front=0,rear=0,j;
	printf("%d ",i);
	visited[i]=1;
	rear++;
	que[rear]=i;
	while(front<rear)
		{
			front++;
		    i=que[front];
		    for(j=1;j<=g.numNodes;j++)
		    {
		    	if((g.arc[i][j]>=1)&&(!visited[j]))
		    	{
		    		printf("%d ",j);
		    		visited[j]=1;
		    		rear++;
		    		que[rear]=j;
				}
			}
		}
}
