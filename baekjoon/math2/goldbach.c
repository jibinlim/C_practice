#include<stdio.h>
#include<stdlib.h>

int* is_prime(int n)
{
	int *arr;

	arr = (int *) malloc (sizeof(int) * n + 1);

	for(int i = 0; i < n+1; i++)
		arr[i] = 0;

	arr[0] = 1;
	arr[1] = 1;

	for(int i = 2; i <= n; i++)
	{
		if(arr[i] == 1)
			continue;
		for(int j=2*i; j<=n ; j+=i)
			arr[j] = 1;
	}
	return (arr);
}

int main(void)
{
	int t;
	scanf("%d",&t);

	int p;
	int *ans_1;
	int *ans_2;
	int min;
	int x;
	int y;
	int *arr;

	ans_1 = (int *) malloc (sizeof(int) * t);
	ans_2 = (int *) malloc (sizeof(int) * t);

	for(int i = 0; i < t; i++)
	{
		scanf("%d",&p);
		arr = is_prime(p);
		x = p/2;
		y = 2147483647;
		min = 2147483647;
		while(y >= x)
		{
			while(arr[x] == 1)
				x--;
			if(arr[p - x] == 0)
			{
				y = p - x;
				ans_1[i] = x;
				ans_2[i] = y;
				break;
			}
			x--;
		}
	}
	for(int i = 0; i < t;i++)
		printf("%d %d\n",ans_1[i],ans_2[i]);
	free(ans_1);
	free(ans_2);
	free(arr);
	return (0);
}
