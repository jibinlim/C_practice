#include <stdio.h>

int main(void)
{
	unsigned long long dp[91];

	int n;
	scanf("%d",&n);

	dp[0] = 0;
	dp[1] = 1;

	for(int i = 2; i <= n; i++)
		dp[i] = dp[i - 2] + dp [i - 1];

	printf("%lld",dp[n]);
	return (0);
}
