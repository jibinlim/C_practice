#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n;
	scanf("%d",&n);

	int *tower;
	tower = (int *) malloc (sizeof(int) * (n + 1));
	for(int i = 1; i <= n; i++)
		scanf("%d",&tower[i]);
	int* dp;
	dp = (int *) malloc (sizeof(int) * (n + 1));
	dp[0] = 0;

	for(int i = 1; i <= n; i++)
	{
		if(tower[i] >= tower[i - 1])
		{
			for(int j = dp[i - 1]; j >= 0; j--)
			{
				if(tower[j] > tower[i])
				{
					dp[i] = j;
					break;
				}
				else
					dp[i] = 0;
			}
		}
		else
		{
			for(int j = i - 1; j >= 0; j--)
			{
				if(tower[j] > tower[i])
				{
					dp[i] = j;
					break;
				}
				else
					dp[i] = 0;
			}
		}
	}
	for(int i = 1; i <= n; i++)
		printf("%d ",dp[i]);
	free(tower);
	free(dp);
	return (0);
}
