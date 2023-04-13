#include <stdio.h>

int main(void)
{
	int n;
	while(1)
	{
		scanf("%d",&n);
		if(n == -1)
			break;
	int i = 0;
	int a[100001];
	int x = 1;
	int sum = 0;
	while(n > x)
	{
		if(n % x == 0)
		{
			a[i] = x;
			sum += x;
			i++;
		}
		x++;
	}
	if(n != sum)
		printf("%d is NOT perfect.\n",n);
	else
	{
		printf("%d =",n);
		for(int j = 0; j < i; j++)
		{
			if(j != i - 1)
				printf(" %d +",a[j]);
			else
				printf(" %d\n",a[j]);
		}
	}
	}
	return (0);
}
