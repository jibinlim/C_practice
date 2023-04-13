#include <stdio.h>
#include <stdlib.h>

int cmp(const int *a,const int *b)
{
	if(*a < *b)
		return (-1);
	else if(*a > *b)
		return (1);
	else
		return (0);
}

int main(void)
{
	int n;
	scanf("%d",&n);

	int *a;

	a = (int *) malloc (sizeof(int) * n);

	for(int i = 0 ; i < n; i++)
		scanf("%d",&a[i]);
	qsort(a,n,sizeof(int),(int(*)(const void *, const void *))cmp);
	for(int i = 0; i < n; i++)
		printf("%d\n",a[i]);
	free(a);
	return (0);
}
