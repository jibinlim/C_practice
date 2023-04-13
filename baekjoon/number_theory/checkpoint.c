#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a,const void *b)
{
	if(*(int *)a > *(int *)b)
		return (1);
	else if(*(int *)a < *(int *)b)
		return (-1);
	else
		return (0);
}

int main(void)
{
	int n;
	scanf("%d",&n);
	int *a;
	int i;
	a = (int *) malloc (sizeof(int) * n);
	for(i = 0; i < n; i++)
		scanf("%d",a+i);
	int *m;
	int x;
	m = (int *) malloc (sizeof(int) * 500);
	int j = 0;
	int t = 2;
	qsort(a,n,sizeof(int),cmp);
	while(t <= a[1])
	{
		x = a[0] % t;
		for(i = 1; i < n; i++)
			if(a[i] % t != x)
				break;
		if(i == n)
		{
			m[j] = t;
			j++;
		}

		t++;
	}
	for(int i = 0; i < j; i++)
		printf("%d ",m[i]);
	free(m);
	free(a);
	return (0);
}
