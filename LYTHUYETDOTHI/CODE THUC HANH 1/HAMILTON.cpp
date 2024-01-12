#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

#define max 10
#define fi "TEST.TXT"

struct DOTHI
{
	int n;
	int a[max][max];
};
int b[max],c[max];

void Init(DOTHI &g)
{
    FILE *f=fopen(fi,"r");
    if (f==NULL)
    {
    	printf("Khong mo duoc tep.\n");
    	exit(0);
	}
    fscanf(f,"%d",&g.n);
    for (int k=0;k<g.n;k++)
        for (int j=0;j<g.n;j++)
            fscanf(f,"%d",&g.a[k][j]);
    memset(b,0,sizeof(b));
    c[0]=0; b[0]=1; //xuat phat tu dinh 0
}

void ShowPath(DOTHI g)
{
    for (int k=0;k<g.n;k++) printf("%d\t",c[k]+1);
    printf("%d\n",c[0]+1);
}

void Hamilton(DOTHI g,int j)
{
    for (int k=0;k<g.n;k++)
        if (b[k]==0 && g.a[c[j-1]][k])
        {
            b[k]=1; c[j]=k;
            if (j==g.n-1)
                if (g.a[c[j]][c[0]]) ShowPath(g);
            else Hamilton(g,j+1);
            b[k]=0;
        }
}

int main()
{
	DOTHI g;
    Init(g);
    Hamilton(g,1);
    return 0;
}
