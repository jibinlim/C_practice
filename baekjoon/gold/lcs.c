#include <stdio.h>
#include <string.h>

int max(int a, int b)
{
	if(a > b)
		return a;
	else
		return b;
}

int main(void)
{
	char s[1001];
	char t[1001];

	scanf("%s",s);
	scanf("%s",t);

	int dp[1001][1001] = {0,};
	int s_len = strlen(s);
	int t_len = strlen(t);
	int i = 0;
	int j = 0;
	int x = 0;
	for(i = 1; i <= s_len; i++)
		for(j = 1; j <= t_len; j++)
		{
			if(s[i - 1] == t[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j],dp[i][j - 1]);
		}

	printf("%d",dp[s_len][t_len]);
	return (0);
}
