#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n;
	scanf("%d",&n);
	int *arr;
	int v;
	int count;

	arr = (int *) malloc (sizeof(int) * n);

	for(int i = 0; i < n; i++)
		scanf("%d",&arr[i]);
	scanf("%d",&v);
	count = 0;
	for(int i = 0; i < n; i++)
		if(arr[i] == v)
			count++;
	printf("%d",count);
	free(arr);
	return (0);
}
