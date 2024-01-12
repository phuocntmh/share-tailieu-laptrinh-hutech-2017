#include <stdio.h>
#include <conio.h>
#include <memory.h>

#define MAX_ARR 10
#define fi "TEST6.TXT"

struct GRAPH
{
	int n;
	int a[MAX_ARR][MAX_ARR];
};

int Check[MAX_ARR];
int Trace[MAX_ARR];

int ReadData(char filename[20],GRAPH &g)
{
	FILE *f;
	f=fopen(filename,"rt");
	if (f==NULL)
	{
		printf("Khong doc duoc file.\n");
		return 0;
	}
	fscanf(f,"%d",&g.n);
	for (int i=0;i<g.n;i++)
		for (int j=0;j<g.n;j++) 
			fscanf(f,"%d",&g.a[i][j]);
	fclose(f);
	return 1;
}

void OutData(GRAPH g)
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

void DFS(int v,GRAPH g)
{
	Check[v]=1;
	for (int u=0;u<g.n;u++)
		if (g.a[u][v]!=0 && Check[u]==0)
		{
			Trace[u]=v;
			DFS(u,g);
		}
}

void FindPath(int s,int f,GRAPH g)
{
	memset(Trace,-1,sizeof(Trace));
	memset(Check,0,sizeof(Check));
	int ss=s+1, ff=f+1;
	DFS(s,g);
	int i;
	if (Check[f]==1)
	{
		printf("Duong di tu %d den %d la:\n\t",ss,ff);
		i=f;
		printf("%d",f+1);
		while (Trace[i]!=s)
		{
			printf(" <- %d",Trace[i]+1);
			i=Trace[i];
		}
		printf(" <- %d\n",Trace[i]+1);
	}
	else printf("Khong co duong di tu %d den %d.\n",ss,ff);
}

int main()
{
	GRAPH g;
	int s,f;
	if (ReadData(fi,g)==1)
	{
		printf("Da lay thong tin do thi thanh cong.\n");
		OutData(g);
		printf("Bam mot phim bat ki de duyet theo DFS...\n");
		getch();
		printf("Nhap dinh bat dau: ");
		scanf("%d",&s);
		printf("Nhap dinh ket thuc: ");
		scanf("%d",&f);
		FindPath(s-1,f-1,g);
	}
	return 0;
}
