#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b)
{
	if(*(int *)a > *(int *)b)
		return (1);
	else if (*(int *)a < *(int *)b)
		return (-1);
	else return (0);
}

int main(void)
{
	int n;
	scanf("%d",&n);

	int *a;
	a = (int *) malloc (sizeof(int) * n);

	for(int i = 0; i < n; i++)
		scanf("%d",a+i);

	qsort(a,n,sizeof(int),cmp);
	for(int i = 0; i < n; i++)
	{
		if(i != n - 1)
			printf("%d ",a[i]);
		else
			printf("%d",a[i]);
	}
	free(a);
	return (0);
}
