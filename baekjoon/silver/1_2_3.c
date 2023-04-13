#include <stdio.h>
#include <stdlib.h>

unsigned long long dp[1000001] = {0,};

int main(void)
{
	int t;
	scanf("%d",&t);
	int *x;
	x = (int *) malloc (sizeof(int) * t);
	for(int i = 0; i < t; i++)
	{
		int n;
		scanf("%d",&n);
		dp[1] = 1;
		dp[2] = 2;
		dp[3] = 4;
		for(int j = 4; j <= n; j++)
			dp[j] = (dp[j - 3] + dp[j - 2] + dp[j - 1]) % 1000000009;
		dp[n] %= 1000000009;
		x[i] = dp[n];
	}
	for(int i = 0; i < t; i++)
		printf("%d\n",x[i]);
	free(x);
	return (0);
}
