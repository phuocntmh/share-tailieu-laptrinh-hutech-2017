#include<stdio.h>
#include<conio.h>
#define MAX 10
#define inputfile "TEST2.TXT"

typedef struct GRAPH{
	int n;
	int a[MAX][MAX];
	
}DOTHI;

int DocMaTranKe(char test[100],DOTHI&g)
{
	FILE* f;
	f = fopen(test,"rt");
	if(f==NULL)
	{
		printf("Khong mo duoc file\n");
		return 0;
	}
	fscanf(f,"%d",&g.n);
	int i,j;
	for (i=0;i<g.n;i++)
	{
		for(j=0;j<g.n;j++)
		{
			fscanf(f,"%d",&g.a[i][j]);
		}
	}
	fclose(f);
	return 1;
}
void XuatMaTranKe(DOTHI g)
{
	printf("So dinh cua do thi la %d\n\n",g.n);
	printf("Ma tran ke cua do thi la\n");
	for(int i=0;i<g.n;i++)
	{
		printf("\t");
		for(int j=0;j<g.n;j++)
		{
			printf("%d\t",g.a[i][j]);
		}
		printf("\n");
	}
}

struct STACK
{
	int array[100];
	int size;
};
void khoitaoStack(STACK &stack)
{
	stack.size = 0;
}
void DayGiaTriVaoStack(STACK &stack, int value)
{
	if(stack.size +1 >= 100)
	return;
	stack.array[stack.size] = value;
	stack.size++;
}
void TimDuongDi(int i,DOTHI &g,STACK & stack)
{
	for (int j=0;j<g.n;j++)
	{
		if(g.a[i][j]!=0)
		{
			g.a[i][j] = g.a[j][i] = 0;
			TimDuongDi(j,g,stack);
		}
	}
	DayGiaTriVaoStack(stack,i);
}
int KiemTraChuTrinhEuler(DOTHI g)
{
	int i,j;
	int x = 0;
	int flag = 0;
	for(i=0;i<g.n;i++)
	{
		for(j=0;j<g.n;j++)
		{
			if(g.a[i][j]!=0)
			{
				x = i;
				flag = 1;
				break;
			}
		}
		if(flag == 1)
			break;
	}
	DOTHI temp =g;
	STACK stack;
	khoitaoStack(stack);
	TimDuongDi(x,temp,stack);
	for(i=0;i<temp.n;i++)
	{
		for(j=0;j<temp.n;j++)
		{
			if(temp.a[i][j]!=0)
				return 0;
		}
	}
	if(stack.array[stack.size - 1]!= stack.array[0])
		return 0;
	printf("\n Chu Trinh Euler: \n");
	for(i=stack.size - 1;i>=0;i--)
		printf("%d\t",stack.array[i] +1);
	return 1;
}
int KiemTraDuongDiEuler(DOTHI g)
{
	int i,j;
	int x=0;
	int flag =0;
	int bac = 0;
	for(i=0;i<g.n;i++)
	{
		bac=0;
		for(j=0;j<g.n;j++)
		{
			if(g.a[i][j]!=0)
			{
				bac++;
			}
		}
		if(bac%2 !=0)
		{
			x=i;
			flag = 1;
			break;
		}
	}
	if(flag == 0)
		return 0;
	DOTHI temp = g;
	STACK stack;
	khoitaoStack(stack);
	TimDuongDi(x,temp,stack);
	for(i=0;i<temp.n;i++)
	{
		for(j=0;j<temp.n;j++)
		{
			if(temp.a[i][j]!=0)
				return 0;
		}
	}
	if(stack.array[stack.size -1]== stack.array[0])
		return 0;
	printf("\nDuong di Euler: ");
	for(i= stack.size-1;i>=0;i--)
		printf("%d\t",stack.array[i]+1);
	return 1;
}
int main()
{
	DOTHI g;
	//clrscr();
	if(DocMaTranKe(inputfile,g)==1)
	{
		printf("\nDa lay thong tin do thi tu file thanh cong.\n\n");
		XuatMaTranKe(g);
		printf("\nBam 1 phim bat ki de tien hanh kiem tra do thi....\n\n");
		getch();
		if(!KiemTraChuTrinhEuler(g))
		{
			printf("Khong co chu trinh Euler trong do thi cua ban\n");
			printf("Bam 1 phim bat ki de xet tim duong di euler...\n");
			getch();
			if(!KiemTraDuongDiEuler(g))
			{
				printf("Khong co duong di euler trong di thi cua ban\n");
			}
		}
	}
	getch();
}
