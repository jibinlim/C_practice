#include <stdio.h>
#include <math.h>

int min(int a,int b)
{
	if(a < b)
		return a;
	else
		return b;
}

int main(void)
{
	int n;
	scanf("%d",&n);
	int dp[100001] = {0,};
	int x;
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	for(int i = 3; i <= n; i++)
	{
		dp[i] = dp[i - 1] + 1;
		x = 2;
		while((int) pow(x , 2) <= i)
		{
			dp[i] = min(dp[i], 1 + dp[i - (int) pow(x,2)]);
			x++;
		}
	}
	printf("%d",dp[n]);
	return (0);
}
