#include <stdio.h>
#include <stdlib.h>

int max(int a,int b)
{
	if(a > b)
		return a;
	else
		return b;
}

int main(void)
{
	int s;
	scanf("%d",&s);

	int *stair;
	stair = (int *) malloc (sizeof(int) * s);

	for(int i = 0; i < s; i++)
		scanf("%d", &stair[i]);
	long long dp[301];
	int c = 0;
	int m = 0;

	dp[1] = stair[0];
	dp[2] = stair[0] + stair[1];
	if(stair[0] + stair[2] < stair[1] + stair[2])
		c = 1;
	dp[3] = max(stair[0] + stair[2], stair[1] + stair[2]);
	for(int i = 4; i <= s; i++)
	{
		if(c == 1)
		{
			dp[i] = max(dp[i - 2], dp[i - 3] + stair[i - 2]) + stair[i - 1];
			if(dp[i - 3] + stair[i - 2] > dp[i - 2])
				c = 1;
			else
				c = 0;
		}
		else
		{
			dp[i] = max(dp[i - 2],dp[i - 1]) + stair[i - 1];
			if(dp[i - 1] > dp[i - 2])
				c = 1;
			else
				c = 0;
		}
	}
	free(stair);
	printf("%lld\n",dp[s]);
	return (0);
}
