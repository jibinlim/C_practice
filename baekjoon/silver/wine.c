#include <stdio.h>
#include <stdlib.h>
int max(int a, int b)
{
	if(a > b)
		return a;
	else
		return b;
}

int main(void)
{
	int n;
	scanf("%d",&n);
	int *wine;
	int *dp;

	wine = (int *) malloc (sizeof(int) * (n + 1));
	dp = (int *) malloc (sizeof(int) * (n + 1));

	for(int i = 1; i <= n; i++)
		scanf("%d",&wine[i]);
	wine[0] = 0;
	dp[1] = wine[1];
	dp[2] = wine[1] + wine[2];
	for(int i = 3; i <= n; i++)
	{
		dp[i] = max(dp[i - 2] + wine[i], max(dp[i - 3] + wine[i - 1] + wine[i], dp[i - 1]));
	}
	printf("%d",dp[n]);
	free(wine);
	free(dp);
	return (0);
}
