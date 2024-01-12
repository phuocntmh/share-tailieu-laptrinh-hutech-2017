#include<bits/stdc++.h>
using namespace std;
#define max 100
typedef struct dothi
{
	int a[max][max];
	int n;
}G;
typedef struct Stack
{
	int top;
	int stack[max];
}S;
int size,i,j;
int array[max],luuvet[max],chuaxet[max];
void docfile(char *filename,G &g)
{
	FILE *f=fopen(filename,"rt");
	if(f==NULL)
	{
		printf("ko doc dc file");
		exit(0);
	}
	fscanf(f,"%d",&g.n);
	for(i=0;i<g.n;i++)
		for(j=0;j<g.n;j++)
			fscanf(f,"%d",&g.a[i][j]);
	fclose(f);
}
void xuat(G g)
{
	for(i=0;i<g.n;i++)
	{
		for(j=0;j<g.n;j++)
			printf("%3d",g.a[i][j]);
	printf("\n");
	}
}
int lienthong(int i,int nhan[max],G g)
{
	for(j=0;j<g.n;j++)
			if(g.a[i][j]!=0&&nhan[j]!=nhan[i])
				{
					nhan[j]=nhan[i];
					lienthong(j,nhan,g);			
				}
}
int ktlienthong(G g)
{
	int nhan[max];
	int sotp=0;
	for(i=0;i<g.n;i++)
			nhan[i]=0;
	for(i=0;i<g.n;i++)
	{
		if(nhan[i]==0)
		{
			sotp++;
			nhan[i]=sotp;
		}
		if(nhan[i]!=0)
			lienthong(i,nhan,g);
	}
	if(sotp==1)
		return 1;
	return 0;
}
int Bacchan(G g)
{
	int Bac=0;
	for( i=0;i<g.n;i++)
	{
		for( j=0;j<g.n;j++)
			if(g.a[i][j]!=0)
				Bac++;
		if(Bac%2!=0)
			return 0;
		Bac=0;
	}
	return 1;	
}
int Bacle(G g)
{
	int Bac=0,bacle=0;
	for( i=0;i<g.n;i++)
	{
		for( j=0;j<g.n;j++)
			if(g.a[i][j]!=0)
				Bac++;
		if(Bac%2!=0)
			bacle++;
		Bac=0;
	}
	if(bacle==2)
		return 1;
	return 0;	
}
int bacle2(G g)
{
	int Bac=0;
	if(Bacle(g)==1)
	{
		for( i=0;i<g.n;i++)
		{
			for( j=0;j<g.n;j++)
				if(g.a[i][j]!=0)
					Bac++;
			if(Bac%2!=0)
				printf("do thi se co duong di Euler neu bat dau tu dinh %d\n",i);
			Bac=0;
		}
	}	
}
int dinhdauke(G x,int b)
{
	for(int i=0;i<x.n;i++)
		if(x.a[b][i]!=0)
			return i;
	return -1;
}
void chutrinhe2(G x,int u,S s)
{
	 s.top=-1;
	 s.stack[++s.top]=u;
	 while(s.top!=-1)
	{
		int c;
		int b= s.stack[s.top];
		if((c=dinhdauke(x,b))!=-1)
		{
			s.stack[++s.top]=c;
			x.a[b][c]=x.a[c][b]=0;
		}
		else
		{
			s.top--;
			printf("<-%d",b);
		}
	}
	printf("\n");
}

int main()
{
	G g; S s;
	int chon,u;
	docfile("f:\matran1.txt",g);
	xuat(g);
	do
	{
		printf("*******MENU*******\n");
		printf("1.Kt lien thong \n");
		printf("2.Kt bac chan \n");
		printf("3.Kt bac le \n");
		printf("4.Chu trinh Euler \n");
		printf("0.Thoat \n");
		cin>>chon;
		switch(chon)
		{
			case 1:
				if(ktlienthong(g)==1)
					printf("do thi lien thong \n");
				else
					printf("do thi ko lien thong \n ");
				break; 
			case 2:
				if(Bacchan(g)==1)
					printf("do thi co tat ca deu la bac chan \n");
				else
					printf("do thi co bac le \n");
				break;
			case 3:
				if(Bacle(g)==1)
					printf("do thi co 2 bac le \n");
				else
					printf("do thi co nhieu hon 2 bac le \n");
				break;
			case 4:
				if(ktlienthong(g)==0)
					printf("do thi ko co chu trinh va duong di Euler \n");
				else
				{
					if(Bacchan(g)==1)
						{
							printf("do thi co chu trinh euler \n");
							printf("moi nhap dinh bat dau \n");
							cin>>u;
							chutrinhe2(g,u,s);
						}
					else
						{
						if(Bacle(g)==1)
						{
							bacle2(g);
							printf("moi nhap dinh bat dau \n");
							cin>>u;
							chutrinhe2(g,u,s);
						}	
						else
							printf("do thi ko co chu trinh va duong di Euler \n");
						}
				}
					break;
		}
	}while(chon!=0);
}
