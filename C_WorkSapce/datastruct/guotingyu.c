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
  system( "cls" );
  printf( "\t\t\t\t\t\t——————所有简单路径查询——————\n" );
  PriV(&G);
  printf( "\n\t\t\t\t\t输入起点编号:" );
  scanf( "%d", &start );
  printf( "\t\t\t\t\t输入终点编号:" );
  scanf( "%d", &end );
  if ( start > G.vexnum || start <= 0 || end > G.vexnum || end < 0 || start == end )
   printf( "\t\t\t\t\t\t输入错误!\n\n" );
  else{
   printf( "\n\t\t\t从%s到%s的所有简单路径有:\n", G.vex[start].name, G.vex[end].name );
   DFS_All(&G,start,end); 
  }
  printf("\n"); 
  printf( "\n\t\t\t\t\t\t是否继续查询所有路径?\n" );
  printf( "\t\t\t\t\t\t1:是\n" );
  printf( "\t\t\t\t\t\t0:返回上级菜单\n" );
  scanf( "%d", &c );
 }
 system( "cls" );
}