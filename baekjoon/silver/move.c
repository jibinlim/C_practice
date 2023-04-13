#include <stdio.h>
int map[1001][1001] = {0,};
int n , m;

int MAX(int a, int b)
{
	if(a > b)
		return a;
	else
		return b;
}

int main(void)
{
	scanf("%d %d",&n,&m);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			scanf("%d",&map[i][j]);
	int dp[1001][1001] = {0,};

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			dp[i][j] = MAX(dp[i - 1][j], MAX(dp[i][j - 1],dp[i - 1][j - 1])) + map[i - 1][j - 1];
	printf("%d\n",dp[n][m]);
	return (0);
}
