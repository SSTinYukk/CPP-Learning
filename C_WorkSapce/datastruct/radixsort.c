#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXVEX 100
#define INFINITY 65535
int visited[MAXVEX]={0};
typedef struct
{
	char vexs[MAXVEX];
	int arc[MAXVEX][MAXVEX];
	int numNodes,numEdges;
}MGraph;
void CreateMGraph(MGraph *g);
void DFS(MGraph *g,int i);
int main()
{
	MGraph g;
	int i;
	CreateMGraph(&g);
	printf("\n"); 
	printf("输入i\n");
	scanf("%d",&i);
	printf("深度优先遍历\n");
	DFS(&g,i);
}
void CreateMGraph(MGraph *g)
{
	int i,j,k,w;
	printf("请输入顶点数和边数:\n");
	scanf("%d%d",&g->numNodes,&g->numEdges);
	for(i=1;i<=g->numNodes;i++)
	{
        char c;
        while ((c = getchar()) != EOF && c != '\n');//不停地使用getchar()获取缓冲中字符，直到获取的c是“\n”或文件结尾符EOF为止  
	    printf("输入第%d个顶点信息",i);
		scanf("%c",&g->vexs[i]);
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
void DFS(MGraph *g,int i)
{
	int j;
	visited[i]=1;
	printf("%d",i);
    fflush(stdout);
	for(j=1;j<=g->numNodes;j++)
	{
		if((g->arc[i][j]>=1)&& (!visited[j]))
		{
			DFS(g,j);
		}
	}
}