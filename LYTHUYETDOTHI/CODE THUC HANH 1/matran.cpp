#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
#define max 100
//to mau;
void textcolor(WORD color)
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
 
    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
 
    WORD wAttributes = screen_buffer_info.wAttributes;
    color &= 0x000f;
    wAttributes &= 0xfff0;
    wAttributes |= color;
 
    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
//ket thuc ham khai bao to mau;
int luuvet[max],chuaxet[max];
struct G
{
	int n;	
	int a[max][max];
};
void readfile(char *filename,G &x)
{
	FILE *f=fopen(filename,"rt");
	if(f==NULL)
	{
		printf("ko doc dc file");
		exit(0);
	}
	fscanf(f,"%d",&x.n);
	for (int i=0;i<x.n;i++)
		for(int j=0;j<x.n;j++)
			fscanf(f,"%d",&x.a[i][j]);
	fclose(f);
}
void hople(G x)
{
	int i,j;
	for(i=0;i<x.n;i++)
		if(x.a[i][i]!=0)
		{
			cout<<"ma tran ko hop le ";
			return ;
		}
	cout<<"ma tran hop le";
}
void tinhbac(G x)
{
	int bacra=0,bacvao=0;
	for(int i=0;i<x.n;i++)
	{	printf("dinh %d co : \t",i);
		for(int j=0;j<x.n;j++)
		{
			if(x.a[i][j]!=0)
				bacra++;
			if(x.a[j][i]!=0)
				bacvao++;
		}
		printf("bac ra :%d \tbac vao :%d\n",bacra,bacvao);
		bacra=0;bacvao=0;
	}
}
void xuat(G x)
{
	for (int i=0;i<x.n;i++)
	{
		for(int j=0;j<x.n;j++)
		{	
			textcolor(i+1);printf("%3d",x.a[i][j]);
		}
	printf("\n");
	}
}
int KtHuong(G x)
{
	for (int i=0;i<x.n;i++)
		for(int j=0;j<x.n;j++)
			if(x.a[i][j]!=x.a[j][i])
				return 1;
	return 0;
}
void KtTrongSo(G x)
{
	for (int i=0;i<x.n;i++)
		for(int j=0;j<x.n;j++)
			if(x.a[i][j]>1)
			{
				printf("co trong so \n");
				return ;
			}
	cout<<"ko co trong so\n";
	
}
void DinhLt(G x,int nhan[100],int i)
{
	for(int j=0;j<x.n;j++)
		if(x.a[i][j]!=0&&nhan[j]!=nhan[i])
		{
			nhan[j]=nhan[i];
			DinhLt(x,nhan,j);
		}
}
int XetLt(G x)
{
	int Nhan[100];
	int i;
	for(i=0;i<x.n;i++)
		Nhan[i]=0;
	int sotp=0;
	for(i=0;i<x.n;i++)
	{
		if(Nhan[i]==0)
		{
			sotp++;
			Nhan[i]=sotp;
			
		}
		if(Nhan[i]!=0)
			DinhLt(x,Nhan,i);

	}
	return (sotp==1)?1:0;
	printf("so thanh phan lien thong la %d \n",sotp);
	for(i=1;i<=sotp;i++)
	{
		printf("Thanh phan lien thong thu %d gom cac dinh ",i);
		for(int j=0;j<x.n;j++)
		{
			if(Nhan[j]==i)
				printf("%d, ",j);
		}
		printf("\n");
	}
}
int main()
{
	G x;
	int a[max],i,n;
	cout<<"nhap so luong do thi muon doc, luu y dat ten do thi theo cu phap dothi[i] (i la so nguyen bat dau tu 0) \nmoi nhap n: ";
	cin>>n;
	char b[30]="f:\dothi";
	char c[30]=".txt";
	char s[n][30];
	for(i=0;i<n;i++)
	{
		a[i]=i;
		b[strlen(b)]=a[i]+48; b[strlen(b)+1]='\0';
		strcpy(s[i],b);
		strcpy(b,"f:\dothi");
	}
	for(i=0;i<n;i++)
	{
		strcat(s[i],c);	
		readfile(s[i],x);
		xuat(x);
		cout<<"vi tri do thi dang doc : "<<s[i]<<"\n";
		if(KtHuong(x)==1)
		{
			cout<<"do thi co huong ";
			//tinhbac(x);
		}
		else
			cout<<"do thi vo huong ";
		KtTrongSo(x);
		if(XetLt(x)==1)
		{	
			printf("do thi lien thong \n");
		}
		else
			printf("DO THI KHONG LIEN THONG \n");
		//hople(x);
	}
}
