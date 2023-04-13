#include <stdio.h>
#include <stdlib.h>



int cmp(const void *a, const void *b)
{
	if(*(int *)a > *(int *)b)
		return 1;
	else if (*(int *)a < *(int *)b)
		return -1;
	else
		return 0;
}

int min(int a,int b)
{
	if(a > b)
		return b;
	else
		return a;
}

int main(void)
{
	int n,k;
	scanf("%d %d",&n,&k);

	int *coin;
	coin = (int *) malloc (sizeof(int) * n);
	for(int i = 0; i < n; i++)
		scanf("%d",&coin[i]);
	qsort(coin,n,sizeof(int),cmp);
	int dp[10001] = {0,};

	dp[coin[0]] = 1;
	
	for(int i = 0; i < n; i++)
		for(int j = coin[i]; j <= k; j++)
		{
			if(j % coin[i] == 0)
				dp[j] = j / coin[i];
			else
			{
				if(dp[j - coin[i]] != 0)
				{
					if(dp[j] == 0)
						dp[j] = dp[coin[i]] + dp[j - coin[i]];
					else
						dp[j] = min(dp[j],dp[coin[i]] + dp[j - coin[i]]);
				}
			}
		}
	if(dp[k] == 0)
		printf("-1\n");
	else
		printf("%d\n",dp[k]);
	free(coin);
	return (0);
}
