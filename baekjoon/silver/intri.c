#include <stdio.h>

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

	int a = 1;
	int tri[500][500] = {0,};
	int m = 0;

	int dp[501][501] = {0 ,};

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < a; j++)
			scanf("%d",&tri[i][j]);
		a++;
	}
	dp[1][0] = tri[0][0];
	dp[2][0] = tri[1][0] + dp[1][0];
	dp[2][1] = tri[1][1] + dp[1][0];
	a = 3;
	for(int i = 3; i <= n; i++)
	{
		dp[i][0] = dp[i - 1][0] + tri[i - 1][0];
		for(int j = 1; j <= a; j++)
			dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + tri[i - 1][j];
		a++;
	}
	for(int i = 0; i <= n; i++)
		if(m < dp[n][i])
			m = dp[n][i];
	printf("%d",m);
	return (0);
}
