#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	int n;
	scanf("%d",&n);

	int *arr;
	arr = (int *) malloc (sizeof(int *) * (n + 1));
	int dp[1001] = {0,};
	int r_dp[1001] = {0,};

	for(int i = 1; i <= n; i++)
		scanf("%d",arr+i);

	for(int i = 1; i <= n; i++)
	{
		dp[i] = 1;
		for(int j = 1 ; j <= i; j++)
			if(arr[j] < arr[i] && dp[i] < dp[j] + 1)
				dp[i] = dp[j] + 1;
	}

	for(int i = n; i >= 1; i--)
	{
		r_dp[i] = 1;
		for(int j = n; j >= i; j--)
			if(arr[i] > arr[j] && r_dp[j] + 1 > r_dp[i])
				r_dp[i] = r_dp[j] + 1;
	}
	int ans = 0;
	for(int i = 0; i <= n; i++)
		if(ans < dp[i] + r_dp[i] - 1)
			ans = dp[i] + r_dp[i] - 1;
	printf("%d\n",ans);
	free(arr);
	return (0);
}
