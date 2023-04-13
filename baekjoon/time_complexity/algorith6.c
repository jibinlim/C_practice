#include <stdio.h>

unsigned long long dp[500001] = {0,};

int main(void)
{
	int n;
	scanf("%d",&n);
	if(n <= 2)
		printf("0\n3");
	else
	{
		unsigned long long x = 4;
		dp[3] = 1;
		dp[4] = 4;
		dp[5] = 10;
		for(int i = 6; i <= n; i++)
		{
			dp[i] =2 * dp[i - 1] - dp [i - 2] + x;
			x++;
		}
		printf("%lld\n3",dp[n]);
	}
	return (0);
}
