#include <stdio.h>

int main(void)
{
	unsigned int n;
	scanf("%d",&n);

	long long dp[91];

	dp[1] = 1;
	dp[2] = 1;

	for(int i = 3; i <= n; i++)
		dp[i] = dp[i - 2] + dp[i - 1];
	printf("%lld",dp[n]);
	return (0);
}
