#include <stdio.h>

int min(int a,int b)
{
	if(a > b)
		return b;
	else
		return a;
}

int main(void)
{
	int x;
	scanf("%d",&x);

	int dp[1000001] = {0,};

	dp[1] = 0;

	for(int i = 2; i <= x; i++)
	{
		dp[i] = dp[i - 1] + 1;
		if(i % 2 == 0)
			dp[i] = min(dp[i / 2] + 1, dp[i]);
		if(i % 3 == 0)
			dp[i] = min(dp[i / 3] + 1, dp[i]);
		if(i % 6 == 0)
			dp[i] = min(dp[i / 2] + 1, min(dp[i / 3] + 1, dp[i]));
	}
	printf("%d",dp[x]);

	return (0);
}
