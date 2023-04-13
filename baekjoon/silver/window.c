#include <stdio.h>

int main(void)
{
	int n;
	scanf("%d",&n);

	int count = 0;
	for(long long i = 1; i * i <= n; i++)
	{
		count++;
	}
	printf("%d\n",count);
	return (0);
}
