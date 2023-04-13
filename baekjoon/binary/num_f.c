#include <stdio.h>
#include <stdlib.h>

int binary(int *a, int b,int s, int m)
{
	int md = (s + m) / 2;
	if(a[m - 1] < b || a[0] > b)
		return (0);
	else
	{
	if(a[md] > b)
		return binary(a,b,s,md);
	else if(a[md] < b)
		return binary(a,b,md,m);
	else
		return (1);
	}
}


int cmp(const void *a, const void *b)
{
	if(*(int *)a > *(int *)b)
		return (1);
	else if (*(int *)b > *(int *)a)
		return (-1);
	else
		return (0);
}

int main(void)
{
	int n;
	int *a;
	int m;
	int *b;
	int *c;

	scanf("%d",&n);
	a = (int *) malloc (sizeof(int) * n);

	for(int i = 0; i < n; i++)
		scanf("%d",&a[i]);
	scanf("%d",&m);
	b = (int *) malloc (sizeof(int) * m);
	c = (int *) malloc (sizeof(int) * m);
	for(int i = 0; i < m; i++)
	{
		scanf("%d",&b[i]);
		c[i] = 0;
	}
	qsort(a,n,sizeof(int),cmp);
	for(int i = 0; i < m; i++)
	{
		if(binary(a,b[i],0,n) == 1)
			c[i]++;
	}
	for(int i = 0; i < m; i++)
		printf("%d\n",c[i]);
	free(a);
	free(b);
	free(c);
	return (0);
}
