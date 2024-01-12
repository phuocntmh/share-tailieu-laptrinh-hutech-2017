#include <stdio.h>
#include <conio.h>
#include <memory.h>

#define MAX_ARR 10
#define fi "DUONGDI.TXT"
#define oo 10000

struct GRAPH
{
	int n;
	int a[MAX_ARR][MAX_ARR];
};

int Trace[MAX_ARR];
int Free[MAX_ARR];
int Path[MAX_ARR];

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

int FindMinPath(GRAPH g)
{
	int li=-1; float p=oo;
	for (int i=0;i<g.n;i++)	
		if (Free[i]==0 && Path[i]<p)
		{
			p=Path[i];
			li=i;
		}
	return li;
}

void UpdatePath(int u,GRAPH g)
{
	Free[u]=1;
	for (int v=0;v<g.n;v++)
	{
		if (Free[v]==0 && g.a[u][v]>0 && g.a[u][v]<oo)
			if (Path[v]>Path[u]+g.a[u][v])
			{
				Path[v]=Path[u]+g.a[u][v];
				Trace[v]=u;
			}
	}
}

void Dijkstra(int s,int f,GRAPH g)
{
	memset(Free,0,sizeof(Free));
	memset(Path,oo,sizeof(Path));
	memset(Trace,-1,sizeof(Trace));
	Path[s]=0;
	while (Free[f]==0)
	{
		int u=FindMinPath(g);
		if (u==-1) break;
		UpdatePath(u,g);
	}
	if (Free[f]==1)
	{
		printf("Duong di ngan nhat tu dinh %d den dinh %d la:\n",s,f);
		int i=f;
		printf("%d ",f);
		while (Trace[i]!=s)
		{
			printf("<- %d ",Trace[i]);
			i=Trace[i];
		}
		printf("<- %d\n",Trace[i]);
		printf("\tVoi do dai la: %d\n",Path[f]);		
	}
	else
		printf("Khong co duong di tu dinh %d den dinh %d.",s,f);
}

int main()
{
	GRAPH g;
	if (ReadData(fi,g)==1)
	{
		printf("Doc thong tin do thi thanh cong...\n");
		WriteData(g);
		printf("Bam phim bat ki de bat dau tim duong di ngan nhat...\n");
		getch();
		int s,f;
		printf("Nhap dinh bat dau: ");
		scanf("%d",&s);
		printf("Nhap dinh ket thuc: ");
		scanf("%d",&f);
		Dijkstra(s,f,g);
	}
	return 0;
}
