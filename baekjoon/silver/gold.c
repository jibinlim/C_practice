#include <stdio.h>

int main(void)
{
	int t;
	scanf("%d",&t);

	int dp[1000001] = {0,};

	dp[0] = 1;
	dp[1] = 1;

	for(int i = 2; i * i <= 1000001; i++)
	{
		if(dp[i] == 0)
		{
			for(int j = 2; i * j < 1000001; j++)
				dp[i * j] = 1;
		}
	}

	for(int i = 0; i < t; i++)
	{
		int n;
		scanf("%d",&n);

		int count = 0;
		for(int j = 2; j <= n / 2; j++)
			if(dp[j] == 0)
				if(dp[n - j] == 0)
					count++;
		printf("%d\n",count);
	}
	return (0);
}
