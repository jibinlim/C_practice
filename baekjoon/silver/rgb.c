#include <stdio.h>

int Min(int a, int b)
{
	if(a > b)
		return b;
	else
		return a;
}

int main(void)
{
	int i;
	int c,r,g,b;
	int dp[1000][3],arrR[1000],arrG[1000],arrB[1000],min = 2147483647;

	scanf("%d",&c);
	for(int i = 0; i < c; i++)
	{
		scanf("%d %d %d",&r,&g,&b);
		arrR[i] = r;
		arrG[i] = g;
		arrB[i] = b;
	}

	dp[0][0] = arrR[0];
	dp[0][1] = arrG[0];
	dp[0][2] = arrB[0];

	for(i = 1; i < c; i++)
	{
		dp[i][0] = arrR[i] + Min(dp[i - 1][1], dp[i - 1][2]);
		dp[i][1] = arrG[i] + Min(dp[i - 1][0], dp[i - 1][2]);
		dp[i][2] = arrB[i] + Min(dp[i - 1][0], dp[i - 1][1]);
	}

	printf("%d", Min(Min(dp[c - 1][0], dp[c - 1][1]), dp[c - 1][2]));

	return (0);
}
