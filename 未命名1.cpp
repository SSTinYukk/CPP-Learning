#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE	40
#define MAXVEX  20             	//最大顶点数
#define INFINITY 32768			//表示极大值             	

int count=0;// DFSALL
int flag=0;
int way[MAXSIZE]={0}; 

int min_count=INFINITY;
int min_Way[MAXSIZE]={0};
typedef struct//定义地点及介绍的结构体 
{
    char  name[20];		//名称
	char  info[220];     //信息 
	int visited;
}Vextype;

typedef struct//定义各边以及距离数据的结构体 
{
	int arcs[MAXVEX][MAXVEX];
	Vextype vex[MAXVEX];
    int vexnum;		//顶点数
	int arcnum;     //边数
	int visited[MAXVEX];
}AdjMatrix;

void Map() //地图 
{
	char ch;
	FILE *fp;
	fp=fopen("sjjgks.txt","rt");
	if(fp==NULL)
	{
		printf("\n不能打开d:\\code\\map.txt file!");
		exit(1);
	}
	while((ch=fgetc(fp))!=EOF)	printf("%c",ch);
	fclose(fp);
} 
 
void Welcome()//欢迎页 
{
	printf("\n"); 
	printf("\n");
	printf("\n");
    printf("——————————————————————————————————————————\n"); 
    printf("\n\t\t\t欢迎使用导游系统\n\n");  
	printf("\n\t\t\t1.管理员\n\n"); 
	printf("\n\t\t\t2.学生\n\n");
    printf("——————————————————————————————————————————\n");
}
	

void Create(AdjMatrix *G)//建立邻接矩阵，存储地点名称和介绍 
{
	int i,j;
	int a,b,c;
	int vexnum,arcnum;
	char name[20],info[200];

	FILE *fp;
	fp=fopen("information.txt","rt");
	if(fp==NULL)
	{
		printf("\n不能打开!");
		exit(1);
	}
	fscanf(fp,"%d %d",&vexnum,&arcnum);
	G->vexnum=vexnum;
	G->arcnum=arcnum;	
	for(i=1;i<=G->vexnum;i++)//初始化visited 
	   G->vex[i].visited=0;
	for(i=1;i<=G->vexnum;i++)
	{
		fscanf(fp,"%s\n%s",name,info);
		strcpy(G->vex[i].name,name);
		strcpy(G->vex[i].info,info);

	}
	
	for(i=1;i<=G->vexnum;i++)
		for(j=1;j<=G->vexnum;j++)
		   G->arcs[i][j]=INFINITY;
	
	for(j=1;j<=G->arcnum ;j++)
	{
		fscanf(fp,"%5d %5d %5d",&a,&b,&c);
		G->arcs[a][b]=c;
		G->arcs[b][a]=c;
	}
	
		fclose(fp);
}

int PriV(AdjMatrix *G)// 打印建筑列表 
{
	int i;
	for ( i = 1; i <=G->vexnum; i++ )
	   printf("\t\t\t\t\t\t%d\t%s\n",i,G->vex[i].name); 
	return 0;
}

int PriAM(AdjMatrix *G)// 打印矩阵
{
	int i,j;
	for(i=1;i<=G->vexnum;i++)
	{
		for(j=1;j<=G->vexnum;j++)
		{
			printf("%10d",G->arcs[i][j]) ;
			printf("\n");
		}
	 } 
	return 0;
}
	 

void SearchPlace(AdjMatrix G)//景点介绍 
{
	int i, num,c = 1;
	while ( c == 1 )
	{
		 
		printf( "\t\t\t\t\t\t——————建筑信息查询——————\n" );
		PriV(&G);
		printf( "\t\t\t\t\t\t请输入您要查找的建筑编号：" );
		scanf( "%d", &num );
		if ( num > 0 && num <= G.vexnum ) 
		{
			printf( "\n\n");
			printf( "\t\t\t名称:%s\n", G.vex[num].name );
			printf( "\t\t\t简介:%s\n\n", G.vex[num].info );
		}else
			printf( "\t\t\t\t\t\t信息输入有误!\n" );
		num = 0;
		printf( "\n\t\t\t\t\t\t是否继续查询建筑信息？\n" );
		printf( "\t\t\t\t\t\t1:是\n" );
		printf( "\t\t\t\t\t\t0:返回上级菜单\n" );
		scanf( "%d", &c );
	}
}

void In(AdjMatrix G)//读取文件 
{
	int i,j;
	char filename[40]="information.txt";
	char ch;
	FILE *fp;
		fp=fopen(filename,"rt");
	if(fp==NULL)
	{
		printf("\n不能打开!");
		exit(1);
	}
	G.vexnum=16;G.arcnum=33;
	fprintf(fp,"%d %d\n",G.vexnum,G.arcnum);
	strcpy(G.vex[1].name	,"北门"); 
	strcpy(G.vex[1].info	,"位于景区的正北方向、是第一道亮丽的风景线"); 
	strcpy(G.vex[2].name	,"行政楼"); 
	strcpy(G.vex[2].info	,"工作、及重大会议召开的地点"); 
	strcpy(G.vex[3].name	,"基础楼"); 
	strcpy(G.vex[3].info	,"其中A栋楼有7层,B栋有3层楼"); 
	strcpy(G.vex[4].name	,"喷泉"); 
	strcpy(G.vex[4].info	,"位于正门口;造型似一只鸽子，底部常年有水，被戏称为水煮鸽子"); 
	strcpy(G.vex[5].name	,"旭日苑"); 
	strcpy(G.vex[5].info	,"共有三栋!可供不同菜品、不同兴趣的同学可以品尝到新鲜的美食"); 
	strcpy(G.vex[6].name	,"大学生活动中心"); 
	strcpy(G.vex[6].info	,"展现自己各种特长才艺的地方!每周这里都会有非常精彩的活动、晚会,乃才艺高人的聚集地"); 
	strcpy(G.vex[7].name	,"图书馆"); 
	strcpy(G.vex[7].info	,"同学们看书，学习的地方，书籍种类丰富"); 
	strcpy(G.vex[8].name	,"洗浴中心"); 
	strcpy(G.vex[8].info	,"洗浴的地方!"); 
	strcpy(G.vex[9].name	,"体育馆"); 
	strcpy(G.vex[9].info	,"室内的小型体育场,内设有篮球场，羽毛球场及乒乓球场等"); 
	strcpy(G.vex[10].name   ,"大操场"); 
	strcpy(G.vex[10].info   ,"举行大型赛事的地点，平时主要各种足球训练、比赛使用,也是跑步健身的好场所!"); 
	strcpy(G.vex[11].name   ,"小操场"); 
	strcpy(G.vex[11].info   ,"主要供平时运动、跑步使用;其侧面还有乒乓球、网球场地,活动的地点之一!"); 
	strcpy(G.vex[12].name   ,"篮球场"); 
	strcpy(G.vex[12].info   ,"篮球比赛的重要场所!"); 
	strcpy(G.vex[13].name   ,"美食广场"); 
	strcpy(G.vex[13].info   ,"两大食堂之一、饭菜美味可口!"); 
	strcpy(G.vex[14].name   ,"超市"); 
	strcpy(G.vex[14].info   ,"可以在里面买到零食及生活用品");
	strcpy(G.vex[15].name   ,"东升苑");
	strcpy(G.vex[15].info   ,"东区食堂，食品种类繁多");
	strcpy(G.vex[16].name   ,"逸夫楼");
	strcpy(G.vex[16].info   ,"东区教学楼，共八层");
	for ( i = 1; i <= G.vexnum; i++ )
	   fprintf(fp,"%s\n%s\n",G.vex[i].name,G.vex[i].info); 
	
	for ( i = 0; i <=G.vexnum; ++i )
		for ( j = 0; j <=G.vexnum; ++j )
		   G.arcs[i][j] = INFINITY;//初始化矩阵 ，存储地点以及之间的距离 
	G.arcs[1][2] = G.arcs[2][1] = 70;
	G.arcs[1][3] = G.arcs[3][1] = 100;
	G.arcs[2][4] = G.arcs[4][2] = 60;
	G.arcs[1][4] = G.arcs[4][1] = 40;
	G.arcs[4][3] = G.arcs[3][4] = 80;
	G.arcs[2][6] = G.arcs[6][2] = 100;
	G.arcs[4][6] = G.arcs[6][4] = 100;
	G.arcs[5][3] = G.arcs[3][5] = 100;
	G.arcs[5][6] = G.arcs[6][5] = 100;
	G.arcs[4][7] = G.arcs[7][4] = 140;
	G.arcs[6][7] = G.arcs[7][6] = 80;
	G.arcs[7][5] = G.arcs[5][7] = 80;
	G.arcs[8][7] = G.arcs[7][8] = 100;
	G.arcs[9][7] = G.arcs[7][9] = 80;
	G.arcs[5][8] = G.arcs[8][5] = 100;
	G.arcs[5][12] = G.arcs[12][5] = 120;
	G.arcs[5][15] = G.arcs[15][5] = 300;
	G.arcs[5][16] = G.arcs[16][5] = 400;
	G.arcs[9][14] = G.arcs[14][9] = 60;
	G.arcs[6][10] = G.arcs[10][6] = 150;
	G.arcs[7][10] = G.arcs[10][7] = 100;
	G.arcs[7][16] = G.arcs[16][7] = 300;
	G.arcs[12][8] = G.arcs[8][12] = 50;
	G.arcs[10][9] = G.arcs[9][10] = 30;
	G.arcs[9][12] = G.arcs[12][9] = 70;
	G.arcs[13][8] = G.arcs[8][13] = 30;
	G.arcs[13][12] = G.arcs[12][13] = 40;
	G.arcs[11][12] = G.arcs[12][11] = 20;
	G.arcs[11][14] = G.arcs[14][11] = 30;
	G.arcs[13][14] = G.arcs[14][13] = 120;
	G.arcs[10][14] = G.arcs[14][10] = 120;
	G.arcs[10][14] = G.arcs[14][10] = 120;
	G.arcs[10][15] = G.arcs[15][10] = 200;
	G.arcs[15][16] = G.arcs[16][15] = 50;
	for ( i = 0; i <=G.vexnum; ++i )
		for ( j = 0; j <=G.vexnum; ++j )
		    if(G.arcs[i][j]!=INFINITY)
		       fprintf(fp,"%10d %10d %10d\n",i,j,G.arcs[i][j]);
	fclose(fp);
}

void Im(AdjMatrix G)//从文件读取地图 
{
	char filename[40]="./sjjgks.txt";
	FILE *fp;
	fp=fopen(filename,"rt");
	if(fp==NULL)
	{
		printf("\n不能打开!");
		exit(1);
	}
    fprintf(fp,"----------------------------------------------------------------------------------------------\n");   
	fprintf(fp,"|------------------------------------------------------------------------------------------|\n");
    fprintf(fp,"|                                  ★景区 ★                                               |\n");
    fprintf(fp,"|------------------------------------------------------------------------------------------|\n");
    fprintf(fp,"|                                         |    |                                           |\n");
    fprintf(fp,"|                                         |    |                                           |\n"); 
    fprintf(fp,"|                                         |    |                                           |\n");
	fprintf(fp,"|              北门                       |    |                                      ↑北 |\n"); 
	fprintf(fp,"|                |                        |    |                   操场                    |\n");     
	fprintf(fp,"|                |                        |    |                       |                   |\n");
	fprintf(fp,"|                |------------行政楼      |    |     正门----------    |    逸夫楼         |\n");                          
	fprintf(fp,"|                |                        |    |                       |                   |\n");     
	fprintf(fp,"|       --------喷泉                      | 子 |                       |                   |\n"); 
	fprintf(fp,"|      |         |      |                 |    |                       |                   |\n");     
	fprintf(fp,"|      |         |      |                 |    |                         住宿楼            |\n");    
	fprintf(fp,"|     基础楼     |      |                 |    |                       |                   |\n");    
	fprintf(fp,"|      |         |------大学生            | 午 |                       |                   |\n");  
	fprintf(fp,"|      |         |     活动中心           |    |                       |                   |\n");  
	fprintf(fp,"|      |         |                        |    |       东升苑----------|                   |\n");    
	fprintf(fp,"|      |         |                        |    |                       |                   |\n");
	fprintf(fp,"|      |      图书馆--------播云湖        |    |                       |                   |\n");    
	fprintf(fp,"|      |         |                        |    |                       |                   |\n");     
	fprintf(fp,"|     篮球场     |---------------------------------------------------- |                   |\n");     
	fprintf(fp,"|      |         |                     |   天桥   |                    |                   |\n");
	fprintf(fp,"|      | 小操场  |--------  --------------------------  -------------- |                   |\n");
	fprintf(fp,"|      |         |        |               |    |      |                                    |\n");    
	fprintf(fp,"| 洗浴中心       |        |    大操场     |    |      |                                    |\n");
	fprintf(fp,"|      |         |        |               |    |      |                                    |\n");
	fprintf(fp,"|  美食          |------体育馆            |    |      |                                    |\n");     
	fprintf(fp,"|  广场          |                        | 大 |      |                                    |\n");    
	fprintf(fp,"|      |         |                        |    |       ------------------家属楼            |\n");    
	fprintf(fp,"|      |       旭日苑                     |    |                                           |\n");     
	fprintf(fp,"|      |         |                        |    |                                           |\n");
    fprintf(fp,"|      |         |                        |    |                                           |\n");
	fprintf(fp,"|      |-------超市---------              |    |                                           |\n");      
	fprintf(fp,"|      |                         |        |    |                                           |\n");     
	fprintf(fp,"|      |                         |        | 道 |                                           |\n");     
	fprintf(fp,"|    住宿楼          住宿楼               |    |                                           |\n"); 
	fprintf(fp,"|                                         |    |                                           |\n"); 
    fprintf(fp,"|                                         |    |                                           |\n");   
    fprintf(fp,"----------------------------------------------------------------------------------------------\n");   
	fclose(fp);
}
void addline(AdjMatrix G)
{
	int start,end,n;
	PriV(&G);
	printf( "\n\t\t\t\t\t输入起点编号:" );
	scanf( "%d", &start );
	printf( "\t\t\t\t\t输入终点编号:" );
	scanf( "%d", &end );
	printf("\t\t\t\t\t请输入路径长度:");
	scanf("%d",&n);
	G.arcs[start][end]=G.arcs[end][start]=n;
	FILE *fp;
	fp=fopen("./information.txt", "a+");//把新添加的路线输入到文件
	if (fp == NULL)
	{
		printf("文件无法打开\n");
		return;
	}
	fprintf(fp, "%d %d %d\n", start,end,n);
	fprintf(fp, "%d %d %d\n", end,start,n);
	printf("添加成功\n");
	fclose(fp);
}
/*void deleteline(AdjMatrix G)
{
	int start,end;
	PriV(&G);
	printf( "\n\t\t\t\t\t输入起点编号:" );
	scanf( "%d", &start );
	printf( "\t\t\t\t\t输入终点编号:" );
	scanf( "%d", &end );
	FILE *fp;
	fp
}*/
void DFS_All(AdjMatrix *G,int start,int end)//所有路径 
{
	int i,j;	
	G->vex[start].visited =1;
	way[count]=start;
	for(i=1;i<=G->vexnum;i++)
	{		
		if(G->arcs[start][i]!=INFINITY&&G->vex[i].visited==0&&i!=end)
		{
			count++;
			way[count]=i;
			DFS_All(G,i,end);
			G->vex[i].visited=0;
			count--;
			flag=0;
			continue;
		}
		if(G->arcs[start][i]!=INFINITY&&G->vex[i].visited==0&&i==end&&flag==0)
		{
			count++;
			way[count]=end;
			flag=1;
			printf("\n\n");
			printf("\t\t%d ",way[0]);
			printf("%s ",G->vex[way[0]].name);
			for(j=1;j<=count;j++)
			{
				printf("----->");
				printf("\t%d ",way[j]);
				printf("%s ",G->vex[way[j]].name);		
			}
			if(count<min_count){
				min_count=count;
				for(j=1;j<=count;j++)
				{
					min_Way[j]=way[j];	
				}
			}
			count--;
			return;
		}	
	}		
}
void AllPath(AdjMatrix G,int dist[],int path[][MAXVEX]) //所有路径输出 
{
	int i,j,start,end,c=1;
	while ( c==1 )
	{
		 
		printf( "\t\t\t\t\t\t——————所有简单路径查询——————\n" );
		PriV(&G);
		printf( "\n\t\t\t\t\t输入起点编号:" );
				 char x;
		scanf( "%d", &start );
		printf( "\t\t\t\t\t输入终点编号:" );
		while ((x = getchar()) != EOF && x != '\n');
		scanf( "%d", &end );
		if ( start > G.vexnum || start <= 0 || end > G.vexnum || end < 0 || start == end )
			printf( "\t\t\t\t\t\t输入错误!\n\n" );
		else{
			printf( "\n\t\t\t从%s到%s的所有简单路径有:\n", G.vex[start].name, G.vex[end].name );
			DFS_All(&G,start,end); 
			printf( "\n\t\t\t从%s到%s的最短简单路径有:\n", G.vex[start].name, G.vex[end].name );
			printf("\t\t\t\t%d %s",start,G.vex[start].name);
			for(i=1;i<=min_count;i++){
				printf("------>");
				printf("%d",min_Way[i]);
				printf("%s",G.vex[min_Way[i]].name);
			}
		}
		printf("\n"); 
		printf( "\n\t\t\t\t\t\t是否继续查询所有路径?\n" );
		printf( "\t\t\t\t\t\t1:是\n" );
		printf( "\t\t\t\t\t\t0:返回上级菜单\n" );
		scanf( "%d", &c );
	}
	 
}
void Dijkstra(int start,int end,AdjMatrix *G,int dist[MAXVEX],int path[][MAXVEX])//最短路径
{
	int i,j,k,t;
	int mindist;//记录权值、最终输出路径
	for(i=1;i<=G->vexnum;i++)//初始化 
	{
		dist[i]=G->arcs[start][i];//将顶点start到其他各顶点的权值赋给dist[] 
		if(G->arcs[start][i]!=INFINITY)
		   path[i][1]=start;//有路，将起点记录（path[i]记录从源点到Vi最短路径上的各个顶点） 
	}
	path[start][0]=1;//表示顶点start加入到集合S中
	for(i=2;i<=G->vexnum;i++)//寻找各条最短路径 
	{
		mindist=INFINITY;
		for(j=1;j<=G->vexnum;j++)//选择最小权值的路径 
		{
			if(!path[j][0]&&dist[j]<mindist)//j未加入集合S且…… 
			{
				k=j;//当前起点到顶点k权值最小
				mindist=dist[j];
			}
			
			if(mindist==INFINITY) return;//不存在start到其他顶点的路径 
			path[k][0]=1; // 将顶点k加入到集合S中
			for(j=1;j<=G->vexnum;j++)//更新路径
			{
				if(!path[j][0]&&G->arcs[k][j]<INFINITY&&dist[k]+G->arcs[k][j]<dist[j])//……第k行有路且未被选中过的顶点 &&到k的最小权值+k到j的权值<当前到j的最小权值路径 
				{
					dist[j]=dist[k]+G->arcs[k][j];
					t=1;
					while(path[k][t])//记录最新的最短路径 
					{
						path[j][t]=path[k][t];
						t++;
					}
					path[j][t]=k;
					path[j][t+1]=0;
				}
			}
		}
	}
}

void Output( int sight1, int sight2 ,AdjMatrix G,int path[][MAXVEX])// 最短路径输出 
{
	int i=2;
	if ( sight1 != sight2 )
	printf( "\n\t\t\t\t\t\t从%s到%s的最短路径是:\n", G.vex[sight1].name, G.vex[sight2].name );
	printf( "\t\t\t\t\t\t%s", G.vex[sight1].name );
	
	while(path[sight2][i])
	{
		printf("--->%s ",G.vex[path[sight2][i]].name);		
		i++;
	}
	printf( "--->%s", G.vex[sight2].name );
	printf( "\n");
 } 

void ShotPath(AdjMatrix G,int dist[],int path[][MAXVEX]) //最佳路径输出 
{
	int i,j,start,end,c=1;
	while ( c==1 )
	{
		 
		printf( "\t\t\t\t\t\t——————最佳路径查询——————\n" );
		PriV(&G);
		printf( "\n\t\t\t\t\t输入起点编号:" );
		scanf( "%d", &start );
		printf( "\t\t\t\t\t输入终点编号:" );
		scanf( "%d", &end );
		if ( start > G.vexnum || start <= 0 || end > G.vexnum || end < 0 || start == end )
			printf( "\t\t\t\t\t\t输入错误!\n\n" );
		else{
			Dijkstra(start,end,&G,dist,path);
			Output(start,end,G,path);
		}
		printf( "\n\t\t\t\t\t\t是否继续查询最短简单路径?\n" );
		printf( "\t\t\t\t\t\t1:是\n" );
		printf( "\t\t\t\t\t\t0:返回上级菜单\n" );
		scanf( "%d", &c );
	}
	 
}

void SearchPath(AdjMatrix G,int dist[],int path[][MAXVEX]) //查找界面 
{
	int x,c=1;
	while (c==1)
	{
		printf( "\t\t\t1. 所有简单路径\n" );
		printf( "\t\t\t2. 最短简单路径\n" );
		printf( "\t\t\t3. 最佳访问路径\n" );
		printf( "\t\t\t0. 返回主菜单\n" );
		printf( "\t\t\t请选择您需要的操作:" );
		scanf( "%d", &x );
		getchar();
		switch ( x )
		{
			case 1: 
			    
			   AllPath(G,dist,path);
			   break;
			case 2: 
			     // break;
			case 3: 
			     
			   ShotPath(G,dist,path); 
			   break;
			case 0: 
			   c=0;
			   break;
			default:
			   printf( "\t\t\t\t\t\t\t输入信息错误,请重新输入!\n" ); 
			   break;
		}
	 
    } 
}
int user()
{
	char fusername[100], fpassword[10];
	char username[100], password[10];
	FILE* f1 = fopen("users.txt", "r+");
	printf("请输入用户名：");
	scanf("%s", username);
	getchar();
	printf("请输入密码：");
	char c;
	int i = 0;
	while ((c = getchar()) != '\r')
	{
		if (c == '\b')
		{
			i--;
			putchar('\b');
			putchar(' ');
			putchar('\b');
		}
		else
		{
			password[i] = c;
			i++;
			putchar('*');
		}
	}
	printf("\n");
	password[i] = '\0';
	fscanf(f1, "%s %s", fusername, fpassword);
	if ((strcmp(fusername, username) == 0) && (strcmp(fpassword, password)) == 0)
	{
		printf("登陆成功,正在跳转到系统页面！\n");
		getchar();
		system("cls");
		return 1;
	}
	else
	{
		printf("用户名或密码错误\n");
		getchar();
		system("cls");
		user();
		return 0; 
	}
}
int main() 
 {
 	int x,i;//选择 
	int dist[MAXVEX];// 记录各条最短路径长度 
	int	path[MAXVEX][MAXVEX]={0};//记录对应路径上的各顶点
	AdjMatrix G;
	Create(&G);
	Welcome();
	scanf("%d",&i);
	if(i==1)
	{
		user();
		while(1)
		{
			printf("\n");
			printf("\n");
			printf("\n");
			printf( "\t\t\t1. 景区全景浏览\n" );
			printf( "\t\t\t2. 建筑信息查询\n" );
			printf( "\t\t\t3. 路径查询\n" );
			printf( "\t\t\t4. 增加路径\n" );
			printf( "\t\t\t6. 返回上一级菜单\n" );
			printf( "\t\t\t0. 退出系统\n" );
			printf( "\t\t\t请选择您需要的操作:" );
			scanf( "%d", &x );
			getchar();
			switch ( x )
			{
		    	case 1: 
				      
					Map(); 
					break;	
				case 2:
					 
					SearchPlace(G); 
					break;
				case 3: 
					  
					SearchPath(G,dist,path); 
					break;
				case 4:
				     
				    addline(G);
					break; 
				case 6:
					 
					main(); 
				case 0:
					printf( "\n\t\t\t\t\t\t\t" ); 
					exit( 0 );  
				default: 
					  
					printf( "\t\t\t\t\t\t\t输入信息错误,请重新输入!\n" ); 
					break;
			}
		}
	}
	else if(i==2)
	{
		while(1)
		{
			printf( "\t\t\t1. 景区全景浏览\n" );
			printf( "\t\t\t2. 建筑信息查询\n" );
			printf( "\t\t\t3. 路径查询\n" );
			printf( "\t\t\t4. 返回上一级菜单\n" );
			printf( "\t\t\t0. 退出系统\n" );
			printf( "\t\t\t请选择您需要的操作:" );
			scanf( "%d", &x );
			getchar();
			switch ( x )
			{
		    	case 1: 
				      
					Map(); 
					break;	
				case 2:
					 
					SearchPlace(G); 
					break;
				case 3: 
					  
					SearchPath(G,dist,path); 
					break;
				case 4:
					 
					main();
				case 0:
					printf( "\n\t\t\t\t\t\t\t" ); 
					exit( 0 ); 
				default: 
					  
					printf( "\t\t\t\t\t\t\t输入信息错误,请重新输入!\n" ); 
					break;
			}		
		}
	}
	else if(i==3)
	{
		printf( "\n\t\t\t\t\t\t\t" ); 
		exit( 0 ); 
	}
	else
	{
		printf("输入有误，请重新输入！\n");
	}		
}

