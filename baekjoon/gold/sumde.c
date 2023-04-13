#include <stdio.h>

int main(void)
{
	int n,k;
	scanf("%d %d",&n,&k);

	long long dp[201][201] = {0,};

	dp[1][1] = 1;
	for(int i = 2; i <= 200; i++)
	{
		dp[i][1] = 1;
		dp[1][i] = i;
	}
	for(int i = 2; i <= n; i++)
		for(int j = 2; j <= k; j++)
				dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000000;
	printf("%lld\n",dp[n][k]);
	return (0);
}
