#include <stdio.h>
#include <stdlib.h>

void sol(int **b, int x,int y, int n)
{
	int f = b[x][y];
	int flag = 1;

	for(int i = x; i < x + n; i++)
		for(int j = y; j < y + n; j++)
			if(f != b[i][j])
				flag = 0;
	if(flag == 1)
		printf("%d", f);
	else
	{
		printf("(");
		sol(b, x, y, n / 2);
		sol(b, x, y + n / 2, n / 2);
		sol(b, x + n / 2, y, n / 2);
		sol(b, x + n / 2, y + n / 2, n / 2);
		printf(")");
	}
}

int main(void)
{
	int n;
	scanf("%d",&n);

	int **b;

	b = (int **) malloc (sizeof(int *) * (n + 1));
	for(int i = 0; i < n; i++)
	{
		b[i] = (int *) malloc (sizeof(int) * (n + 1));
		for(int j = 0; j < n ; j++)
			scanf("%1d",&b[i][j]);
	}

	sol(b,0,0,n);

	for(int i = 0; i < n ; i++)
		free(b[i]);
	free(b);
	return (0);
}
