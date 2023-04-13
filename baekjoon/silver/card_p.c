#include <stdio.h>

int max(int a,int b)
{
	if(a > b)
		return (a);
	else
		return (b);
}

int main(void)
{
	unsigned long long dp[1001] = {0,};
	int n;
	int card[1001] ={0,};
	scanf("%d",&n);
	int rear,front;

	for(int i = 1; i <= n; i++)
		scanf("%d",card + i);
	dp[1] = card[1];
	for(int i = 2; i <= n; i++)
	{
		front = 1;
		rear = i - 1;
		if(i % 2 == 0)
		{
			dp[i] = max(dp[i / 2] * 2,card[i]);
			while(front < rear)
			{
				dp[i] = max(dp[front] + dp[rear],dp[i]);
				front++;
				rear--;
			}
		}
		else
		{
			dp[i] = card[i];
			while(front < rear)
			{
				dp[i] = max(dp[front] + dp[rear], dp[i]);
				front++;
				rear--;
			}
		}
	}
	printf("%lld",dp[n]);
	return (0);
}
				

