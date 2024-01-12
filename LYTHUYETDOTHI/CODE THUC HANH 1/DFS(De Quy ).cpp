#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define max 50
int luuvet[max];
int chuaxet[max];
typedef struct dothi
{
	int n;	
	int a[max][max];
}G;
void readfile(char *filename,G &x)
{
	FILE *f=fopen(filename,"rt");
	if(f==NULL)
	{
		printf("ko doc dc file ");
		exit(0);
	}
	fscanf(f,"%d",&x.n);
	for (int i=0;i<x.n;i++)
		for(int j=0;j<x.n;j++)
			fscanf(f,"%d",&x.a[i][j]);
	fclose(f);
}

void xuat(G x)
{

	for (int i=0;i<x.n;i++)
	{
		for(int j=0;j<x.n;j++)
			printf("%3d ",x.a[i][j]);
	printf("\n");
	}
}
void DFS(int v,G x)
{	
	chuaxet[v]=1;
	int i;
	for(i=0;i<x.n;i++)
		if(x.a[v][i]!=0&&chuaxet[i]==0)
			{	
				luuvet[i]=v;
				DFS(i,x);
			}	
}
void duyetDFS(int s,int f,G x)
{
	int i,b;
	for(i=0;i<x.n;i++)
	{
		luuvet[i]=-1;
		chuaxet[i]=0;
	}
	DFS(s,x);
	if(chuaxet[f]==1)
	{
		printf("duong di tu dinh %d den dinh %d la : \n",s,f);
		i=f;
		do{
			if(i!=b)
				printf("%d <-",i);
			else 
				printf("%d ",i);
			i=luuvet[i];
		}while(i!=-1);
	}
	else
	{
		printf("ko co duong di tu dinh %d den dinh %d \n",s,f);
		
	}
}

int main()
{
	G x;
	int a,b;
	readfile("f:\dothi21.txt",x);
	xuat(x);
	printf("moi nhap dinh dau va dinh cuoi \n");
	scanf("%d%d",&a,&b);
	duyetDFS(a,b,x);
	return 0;
}
