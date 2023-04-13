#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int **a;
	int **b;
	int **sum;
	int n;
	int m;

	scanf("%d %d",&n,&m);
	a = (int **) malloc (sizeof(int *) * n);
	b = (int **) malloc (sizeof(int *) * n);
	for(int i = 0; i < n; i++)
	{
		a[i] = (int *) malloc (sizeof(int) * m);
		for(int j = 0; j < m; j++)
			scanf("%d",&a[i][j]);
	}
	for(int i = 0; i < n; i++)
	{
		b[i] = (int *) malloc (sizeof(int) * m);
		for(int j = 0; j < m; j++)
		{
			scanf("%d",&b[i][j]);
			a[i][j] += b[i][j];
		}
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
			printf("%d ",a[i][j]);
		free(a[i]);
		free(b[i]);
		printf("\n");
	}
	free(a);
	free(b);
	return (0);
}
