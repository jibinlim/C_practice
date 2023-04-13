#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
	if(*(int *)a > *(int *)b)
		return (1);
	else if (*(int *)a < *(int *)b)
		return (-1);
	else
		return (0);
}

int main(void)
{
	int n;
	scanf("%d",&n);
	int *a;
	int *sum;
	int ans = 0;

	a = (int *) malloc (sizeof(int) * n);
	sum = (int *) malloc (sizeof(int) * (n + 1));
	sum[0] = 0;
	for(int i = 0; i < n; i++)
		scanf("%d" ,a+i);
	qsort(a,n,sizeof(int),cmp);
	for(int i = 1; i <= n; i++)
	{
		sum[i] = sum[i - 1] + a[i - 1];
		ans += sum[i];
	}
	free(a);
	free(sum);
	printf("%d",ans);
	return (0);
}
