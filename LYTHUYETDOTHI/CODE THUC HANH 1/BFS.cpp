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
struct Q
{
	int size;
	int array[max];
};
int khoitao(Q &q)
{
	q.size=0;	
}
void duavao(Q &q,int vl)
{
	if(q.size>=max)
		return ;
	q.array[q.size]=vl;
	q.size++;
}

void layra(Q &q,int &vl)
{
	if(q.size<=0)
		return;
	vl=q.array[0];
	for(int i=0;i<q.size-1;i++)
		q.array[i]=q.array[i+1];
	q.size--;
}
int ktqueue(Q q)
{
	if(q.size<=0)
		return 1;
	return 0;
}
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

void BFS(int v,G x)
{
	Q q;
	khoitao(q);
	duavao(q,v);
	int dem=0;
	chuaxet[v]=1;
	while(!ktqueue(q))
	{
		layra(q,v);
		for(int i=0;i<x.n;i++)
			if(x.a[v][i]!=0&&chuaxet[i]==0)
			{
				duavao(q,i);
				chuaxet[i]=1;
				luuvet[i]=v;
			}
	}
}
void duyetBFS(int s,int f,G x)
{
	int i,b;
	for( i=0;i<x.n;i++)
	{
		luuvet[i]=-1;
		chuaxet[i]=0;
	}
	BFS(s,x);
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
		printf("ko co duong di tu dinh %d den dinh %d \n",s,f);
}

int main()
{
	G x;
	int a,b;
	readfile("f:\dothi21.txt",x);
	xuat(x);
	printf("moi nhap dinh dau va dinh cuoi \n");
	scanf("%d%d",&a,&b);
	duyetBFS(a,b,x);
	return 0;
}
