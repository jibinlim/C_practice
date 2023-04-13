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
	int *arr;
	arr = (int *) malloc (sizeof(int) * (n + 1));
	int dp[1001] = {0,};

	for(int i = 1; i <= n; i++)
	{
		scanf("%d",arr+i);
		dp[i] = arr[i];
	}

	int sum = 0;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= i; j++)
		{
			if(arr[i] > arr[j])
				dp[i] = max(dp[i], dp[j] + arr[i]);
		}
		sum = max(sum,dp[i]);
	}
	printf("%d",sum);
	free(arr);
	return (0);
}
