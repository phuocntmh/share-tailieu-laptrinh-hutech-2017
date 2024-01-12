#include <stdio.h>
#include <conio.h>

#define MAX_ARR 10
#define infile "TEST1.TXT"

struct DOTHI
{
	int n;
	int a[MAX_ARR][MAX_ARR];
};

int DocMaTranKe(char tenfile[20],DOTHI &g)
{
	FILE *f;
	f=fopen(tenfile,"rt");
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

void XuatMaTranKe(DOTHI g)
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

int HopLe(DOTHI g)
{
	for (int i=0;i<g.n;i++)
		if (g.a[i][i]!=0) return 0;
	return 1;
}

int KiemTra(DOTHI g)
{
	for (int i=0;i<g.n;i++)
		for (int j=0;j<g.n;j++)
			if (g.a[i][j]!=g.a[j][i]) return 0;
	return 1;
}

int main()
{
	DOTHI g;
	if (DocMaTranKe(infile,g)==1)
	{
		printf("Doc thong tin do thi thanh cong...\n");
		XuatMaTranKe(g);
		printf("Bam phim bat ki de kiem tra do thi...\n");
		getch();
		if (HopLe(g)==1) printf("Ma tran ke hop le.\n");
		else printf("Ma tran ke khong hop le.\n");
		if (HopLe(g)==1) printf("Do thi co huong.\n");
		else printf("Do thi vo huong.\n");
	}
	return 0;
}
