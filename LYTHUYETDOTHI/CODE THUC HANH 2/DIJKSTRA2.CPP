#include<bits/stdc++.h>
using namespace std;
#define max 50
#define vocuc 10000
int luuvet[max];
int chuaxet[max];
int dis[max];
int chuaxetdinh[max];
int i,j;
typedef struct dothi
{
	int n;	
	int a[max][max];
}G;
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
void khoitao(G x)
{
	for(i=0;i<x.n;i++)
		{
			luuvet[i]=-1;
			chuaxet[i]=0;
			dis[i]=vocuc;
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

int upmin(G x)
{
	int min=vocuc,vtmin=-1;
	for(i=0;i<x.n;i++)
		if(min>dis[i]&&chuaxet[i]==0)	
		{
				min=dis[i];
				vtmin=i;
		}
	return vtmin;	
}
void lanvet(int s,int f)
{
	if(s==f)
		return;
	else
	{
		lanvet(s,luuvet[f]);
		printf("->%d",f);
	}
}
void dijstra(int S,G x,int f)
{	
	khoitao(x);
	int s=S;
	dis[s]=0;
	do
	{
		chuaxet[s]=1;
		for(i=0;i<x.n;i++)
		{
			if(x.a[s][i]>0&&chuaxet[i]==0)
				if(dis[s]+x.a[s][i]<dis[i])
					{
						dis[i]=dis[s]+x.a[s][i];
						luuvet[i]=s;
					}	
		}
		s=upmin(x);
	}while(s!=f);
	printf("%d",S);
	lanvet(S,f);
	printf("\t voi tong gia tri la : %d",dis[f]);	
}
int main()
{
	G x;
	int s,f;
	readfile("DUONGDI.TXT",x);
	xuat(x);
	if(ktlienthong(x)==1)
	{
		printf("moi nhap diem dau va diem cuoi \n");
		cin>>s>>f;
		dijstra(s,x,f);
	}
	else
		printf("do thi ko lien thong \n");
	return 0;
}
