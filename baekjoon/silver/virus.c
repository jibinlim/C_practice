#include <stdio.h>
#include <stdlib.h>

int count = 0;
int n,c;
int v[100] = {0,};

void solve(int x[100][100], int t)
{
	for(int i = 0; i < c; i++)
	{
		if(x[t][i] == 1)
		{
			if(v[i] == 0)
				count++;
			v[i] = 1;
			x[t][i] = 0;
			x[i][t] = 0;
			solve(x,i);
		}
	}
}

int main(void)
{
	scanf("%d %d",&c,&n);
	int *a,*b;
	int x[100][100] = {0,};
	a = (int *) malloc (sizeof(int) * n);
	b = (int *) malloc (sizeof(int) * n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d %d",a+i,b+i);
		x[a[i] - 1][b[i] - 1] = 1;
		x[b[i] - 1][a[i] - 1] = 1;
	}
	v[0] = 1;
	solve(x,0);
	free(a);
	free(b);
	printf("%d",count);
	return (0);
}
