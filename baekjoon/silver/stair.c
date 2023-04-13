#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n;
	scanf("%d",&n);
	unsigned long long **dp;
	unsigned long long count = 0;
	dp = (unsigned long long **) malloc (sizeof(unsigned long long *) * (n + 1));
	for(int i = 1; i <= n; i++)
	{
		dp[i] = (unsigned long long *) malloc (sizeof(unsigned long long) * 10);
		for(int j = 0; j <= 9; j++)
		{
			if(i == 1)
				dp[i][j] = 1;
			else
				dp[i][j] = 0;
		}
	}
	dp[1][0] = 1;
	for(int i = 2; i <= n; i++)
	{
		dp[i][0] = dp[i - 1][1];
		for(int j = 1; j <= 9; j++)
		{
			if(j != 9)
				dp[i][j] = dp[i - 1][j + 1] + dp[i - 1][j - 1];
			else
				dp[i][j] = dp[i - 1][j - 1];
			if(dp[i][j] > 1000000000)
				dp[i][j] %= 1000000000;
		}
	}
	for(int i = 1; i <= 9; i++)
		count += dp[n][i];
	if(count >= 1000000000)
		count %= 1000000000;
	printf("%lld",count);
	for(int i = 1; i <= n; i++)
		free(dp[i]);
	free(dp);
	return (0);
}
