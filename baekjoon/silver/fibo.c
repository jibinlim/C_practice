#include <stdio.h>

int dp[100] = {0,};

int fibo(int n)
{
	dp[0] = 0;
	dp[1] = 1;
	for(int i = 2; i <= n; i++)
		dp[i] = dp[i - 2] + dp[i - 1];
	return dp[n];
}

int main(void)
{
	int n;
	scanf("%d",&n);

	printf("%d",fibo(n));
	return (0);
}
