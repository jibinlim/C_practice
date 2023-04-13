#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
	if(*(int *)a > *(int *)b)
		return 1;
	else if(*(int *)a < *(int *)b)
		return -1;
	else
		return 0;
}

int main(void)
{
	int n,k;
	scanf("%d %d",&n,&k);

	int *a;
	a = (int *) malloc (sizeof(int) * n);

	for(int i = 0; i < n; i++)
		scanf("%d",a + i);
	qsort(a,n,sizeof(int),cmp);
	printf("%d\n",a[k - 1]);
	free(a);
	return (0);
}
