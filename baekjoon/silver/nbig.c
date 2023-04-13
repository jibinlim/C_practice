#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n;
	scanf("%d",&n);

	int **p;
	int max = -2147483647;
	int y = 0;
	int *a;
	int i = 0 ,j = 0;
	int n_t = n;

	a = (int *) malloc (sizeof(int) * n);
	p = (int **) malloc (sizeof(int *) * n);
	for(i = 0; i < n; i++)
	{
		p[i] = (int *) malloc (sizeof(int) * n);
		for(j = 0; j < n; j++)
		{
			scanf("%d",&p[i][j]);
			if(max < p[i][j])
			{
				max = p[i][j];
				y = j;
			}
		}
		a[i] = j - 1;
	}
	a[y]--;
	n--;

	while(n > 0)
	{
		max = -2147483647;
		for(i = 0; i < n_t; i++)
		{
			if(max <= p[a[i]][i])
			{
				max = p[a[i]][i];
				y = i;
			}
		}
		a[y]--;
		n--;
	}
	printf("%d",max);
	for(i = 0; i < n_t; i++)
		free(p[i]);
	free(p);
	free(a);
	return (0);
}
