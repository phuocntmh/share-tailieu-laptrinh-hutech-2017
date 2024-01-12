#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ARR 15
#define MAX 100
#define fi "TEST2.TXT"

struct GRAPH
{
	int n;
	int a[MAX_ARR][MAX_ARR];
};

struct STACK
{
	int top;
	int stack[MAX];
};

int size,i,j;
int array[MAX],trace[MAX]; 
void ReadData(char *filename,GRAPH &g)
{
	FILE *f=fopen(filename,"rt");
	if(f==NULL)
	{
		printf("Khong mo duoc tep.\n");
		exit(0);
	}
	fscanf(f,"%d",&g.n);
	for(i=0;i<g.n;i++)
		for(j=0;j<g.n;j++)
			fscanf(f,"%d",&g.a[i][j]);
	fclose(f);
}

void Output(GRAPH g)
{
	for(i=0;i<g.n;i++)
	{
		for(j=0;j<g.n;j++)
			printf("%3d",g.a[i][j]);
		printf("\n");
	}
}

int Connect(int i,int label[MAX_ARR],GRAPH g)
{
	for(j=0;j<g.n;j++)
		if(g.a[i][j]!=0 && label[j]!=label[i])
		{
			label[j]=label[i];
			Connect(j,label,g);			
		}
}

int CheckConnect(GRAPH g)
{
	int label[MAX_ARR];
	int count=0;
	memset(label,0,sizeof(label));
	for (i=0;i<g.n;i++)
	{
		if (label[i]==0)
		{
			count++;
			label[i]=count;
		}
		if (label[i]!=0) Connect(i,label,g);
	}
	if (count==1) return 1;
	return 0;
}

int BacChan(GRAPH g)
{
	int Bac=0;
	for (i=0;i<g.n;i++)
	{
		for (j=0;j<g.n;j++)
			if(g.a[i][j]!=0) Bac++;
		if (Bac%2!=0) return 0;
		Bac=0;
	}
	return 1;	
}

int BacLe(GRAPH g)
{
	int Bac=0,bacle=0;
	for (i=0;i<g.n;i++)
	{
		for (j=0;j<g.n;j++)
			if(g.a[i][j]!=0) Bac++;
		if (Bac%2!=0) bacle++;
		Bac=0;
	}
	if (bacle==2) return 1;
	return 0;	
}

int BacLe2(GRAPH g)
{
	int Bac=0;
	if (BacLe(g)==1)
	{
		for (i=0;i<g.n;i++)
		{
			for (j=0;j<g.n;j++)
				if(g.a[i][j]!=0) Bac++;
			if (Bac%2!=0) {
			printf("Do thi se co duong di Euler neu bat dau tu dinh %d\n",i+1);
			break;}
			Bac=0;
		}
	}	
}

int DinhDauKe(GRAPH x,int b)
{
	for (int i=0;i<x.n;i++)
		if(x.a[b][i]!=0) return i;
	return -1;
}

void ChuTrinhE2(GRAPH x,int u,STACK s)
{
	s.top=-1;
	s.stack[++s.top]=u;
	while (s.top!=-1)
	{
		int c;
		int b=s.stack[s.top];
		if ((c=DinhDauKe(x,b))!=-1)
		{
			s.stack[++s.top]=c;
			x.a[b][c]=x.a[c][b]=0;
		}
		else
		{
			s.top--;
			printf("<-%d",b+1);
		}
	}
	printf("\n");
}

int main()
{
	GRAPH g; STACK s;
	int chon,u;
	ReadData(fi,g);
	Output(g);
	do
	{
		printf("*******CHUC NANG*******\n");
		printf("1. Kiem tra lien thong.\n");
		printf("2. Kiem tra bac chan.\n");
		printf("3. Kiem tra bac le.\n");
		printf("4. Chu trinh Euler.\n");
		printf("0. Thoat.\n");
		scanf("%d",&chon);
		switch (chon)
		{
			case 1:
				if (CheckConnect(g)==1) printf("Do thi lien thong.\n");
				else printf("Do thi khong lien thong.\n ");
				break; 
			case 2:
				if (BacChan(g)==1) printf("Do thi co tat ca deu la bac chan.\n");
				else printf("Do thi co bac le.\n");
				break;
			case 3:
				if (BacLe(g)==1) printf("Do thi co 2 bac le.\n");
				else printf("Do thi co nhieu hon 2 bac le.\n");
				break;
			case 4:
				if (CheckConnect(g)==0) printf("Do thi khong co chu trinh va duong di Euler.\n");
				else
				{
					if (BacChan(g)==1)
					{
						printf("Do thi co chu trinh Euler.\n");
						printf("Moi nhap dinh bat dau: ");
						scanf("%d",&u);
						ChuTrinhE2(g,u,s);
						}
					else
					{
						if (BacLe(g)==1)
						{
							BacLe2(g);
							printf("Moi nhap dinh bat dau: ");
							scanf("%d",&u);
							ChuTrinhE2(g,u,s);
						}	
						else printf("Do thi ko co chu trinh va duong di Euler.\n");
					}
				}
				break;
		}
	}
	while(chon!=0);
	return 0;
}
