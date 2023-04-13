#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n;
	scanf("%d",&n);
	int *x = (int *) malloc (sizeof(int) * n);

	for(int i = 0 ; i < n; i++)
		scanf("%d",&x[i]);
	long long b;
	long long c;
	scanf("%lld %lld",&b,&c);
	long long count = 0;

	for(int i = 0; i < n; i++)
	{
		x[i] -= b;
		count++;
		if(x[i] <= 0)
			continue;
		count += x[i] / c;
		if(x[i] % c >= 1)
			count++;
	}
	printf("%lld\n",count);
	free(x);
	return (0);
}
