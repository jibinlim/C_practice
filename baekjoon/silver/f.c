#include <stdio.h>

int main(void)
{
	int a,b,c;
	int d;
	int a_t,b_t,c_t;

	int dp[51][51][51] = {0,};

	dp[0][0][0] = 1;
	while(1)
	{
		scanf("%d %d %d", &a, &b, &c);

		a_t = a;
		b_t = b;
		c_t = c;
		if(a == -1 && b == -1 && c == -1)
			break;
		if(a > 20 || b > 20 || c > 20)
		{
			a_t = 20;
			b_t = 20;
			c_t = 20;
		}
		for(int i = 0; i <= a_t; i++)
			for(int j = 0; j <= b_t; j++)
				for(int k = 0; k <= c_t; k++)
					if(i == 0 || j == 0 || k == 0)
						dp[i][j][k] = 1;
		for(int i = 1; i <= a_t; i++)
			for(int j = 1; j <= b_t; j++)
				for(int k = 1; k <= c_t ; k++)
				{
					if(i < j && j < k)
						dp[i][j][k] = dp[i][j][k - 1] + dp[i][j - 1][k - 1] - dp[i][j - 1][k];
					else
						dp[i][j][k] =dp[i - 1][j][k] + dp[i - 1][j - 1][k] + dp[i - 1][j][k - 1] - dp[i -1][j - 1][k - 1];
				}
		if(a <= 0 || b <= 0 || c <= 0)
			printf("w(%d, %d, %d) = 1\n",a,b,c);
		else
			printf("w(%d, %d, %d) = %d\n",a,b,c,dp[a_t][b_t][c_t]);
	}
	return (0);
}
