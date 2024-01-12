#include <stdio.h>
#include <conio.h>
#include <string.h>

#define MAX_ARR 10
#define fi "TEST1.TXT"

struct GRAPH
{
	int n;
	int a[MAX_ARR][MAX_ARR];
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

void FindConnect(GRAPH g,int label[MAX_ARR],int i)
{
	for (int j=0;j<g.n;j++)
		if (g.a[i][j]!=0 && label[j]!=label[i])
		{
			label[j]=label[i];
			FindConnect(g,label,j);
		}
}

void Connect(GRAPH g)
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
	printf("So thanh phan lien thong la: %d\n",count);
	for (int i=1;i<=count;i++)
	{
		printf("Thanh phan lien thong thu %d gom cac dinh: ",i);
		for (int j=0;j<g.n;j++)
			if (label[j]==i) printf("%d\t",j);
		printf("\n");
	}
}

int main()
{
	GRAPH g;
	if (ReadData(fi,g)==1)
	{
		printf("Doc thong tin do thi thanh cong...\n");
		WriteData(g);
		printf("Bam phim bat ki de bat dau xet tinh lien thong...\n");
		getch();
		Connect(g);
	}
	return 0;
}
