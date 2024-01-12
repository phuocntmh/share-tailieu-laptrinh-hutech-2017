#include <stdio.h>
#include <conio.h>
#include <string.h>

#define MAX_ARR 10
#define fi "CAYKHUNG.TXT"
#define MAX 100
#define Swap(type,a,b) { type tmp=a; a=b; b=tmp; }

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

void Sort(EDGE E[MAX],int nEdge)
{
	for (int i=0;i<nEdge-1;i++)
		for (int j=i+1;j<nEdge;j++)
			if (E[i].value > E[j].value) Swap(EDGE,E[i],E[j]);
}

void Kruskal(GRAPH g)
{
	EDGE ListEdge[MAX_ARR];
	int SumEdge=0;
	for (int i=0;i<g.n;i++)
		for (int j=i+1;j<g.n;j++)
			if (g.a[i][j] > 0)
			{
				ListEdge[SumEdge].u=i;
				ListEdge[SumEdge].v=j;
				ListEdge[SumEdge].value=g.a[i][j];
				SumEdge++;
			}
	Sort(ListEdge,SumEdge);
	int nT=0;
	EDGE T[MAX_ARR];
	int Label[MAX_ARR];
	for (int i=0;i<g.n;i++) Label[i]=i;
	int nowEdge=0;
	while (nT < g.n && nowEdge < SumEdge)
	{
		if (Label[ListEdge[nowEdge].u] != Label[ListEdge[nowEdge].v])
		{
			T[nT]=ListEdge[nowEdge];
			nT++;
			int value=Label[ListEdge[nowEdge].v];
			for (int j=0;j<g.n;j++)
				if (Label[j]==value)
					Label[j]=Label[ListEdge[nowEdge].u];
		}
		nowEdge++;
	}
	if (nT != g.n-1) printf("Do thi khong lien thong.\n");
	else
	{
		int SumVal=0;
		printf("Do thi lien thong.\n");
		printf("Cay khung nho nhat cua do thi la:\n");
		for (int i=0;i<nT;i++)
		{
			printf("(%d,%d), ",T[i].u,T[i].v);
			SumVal+=T[i].value;
		}
		printf("\nTong trong so cua cay khung la: %d\n",SumVal);
	}
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
		Kruskal(g);
	}
	return 0;
}
