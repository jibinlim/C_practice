#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n,k;

	int *a;
	int *sum;
	int max = -2147483548;

	scanf("%d %d",&n,&k);

	a = (int *) malloc (sizeof(int) * n);
	sum = (int *) malloc (sizeof(int) * n + 1);

	sum[0] = 0;
	for(int i = 0; i < n; i++)
	{
		scanf("%d",a + i);
		sum[i + 1] = sum[i] +a [i];
	}
	for(int i = k; i < n + 1; i++)
		if(sum[i] - sum[i - k] > max)
			max = sum[i] - sum[i - k];

	printf("%d",max);
	free(a);
	free(sum);
	return (0);
}
