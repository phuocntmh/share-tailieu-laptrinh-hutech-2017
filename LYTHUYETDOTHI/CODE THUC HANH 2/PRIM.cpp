#include <stdio.h>
#include <conio.h>
#include <string.h>

#define MAX_ARR 10
#define fi "CAYKHUNG.TXT"
#define oo 100000

struct GRAPH
{
	int n;
	int a[MAX_ARR][MAX_ARR];
};

struct EDGE
{
	int u;
	int v;
	int value;
};

int Free[MAX_ARR];
EDGE T[MAX_ARR];

int ReadData(char finame[20],GRAPH &g)
{
	FILE *f;
	f=fopen(finame,"rt");
	if (f==NULL)
	{
		printf("Khong doc duoc file!\n");
		return 0;
	}
	fscanf(f,"%d",&g.n);
	for (int i=0;i<g.n;i++)
		for (int j=0;j<g.n;j++)
			fscanf(f,"%d",&g.a[i][j]);
	fclose(f);
	return 1;
}

void WriteData(GRAPH g)
{
	printf("So dinh cua do thi: %d\n",g.n);
	printf("Ma tran ke cua do thi:\n");
	for (int i=0;i<g.n;i++)
	{
		for (int j=0;j<g.n;j++)
			printf("%d\t",g.a[i][j]);
		printf("\n");
	}
}

void FindConnect(GRAPH g,int label[MAX_ARR],int i)
{
	for (int j=0;j<g.n;j++)
		if (g.a[i][j]!=0 && label[j]!=label[i])
		{
			label[j]=label[i];
			FindConnect(g,label,j);
		}
}

int Connect(GRAPH g)
{
	int label[MAX_ARR];
	memset(label,0,sizeof(label));
	int count=0;
	for (int i=0;i<g.n;i++)
		if (label[i]==0)
		{
			count++;
			label[i]=count;
			FindConnect(g,label,i);
		}
	return count;
}

void Prim(GRAPH g)
{
	if (Connect(g)!=1)
	{
		printf("Do thi khong lien thong, do do khong thuc hien duoc thuat toan Prim...\n");
		return;
	}
	int nT=0;
	memset(Free,0,sizeof(Free));
	Free[0]=1;
	while (nT < g.n-1)
	{
		EDGE MinEdge;
		int MinVal=oo;
		for (int i=0;i<g.n;i++)
			if (Free[i]==1)
			{
				for (int j=0;j<g.n;j++)
					if (Free[j]==0 && g.a[i][j]!=0 && MinVal > g.a[i][j])
					{
						MinEdge.u=i;
						MinEdge.v=j;
						MinEdge.value=g.a[i][j];
						MinVal=g.a[i][j];
					}
			}
		T[nT]=MinEdge;
		nT++;
		Free[MinEdge.v]=1;
	}
	int SumVal=0;
	printf("Cay khung nho nhat cua do thi la:\n");
	for (int i=0;i<nT-1;i++)
	{
		printf("(%d,%d), ",T[i].u,T[i].v);
		SumVal+=T[i].value;
	}
	printf("(%d,%d).\n",T[nT-1].u,T[nT-1].v);
	SumVal+=T[nT-1].value;
	printf("Tong trong so cua cay khung: %d\n",SumVal);
}

int main()
{
	GRAPH g;
	if (ReadData(fi,g)==1)
	{
		printf("Doc thong tin do thi thanh cong...\n");
		WriteData(g);
		printf("Bam phim bat ki de bat dau tim cay khung nho nhat...\n");
		getch();
		Prim(g);
	}
	return 0;
}
