#include <stdio.h>
#include <conio.h>
#include <memory.h>

#define MAX_ARR 10
#define fi "DUONGDI1.TXT"
#define oo 10000

struct GRAPH
{
	int n;
	int a[MAX_ARR][MAX_ARR];
};

int Trace[MAX_ARR];
int Next[MAX_ARR][MAX_ARR];
int L[MAX_ARR][MAX_ARR];

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

void Floyd(int s,int f,GRAPH g)
{
	int i,j;
	for (i=0;i<g.n;i++)
	{
		for (j=0;j<g.n;j++)
		{
			if (g.a[i][j]>0)
			{
				Next[i][j]=j;
				L[i][j]=g.a[i][j];
			}
			else
			{
				Next[i][j]=-1;
				L[i][j]=oo;
			}
		}
	}
	for (int k=0;k<g.n;k++)
	{
		for (i=0;i<g.n;i++)
		{
			for (j=0;j<g.n;j++)
			{
				if (L[i][j] > L[i][k]+L[k][j])
				{
					L[i][j]=L[i][k]+L[k][j];
					Next[i][j]=Next[i][k];
				}
			}
		}
	}
	if (Next[s][f]==-1)
		printf("Khong co duong di tu dinh %d den dinh %d.",s,f);
	else
	{
		printf("Duong di ngan nhat tu dinh %d den dinh %d la:\n",s,f);
		printf("\t%d",s);
		int u=s;
		while (Next[u][f]!=f)
		{
			u=Next[u][f];
			printf(" -> %d",u);
		}
		printf(" -> %d",f);
		printf("\n\tVoi tong trong so la: %d\n",L[s][f]);
	}
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
		Floyd(s,f,g);
	}
	return 0;
}
