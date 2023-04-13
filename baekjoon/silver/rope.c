#include <stdio.h>
#include <stdlib.h>

int MAX(int a, int b)
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

	int *w;
	w = (int *) malloc (sizeof(int) * n);
	int *dp;
	dp = (int *) malloc (sizeof(int) * n);
	for(int i = 0; i < n; i++)
		scanf("%d",&w[i]);
	dp[0] = w[0];
	int min;
	for(int i = 1; i < n; i++)
	{
		min = 2147483647;
		for(int j = 0; j <= i; j++)
			if(min > w[j])
				min = w[j];
		dp[i] = MAX(dp[i - 1],MAX(w[i],min * (i + 1)));
	}
	printf("%d\n",dp[n - 1]);
	free(w);
	free(dp);
	return (0);
}
