#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n,k;
	scanf("%d %d",&n,&k);

	int dp[100001];
	int *coin;
	coin = (int *) malloc (sizeof(int) * n);

	for(int i = 0; i < n; i++)
		scanf("%d",&coin[i]);
	dp[0] = 1;
	for(int i = 0; i < n; i++)
		for(int j = coin[i]; j <= k; j++)
			dp[j] = dp[j] + dp[j - coin[i]];

	printf("%d\n",dp[k]);
	free(coin);
	return (0);
}
