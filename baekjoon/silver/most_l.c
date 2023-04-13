#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n;
	scanf("%d", &n);

	int *a;

	a = (int *) malloc (sizeof(int) * n);

	for(int i = 0; i < n; i++)
		scanf("%d", a + i);
	int max = 0;
	int *dp;
	int min = 0;

	dp = (int *) malloc (sizeof(int) * 1001);

	for(int i = 0; i < n; i++)
	{
		min = 0;
		for(int j = 0; j < i; j++)
		{
			if(a[i] > a[j])
				if(dp[j] > min)
					min = dp[j];
		}
		dp[i] = min + 1;
		if(max < dp[i])
			max = dp[i];
	}
	printf("%d",max);
	free(a);
	free(dp);
	return (0);
}
