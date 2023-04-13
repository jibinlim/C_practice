#include <stdio.h>

int main(void)
{
	int t;
	scanf("%d",&t);

	long long dp[101];

	for(int i = 0; i < t; i++)
	{
		int n;
		scanf("%d",&n);

		dp[1] = 1;
		dp[2] = 1;
		dp[3] = 1;

		for(int j = 4; j <= n; j++)
			dp[j] = dp[j - 3] + dp[j - 2];
		printf("%lld\n",dp[n]);
	}
	return (0);
}
