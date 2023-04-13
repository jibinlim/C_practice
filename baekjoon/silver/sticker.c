#include <stdio.h>
#include <stdlib.h>

int max(int a,int b)
{
	if (a > b)
		return a;
	else
		return b;
}

int main(void)
{
	int t;
	scanf("%d",&t);

	int n;
	int **a;
	int **dp;
	int *ans;

	ans = (int *) malloc (sizeof(int) * t);

	for(int i = 0; i < t; i++)
	{
		scanf("%d",&n);
		dp = (int **) malloc (sizeof(int *) * 2);
		a = (int **) malloc (sizeof(int *) * 2);
		for(int k = 0; k < 2; k++)
		{
			a[k] = (int *) malloc (sizeof(int) * n);
			dp[k] = (int *) malloc (sizeof(int) * n);
			for(int j = 0; j < n; j++)
				scanf("%d",&a[k][j]);
		}
		dp[0][0] = a[0][0];
		dp[1][0] = a[1][0];

		dp[0][1] = a[0][1] + dp[1][0];
		dp[1][1] = a[1][1] + dp[0][0];

		for(int j = 2; j < n; j++)
		{
			dp[0][j] = a[0][j] + max(dp[1][j - 1], dp[1][j - 2]);
			dp[1][j] = a[1][j] + max(dp[0][j - 1], dp[0][j - 2]);
		}

		ans[i] = max(dp[0][n -1],dp[1][n - 1]);
		for(int j = 0; j < 2; j++)
		{
			free(a[j]);
			free(dp[j]);
		}
		free(dp);
		free(a);
	}
	for(int i = 0; i < t; i++)
		printf("%d\n",ans[i]);
	free(ans);
	return (0);
}
