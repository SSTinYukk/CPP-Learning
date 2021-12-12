#include <stdio.h>
#include <string.h>
#define N 100     //待编码字符的个数，即树中叶结点的最大个数
#define M 2*N-1  //树中总的结点数目

typedef struct{
	int weight;
	int parent,lchild,rchild;
}HTNode;  //树中结点的结构

typedef struct {
	char data;     //待编码的字符
	int weight;    //字符的权值
	char code[N];  //字符的编码
}HTCode;

void Select(HTNode ht[],int k,int *s1,int *s2);//ht[1…k]中选择parent为0，并且weight最小的两个结点其序号由指针变量s1,s2指向
void HuffmanCoding(HTNode ht[],HTCode hc[],int n);//构造Huffman树ht，并求出n个字符的编码
void Crtcode(HTCode hc[],int n);//编码 
void Decode(HTNode ht[],HTCode hc[],int n);//译码 

int main(){
	int i,n;
    char s;
    char c;
	HTNode ht[M+1];
	HTCode hc[N+1];
	printf("请输入字符个数：\n");
    scanf("%d",&n);
  
    for(i=1;i<=n;i++)
    {
        printf("请输入字符：\n");
        while ((c = getchar()) != EOF && c != '\n');
        scanf("%c",&hc[i].data);	
        printf("请输入权值：\n");
        scanf("%d",&(hc[i].weight));
    }		
	HuffmanCoding(ht,hc,n);		//构造Huffman树，并形成字符的编码
	printf("\n哈夫曼树构建成功为: \n");
	for(i=1;i<=n;i++)				//输出字符的编码
	printf("%c --- %s\n",hc[i].data,hc[i].code);
	printf("\n");
	Crtcode(hc,n);
	printf("\n");
	Decode(ht,hc,n);
	return 0;
}
//ht[1…k]中选择parent为0，并且weight最小的两个结点其序号由指针变量s1,s2指向
void Select(HTNode ht[],int k,int *s1,int *s2)
{
	
	int i;
	for(i=1;i<=k && ht[i].parent!=0 ;i++);
	*s1=i;
	for(i=1;i<=k;i++)
		if(ht[i].parent==0 && ht[i].weight<ht[*s1].weight) 
			*s1=i;
		for(i=1; i<=k; i++)
			if(ht[i].parent==0 && i!=*s1) 
				break;
			*s2=i;
			for (i=1;i<=k;i++)
				if(ht[i].parent==0 && i!=*s1 && ht[i].weight<ht[*s2].weight) 
					*s2=i;
}

//构造Huffman树ht，并求出n个字符的编码
void HuffmanCoding(HTNode ht[],HTCode hc[],int n){
	
	char cd[N];
	int i,m,c,f,s1,s2,start;
	m=2*n-1;
	for (i=1;i<=m;i++){
		if(i<=n)  
			ht[i].weight=hc[i].weight;
		else
			ht[i].weight=0;
		ht[i].parent=ht[i].lchild=ht[i].rchild=0;
	}
	for (i=n+1;i<=m;i++){
		Select(ht,i-1,&s1,&s2);
		ht[s1].parent=i;   
		ht[s2].parent=i;
		ht[i].lchild=s1;   
		ht[i].rchild=s2;
		ht[i].weight=ht[s1].weight+ht[s2].weight;
	}
	cd[n-1]='\0';
	for (i=1;i<=n;i++){
		start=n-1;
		for (c=i,f=ht[i].parent;f;c=f,f=ht[f].parent)
			if (ht[f].lchild==c) 
				cd[--start]='0';
			else 
				cd[--start]='1';
			strcpy(hc[i].code,&cd[start]);
	}
}

void Crtcode(HTCode hc[],int n)//编码
{
	int i,j=0;
	char str[500],strcode;
	printf("输入字符串:\n"); 
	scanf("%s",str);
	printf("编码后为:\n");
	while(str[j]!='\0')
	{
		i=0;
		while(i<=n)
		{
			if(str[j]==hc[i].data)
			{
				printf("%s",hc[i].code);
			}
			i++;
		}
		j++;
	  }  
  printf("\n"); 
}

void Decode(HTNode ht[],HTCode hc[],int n)//译码
{
	int i,j; 
	char b[200];
	j=0;
	i=2*n-1; 
	printf("输入编码(以'#'为结束标志):\n");  
	scanf("%s",b);
    printf("译码后的字符为:\n");  
	while(b[j]!='#'){
		if(b[j]=='0')
			i=ht[i].lchild;
		else  
		    i=ht[i].rchild;  
		if(ht[i].weight==hc[i].weight){  
		    printf("%c",hc[i].data);
			i=2*n-1;              //每次译码从初始位置开始
		  } 
		 j++;  
	  }  
  printf("\n"); 
}
