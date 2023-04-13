#include <stdio.h>

int main(void)
{
	int n;
	scanf("%d",&n);
	int arr[1001] = {0,};
	int dp[1001] = {0,};

	int min = 0;
	int max = 0;
	for(int i = 0; i < n; i++)
		scanf("%d",&arr[i]);

	dp[0] = 0;
	for(int i = 0; i < n; i++)
	{
		min = 0;
		for(int j = 0; j < i; j++)
		{
			if(arr[j] > arr[i])
				if(dp[j] > min)
					min = dp[j];
		}
		dp[i] = min + 1;
		if(max < dp[i])
			max = dp[i];
	}

	printf("%d\n",max);
	return (0);
}
