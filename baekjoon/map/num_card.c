#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
	int *x = (int *) a;
	int *y = (int *) b;
	if(*x > *y)
		return (1);
	else if(*x < *y)
		return (-1);
	else
		return (0);
}

int binary(int *mc, int n, int left, int right)
{
	int c = (left + right) / 2;
	int m = mc[c];
	if(left <= right)
	{
		if(m > n)
			return (binary(mc, n, left, c - 1));
		else if (m < n)
			return (binary(mc, n, c + 1, right));
		else
			return (1);
	}
	return (0);
}

int main(void)
{
	int n;
	int *nc;
	int m;
	int *mc;
	int *ans;
	scanf("%d",&n);
	nc = (int *) malloc (sizeof(int) * n);
	for(int i = 0; i < n; i++)
		scanf("%d",&nc[i]);
	scanf("%d",&m);
	mc = (int *) malloc (sizeof(int) * m);
	for(int i = 0; i < m; i++)
		scanf("%d",&mc[i]);
	ans = (int *) malloc (sizeof(int) * m);
	qsort(nc, n, sizeof(int), cmp);
	for(int i = 0; i < m; i++)
	{
		if(binary(nc, mc[i], 0, n - 1) == 1)
			ans[i] = 1;
		else
			ans[i] = 0;
	}
	for(int i = 0; i < m; i++)
	{
		if(i < m - 1)
			printf("%d ",ans[i]);
		else
			printf("%d",ans[i]);
	}
	free(nc);
	free(mc);
	free(ans);
	return (0);
}
