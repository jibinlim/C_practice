#include <stdio.h>

int main(void)
{
	int dp[1001][10] = {0,};
	int n;
	scanf("%d",&n);

	for(int i = 0; i <= 9; i++)
		dp[1][i] = 1;
	long long sum = 0;
	for(int i = 2; i <= n; i++)
	{
		for(int j = 0; j <= 9; j++)
		{
			sum = 0;
			for(int k = j; k <= 9; k++)
				sum += dp[i - 1][k] % 10007;
			dp[i][j] = sum % 10007;
		}
	}
	sum = 0;
	for(int i = 0; i <= 9; i++)
		sum += dp[n][i] % 10007;
	printf("%lld\n",sum % 10007);
	return (0);
}
