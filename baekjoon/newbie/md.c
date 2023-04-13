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
	int t;
	scanf("%d",&t);
	int *a;
	int *ans;
	int sum;

	a = (int *) malloc (sizeof(int) * 10);
	ans = (int *) malloc (sizeof(int) * t);

	for(int i = 0; i < t; i++)
	{
		sum = 0;
		for(int j = 0; j < 10; j++)
			scanf("%d",a+j);
		qsort(a,10,sizeof(int),cmp);
		for(int j = 1; j < 9; j++)
			sum += a[j];
		ans[i] = sum / 8;
	}
	for(int i = 0; i < t; i++)
		printf("#%d %d\n",i+1,ans[i]);
	free(a);
	free(ans);
	return (0);
}
