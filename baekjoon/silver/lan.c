#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	int n,k;
	scanf("%d %d",&k,&n);
	int *x;
	unsigned long long sum = 0;
	unsigned long long start = 0, mid, end = 1;

	x = (int *) malloc (sizeof(int) * k);

	for(int i = 0; i < k; i++)
	{
		scanf("%d",x + i);
		if(end < x[i])
			end = x[i];
	}
	while(start <= end)
	{
		mid = (start + end) / 2;
		if(mid == 0)
			break;
		for(int i = 0; i < k; i++)
			sum += x[i] / mid;
		if(sum < n)
			end = mid - 1;
		else
			start = mid + 1;
		sum = 0;
	}
	printf("%llu",end);
	free(x);
	return (0);
}
