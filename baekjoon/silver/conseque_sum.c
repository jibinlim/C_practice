#include <stdio.h>
#include <stdlib.h>

int max(int a,int b)
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
	int *a;
	int *dp;
	int x;

	a = (int *) malloc (sizeof(int) * n);
	dp = (int *) malloc (sizeof(int) * (n + 1));
	for(int i = 0; i < n; i++)
		scanf("%d",a + i);
	dp[0] = a[0];
	x = a[0];
	for(int i = 1; i < n; i++)
	{
		dp[i] = max(a[i], a[i] + dp[i - 1]);
		x = max(dp[i], x);
	}
	printf("%d",x);
	free(dp);
	free(a);
	return (0);
}
