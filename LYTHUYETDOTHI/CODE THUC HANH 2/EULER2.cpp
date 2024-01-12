#include <stdio.h>
#include <conio.h>

#define MAX_ARR 10
#define MAX 100
#define fi "TEST2.TXT"

struct GRAPH
{
	int n;
	int a[MAX_ARR][MAX_ARR];
};

struct STACK
{
	int array[MAX];
	int size;
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

void InitStack(STACK &stack)
{
	stack.size=0;
}

void Push(STACK &stack,int value)
{
	if (stack.size+1 <= MAX) return;
	stack.array[stack.size]=value;
	stack.size++;
}

void Euler(int i,GRAPH &g,STACK &stack)
{
	for (int j=0;j<g.n;j++)
		if (g.a[i][j]!=0)
		{
			g.a[i][j]=g.a[j][i]=0;
			Euler(j,g,stack);
			break;
		}
	Push(stack,i);
}

int ShowCycle(GRAPH g)
{
	int i,j,x=0,flag=0;
	for (i=0;i<g.n;i++)
	{
		for (j=0;j<g.n;j++)
			if (g.a[i][j]!=0)
			{
				x=i;
				flag=1;
				break;
			}
		if (flag==1) break;
	}
	GRAPH tmp=g;
	STACK stack;
	InitStack(stack);
	Euler(x,tmp,stack);
	for (i=0;i<tmp.n;i++)
		for (j=0;j<tmp.n;j++)
			if (tmp.a[i][j]!=0) return 0;
	if (stack.array[stack.size-1]!=stack.array[0]) return 0;
	printf("Chu trinh Euler:\n");
	for (i=stack.size-1;i>=0;i--)
		printf("%d ",stack.array[i]+1);
	return 1;
}

int ShowPath(GRAPH g)
{
	int i,j,x=0,flag=0,deg=0;
	for (i=0;i<g.n;i++)
	{
		deg=0;
		for (j=0;j<g.n;j++)
			if (g.a[i][j]!=0) deg++;
		if (deg%2!=0)
		{
			x=i;
			flag=1;
			break;
		}
	}
	if (flag==0) return 0;
	GRAPH tmp=g;
	STACK stack;
	InitStack(stack);
	Euler(x,tmp,stack);
	for (i=0;i<tmp.n;i++)
		for (j=0;j<tmp.n;j++)
			if (tmp.a[i][j]!=0) return 0;
	if (stack.array[stack.size-1]==stack.array[0]) return 0;
	printf("Duong di Euler:\n");
	for (i=stack.size-1;i>=0;i--)
		printf("%d ",stack.array[i]+1);
	return 1;
}

int main()
{
	GRAPH g;
	if (ReadData(fi,g)==1)
	{
		printf("Da lay thong tin do thi thanh cong...\n");
		WriteData(g);
		printf("Bam 1 phim bat ki de kiem tra chu trinh Euler...\n");
		getch();
		if (ShowCycle(g)==0)
		{
			printf("Khong co chu trinh Euler!\n");
			printf("Bam phim bat ki de tim duong di Euler...\n");
			getch();
			if (ShowPath(g)==0)
				printf("Khong co duong di Euler!\n");
			else ShowPath(g);
		}
		else ShowCycle(g);
	}
	return 0;
}
