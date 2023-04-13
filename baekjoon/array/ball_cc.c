#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n,m;
	scanf("%d %d",&n,&m);

	int *b;
	int *a;
	b = (int *) malloc (sizeof(int) * (n + 1));
	a = (int *) malloc (sizeof(int) * (n + 1));
	for(int i = 1; i <= n; i++)
	{
		b[i] = i;
		a[i] = i;
	}
	for(int i = 0; i < m; i++)
	{
		int begin,mid,end;
		scanf("%d %d %d",&begin,&end,&mid);
		for(int j = 1; j <= n; j++)
			a[j] = b[j];
		for(int j = begin; j <= end; j++)
		{
			b[j] = a[mid];
			mid++;
			if(mid > end)
				mid = begin;
		}
	}
	for(int i = 1; i <= n; i++)
		printf("%d ",b[i]);
	free(b);
	free(a);
	return (0);
}
