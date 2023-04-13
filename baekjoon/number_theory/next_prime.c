#include <stdio.h>

unsigned long long np(unsigned long long n)
{
	unsigned long long nn = n;
	int f = 0;
	while(1)
	{
		f = 0;
		for(unsigned long long i = 2; i * i <= nn; i++)
		{
			if(nn % i == 0)
			{
				f = 1;
				break;
			}
		}
		if(f == 0)
			break;
		nn++;
	}
	return (nn);
}

int main(void)
{
	int t;
	scanf("%d",&t);
	unsigned long long n;
	
	for(int i = 0; i < t; i++)
	{
		scanf("%lld",&n);
		if(n <= 1)
		{
			printf("2\n");
			continue;
		}
		printf("%lld\n",np(n));
	}
	return (0);
}
