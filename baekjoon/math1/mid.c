#include <stdio.h>

int main(void)
{
	int n;
	scanf("%d",&n);

	long long ans = 1;
	long long x = 2;

	for(int i = 1; i <= n; i++)
	{
		x = x * 2 - 1;
	}
	ans = x * x;
	printf("%lld\n",ans);
	return (0);
}
