#include<bits/stdc++.h>
using namespace std;
#define max 50
#define vocuc 1000
int luuvet[max];
int chuaxet[max];
int minroad[max];
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
struct S
{
	int stack[max];
	int top;
};
void khoitaos(S &s)
{
	s.top=0;
}
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
void duavaos(S &s, int vl)
{
	if(s.top>=max)
		return;
	s.stack[s.top]=vl;
	s.top++;
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
void timduongdi(int i, G &x,S &s)
{
	for(int j=0;j<x.n;j++)
		if(x.a[i][j]!=0)
		{
			x.a[i][j]=x.a[j][i]=0;
			timduongdi(j,x,s);
		}
	duavaos(s,i);
}
int chutrinhe(G x)
{
	int i,j,c,bac=0,flag=0;
	printf("nhap diem bat dau :");
	scanf("%d",&c);
	for(i=0;i<x.n;i++)
	{
		for(j=0;j<x.n;j++)
			if(x.a[i][j]!=0)
				bac++;
		if(bac%2!=0)
		{
			flag=1;
			break;
		}	
		bac=0;
	}
	if(flag==1)
		return 0;
	G t=x;
	S s;
	khoitaos(s);
	timduongdi(c,t,s);
	for(i=0;i<t.n;i++)
	{
		for(j=0;j<t.n;j++)
		{
			if(t.a[i][j]!=0)
				return 0;
		}
	}
	if(s.stack[s.top-1]!=s.stack[0])
		return 0;
	printf("\n chu trinh Euler\n");
	for(i=s.top-1;i>=0;i--)
		printf("%3d",s.stack[i]);
	return 1;
}
int duongdie(G x)
{
	int i,j,bac=0,bacle=0,b,flag=0;
	printf("nhap diem bat dau :");
	cin>>b;
	for(i=0;i<x.n;i++)
	{
		for(j=0;j<x.n;j++)
			if(x.a[i][j]!=0)
				bac++;
		if(bac%2!=0)
			bacle++;
		bac=0;
	}
		if(bacle!=2&&bacle!=0)
			return 0;
		G t=x;
		S s;
		khoitaos(s);
		timduongdi(b,t,s);
		for(i=0;i<t.n;i++)
			for(j=0;j<t.n;j++)
			{
				if(t.a[i][j]!=0)
					return 0;
			}
		if(s.stack[s.top-1]==s.stack[0])
			return 0;
		printf("duong di Euler \n");
		for(i=s.top-1;i>=0;i--)
			printf("%3d",s.stack[i]);
		return 1;				
	
}
int ktqueue(Q q)
{
	if(q.size<=0)
		return 1;
	return 0;
}
void BFS1(int v,G x)
{
	Q q;
	khoitao(q);
	duavao(q,v);
	int dem=0;
	chuaxet[v]=1;
	while(!ktqueue(q))
	{
		layra(q,v);
			printf("%5d ",v);
		for(int i=0;i<x.n;i++)
			if(x.a[v][i]!=0&&chuaxet[i]==0)
			{
				duavao(q,i);
				chuaxet[i]=1;
				luuvet[i]=v;
			}
	}
	printf("\n");
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
	int i;
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
				printf("%d <-",i);
				i=luuvet[i];
		}while(i!=-1);
	}
	else
	{
		printf("ko co duong di tu dinh %d den dinh %d \n",s,f);
		
	}
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
void DFS(int v,G x)
{	
	chuaxet[v]=1;
	int i;
	for(i=0;i<x.n;i++)
		{
			if(x.a[v][i]!=0&&chuaxet[i]==0)
				{	
					luuvet[i]=v;
					DFS(i,x);
				}
		}
	
}
void duyetDFS(int s,int f,G x)
{
	int i;
	int b;
	for(i=0;i<x.n;i++)
	{
		luuvet[i]=-1;
		chuaxet[i]=0;
	}
	DFS(s,x);
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
	{
		printf("ko co duong di tu dinh %d den dinh %d \n",s,f);
		
	}
}
int Minroad(G x)
{
	int li=-1;
	float p=vocuc;
	for(int i=0;i<x.n;i++)
	{
		if(chuaxet[i]==0&&minroad[i]<p)
		{
			p=minroad[i];
			li=i;
		}
	}
	return li;
}
void updateroad(int u, G x)
{
	chuaxet[u]=1;
	for(int v=0;v<x.n;v++)
		if(chuaxet[v]==0&&x.a[u][v]>0&&x.a[u][v]<vocuc)
			if(minroad[v]>minroad[u]+x.a[u][v])
				{
					minroad[v]=minroad[u]+x.a[u][v];
					luuvet[v]=u;
				}
	
}
void Dijkstra(int s,int f, G x)
{
	int i;
	for(i=0;i<x.n;i++)
	{
		chuaxet[i]=0;
		minroad[i]=vocuc;
		luuvet[i]=-1;
	}
	minroad[s]=0;
	while(chuaxet[f]==0)
	{
		int u=Minroad(x);
		if(u==-1)
		break;
		updateroad(u,x);
	}
	if(chuaxet[f]==1)
	{
		printf("duong di ngan nhat tu dinh %d den dinh %d la:\n",s,f);
		i=f;
		printf("%d",f);
		while(luuvet[i]!=s)
		{
			printf("<-%d",luuvet[i]);
			i=luuvet[i];
		}
		printf("<-%d",luuvet[i]);
		printf("\tvoi do dai la %d\n",minroad[f]);
	}
	else
	{
		printf("ko co duong di tu dinh %d  den dinh %d\n",s,f);
		
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
			printf("%d,",b);
		}
	}
	printf("\n");
}
int main()
{
	G x;
	Q q;
	S s;
	int chon;
	int a,b,c,u;
	readfile("f:\matran1234.txt",x);
	xuat(x);
	do{
		printf("\n1.Kiem tra duong di tu 1 dinh den tat ca dinh con lai \n");
		printf("2.Duyet BFS \n");
		printf("3.Duyet DFS \n");
		printf("4.Euler \n");
		printf("5.Tim duong di ngan nhat \n");
		printf("6.Chu trinh e moi \n");
		printf("0.Thoat \n");
		scanf("%d",&chon);
		switch(chon)
		{
			case 1: 
				printf("moi nhap dinh bat dau : \n");
				scanf("%d",&a);
				BFS1(a,x);
				break;
			case 2:
				printf("moi nhap dinh dau va dinh cuoi \n");
				scanf("%d%d",&a,&b);
				duyetBFS(a,b,x);
				break;
			case 3:
				printf("moi nhap dinh dau va dinh cuoi \n");
				scanf("%d%d",&a,&b);
				duyetDFS(a,b,x);
				break;
			case 4:
				if(!chutrinhe(x))
				{
					printf("ko co chu trinh e trong do thi cua ban \n");
					if(!duongdie(x))
					{
						printf("ko co duong di e trong do thi \	");
					}
				}
				break;
			case 5: 
				printf("moi nhap dinh dau va dinh cuoi \n");
				scanf("%d%d",&a,&b);
				Dijkstra(a,b,x);
				break;
			case 6:
				printf("moi nhap dinh bat dau: \n");
				scanf("%d",&u);
				chutrinhe2(x,u,s);
				xuat(x);
				break;
		}
	}while(chon!=0);
	return 0;
}
