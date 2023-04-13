#include <stdio.h>
#include <stdlib.h>

int is_prime(int n)
{
	int a = 2;
	if(n < 2)
		return (0);
	while(n != a)
	{
		if(n % a == 0)
			return (0);
		a++;
	}
	return (1);
}

int main(void)
{
	int m,n;

	scanf("%d",&m);
	scanf("%d",&n);

	int min = 100000;
	int sum = 0;

	while(m <= n)
	{
		if(is_prime(m) == 1)
		{
			sum += m;
			if(m < min)
				min = m;
		}
		m++;
	}
	if(sum == 0)
		printf("-1\n");
	else
		printf("%d\n%d\n",sum,min);
	return (0);
}
