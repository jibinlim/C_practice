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
	int n,k;
	scanf("%d %d",&n,&k);
	int **dp;
	int w[101];
	int v[101];
	dp = (int **) malloc (sizeof(int *) * (n + 1));

	for(int i = 1; i <= n; i++)
		scanf("%d %d",&w[i], &v[i]);
	for(int i = 0; i <= n; i++)
	{
		dp[i] = (int *) malloc (sizeof(int) * (k + 1));
		if(i == 0)
			for(int j = 0; j <= k; j++)
				dp[i][j] = 0;
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= k; j++)
		{
			if(w[i] > j)
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
		}
	}
	printf("%d",dp[n][k]);
	for(int i = 0; i <= n; i++)
		free(dp[i]);
	free(dp);
	return (0);
}
